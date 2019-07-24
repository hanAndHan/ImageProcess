/********************************************************************************
** Form generated from reading UI file 'imageprocess.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_IMAGEPROCESS_H
#define UI_IMAGEPROCESS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_imageprocessClass
{
public:
    QAction *actionOpen;
    QAction *actionErode;
    QAction *actionDilate;
    QAction *actionCanny;
    QAction *actionSobel;
    QAction *actionLaplacian;
    QAction *actionR;
    QAction *actionG;
    QAction *actionB;
    QAction *actionGry;
    QAction *actionBox;
    QAction *actionMeans;
    QAction *actionGuass;
    QAction *actionMidvalue;
    QAction *actionDoubledge;
    QAction *actionReset;
    QAction *actionFacedetect;
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QScrollArea *scrollArea;
    QWidget *scrollAreaWidgetContents;
    QGroupBox *groupBox_2;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents_2;
    QGroupBox *groupBox_3;
    QLabel *label;
    QMenuBar *menuBar;
    QMenu *menu;
    QMenu *menu_2;
    QMenu *menu_edge;
    QMenu *menu_histogram;
    QMenu *menu_3;
    QMenu *menu_line;
    QMenu *menu_nonline;
    QMenu *menu_4;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *imageprocessClass)
    {
        if (imageprocessClass->objectName().isEmpty())
            imageprocessClass->setObjectName(QStringLiteral("imageprocessClass"));
        imageprocessClass->resize(815, 624);
        actionOpen = new QAction(imageprocessClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionErode = new QAction(imageprocessClass);
        actionErode->setObjectName(QStringLiteral("actionErode"));
        actionErode->setEnabled(false);
        actionDilate = new QAction(imageprocessClass);
        actionDilate->setObjectName(QStringLiteral("actionDilate"));
        actionDilate->setEnabled(false);
        actionCanny = new QAction(imageprocessClass);
        actionCanny->setObjectName(QStringLiteral("actionCanny"));
        actionSobel = new QAction(imageprocessClass);
        actionSobel->setObjectName(QStringLiteral("actionSobel"));
        actionLaplacian = new QAction(imageprocessClass);
        actionLaplacian->setObjectName(QStringLiteral("actionLaplacian"));
        actionR = new QAction(imageprocessClass);
        actionR->setObjectName(QStringLiteral("actionR"));
        actionG = new QAction(imageprocessClass);
        actionG->setObjectName(QStringLiteral("actionG"));
        actionB = new QAction(imageprocessClass);
        actionB->setObjectName(QStringLiteral("actionB"));
        actionGry = new QAction(imageprocessClass);
        actionGry->setObjectName(QStringLiteral("actionGry"));
        actionBox = new QAction(imageprocessClass);
        actionBox->setObjectName(QStringLiteral("actionBox"));
        actionMeans = new QAction(imageprocessClass);
        actionMeans->setObjectName(QStringLiteral("actionMeans"));
        actionGuass = new QAction(imageprocessClass);
        actionGuass->setObjectName(QStringLiteral("actionGuass"));
        actionMidvalue = new QAction(imageprocessClass);
        actionMidvalue->setObjectName(QStringLiteral("actionMidvalue"));
        actionDoubledge = new QAction(imageprocessClass);
        actionDoubledge->setObjectName(QStringLiteral("actionDoubledge"));
        actionReset = new QAction(imageprocessClass);
        actionReset->setObjectName(QStringLiteral("actionReset"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/imageprocess/Resources/reset (2).png"), QSize(), QIcon::Normal, QIcon::Off);
        actionReset->setIcon(icon);
        actionFacedetect = new QAction(imageprocessClass);
        actionFacedetect->setObjectName(QStringLiteral("actionFacedetect"));
        actionFacedetect->setEnabled(false);
        centralWidget = new QWidget(imageprocessClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(0, 10, 391, 351));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        scrollArea = new QScrollArea(groupBox);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        scrollArea->setWidgetResizable(true);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 369, 317));
        scrollArea->setWidget(scrollAreaWidgetContents);

        horizontalLayout->addWidget(scrollArea);

        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(400, 10, 391, 351));
        scrollArea_2 = new QScrollArea(groupBox_2);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        scrollArea_2->setGeometry(QRect(10, 20, 371, 319));
        scrollArea_2->setWidgetResizable(true);
        scrollAreaWidgetContents_2 = new QWidget();
        scrollAreaWidgetContents_2->setObjectName(QStringLiteral("scrollAreaWidgetContents_2"));
        scrollAreaWidgetContents_2->setGeometry(QRect(0, 0, 369, 317));
        scrollArea_2->setWidget(scrollAreaWidgetContents_2);
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(290, 390, 211, 111));
        label = new QLabel(groupBox_3);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(80, 10, 71, 91));
        imageprocessClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(imageprocessClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 815, 23));
        menu = new QMenu(menuBar);
        menu->setObjectName(QStringLiteral("menu"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        menu_edge = new QMenu(menu_2);
        menu_edge->setObjectName(QStringLiteral("menu_edge"));
        menu_edge->setEnabled(false);
        menu_histogram = new QMenu(menu_2);
        menu_histogram->setObjectName(QStringLiteral("menu_histogram"));
        menu_histogram->setEnabled(false);
        menu_3 = new QMenu(menuBar);
        menu_3->setObjectName(QStringLiteral("menu_3"));
        menu_line = new QMenu(menu_3);
        menu_line->setObjectName(QStringLiteral("menu_line"));
        menu_line->setEnabled(false);
        menu_nonline = new QMenu(menu_3);
        menu_nonline->setObjectName(QStringLiteral("menu_nonline"));
        menu_nonline->setEnabled(false);
        menu_4 = new QMenu(menuBar);
        menu_4->setObjectName(QStringLiteral("menu_4"));
        imageprocessClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(imageprocessClass);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        mainToolBar->setEnabled(false);
        imageprocessClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(imageprocessClass);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        imageprocessClass->setStatusBar(statusBar);

        menuBar->addAction(menu->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_3->menuAction());
        menuBar->addAction(menu_4->menuAction());
        menu->addAction(actionOpen);
        menu->addSeparator();
        menu_2->addAction(menu_edge->menuAction());
        menu_2->addSeparator();
        menu_2->addAction(actionErode);
        menu_2->addAction(actionDilate);
        menu_2->addSeparator();
        menu_2->addAction(menu_histogram->menuAction());
        menu_2->addSeparator();
        menu_edge->addAction(actionCanny);
        menu_edge->addAction(actionSobel);
        menu_edge->addAction(actionLaplacian);
        menu_histogram->addAction(actionR);
        menu_histogram->addAction(actionG);
        menu_histogram->addAction(actionB);
        menu_histogram->addAction(actionGry);
        menu_3->addAction(menu_line->menuAction());
        menu_3->addAction(menu_nonline->menuAction());
        menu_line->addAction(actionBox);
        menu_line->addAction(actionMeans);
        menu_line->addAction(actionGuass);
        menu_nonline->addSeparator();
        menu_nonline->addAction(actionMidvalue);
        menu_nonline->addAction(actionDoubledge);
        menu_4->addAction(actionFacedetect);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionReset);
        mainToolBar->addSeparator();

        retranslateUi(imageprocessClass);

        QMetaObject::connectSlotsByName(imageprocessClass);
    } // setupUi

    void retranslateUi(QMainWindow *imageprocessClass)
    {
        imageprocessClass->setWindowTitle(QApplication::translate("imageprocessClass", "imageprocess", 0));
        actionOpen->setText(QApplication::translate("imageprocessClass", "\346\211\223\345\274\200", 0));
        actionErode->setText(QApplication::translate("imageprocessClass", "\350\205\220\350\232\200", 0));
        actionDilate->setText(QApplication::translate("imageprocessClass", "\350\206\250\350\203\200", 0));
        actionCanny->setText(QApplication::translate("imageprocessClass", "Canny", 0));
        actionSobel->setText(QApplication::translate("imageprocessClass", "Sobel", 0));
        actionLaplacian->setText(QApplication::translate("imageprocessClass", "Laplacian", 0));
        actionR->setText(QApplication::translate("imageprocessClass", "R\351\200\232\351\201\223", 0));
        actionG->setText(QApplication::translate("imageprocessClass", "G\351\200\232\351\201\223", 0));
        actionB->setText(QApplication::translate("imageprocessClass", "B\351\200\232\351\201\223", 0));
        actionGry->setText(QApplication::translate("imageprocessClass", "\347\201\260\345\272\246\347\233\264\346\226\271\345\233\276", 0));
        actionBox->setText(QApplication::translate("imageprocessClass", "\346\226\271\346\241\206\346\273\244\346\263\242", 0));
        actionMeans->setText(QApplication::translate("imageprocessClass", "\345\235\207\345\200\274\346\273\244\346\263\242", 0));
        actionGuass->setText(QApplication::translate("imageprocessClass", "\351\253\230\346\226\257\346\273\244\346\263\242", 0));
        actionMidvalue->setText(QApplication::translate("imageprocessClass", "\344\270\255\345\200\274\346\273\244\346\263\242", 0));
        actionDoubledge->setText(QApplication::translate("imageprocessClass", "\345\217\214\350\276\271\346\273\244\346\263\242", 0));
        actionReset->setText(QApplication::translate("imageprocessClass", "\351\207\215\347\275\256", 0));
        actionFacedetect->setText(QApplication::translate("imageprocessClass", "\344\272\272\350\204\270\346\243\200\346\265\213", 0));
        groupBox->setTitle(QApplication::translate("imageprocessClass", "\350\275\275\345\205\245\345\233\276\345\203\217", 0));
        groupBox_2->setTitle(QApplication::translate("imageprocessClass", "\345\244\204\347\220\206\346\230\276\347\244\272", 0));
        groupBox_3->setTitle(QApplication::translate("imageprocessClass", "GroupBox", 0));
        label->setText(QApplication::translate("imageprocessClass", "TextLabel", 0));
        menu->setTitle(QApplication::translate("imageprocessClass", "\346\226\207\344\273\266", 0));
        menu_2->setTitle(QApplication::translate("imageprocessClass", "\345\233\276\345\203\217\345\244\204\347\220\206", 0));
        menu_edge->setTitle(QApplication::translate("imageprocessClass", "\350\276\271\347\274\230\346\243\200\346\265\213", 0));
        menu_histogram->setTitle(QApplication::translate("imageprocessClass", "\347\233\264\346\226\271\345\233\276", 0));
        menu_3->setTitle(QApplication::translate("imageprocessClass", "\346\273\244\346\263\242", 0));
        menu_line->setTitle(QApplication::translate("imageprocessClass", "\347\272\277\346\200\247\346\273\244\346\263\242", 0));
        menu_nonline->setTitle(QApplication::translate("imageprocessClass", "\351\235\236\347\272\277\346\200\247\346\273\244\346\263\242", 0));
        menu_4->setTitle(QApplication::translate("imageprocessClass", "\344\272\272\350\204\270\346\243\200\346\265\213", 0));
    } // retranslateUi

};

namespace Ui {
    class imageprocessClass: public Ui_imageprocessClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_IMAGEPROCESS_H
