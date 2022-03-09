/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.8
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *LabelTitulo;
    QLineEdit *campoTexto;
    QPushButton *pushButton;
    QLabel *MensajeRecibido;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(747, 345);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        LabelTitulo = new QLabel(centralwidget);
        LabelTitulo->setObjectName(QString::fromUtf8("LabelTitulo"));
        LabelTitulo->setGeometry(QRect(280, 50, 101, 71));
        campoTexto = new QLineEdit(centralwidget);
        campoTexto->setObjectName(QString::fromUtf8("campoTexto"));
        campoTexto->setGeometry(QRect(90, 130, 491, 31));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(290, 180, 89, 25));
        MensajeRecibido = new QLabel(centralwidget);
        MensajeRecibido->setObjectName(QString::fromUtf8("MensajeRecibido"));
        MensajeRecibido->setGeometry(QRect(90, 210, 511, 71));
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 747, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", nullptr));
        LabelTitulo->setText(QApplication::translate("MainWindow", "Buenas tardes!", nullptr));
        pushButton->setText(QApplication::translate("MainWindow", "Enviar!", nullptr));
        MensajeRecibido->setText(QApplication::translate("MainWindow", "Mensaje recibido", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
