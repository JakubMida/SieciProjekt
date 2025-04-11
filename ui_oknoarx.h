/********************************************************************************
** Form generated from reading UI file 'oknoarx.ui'
**
** Created by: Qt User Interface Compiler version 6.7.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OKNOARX_H
#define UI_OKNOARX_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_OknoARX
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout_9;
    QSpinBox *delaySpinBox_2;
    QLabel *label_16;
    QDoubleSpinBox *vectorbbSpinBox_2;
    QDoubleSpinBox *vectoraaSpinBox_2;
    QLabel *label_12;
    QDoubleSpinBox *vectoraaa_2;
    QDoubleSpinBox *zaklocenieSpinBox_2;
    QDoubleSpinBox *vectoraSpinBox_2;
    QDoubleSpinBox *vectorbbb_2;
    QDoubleSpinBox *vectorbSpinBox_2;
    QLabel *label_11;
    QLabel *label_13;
    QHBoxLayout *horizontalLayout;
    QPushButton *btnOK;
    QPushButton *btnAnuluj;

    void setupUi(QDialog *OknoARX)
    {
        if (OknoARX->objectName().isEmpty())
            OknoARX->setObjectName("OknoARX");
        OknoARX->resize(296, 197);
        gridLayout = new QGridLayout(OknoARX);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        gridLayout_9 = new QGridLayout();
        gridLayout_9->setObjectName("gridLayout_9");
        gridLayout_9->setHorizontalSpacing(0);
        delaySpinBox_2 = new QSpinBox(OknoARX);
        delaySpinBox_2->setObjectName("delaySpinBox_2");
        delaySpinBox_2->setAlignment(Qt::AlignCenter);
        delaySpinBox_2->setMinimum(1);

        gridLayout_9->addWidget(delaySpinBox_2, 1, 1, 1, 1);

        label_16 = new QLabel(OknoARX);
        label_16->setObjectName("label_16");

        gridLayout_9->addWidget(label_16, 11, 0, 1, 1);

        vectorbbSpinBox_2 = new QDoubleSpinBox(OknoARX);
        vectorbbSpinBox_2->setObjectName("vectorbbSpinBox_2");
        vectorbbSpinBox_2->setMinimum(-1.000000000000000);
        vectorbbSpinBox_2->setMaximum(1.000000000000000);
        vectorbbSpinBox_2->setSingleStep(0.010000000000000);

        gridLayout_9->addWidget(vectorbbSpinBox_2, 10, 2, 1, 1);

        vectoraaSpinBox_2 = new QDoubleSpinBox(OknoARX);
        vectoraaSpinBox_2->setObjectName("vectoraaSpinBox_2");
        vectoraaSpinBox_2->setMinimum(-1.000000000000000);
        vectoraaSpinBox_2->setMaximum(1.000000000000000);
        vectoraaSpinBox_2->setSingleStep(0.010000000000000);

        gridLayout_9->addWidget(vectoraaSpinBox_2, 2, 2, 1, 1);

        label_12 = new QLabel(OknoARX);
        label_12->setObjectName("label_12");
        label_12->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_12, 10, 0, 1, 1);

        vectoraaa_2 = new QDoubleSpinBox(OknoARX);
        vectoraaa_2->setObjectName("vectoraaa_2");
        vectoraaa_2->setMinimum(-1.000000000000000);
        vectoraaa_2->setMaximum(1.000000000000000);
        vectoraaa_2->setSingleStep(0.010000000000000);

        gridLayout_9->addWidget(vectoraaa_2, 2, 3, 1, 1);

        zaklocenieSpinBox_2 = new QDoubleSpinBox(OknoARX);
        zaklocenieSpinBox_2->setObjectName("zaklocenieSpinBox_2");
        zaklocenieSpinBox_2->setSingleStep(0.010000000000000);

        gridLayout_9->addWidget(zaklocenieSpinBox_2, 11, 1, 1, 1);

        vectoraSpinBox_2 = new QDoubleSpinBox(OknoARX);
        vectoraSpinBox_2->setObjectName("vectoraSpinBox_2");
        vectoraSpinBox_2->setDecimals(2);
        vectoraSpinBox_2->setMinimum(-1.000000000000000);
        vectoraSpinBox_2->setMaximum(1.000000000000000);
        vectoraSpinBox_2->setSingleStep(0.010000000000000);
        vectoraSpinBox_2->setValue(-0.400000000000000);

        gridLayout_9->addWidget(vectoraSpinBox_2, 2, 1, 1, 1);

        vectorbbb_2 = new QDoubleSpinBox(OknoARX);
        vectorbbb_2->setObjectName("vectorbbb_2");
        vectorbbb_2->setMinimum(-1.000000000000000);
        vectorbbb_2->setMaximum(1.000000000000000);
        vectorbbb_2->setSingleStep(0.010000000000000);

        gridLayout_9->addWidget(vectorbbb_2, 10, 3, 1, 1);

        vectorbSpinBox_2 = new QDoubleSpinBox(OknoARX);
        vectorbSpinBox_2->setObjectName("vectorbSpinBox_2");
        vectorbSpinBox_2->setMinimum(-1.000000000000000);
        vectorbSpinBox_2->setMaximum(1.000000000000000);
        vectorbSpinBox_2->setSingleStep(0.010000000000000);
        vectorbSpinBox_2->setValue(0.600000000000000);

        gridLayout_9->addWidget(vectorbSpinBox_2, 10, 1, 1, 1);

        label_11 = new QLabel(OknoARX);
        label_11->setObjectName("label_11");
        label_11->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_11, 1, 0, 1, 1);

        label_13 = new QLabel(OknoARX);
        label_13->setObjectName("label_13");
        label_13->setAlignment(Qt::AlignCenter);

        gridLayout_9->addWidget(label_13, 2, 0, 1, 1);


        verticalLayout->addLayout(gridLayout_9);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        btnOK = new QPushButton(OknoARX);
        btnOK->setObjectName("btnOK");

        horizontalLayout->addWidget(btnOK);

        btnAnuluj = new QPushButton(OknoARX);
        btnAnuluj->setObjectName("btnAnuluj");

        horizontalLayout->addWidget(btnAnuluj);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(OknoARX);

        QMetaObject::connectSlotsByName(OknoARX);
    } // setupUi

    void retranslateUi(QDialog *OknoARX)
    {
        OknoARX->setWindowTitle(QCoreApplication::translate("OknoARX", "Model ARX", nullptr));
        label_16->setText(QCoreApplication::translate("OknoARX", "Zak\305\202\303\263cenie", nullptr));
        label_12->setText(QCoreApplication::translate("OknoARX", "Vector B", nullptr));
        label_11->setText(QCoreApplication::translate("OknoARX", "Op\303\263\305\272nienie", nullptr));
        label_13->setText(QCoreApplication::translate("OknoARX", "Vector A", nullptr));
        btnOK->setText(QCoreApplication::translate("OknoARX", "OK", nullptr));
        btnAnuluj->setText(QCoreApplication::translate("OknoARX", "Anuluj", nullptr));
    } // retranslateUi

};

namespace Ui {
    class OknoARX: public Ui_OknoARX {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OKNOARX_H
