/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout_3;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_2;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *resetButton;
    QPushButton *saveButton;
    QPushButton *loadButton;
    QLabel *label_16;
    QSpinBox *interwalSpinBox;
    QCheckBox *cbxCzarnyMotyw;
    QGridLayout *gridLayout_6;
    QGridLayout *gridLayout_7;
    QDoubleSpinBox *GornaGranica;
    QPushButton *btnModelARx;
    QLabel *label_7;
    QLabel *label_6;
    QDoubleSpinBox *DolnaGranica;
    QCheckBox *AntyWindUP;
    QFrame *frame;
    QFrame *frame_3;
    QGridLayout *gridLayout_9;
    QDoubleSpinBox *okresSpinBox;
    QDoubleSpinBox *wypelnienieSpinBox;
    QDoubleSpinBox *valueSpinBox;
    QLabel *label_14;
    QLabel *lblStala;
    QComboBox *comboBox;
    QLabel *lblWypelnienie;
    QLabel *lblOkres;
    QLabel *lblAmplituda;
    QDoubleSpinBox *skladowaStalaSpinBox;
    QSpinBox *czasAktywacjiSpinBox;
    QLabel *lblCzasAktywacji;
    QGridLayout *gridLayout_2;
    QLabel *label_3;
    QDoubleSpinBox *kSpinBox;
    QComboBox *networkCombo;
    QLabel *label;
    QLabel *label_4;
    QDoubleSpinBox *tiSpinBox;
    QLabel *label_5;
    QRadioButton *radioButton_3;
    QDoubleSpinBox *tdSpinBox;
    QRadioButton *radioButton_2;
    QPushButton *networkButton;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGridLayout *gridLayout;
    QCustomPlot *nastawyPlot;
    QCustomPlot *uchybPlot;
    QCustomPlot *zadajnikPlot;
    QCustomPlot *regPlot;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1104, 785);
        MainWindow->setMinimumSize(QSize(1100, 750));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        gridLayout_3 = new QGridLayout(centralwidget);
        gridLayout_3->setObjectName("gridLayout_3");
        scrollArea_2 = new QScrollArea(centralwidget);
        scrollArea_2->setObjectName("scrollArea_2");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(1);
        sizePolicy.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy);
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName("scrollAreaWidgetContents_2");
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 1063, 240));
        QSizePolicy sizePolicy1(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(1);
        sizePolicy1.setHeightForWidth(scrollAreaWidgetContents_2->sizePolicy().hasHeightForWidth());
        scrollAreaWidgetContents_2->setSizePolicy(sizePolicy1);
        horizontalLayout = new QHBoxLayout(scrollAreaWidgetContents_2);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(5, 5, 5, 5);
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setSizeConstraint(QLayout::SizeConstraint::SetDefaultConstraint);
        verticalLayout_2->setContentsMargins(5, 5, 0, 5);
        startButton = new QPushButton(scrollAreaWidgetContents_2);
        startButton->setObjectName("startButton");

        verticalLayout_2->addWidget(startButton);

        stopButton = new QPushButton(scrollAreaWidgetContents_2);
        stopButton->setObjectName("stopButton");

        verticalLayout_2->addWidget(stopButton);

        resetButton = new QPushButton(scrollAreaWidgetContents_2);
        resetButton->setObjectName("resetButton");

        verticalLayout_2->addWidget(resetButton);

        saveButton = new QPushButton(scrollAreaWidgetContents_2);
        saveButton->setObjectName("saveButton");

        verticalLayout_2->addWidget(saveButton);

        loadButton = new QPushButton(scrollAreaWidgetContents_2);
        loadButton->setObjectName("loadButton");

        verticalLayout_2->addWidget(loadButton);

        label_16 = new QLabel(scrollAreaWidgetContents_2);
        label_16->setObjectName("label_16");
        label_16->setAlignment(Qt::AlignmentFlag::AlignCenter);

        verticalLayout_2->addWidget(label_16);

        interwalSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        interwalSpinBox->setObjectName("interwalSpinBox");
        interwalSpinBox->setMinimum(1);
        interwalSpinBox->setMaximum(1000);
        interwalSpinBox->setSingleStep(10);
        interwalSpinBox->setValue(50);

        verticalLayout_2->addWidget(interwalSpinBox);

        cbxCzarnyMotyw = new QCheckBox(scrollAreaWidgetContents_2);
        cbxCzarnyMotyw->setObjectName("cbxCzarnyMotyw");

        verticalLayout_2->addWidget(cbxCzarnyMotyw);


        horizontalLayout->addLayout(verticalLayout_2);

        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName("gridLayout_6");
        gridLayout_6->setHorizontalSpacing(20);
        gridLayout_7 = new QGridLayout();
        gridLayout_7->setObjectName("gridLayout_7");
        gridLayout_7->setHorizontalSpacing(0);
        GornaGranica = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        GornaGranica->setObjectName("GornaGranica");
        GornaGranica->setAlignment(Qt::AlignmentFlag::AlignCenter);
        GornaGranica->setValue(10.000000000000000);

        gridLayout_7->addWidget(GornaGranica, 1, 1, 1, 1);

        btnModelARx = new QPushButton(scrollAreaWidgetContents_2);
        btnModelARx->setObjectName("btnModelARx");

        gridLayout_7->addWidget(btnModelARx, 0, 0, 1, 1);

        label_7 = new QLabel(scrollAreaWidgetContents_2);
        label_7->setObjectName("label_7");
        label_7->setAlignment(Qt::AlignmentFlag::AlignBottom|Qt::AlignmentFlag::AlignHCenter);

        gridLayout_7->addWidget(label_7, 2, 0, 1, 1);

        label_6 = new QLabel(scrollAreaWidgetContents_2);
        label_6->setObjectName("label_6");
        label_6->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_7->addWidget(label_6, 1, 0, 1, 1);

        DolnaGranica = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        DolnaGranica->setObjectName("DolnaGranica");
        DolnaGranica->setAlignment(Qt::AlignmentFlag::AlignCenter);
        DolnaGranica->setMinimum(-99.989999999999995);

        gridLayout_7->addWidget(DolnaGranica, 2, 1, 1, 1);

        AntyWindUP = new QCheckBox(scrollAreaWidgetContents_2);
        AntyWindUP->setObjectName("AntyWindUP");
        AntyWindUP->setLayoutDirection(Qt::LayoutDirection::LeftToRight);

        gridLayout_7->addWidget(AntyWindUP, 0, 1, 1, 1);


        gridLayout_6->addLayout(gridLayout_7, 0, 4, 1, 1);

        frame = new QFrame(scrollAreaWidgetContents_2);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::Shape::VLine);
        frame->setFrameShadow(QFrame::Shadow::Plain);
        frame->setMidLineWidth(1);

        gridLayout_6->addWidget(frame, 0, 1, 1, 1);

        frame_3 = new QFrame(scrollAreaWidgetContents_2);
        frame_3->setObjectName("frame_3");
        frame_3->setFrameShape(QFrame::Shape::VLine);
        frame_3->setFrameShadow(QFrame::Shadow::Plain);
        frame_3->setMidLineWidth(1);

        gridLayout_6->addWidget(frame_3, 0, 5, 1, 1);

        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setHorizontalSpacing(0);
        okresSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        okresSpinBox->setObjectName("okresSpinBox");
        okresSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        okresSpinBox->setSingleStep(0.100000000000000);
        okresSpinBox->setValue(1.000000000000000);

        gridLayout_9->addWidget(okresSpinBox, 4, 1, 1, 1);

        wypelnienieSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        wypelnienieSpinBox->setObjectName("wypelnienieSpinBox");
        wypelnienieSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        wypelnienieSpinBox->setMinimum(0.010000000000000);
        wypelnienieSpinBox->setMaximum(1.000000000000000);
        wypelnienieSpinBox->setSingleStep(0.100000000000000);
        wypelnienieSpinBox->setValue(0.500000000000000);

        gridLayout_9->addWidget(wypelnienieSpinBox, 5, 1, 1, 1);

        valueSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        valueSpinBox->setObjectName("valueSpinBox");
        valueSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        valueSpinBox->setSingleStep(0.100000000000000);
        valueSpinBox->setValue(2.000000000000000);

        gridLayout_9->addWidget(valueSpinBox, 3, 1, 1, 1);

        label_14 = new QLabel(scrollAreaWidgetContents_2);
        label_14->setObjectName("label_14");
        label_14->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(label_14, 0, 0, 1, 1);

        lblStala = new QLabel(scrollAreaWidgetContents_2);
        lblStala->setObjectName("lblStala");
        lblStala->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(lblStala, 1, 0, 1, 1);

        comboBox = new QComboBox(scrollAreaWidgetContents_2);
        comboBox->setObjectName("comboBox");
        QSizePolicy sizePolicy2(QSizePolicy::Policy::Preferred, QSizePolicy::Policy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(comboBox->sizePolicy().hasHeightForWidth());
        comboBox->setSizePolicy(sizePolicy2);
        comboBox->setMinimumSize(QSize(150, 0));

        gridLayout_9->addWidget(comboBox, 0, 1, 1, 1);

        lblWypelnienie = new QLabel(scrollAreaWidgetContents_2);
        lblWypelnienie->setObjectName("lblWypelnienie");
        lblWypelnienie->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(lblWypelnienie, 5, 0, 1, 1);

        lblOkres = new QLabel(scrollAreaWidgetContents_2);
        lblOkres->setObjectName("lblOkres");
        lblOkres->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(lblOkres, 4, 0, 1, 1);

        lblAmplituda = new QLabel(scrollAreaWidgetContents_2);
        lblAmplituda->setObjectName("lblAmplituda");
        lblAmplituda->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(lblAmplituda, 3, 0, 1, 1);

        skladowaStalaSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        skladowaStalaSpinBox->setObjectName("skladowaStalaSpinBox");
        skladowaStalaSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        skladowaStalaSpinBox->setSingleStep(0.100000000000000);
        skladowaStalaSpinBox->setValue(2.000000000000000);

        gridLayout_9->addWidget(skladowaStalaSpinBox, 1, 1, 1, 1);

        czasAktywacjiSpinBox = new QSpinBox(scrollAreaWidgetContents_2);
        czasAktywacjiSpinBox->setObjectName("czasAktywacjiSpinBox");
        czasAktywacjiSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        czasAktywacjiSpinBox->setMaximum(10000);
        czasAktywacjiSpinBox->setValue(1000);

        gridLayout_9->addWidget(czasAktywacjiSpinBox, 2, 1, 1, 1);

        lblCzasAktywacji = new QLabel(scrollAreaWidgetContents_2);
        lblCzasAktywacji->setObjectName("lblCzasAktywacji");
        lblCzasAktywacji->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_9->addWidget(lblCzasAktywacji, 2, 0, 1, 1);


        gridLayout_6->addLayout(gridLayout_9, 0, 6, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout_2->setHorizontalSpacing(0);
        label_3 = new QLabel(scrollAreaWidgetContents_2);
        label_3->setObjectName("label_3");
        label_3->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_3, 4, 0, 1, 1);

        kSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        kSpinBox->setObjectName("kSpinBox");
        kSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        kSpinBox->setSingleStep(0.100000000000000);
        kSpinBox->setValue(0.500000000000000);

        gridLayout_2->addWidget(kSpinBox, 4, 1, 1, 1);

        networkCombo = new QComboBox(scrollAreaWidgetContents_2);
        networkCombo->setObjectName("networkCombo");

        gridLayout_2->addWidget(networkCombo, 1, 2, 1, 1);

        label = new QLabel(scrollAreaWidgetContents_2);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label, 1, 1, 1, 1);

        label_4 = new QLabel(scrollAreaWidgetContents_2);
        label_4->setObjectName("label_4");
        label_4->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_4, 6, 0, 1, 1);

        tiSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        tiSpinBox->setObjectName("tiSpinBox");
        tiSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tiSpinBox->setSingleStep(0.100000000000000);
        tiSpinBox->setValue(5.000000000000000);

        gridLayout_2->addWidget(tiSpinBox, 6, 1, 1, 1);

        label_5 = new QLabel(scrollAreaWidgetContents_2);
        label_5->setObjectName("label_5");
        label_5->setAlignment(Qt::AlignmentFlag::AlignCenter);

        gridLayout_2->addWidget(label_5, 8, 0, 1, 1);

        radioButton_3 = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_3->setObjectName("radioButton_3");

        gridLayout_2->addWidget(radioButton_3, 6, 2, 1, 1);

        tdSpinBox = new QDoubleSpinBox(scrollAreaWidgetContents_2);
        tdSpinBox->setObjectName("tdSpinBox");
        tdSpinBox->setAlignment(Qt::AlignmentFlag::AlignCenter);
        tdSpinBox->setSingleStep(0.100000000000000);
        tdSpinBox->setValue(0.200000000000000);

        gridLayout_2->addWidget(tdSpinBox, 8, 1, 1, 1);

        radioButton_2 = new QRadioButton(scrollAreaWidgetContents_2);
        radioButton_2->setObjectName("radioButton_2");
        radioButton_2->setChecked(true);

        gridLayout_2->addWidget(radioButton_2, 4, 2, 1, 1);

        networkButton = new QPushButton(scrollAreaWidgetContents_2);
        networkButton->setObjectName("networkButton");

        gridLayout_2->addWidget(networkButton, 2, 2, 1, 1);


        gridLayout_6->addLayout(gridLayout_2, 0, 0, 1, 1);


        horizontalLayout->addLayout(gridLayout_6);

        horizontalLayout->setStretch(1, 3);
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);

        gridLayout_3->addWidget(scrollArea_2, 0, 0, 1, 1);

        scrollArea = new QScrollArea(centralwidget);
        scrollArea->setObjectName("scrollArea");
        QSizePolicy sizePolicy3(QSizePolicy::Policy::Expanding, QSizePolicy::Policy::Expanding);
        sizePolicy3.setHorizontalStretch(1);
        sizePolicy3.setVerticalStretch(3);
        sizePolicy3.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy3);
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName("scrollAreaWidgetContents");
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1080, 520));
        gridLayout = new QGridLayout(scrollAreaWidgetContents);
        gridLayout->setSpacing(5);
        gridLayout->setObjectName("gridLayout");
        gridLayout->setContentsMargins(10, 10, 10, 10);
        nastawyPlot = new QCustomPlot(scrollAreaWidgetContents);
        nastawyPlot->setObjectName("nastawyPlot");

        gridLayout->addWidget(nastawyPlot, 1, 1, 1, 1);

        uchybPlot = new QCustomPlot(scrollAreaWidgetContents);
        uchybPlot->setObjectName("uchybPlot");

        gridLayout->addWidget(uchybPlot, 1, 2, 1, 1);

        zadajnikPlot = new QCustomPlot(scrollAreaWidgetContents);
        zadajnikPlot->setObjectName("zadajnikPlot");

        gridLayout->addWidget(zadajnikPlot, 0, 0, 1, 3);

        regPlot = new QCustomPlot(scrollAreaWidgetContents);
        regPlot->setObjectName("regPlot");

        gridLayout->addWidget(regPlot, 1, 0, 1, 1);

        scrollArea->setWidget(scrollAreaWidgetContents);

        gridLayout_3->addWidget(scrollArea, 1, 0, 1, 1);

        gridLayout_3->setRowStretch(0, 2);
        gridLayout_3->setRowStretch(1, 5);
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "Start", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "Stop", nullptr));
        resetButton->setText(QCoreApplication::translate("MainWindow", "Reset", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "Zapis", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "Wczytaj", nullptr));
        label_16->setText(QCoreApplication::translate("MainWindow", "Interwa\305\202 [ms]", nullptr));
        cbxCzarnyMotyw->setText(QCoreApplication::translate("MainWindow", "Czarny motyw", nullptr));
        btnModelARx->setText(QCoreApplication::translate("MainWindow", "ModelARX", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "Dolna Granica", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "G\303\263rna Granica", nullptr));
        AntyWindUP->setText(QCoreApplication::translate("MainWindow", "Antywindup", nullptr));
        label_14->setText(QCoreApplication::translate("MainWindow", "Warto\305\233\304\207 zadana", nullptr));
        lblStala->setText(QCoreApplication::translate("MainWindow", "Sk\305\202adowa sta\305\202a", nullptr));
        lblWypelnienie->setText(QCoreApplication::translate("MainWindow", "Wype\305\202nienie", nullptr));
        lblOkres->setText(QCoreApplication::translate("MainWindow", "Okres", nullptr));
        lblAmplituda->setText(QCoreApplication::translate("MainWindow", "Amplituda", nullptr));
        lblCzasAktywacji->setText(QCoreApplication::translate("MainWindow", "Czas aktywacji [ms]", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "P:", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Regulator PID", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "Ti:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "Td:", nullptr));
        radioButton_3->setText(QCoreApplication::translate("MainWindow", "Sta\305\202a pod sum\304\231", nullptr));
        radioButton_2->setText(QCoreApplication::translate("MainWindow", "Sta\305\202a przed sum\304\231", nullptr));
        networkButton->setText(QCoreApplication::translate("MainWindow", "SET NET MODE", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
