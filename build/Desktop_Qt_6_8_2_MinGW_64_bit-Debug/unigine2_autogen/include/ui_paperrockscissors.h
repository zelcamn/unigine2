/********************************************************************************
** Form generated from reading UI file 'paperrockscissors.ui'
**
** Created by: Qt User Interface Compiler version 6.8.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PAPERROCKSCISSORS_H
#define UI_PAPERROCKSCISSORS_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PaperRockScissors
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QPushButton *ReadyBtn;
    QLabel *WinLoseLbl;
    QHBoxLayout *horizontalLayout;
    QPushButton *RockBtn;
    QPushButton *ScissorsBtn;
    QPushButton *PaperBtn;
    QVBoxLayout *verticalLayout_3;
    QLabel *ConnectionLbl;
    QFormLayout *formLayout;
    QLabel *label_3;
    QLabel *label_2;
    QLabel *label;
    QLineEdit *PeerIPLblEdit;
    QSpinBox *LocalPortSpinBox;
    QSpinBox *PeerPortSpinBox;
    QPushButton *ConnectBtn;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *PaperRockScissors)
    {
        if (PaperRockScissors->objectName().isEmpty())
            PaperRockScissors->setObjectName("PaperRockScissors");
        PaperRockScissors->resize(359, 378);
        centralwidget = new QWidget(PaperRockScissors);
        centralwidget->setObjectName("centralwidget");
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName("gridLayout");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        ReadyBtn = new QPushButton(centralwidget);
        ReadyBtn->setObjectName("ReadyBtn");

        horizontalLayout_3->addWidget(ReadyBtn);

        WinLoseLbl = new QLabel(centralwidget);
        WinLoseLbl->setObjectName("WinLoseLbl");

        horizontalLayout_3->addWidget(WinLoseLbl);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setSizeConstraint(QLayout::SizeConstraint::SetMaximumSize);
        RockBtn = new QPushButton(centralwidget);
        RockBtn->setObjectName("RockBtn");
        QSizePolicy sizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Expanding);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(RockBtn->sizePolicy().hasHeightForWidth());
        RockBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(RockBtn);

        ScissorsBtn = new QPushButton(centralwidget);
        ScissorsBtn->setObjectName("ScissorsBtn");
        sizePolicy.setHeightForWidth(ScissorsBtn->sizePolicy().hasHeightForWidth());
        ScissorsBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(ScissorsBtn);

        PaperBtn = new QPushButton(centralwidget);
        PaperBtn->setObjectName("PaperBtn");
        sizePolicy.setHeightForWidth(PaperBtn->sizePolicy().hasHeightForWidth());
        PaperBtn->setSizePolicy(sizePolicy);

        horizontalLayout->addWidget(PaperBtn);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        ConnectionLbl = new QLabel(centralwidget);
        ConnectionLbl->setObjectName("ConnectionLbl");

        verticalLayout_3->addWidget(ConnectionLbl);

        formLayout = new QFormLayout();
        formLayout->setObjectName("formLayout");
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");

        formLayout->setWidget(1, QFormLayout::LabelRole, label_3);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");

        formLayout->setWidget(2, QFormLayout::LabelRole, label_2);

        label = new QLabel(centralwidget);
        label->setObjectName("label");

        formLayout->setWidget(3, QFormLayout::LabelRole, label);

        PeerIPLblEdit = new QLineEdit(centralwidget);
        PeerIPLblEdit->setObjectName("PeerIPLblEdit");

        formLayout->setWidget(3, QFormLayout::FieldRole, PeerIPLblEdit);

        LocalPortSpinBox = new QSpinBox(centralwidget);
        LocalPortSpinBox->setObjectName("LocalPortSpinBox");

        formLayout->setWidget(1, QFormLayout::FieldRole, LocalPortSpinBox);

        PeerPortSpinBox = new QSpinBox(centralwidget);
        PeerPortSpinBox->setObjectName("PeerPortSpinBox");

        formLayout->setWidget(2, QFormLayout::FieldRole, PeerPortSpinBox);


        verticalLayout_3->addLayout(formLayout);


        verticalLayout->addLayout(verticalLayout_3);

        ConnectBtn = new QPushButton(centralwidget);
        ConnectBtn->setObjectName("ConnectBtn");

        verticalLayout->addWidget(ConnectBtn);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        PaperRockScissors->setCentralWidget(centralwidget);
        menubar = new QMenuBar(PaperRockScissors);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 359, 21));
        PaperRockScissors->setMenuBar(menubar);
        statusbar = new QStatusBar(PaperRockScissors);
        statusbar->setObjectName("statusbar");
        PaperRockScissors->setStatusBar(statusbar);

        retranslateUi(PaperRockScissors);

        QMetaObject::connectSlotsByName(PaperRockScissors);
    } // setupUi

    void retranslateUi(QMainWindow *PaperRockScissors)
    {
        PaperRockScissors->setWindowTitle(QCoreApplication::translate("PaperRockScissors", "PaperRockScissors", nullptr));
        ReadyBtn->setText(QCoreApplication::translate("PaperRockScissors", "ready", nullptr));
        WinLoseLbl->setText(QString());
        RockBtn->setText(QCoreApplication::translate("PaperRockScissors", "Rock", nullptr));
        ScissorsBtn->setText(QCoreApplication::translate("PaperRockScissors", "Scissors", nullptr));
        PaperBtn->setText(QCoreApplication::translate("PaperRockScissors", "Paper", nullptr));
        ConnectionLbl->setText(QCoreApplication::translate("PaperRockScissors", "connection", nullptr));
        label_3->setText(QCoreApplication::translate("PaperRockScissors", "LocalPort", nullptr));
        label_2->setText(QCoreApplication::translate("PaperRockScissors", "PeerPort", nullptr));
        label->setText(QCoreApplication::translate("PaperRockScissors", "PeerIP", nullptr));
        ConnectBtn->setText(QCoreApplication::translate("PaperRockScissors", "connect", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PaperRockScissors: public Ui_PaperRockScissors {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PAPERROCKSCISSORS_H
