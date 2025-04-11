#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <vector>
#include <oknoarx.h>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , timer(new QTimer(this))
    , network(new Network(this))
{
    ui->setupUi(this);
    ui->stopButton->setEnabled(false);
    connect(timer, &QTimer::timeout, this, &MainWindow::aktualizujWykres);
    setupPlots();
    QStringList sygnal = {"Skok jednostkowy", "Sinusoida", "Prostokąt"};
    ui->comboBox->addItems(sygnal);
    RegulatorPID regulator;
    ARXModel model;
    sym = new symulacja(regulator, model);

    connect(network, &Network::connected,this, [=](QString adr, int port){});
    connect(network, &Network::disconecetd, this,[=](){});

    ui->networkCombo->addItem("Lokalny", QVariant::fromValue(static_cast<int>(NetworkMode::Local)));
    ui->networkCombo->addItem("Server", QVariant::fromValue(static_cast<int>(NetworkMode::Server)));
    ui->networkCombo->addItem("Client", QVariant::fromValue(static_cast<int>(NetworkMode::Client)));
}

MainWindow::~MainWindow()
{
    delete sym;
    delete ui;
}

void MainWindow::on_startButton_clicked()
{
    sym->start();
    timer->start(sym->getKrokCzasowy() * 1000.0);
    ui->startButton->setEnabled(0);
    ui->stopButton->setEnabled(true);
}

void MainWindow::on_stopButton_clicked()
{
    sym->stop();
    timer->stop();
    ui->startButton->setEnabled(1);
    ui->stopButton->setEnabled(false);
}

void MainWindow::aktualizujWykres()
{
    double czas = sym->getCzas();
    double wartosc = sym->getWartoscZadana();
    double sygnal_regulowany = sym->getUAR()->getPoprzednieWyjscie();
    double sygnal_sterujacy = sym->getUAR()->getSygnal();
    double Uip = sym->getUAR()->getRegulator().getUip();
    double Uii = sym->getUAR()->getRegulator().getUii();
    double Uid = sym->getUAR()->getRegulator().getUid();
    double uchyb = sym->getUAR()->getUchyb();

    ui->zadajnikPlot->graph(0)->addData(czas, wartosc);
    ui->zadajnikPlot->graph(1)->addData(czas, sygnal_regulowany);
    ui->nastawyPlot->graph(0)->addData(czas, Uip);
    ui->nastawyPlot->graph(1)->addData(czas, Uii);
    ui->nastawyPlot->graph(2)->addData(czas, Uid);
    ui->regPlot->graph()->addData(czas, sygnal_sterujacy);
    ui->uchybPlot->graph()->addData(czas, uchyb);

    if(czas >= 5)
    {
        ui->zadajnikPlot->xAxis->setRange(czas - 5, czas);
        ui->nastawyPlot->xAxis->setRange(czas - 5, czas);
        ui->regPlot->xAxis->setRange(czas - 5, czas);
        ui->uchybPlot->xAxis->setRange(czas - 5, czas);
    }

    ui->zadajnikPlot->graph(0)->rescaleValueAxis(true);
    ui->zadajnikPlot->graph(1)->rescaleValueAxis(true);
    ui->nastawyPlot->graph(0)->rescaleValueAxis(true);
    ui->nastawyPlot->graph(1)->rescaleValueAxis(true);
    ui->nastawyPlot->graph(2)->rescaleValueAxis(true);
    ui->regPlot->graph(0)->rescaleValueAxis(true);
    ui->uchybPlot->graph(0)->rescaleValueAxis(true);

    ui->zadajnikPlot->replot();
    ui->nastawyPlot->replot();
    ui->regPlot->replot();
    ui->uchybPlot->replot();

    ui->zadajnikPlot->graph(0)->data()->removeBefore(czas - 5);
    ui->zadajnikPlot->graph(1)->data()->removeBefore(czas - 5);
    ui->nastawyPlot->graph(0)->data()->removeBefore(czas - 5);
    ui->nastawyPlot->graph(1)->data()->removeBefore(czas - 5);
    ui->nastawyPlot->graph(2)->data()->removeBefore(czas - 5);
    ui->regPlot->graph()->data()->removeBefore(czas - 5);
    ui->uchybPlot->graph()->data()->removeBefore(czas - 5);
    sym->wykonajKrok();
}

