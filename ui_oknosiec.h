/********************************************************************************
** Form generated from reading UI file 'oknosiec.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOSIEC_H
#define UI_OKNOSIEC_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_oknosiec
{
public:
    QLabel *lbl_IP;
    QLabel *lbl_Port;
    QComboBox *comboBox;
    QPushButton *btn_start_connect;
    QPushButton *btn_stop_disconnect;
    QLineEdit *txt_ip1;
    QLineEdit *txt_ip2;
    QLineEdit *txt_ip3;
    QLineEdit *txt_ip4;
    QLineEdit *txt_port;
    QLabel *lbl_tryb;
    QLabel *lbl_message;

    void setupUi(QDialog *oknosiec)
    {
        if (oknosiec->objectName().isEmpty())
            oknosiec->setObjectName("oknosiec");
        oknosiec->resize(423, 232);
        lbl_IP = new QLabel(oknosiec);
        lbl_IP->setObjectName("lbl_IP");
        lbl_IP->setGeometry(QRect(30, 70, 49, 16));
        lbl_Port = new QLabel(oknosiec);
        lbl_Port->setObjectName("lbl_Port");
        lbl_Port->setGeometry(QRect(30, 120, 49, 16));
        comboBox = new QComboBox(oknosiec);
        comboBox->addItem(QString());
        comboBox->addItem(QString());
        comboBox->setObjectName("comboBox");
        comboBox->setGeometry(QRect(30, 30, 91, 24));
        btn_start_connect = new QPushButton(oknosiec);
        btn_start_connect->setObjectName("btn_start_connect");
        btn_start_connect->setGeometry(QRect(30, 160, 80, 24));
        btn_stop_disconnect = new QPushButton(oknosiec);
        btn_stop_disconnect->setObjectName("btn_stop_disconnect");
        btn_stop_disconnect->setGeometry(QRect(130, 160, 80, 24));
        txt_ip1 = new QLineEdit(oknosiec);
        txt_ip1->setObjectName("txt_ip1");
        txt_ip1->setGeometry(QRect(60, 60, 51, 24));
        txt_ip1->setMaxLength(3);
        txt_ip2 = new QLineEdit(oknosiec);
        txt_ip2->setObjectName("txt_ip2");
        txt_ip2->setGeometry(QRect(120, 60, 51, 24));
        txt_ip2->setMaxLength(3);
        txt_ip3 = new QLineEdit(oknosiec);
        txt_ip3->setObjectName("txt_ip3");
        txt_ip3->setGeometry(QRect(180, 60, 51, 24));
        txt_ip3->setMaxLength(3);
        txt_ip4 = new QLineEdit(oknosiec);
        txt_ip4->setObjectName("txt_ip4");
        txt_ip4->setGeometry(QRect(240, 60, 51, 24));
        txt_ip4->setMaxLength(3);
        txt_port = new QLineEdit(oknosiec);
        txt_port->setObjectName("txt_port");
        txt_port->setGeometry(QRect(70, 110, 51, 24));
        txt_port->setMaxLength(5);
        lbl_tryb = new QLabel(oknosiec);
        lbl_tryb->setObjectName("lbl_tryb");
        lbl_tryb->setGeometry(QRect(350, 20, 49, 16));
        lbl_message = new QLabel(oknosiec);
        lbl_message->setObjectName("lbl_message");
        lbl_message->setGeometry(QRect(30, 190, 341, 16));

        retranslateUi(oknosiec);

        QMetaObject::connectSlotsByName(oknosiec);
    } // setupUi

    void retranslateUi(QDialog *oknosiec)
    {
        oknosiec->setWindowTitle(QCoreApplication::translate("oknosiec", "Dialog", nullptr));
        lbl_IP->setText(QCoreApplication::translate("oknosiec", "IP", nullptr));
        lbl_Port->setText(QCoreApplication::translate("oknosiec", "Port", nullptr));
        comboBox->setItemText(0, QCoreApplication::translate("oknosiec", "Serwer", nullptr));
        comboBox->setItemText(1, QCoreApplication::translate("oknosiec", "Client", nullptr));

        btn_start_connect->setText(QCoreApplication::translate("oknosiec", "Start", nullptr));
        btn_stop_disconnect->setText(QCoreApplication::translate("oknosiec", "Stop", nullptr));
        lbl_tryb->setText(QCoreApplication::translate("oknosiec", "Online", nullptr));
        lbl_message->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class oknosiec: public Ui_oknosiec {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOSIEC_H
