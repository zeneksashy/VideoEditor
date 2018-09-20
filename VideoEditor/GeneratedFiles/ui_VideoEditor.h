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
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
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
    QAction *actionNew;
    QAction *actionExport;
    QAction *actionInport;
    QAction *actiongausian_blur;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QWidget *widget;
    PreviewPlayer *preview;
    QSpacerItem *verticalSpacer;
    QHBoxLayout *horizontalLayout;
    TimeLine *timeLine;
    QFrame *frame;
    QMenuBar *menuBar;
    QMenu *menuFIle;
    QMenu *menuEdit;
    QMenu *menuEffects;
    QMenu *menublur;

    void setupUi(QMainWindow *VideoEditorClass)
    {
        if (VideoEditorClass->objectName().isEmpty())
            VideoEditorClass->setObjectName(QStringLiteral("VideoEditorClass"));
        VideoEditorClass->resize(1639, 1034);
        VideoEditorClass->setMinimumSize(QSize(1200, 800));
        VideoEditorClass->setStyleSheet(QLatin1String("QMainWindow\n"
"{\n"
"background-color:rgb(45, 45, 48)\n"
"}"));
        actionOpen = new QAction(VideoEditorClass);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        actionNew = new QAction(VideoEditorClass);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        actionExport = new QAction(VideoEditorClass);
        actionExport->setObjectName(QStringLiteral("actionExport"));
        actionInport = new QAction(VideoEditorClass);
        actionInport->setObjectName(QStringLiteral("actionInport"));
        actiongausian_blur = new QAction(VideoEditorClass);
        actiongausian_blur->setObjectName(QStringLiteral("actiongausian_blur"));
        centralWidget = new QWidget(VideoEditorClass);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setStyleSheet(QStringLiteral(""));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        verticalLayout->setContentsMargins(-1, -1, -1, 1);
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        QSizePolicy sizePolicy(QSizePolicy::MinimumExpanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(widget->sizePolicy().hasHeightForWidth());
        widget->setSizePolicy(sizePolicy);
        widget->setMinimumSize(QSize(500, 15));
        widget->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:\"white\";\n"
"}"));

        horizontalLayout_2->addWidget(widget);

        preview = new PreviewPlayer(centralWidget);
        preview->setObjectName(QStringLiteral("preview"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(preview->sizePolicy().hasHeightForWidth());
        preview->setSizePolicy(sizePolicy1);
        preview->setMinimumSize(QSize(700, 400));
        preview->setLayoutDirection(Qt::LeftToRight);
        preview->setStyleSheet(QLatin1String("PreviewPlayer\n"
"{\n"
"border-style: outset;\n"
"    border-width: 2px;\n"
"border-color:rgb(104, 104, 104)\n"
"}"));

        horizontalLayout_2->addWidget(preview);


        verticalLayout->addLayout(horizontalLayout_2);

        verticalSpacer = new QSpacerItem(5, 25, QSizePolicy::Minimum, QSizePolicy::Maximum);

        verticalLayout->addItem(verticalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        timeLine = new TimeLine(centralWidget);
        timeLine->setObjectName(QStringLiteral("timeLine"));
        sizePolicy1.setHeightForWidth(timeLine->sizePolicy().hasHeightForWidth());
        timeLine->setSizePolicy(sizePolicy1);
        timeLine->setMinimumSize(QSize(1800, 350));
        timeLine->setBaseSize(QSize(1800, 350));
        timeLine->setStyleSheet(QStringLiteral(""));

        horizontalLayout->addWidget(timeLine, 0, Qt::AlignLeft|Qt::AlignBottom);

        frame = new QFrame(centralWidget);
        frame->setObjectName(QStringLiteral("frame"));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);

        VideoEditorClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(VideoEditorClass);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1639, 21));
        menuFIle = new QMenu(menuBar);
        menuFIle->setObjectName(QStringLiteral("menuFIle"));
        menuEdit = new QMenu(menuBar);
        menuEdit->setObjectName(QStringLiteral("menuEdit"));
        menuEffects = new QMenu(menuBar);
        menuEffects->setObjectName(QStringLiteral("menuEffects"));
        menublur = new QMenu(menuEffects);
        menublur->setObjectName(QStringLiteral("menublur"));
        VideoEditorClass->setMenuBar(menuBar);

        menuBar->addAction(menuFIle->menuAction());
        menuBar->addAction(menuEdit->menuAction());
        menuBar->addAction(menuEffects->menuAction());
        menuFIle->addAction(actionNew);
        menuFIle->addAction(actionOpen);
        menuFIle->addAction(actionExport);
        menuFIle->addAction(actionInport);
        menuEffects->addAction(menublur->menuAction());
        menublur->addAction(actiongausian_blur);

        retranslateUi(VideoEditorClass);
        QObject::connect(actionOpen, SIGNAL(triggered()), VideoEditorClass, SLOT(open()));

        QMetaObject::connectSlotsByName(VideoEditorClass);
    } // setupUi

    void retranslateUi(QMainWindow *VideoEditorClass)
    {
        VideoEditorClass->setWindowTitle(QApplication::translate("VideoEditorClass", "VideoEditor", nullptr));
        actionOpen->setText(QApplication::translate("VideoEditorClass", "Open", nullptr));
        actionNew->setText(QApplication::translate("VideoEditorClass", "New", nullptr));
        actionExport->setText(QApplication::translate("VideoEditorClass", "Export", nullptr));
        actionInport->setText(QApplication::translate("VideoEditorClass", "Inport", nullptr));
        actiongausian_blur->setText(QApplication::translate("VideoEditorClass", "gausian blur", nullptr));
        menuFIle->setTitle(QApplication::translate("VideoEditorClass", "FIle", nullptr));
        menuEdit->setTitle(QApplication::translate("VideoEditorClass", "Edit", nullptr));
        menuEffects->setTitle(QApplication::translate("VideoEditorClass", "Effects", nullptr));
        menublur->setTitle(QApplication::translate("VideoEditorClass", "blur", nullptr));
    } // retranslateUi

};

namespace Ui {
    class VideoEditorClass: public Ui_VideoEditorClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIDEOEDITOR_H