void MainWindow::on_resetButton_clicked()
{
    sym->reset();
    ui->zadajnikPlot->graph(0)->data()->clear();
    ui->zadajnikPlot->graph(1)->data()->clear();
    ui->zadajnikPlot->xAxis->setRange(0, 5);
    ui->zadajnikPlot->yAxis->setRange(-5,10);
    ui->zadajnikPlot->replot();

    ui->nastawyPlot->graph(0)->data()->clear();
    ui->nastawyPlot->graph(1)->data()->clear();
    ui->nastawyPlot->graph(2)->data()->clear();
    ui->nastawyPlot->xAxis->setRange(0,5);
    ui->nastawyPlot->yAxis->setRange(-5,10);
    ui->nastawyPlot->replot();

    ui->regPlot->graph()->data()->clear();
    ui->regPlot->xAxis->setRange(0,5);
    ui->regPlot->yAxis->setRange(-5,10);
    ui->regPlot->replot();

    ui->uchybPlot->graph()->data()->clear();
    ui->uchybPlot->xAxis->setRange(0,5);
    ui->uchybPlot->yAxis->setRange(-5,10);
    ui->uchybPlot->replot();


}

void MainWindow::on_valueSpinBox_editingFinished()
{
    sym->getZadajnik()->setAmplituda(ui->valueSpinBox->value());
}

void MainWindow::on_okresSpinBox_editingFinished()
{
    sym->getZadajnik()->setOkres(ui->okresSpinBox->value());
}


void MainWindow::on_wypelnienieSpinBox_editingFinished()
{
    sym->getZadajnik()->setWypelnienie(ui->wypelnienieSpinBox->value());
}


void MainWindow::on_comboBox_activated(int index)
{
    TypSygnalu t = static_cast<TypSygnalu>(index);
    sym->getZadajnik()->setTyp(t);
}


void MainWindow::setupPlots()
{
    QFont legenda;
    legenda.setPointSize(7);

    ui->zadajnikPlot->addGraph()->setName("Wartość zadana");
    ui->zadajnikPlot->addGraph()->setName("Sygnał regulowany");
    ui->zadajnikPlot->xAxis->setLabel("Czas [s]");
    ui->zadajnikPlot->xAxis->setRange(0,5);
    ui->zadajnikPlot->yAxis->setRange(-5,10);
    ui->zadajnikPlot->legend->setVisible(true);
    ui->zadajnikPlot->legend->setFont(legenda);
    ui->zadajnikPlot->legend->setMargins(QMargins(2,2,2,2));

    ui->nastawyPlot->addGraph()->setName("Składowa Up");
    ui->nastawyPlot->addGraph()->setName("Składowa Ui");
    ui->nastawyPlot->addGraph()->setName("Składowa Ud");
    ui->nastawyPlot->xAxis->setLabel("Czas [s]");
    ui->nastawyPlot->xAxis->setRange(0,5);
    ui->nastawyPlot->yAxis->setRange(-5,10);
    ui->nastawyPlot->legend->setVisible(true);
    ui->nastawyPlot->legend->setFont(legenda);
    ui->nastawyPlot->legend->setMargins(QMargins(2,2,2,2));

    ui->regPlot->addGraph()->setName("Sygnał sterujący");
    ui->regPlot->xAxis->setLabel("Czas [s]");
    ui->regPlot->xAxis->setRange(0,5);
    ui->regPlot->yAxis->setRange(-5,10);
    ui->regPlot->legend->setVisible(true);
    ui->regPlot->legend->setFont(legenda);
    ui->regPlot->legend->setMargins(QMargins(2,2,2,2));

    ui->uchybPlot->addGraph()->setName("Uchyb regulacji");
    ui->uchybPlot->xAxis->setLabel("Czas [s]");
    ui->uchybPlot->xAxis->setRange(0,5);
    ui->uchybPlot->yAxis->setRange(-5,10);
    ui->uchybPlot->legend->setVisible(true);
    ui->uchybPlot->legend->setFont(legenda);
    ui->uchybPlot->legend->setMargins(QMargins(2,2,2,2));

    QPen penWartosc, penSygReg, penSygSter, penUip, penUii, penUid, penUchyb;
    penWartosc.setWidth(2);
    penWartosc.setColor(Qt::blue);
    ui->zadajnikPlot->graph(0)->setPen(penWartosc);

    penSygReg.setWidth(2);
    penSygReg.setColor(Qt::green);
    ui->zadajnikPlot->graph()->setPen(penSygReg);

    penSygSter.setWidth(2);
    penSygSter.setColor(QColorConstants::Red);
    ui->regPlot->graph(0)->setPen(penSygSter);

    penUip.setWidth(2);
    penUip.setColor(QColorConstants::Svg::red);
    ui->nastawyPlot->graph(0)->setPen(penUip);

    penUii.setWidth(2);
    penUii.setColor(QColorConstants::Svg::blue);
    ui->nastawyPlot->graph(1)->setPen(penUii);

    penUid.setWidth(2);
    penUid.setColor(QColorConstants::Svg::green);
    ui->nastawyPlot->graph(2)->setPen(penUid);

    penUchyb.setWidth(2);
    penUchyb.setColor(QColorConstants::Svg::orange);
    ui->uchybPlot->graph()->setPen(penUchyb);
}


