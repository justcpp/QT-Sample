/********************************************************************************
** Form generated from reading UI file 'QtTetris.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QTTETRIS_H
#define UI_QTTETRIS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QtTetrisClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *QtTetrisClass)
    {
        if (QtTetrisClass->objectName().isEmpty())
            QtTetrisClass->setObjectName(QStringLiteral("QtTetrisClass"));
        QtTetrisClass->resize(600, 400);
        menuBar = new QMenuBar(QtTetrisClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        QtTetrisClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(QtTetrisClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        QtTetrisClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(QtTetrisClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        QtTetrisClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(QtTetrisClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        QtTetrisClass->setStatusBar(statusBar);

        retranslateUi(QtTetrisClass);

        QMetaObject::connectSlotsByName(QtTetrisClass);
    } // setupUi

    void retranslateUi(QMainWindow *QtTetrisClass)
    {
        QtTetrisClass->setWindowTitle(QApplication::translate("QtTetrisClass", "QtTetris", 0));
    } // retranslateUi

};

namespace Ui {
    class QtTetrisClass: public Ui_QtTetrisClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QTTETRIS_H
