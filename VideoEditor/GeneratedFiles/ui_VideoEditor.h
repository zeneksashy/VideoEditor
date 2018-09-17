/********************************************************************************
** Form generated from reading UI file 'VideoEditor.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIDEOEDITOR_H
#define UI_VIDEOEDITOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "previewplayer.h"
#include "timeline.h"

QT_BEGIN_NAMESPACE

class Ui_VideoEditorClass
{
public:
    QAction *actionOpen;
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    PreviewPlayer *preview;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    TimeLine *timeLine;
    QMenuBar *menuBar;
    QMenu *menuFIle;

    void setupUi(QMainWindow *VideoEditorClass)
    {
        if (VideoEditorClass->objectName().isEmpty())
            VideoEditorClass->setObjectName(QStringLiteral("VideoEditorClass"));
        VideoEditorClass->resize(1639, 942);
        VideoEditorClass->setMinimumSize(QSize(1200, 800));
        VideoEditorClass->setStyleSheet(QLatin1String("QMainWindow\n"
"{\n"
"background-color:rgb(45, 45, 48)\n"
"}"));
        actionOpen = new QAction(VideoEditorClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        centralWidget = new QWidget(VideoEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(3, 0, 1631, 991));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(1);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(0, 0, 0, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        widget = new QWidget(verticalLayoutWidget);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:\"white\";\n"
"}"));

        horizontalLayout_2->addWidget(widget);

        preview = new PreviewPlayer(verticalLayoutWidget);
        preview->setObjectName(QStringLiteral("preview"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(preview->sizePolicy().hasHeightForWidth());
        preview->setSizePolicy(sizePolicy);
        preview->setMinimumSize(QSize(700, 500));
        preview->setLayoutDirection(Qt::LeftToRight);
        preview->setStyleSheet(QLatin1String("PreviewPlayer\n"
"{\n"
"border-style: outset;\n"
"    border-width: 2px;\n"
"border-color:rgb(104, 104, 104)\n"
"}"));

        horizontalLayout_2->addWidget(preview);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(5, 40, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        timeLine = new TimeLine(verticalLayoutWidget);
        timeLine->setObjectName(QStringLiteral("timeLine"));
        sizePolicy.setHeightForWidth(timeLine->sizePolicy().hasHeightForWidth());
        timeLine->setSizePolicy(sizePolicy);
        timeLine->setMinimumSize(QSize(1400, 400));
        timeLine->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(timeLine, 0, Qt::AlignLeft|Qt::AlignBottom);


        verticalLayout->addLayout(horizontalLayout);

        VideoEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VideoEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1639, 21));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QStringLiteral("menuFIle"));
        VideoEditorClass->setMenuBar(menuBar);

        menuBar->addAction(menuFIle->menuAction());
        menuFIle->addAction(actionOpen);

        retranslateUi(VideoEditorClass);
        QObject::connect(actionOpen, SIGNAL(triggered()), VideoEditorClass, SLOT(open()));

        QMetaObject::connectSlotsByName(VideoEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *VideoEditorClass)
    {
        VideoEditorClass->setWindowTitle(QApplication::translate("VideoEditorClass", "VideoEditor", nullptr));
        actionOpen->setText(QApplication::translate("VideoEditorClass", "Open", nullptr));
        menuFIle->setTitle(QApplication::translate("VideoEditorClass", "FIle", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoEditorClass: public Ui_VideoEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOEDITOR_H