void MainWindow::on_kSpinBox_editingFinished()
{
    sym->getUAR()->getRegulator().setK(ui->kSpinBox->value());
}


void MainWindow::on_tiSpinBox_editingFinished()
{
    sym->getUAR()->getRegulator().setTi(ui->tiSpinBox->value());
}


void MainWindow::on_tdSpinBox_editingFinished()
{
    sym->getUAR()->getRegulator().setTd(ui->tdSpinBox->value());
}

void MainWindow::on_GornaGranica_editingFinished()
{
    if(ui->AntyWindUP->isChecked())
        sym->getUAR()->getRegulator().setGranicaGorna(ui->GornaGranica->value());
}


void MainWindow::on_DolnaGranica_editingFinished()
{
    if(ui->AntyWindUP->isChecked())
        sym->getUAR()->getRegulator().setGranicaDolna(ui->DolnaGranica->value());
}


void MainWindow::on_AntyWindUP_checkStateChanged(const Qt::CheckState &arg1)
{
    if (arg1 == Qt::Checked)
        sym->getUAR()->getRegulator().setFiltr(Filtr::ON);
    else
        sym->getUAR()->getRegulator().setFiltr(Filtr::OFF);
}


void MainWindow::on_saveButton_clicked() //ZAPIS DO PLIKU
{
    QString filePath = QFileDialog::getSaveFileName(this, "Zapisz ustawienia", "", "Pliki tekstowe (*.txt);;Wszystkie pliki (*)");

    if (filePath.isEmpty())
    {
        qDebug() << "Nie wybrano pliku do zapisu.";
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
    {
        qDebug() << "Nie można otworzyć pliku do zapisu:" << file.errorString();
        return;
    }

    QTextStream zapisz(&file);


    zapisz << "[RegulatorPID]\n";
    zapisz << QString("K=%1\n").arg(sym->getUAR()->getRegulator().getK());
    zapisz << QString("Ti=%1\n").arg(sym->getUAR()->getRegulator().getTi());
    zapisz << QString("Td=%1\n").arg(sym->getUAR()->getRegulator().getTd());
    zapisz << QString("AntyWindUp=%1\n").arg(ui->AntyWindUP->isChecked() ? "true" : "false");
    zapisz << QString("GornaGranica=%1\n").arg(ui->GornaGranica->value());
    zapisz << QString("DolnaGranica=%1\n").arg(ui->DolnaGranica->value());


    zapisz << "[ARXModel]\n";
    zapisz << QString("opoznienie=%1\n").arg(sym->getUAR()->getModel().getOpoznienie());


    zapisz <<"vectorA=";
    for (size_t i = 0; i < sym->getUAR()->getModel().getVectorA().size(); ++i)
    {
        zapisz << sym->getUAR()->getModel().getVectorA()[i];
        if (i != sym->getUAR()->getModel().getVectorA().size() - 1)
            zapisz << ",";
    }
    zapisz << "\n";

    zapisz <<"vectorB=";
    for (size_t i = 0; i < sym->getUAR()->getModel().getVectorB().size(); ++i)
    {
        zapisz << sym->getUAR()->getModel().getVectorB()[i];
        if (i != sym->getUAR()->getModel().getVectorB().size() - 1)
            zapisz << ",";
    }
    zapisz << "\n";


    zapisz << QString("zaklocenie=%1\n").arg(sym->getUAR()->getModel().getZaklocenie());

    file.close();
    qDebug() << "Ustawienia zapisane do pliku:" << filePath;
}

void MainWindow::on_loadButton_clicked() //ODCZYT Z PLIKU
{
    QString filePath = QFileDialog::getOpenFileName(this, "Wczytaj ustawienia", "", "Pliki tekstowe (*.txt);;Wszystkie pliki (*)");

    if (filePath.isEmpty())
    {
        qDebug() << "Nie wybrano pliku do odczytu.";
        return;
    }

    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Nie można otworzyć pliku do odczytu:" << file.errorString();
        return;
    }

    QTextStream wyjscie(&file);
    QString wiersz;
    QString sekcja;

    while (!wyjscie.atEnd())
    {
        wiersz = wyjscie.readLine().trimmed();


        if (wiersz.isEmpty() || wiersz.startsWith("#"))
            continue;

        if (wiersz.startsWith("[") && wiersz.endsWith("]"))
        {
            sekcja = wiersz.mid(1, wiersz.length() - 2);
            continue;
        }

        QStringList czesc = wiersz.split("=");
        if (czesc.size() != 2)
            continue;

        QString slowo = czesc[0].trimmed();
        QString value = czesc[1].trimmed();

        if (sekcja == "RegulatorPID")
        {
            if (slowo == "K")
                ui->kSpinBox->setValue(value.toDouble());
            else if (slowo == "Ti")
                ui->tiSpinBox->setValue(value.toDouble());
            else if (slowo == "Td")
                ui->tdSpinBox->setValue(value.toDouble());
            else if (slowo == "AntyWindUp")
                ui->AntyWindUP->setChecked(value == "true");
            else if (slowo == "GornaGranica")
                ui->GornaGranica->setValue((value.toDouble()));
            else if (slowo == "DolnaGranica")
                ui->DolnaGranica->setValue(value.toDouble());
        }

        else if (sekcja == "ARXModel")
        {
            if (slowo == "opoznienie")
                sym->getUAR()->getModel().setOpoznienie(value.toInt());
            else if (slowo == "vectorA")
            {
                QStringList values = value.split(",", Qt::SkipEmptyParts);
               std::vector<double> vectorA;
                for (QString &val : values)
                {
                    vectorA.push_back(val.toDouble());
                }
                sym->getUAR()->getModel().setVectorA({vectorA[0],vectorA[1],vectorA[2]});
            }
            else if (slowo == "vectorB")
            {
                QStringList values = value.split(",", Qt::SkipEmptyParts);
                std::vector<double> vectorB;
                for (QString &val : values)
                {
                    vectorB.push_back(val.toDouble());
                }
                sym->getUAR()->getModel().setVectorB({vectorB[0],vectorB[1],vectorB[2]});
            }
            else if (slowo == "zaklocenie")
                sym->getUAR()->getModel().setZaklocenie(value.toDouble());
        }
    }

    file.close();
    qDebug() << "Ustawienia wczytane z pliku:" << filePath;
}



