/********************************************************************************
** Form generated from reading UI file 'testconnectionmainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TESTCONNECTIONMAINWINDOW_H
#define UI_TESTCONNECTIONMAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TestConnectionMainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QSpacerItem *horizontalSpacer;
    QGridLayout *gridLayout_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_login;
    QLineEdit *lineEdit_password;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QComboBox *comboBox;
    QSpacerItem *horizontalSpacer_2;
    QSpacerItem *verticalSpacer;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menubar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *TestConnectionMainWindow)
    {
        if (TestConnectionMainWindow->objectName().isEmpty())
            TestConnectionMainWindow->setObjectName(QString::fromUtf8("TestConnectionMainWindow"));
        TestConnectionMainWindow->setEnabled(true);
        TestConnectionMainWindow->resize(308, 293);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TestConnectionMainWindow->sizePolicy().hasHeightForWidth());
        TestConnectionMainWindow->setSizePolicy(sizePolicy);
        TestConnectionMainWindow->setMinimumSize(QSize(0, 0));
        TestConnectionMainWindow->setToolButtonStyle(Qt::ToolButtonIconOnly);
        TestConnectionMainWindow->setDocumentMode(false);
        TestConnectionMainWindow->setDockOptions(QMainWindow::AllowTabbedDocks|QMainWindow::AnimatedDocks);
        centralwidget = new QWidget(TestConnectionMainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer, 1, 0, 1, 1);

        gridLayout_2 = new QGridLayout();
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setEnabled(false);

        gridLayout_2->addWidget(pushButton, 4, 0, 1, 1);

        lineEdit_login = new QLineEdit(centralwidget);
        lineEdit_login->setObjectName(QString::fromUtf8("lineEdit_login"));

        gridLayout_2->addWidget(lineEdit_login, 2, 0, 1, 1);

        lineEdit_password = new QLineEdit(centralwidget);
        lineEdit_password->setObjectName(QString::fromUtf8("lineEdit_password"));
        lineEdit_password->setEchoMode(QLineEdit::Password);

        gridLayout_2->addWidget(lineEdit_password, 3, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFrameShadow(QFrame::Plain);
        label->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        label->setOpenExternalLinks(true);

        horizontalLayout_4->addWidget(label);

        comboBox = new QComboBox(centralwidget);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));

        horizontalLayout_4->addWidget(comboBox);


        gridLayout_2->addLayout(horizontalLayout_4, 1, 0, 1, 1);


        gridLayout->addLayout(gridLayout_2, 1, 1, 1, 1);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        gridLayout->addItem(horizontalSpacer_2, 1, 2, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 0, 1, 1, 1);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer_2, 2, 1, 1, 1);

        TestConnectionMainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(TestConnectionMainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 308, 22));
        TestConnectionMainWindow->setMenuBar(menubar);
        statusBar = new QStatusBar(TestConnectionMainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        TestConnectionMainWindow->setStatusBar(statusBar);

        retranslateUi(TestConnectionMainWindow);

        QMetaObject::connectSlotsByName(TestConnectionMainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *TestConnectionMainWindow)
    {
        TestConnectionMainWindow->setWindowTitle(QApplication::translate("TestConnectionMainWindow", "Connection", nullptr));
        pushButton->setText(QApplication::translate("TestConnectionMainWindow", "Login", nullptr));
#ifndef QT_NO_STATUSTIP
        lineEdit_login->setStatusTip(QApplication::translate("TestConnectionMainWindow", "Enter Login", nullptr));
#endif // QT_NO_STATUSTIP
        lineEdit_login->setPlaceholderText(QApplication::translate("TestConnectionMainWindow", "Login", nullptr));
#ifndef QT_NO_STATUSTIP
        lineEdit_password->setStatusTip(QApplication::translate("TestConnectionMainWindow", "Enter Password", nullptr));
#endif // QT_NO_STATUSTIP
        lineEdit_password->setPlaceholderText(QApplication::translate("TestConnectionMainWindow", "Password", nullptr));
        label->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class TestConnectionMainWindow: public Ui_TestConnectionMainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TESTCONNECTIONMAINWINDOW_H