void MainWindow::on_interwalSpinBox_editingFinished()
{
    sym->setKrokCzasowy(ui->interwalSpinBox->value());
    timer->setInterval(sym->getKrokCzasowy() * 1000.0);
}


void MainWindow::on_btnModelARx_clicked()
{

    OknoARX okno(this);

    okno.setOpoznienie(sym->getUAR()->getModel().getOpoznienie());
    okno.setZaklocenie(sym->getUAR()->getModel().getZaklocenie());
    if(sym->getUAR()->getModel().getVectorA().size()>=3)
    {
    okno.setVectorA(sym->getUAR()->getModel().getVectorA(0));
    okno.setVectorAA(sym->getUAR()->getModel().getVectorA(1));
    okno.setVectorAAA(sym->getUAR()->getModel().getVectorA(2));
    }
    if(sym->getUAR()->getModel().getVectorB().size()>=3)
    {
    okno.setVectorB(sym->getUAR()->getModel().getVectorB(0));
    okno.setVectorBB(sym->getUAR()->getModel().getVectorB(1));
    okno.setVectorBBB(sym->getUAR()->getModel().getVectorB(2));
    }
    if(okno.exec()==QDialog::Accepted)
    {
        sym->getUAR()->getModel().setVectorA({okno.getVectorA(),okno.getVectorAA(), okno.getVectorAAA()});
        sym->getUAR()->getModel().setVectorB({okno.getVectorB(),okno.getVectorBB(), okno.getVectorBBB()});
        sym->getUAR()->getModel().setOpoznienie(okno.getOpoznienie());
        sym->getUAR()->getModel().setZaklocenie(okno.getZaklocenie());

    }

}


void MainWindow::on_czasAktywacjiSpinBox_editingFinished()
{
    sym->getZadajnik()->setCzasAktywacji(ui->czasAktywacjiSpinBox->value());
}


void MainWindow::on_skladowaStalaSpinBox_editingFinished()
{
    sym->getZadajnik()->setSkladowa(ui->skladowaStalaSpinBox->value());
}


void MainWindow::on_AntyWindUP_stateChanged(int arg1)
{
    if (arg1 == Qt::Checked)
        sym->getUAR()->getRegulator().setFiltr(Filtr::ON);
    else
        sym->getUAR()->getRegulator().setFiltr(Filtr::OFF);

}


void MainWindow::on_comboBox_currentIndexChanged(int index)
{

    ui->okresSpinBox->setVisible(false);
    ui->valueSpinBox->setVisible(false);
    ui->lblOkres->setVisible(false);
    ui->lblAmplituda->setVisible(false);
    ui->wypelnienieSpinBox->setVisible(false);
    ui->lblWypelnienie->setVisible(false);
    ui->czasAktywacjiSpinBox->setVisible(true);
    ui->lblCzasAktywacji->setVisible(true);

    if (index >= 1)
    {
        ui->okresSpinBox->setVisible(true);
        ui->lblOkres->setVisible(true);
        ui->valueSpinBox->setVisible(true);
        ui->lblAmplituda->setVisible(true);
        ui->czasAktywacjiSpinBox->setVisible(false);
        ui->lblCzasAktywacji->setVisible(false);
    }
    if (index == 2)
    {
        ui->wypelnienieSpinBox->setVisible(true);
        ui->lblWypelnienie->setVisible(true);

    }
}



void MainWindow::on_radioButton_2_clicked()
{
    ui->radioButton_2->setChecked(true);
    ui->radioButton_3->setChecked(false);
    sym->getUAR()->getRegulator().setTryb(TrybCalkowania::STALA_PRZED_SUMA);
}


void MainWindow::on_radioButton_3_clicked()
{
    ui->radioButton_3->setChecked(true);
    ui->radioButton_2->setChecked(false);
    sym->getUAR()->getRegulator().setTryb(TrybCalkowania::STALA_POD_SUMA);
}



void MainWindow::on_cbxCzarnyMotyw_stateChanged(int arg1)
{
    if (ui->cbxCzarnyMotyw->isChecked()) {

        qApp->setStyleSheet(R"(
            QWidget {
                background-color: #121212;
                color: #ffffff;
            }
            QLineEdit, QSpinBox, QDoubleSpinBox, QComboBox {
                background-color: #1e1e1e;
                color: #ffffff;
                border: 1px solid #666;
                padding: 2px;
            }
            QPushButton {
                background-color: #333;
                color: #ffffff;
                border: 1px solid #666;
                padding: 3px;
            }
            QLabel, QGroupBox, QRadioButton, QCheckBox {
                color: #ffffff;
            }
            QTabWidget::pane {
                border: 1px solid #666;
            }
            QTabBar::tab {
                background: #333;
                color: #ffffff;
                padding: 5px;
            }
            QHeaderView::section {
                background-color: #333;
                color: white;
            }
        )");

        QColor plotBackground("#121212");
        ui->zadajnikPlot->setBackground(plotBackground);
        ui->nastawyPlot->setBackground(plotBackground);
        ui->regPlot->setBackground(plotBackground);
        ui->uchybPlot->setBackground(plotBackground);

        auto configureDarkPlot = [](QCustomPlot* plot) {
            QPen axisPen(Qt::white);

            plot->xAxis->setBasePen(axisPen);
            plot->yAxis->setBasePen(axisPen);
            plot->xAxis->setTickPen(axisPen);
            plot->yAxis->setTickPen(axisPen);
            plot->xAxis->setSubTickPen(axisPen);
            plot->yAxis->setSubTickPen(axisPen);
            plot->xAxis->setLabelColor(Qt::white);
            plot->yAxis->setLabelColor(Qt::white);
            plot->xAxis->setTickLabelColor(Qt::white);
            plot->yAxis->setTickLabelColor(Qt::white);


            QColor gridColor(160, 160, 160);
            plot->xAxis->grid()->setPen(QPen(gridColor, 1, Qt::DotLine));
            plot->yAxis->grid()->setPen(QPen(gridColor, 1, Qt::DotLine));

            if (!plot->legend) {
                plot->legend = new QCPLegend;
                plot->autoAddPlottableToLegend();
            }
            plot->legend->setVisible(true);
            plot->legend->setBrush(QColor(30, 30, 30));
            plot->legend->setTextColor(Qt::white);
            plot->legend->setBorderPen(QPen(Qt::darkGray));
        };

        configureDarkPlot(ui->zadajnikPlot);
        configureDarkPlot(ui->nastawyPlot);
        configureDarkPlot(ui->regPlot);
        configureDarkPlot(ui->uchybPlot);

    } else {

        qApp->setStyleSheet("");

        ui->zadajnikPlot->setBackground(Qt::white);
        ui->nastawyPlot->setBackground(Qt::white);
        ui->regPlot->setBackground(Qt::white);
        ui->uchybPlot->setBackground(Qt::white);

        auto configureDefaultPlot = [](QCustomPlot* plot) {
            QPen axisPen(Qt::black);

            plot->xAxis->setBasePen(axisPen);
            plot->yAxis->setBasePen(axisPen);
            plot->xAxis->setTickPen(axisPen);
            plot->yAxis->setTickPen(axisPen);
            plot->xAxis->setSubTickPen(axisPen);
            plot->yAxis->setSubTickPen(axisPen);
            plot->xAxis->setLabelColor(Qt::black);
            plot->yAxis->setLabelColor(Qt::black);
            plot->xAxis->setTickLabelColor(Qt::black);
            plot->yAxis->setTickLabelColor(Qt::black);

            plot->xAxis->grid()->setPen(QPen(Qt::gray, 1, Qt::DotLine));
            plot->yAxis->grid()->setPen(QPen(Qt::gray, 1, Qt::DotLine));

            if (plot->legend) {
                plot->legend->setBrush(Qt::white);
                plot->legend->setTextColor(Qt::black);
            }
        };

        configureDefaultPlot(ui->zadajnikPlot);
        configureDefaultPlot(ui->nastawyPlot);
        configureDefaultPlot(ui->regPlot);
        configureDefaultPlot(ui->uchybPlot);
    }

    ui->zadajnikPlot->replot();
    ui->nastawyPlot->replot();
    ui->regPlot->replot();
    ui->uchybPlot->replot();
}



void MainWindow::on_networkButton_clicked()
{
    int selectedMode = ui->networkCombo->currentIndex();
    NetworkMode mode = static_cast<NetworkMode>(selectedMode);

    initNetwork(mode);
}

void MainWindow::initNetwork(NetworkMode mode)
{
    network->setMode(mode);

    if(mode == NetworkMode::Client)
    {
        if(network->isServerRunning())
        {
            network->stopListening();
            qDebug() << "Server stopped";
        }
        network->connectToServer("192.168.100.140", 193); //193
        setControlsEnabled(false);
    }
    else if(mode == NetworkMode::Server)
    {
    if(network->startListening(193))
        {
            if(network->isClientConnected())
            {
                network->disconectFrom();
                qDebug() << "Client disconnected form server";
            }
            ui->startButton->setEnabled(true);
            ui->btnModelARx->setEnabled(false);
            setControlsEnabled(true);
        }
    }else
    {
        if(network->isClientConnected())
        {
            network->disconectFrom();
            qDebug() << "Client disconnected form server";
        }
        if(network->isServerRunning())
        {
            network->stopListening();
            qDebug() << "Server stopped";
        }
        ui->startButton->setEnabled(true);
        ui->btnModelARx->setEnabled(true);
        setControlsEnabled(true);
        ui->btnModelARx->setEnabled(true);
    }

}


void MainWindow::setControlsEnabled(bool mode)
{
    ui->startButton->setEnabled(mode);
    ui->btnModelARx->setEnabled(!mode);
    ui->kSpinBox->setEnabled(mode);
    ui->tdSpinBox->setEnabled(mode);
    ui->tiSpinBox->setEnabled(mode);
    ui->comboBox->setEnabled(mode);
    ui->skladowaStalaSpinBox->setEnabled(mode);
    ui->valueSpinBox->setEnabled(mode);
    ui->okresSpinBox->setEnabled(mode);
    ui->interwalSpinBox->setEnabled(mode);
    ui->czasAktywacjiSpinBox->setEnabled(mode);
    ui->radioButton_2->setEnabled(mode);
    ui->radioButton_3->setEnabled(mode);
}
