/********************************************************************************
** Form generated from reading UI file 'TimeLine.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TIMELINE_H
#define UI_TIMELINE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "timelineslider.h"

QT_BEGIN_NAMESPACE

class Ui_TimeLine
{
public:
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *timeLabel;
    QSlider *zoomingSlider;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_4;
    QScrollArea *scrollArea;
    QWidget *Content;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QSpacerItem *horizontalSpacer_2;
    TimeLineSlider *horizontalSlider;
    QScrollArea *scrollArea_2;
    QWidget *scrollAreaWidgetContents;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *timeline;

    void setupUi(QWidget *TimeLine)
    {
        if (TimeLine->objectName().isEmpty())
            TimeLine->setObjectName(QStringLiteral("TimeLine"));
        TimeLine->resize(1500, 500);
        TimeLine->setMinimumSize(QSize(1500, 200));
        TimeLine->setMaximumSize(QSize(4000, 500));
        TimeLine->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background: rgb(36, 36, 36);\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(TimeLine);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(-1, -1, 9, -1);
        timeLabel = new QLabel(TimeLine);
        timeLabel->setObjectName(QStringLiteral("timeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(timeLabel->sizePolicy().hasHeightForWidth());
        timeLabel->setSizePolicy(sizePolicy);
        timeLabel->setMinimumSize(QSize(110, 0));
        QFont font;
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        timeLabel->setFont(font);
        timeLabel->setStyleSheet(QLatin1String("QLabel\n"
"{\n"
"color: white;\n"
"\n"
"}"));

        horizontalLayout_2->addWidget(timeLabel);

        zoomingSlider = new QSlider(TimeLine);
        zoomingSlider->setObjectName(QStringLiteral("zoomingSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Maximum, QSizePolicy::Minimum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(zoomingSlider->sizePolicy().hasHeightForWidth());
        zoomingSlider->setSizePolicy(sizePolicy1);
        zoomingSlider->setMinimumSize(QSize(140, 0));
        zoomingSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"border: 1px solid #bbb;\n"
"background: white;\n"
"height: 12px;\n"
"border-radius: 5px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal {\n"
"\n"
"background: qlineargradient(x1: 0, y1: 0.2, x2: 1, y2: 1,\n"
"    stop: 0 #bbf, stop: 1 #55f);\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal {\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(12, 0, 34, 255), stop:1 rgba(176, 209, 187, 255));\n"
"border: 1px solid #777;\n"
"height: 10px;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal {\n"
"background:qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0.215909 rgba(7, 0, 27, 255), stop:0.994318 rgba(174, 174, 180, 210));\n"
"border: 1px solid #777;\n"
"width: 50px;\n"
"margin-top: -2px;\n"
"margin-bottom: -2px;\n"
"border-radius: 7px;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:hover {\n"
"background: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(0, "
                        "0, 0, 255), stop:1 rgba(90, 181, 237, 255));\n"
"border: 1px solid #444;\n"
"border-radius: 4px;\n"
"}\n"
"\n"
"QSlider::sub-page:horizontal:disabled {\n"
"background: #bbb;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::add-page:horizontal:disabled {\n"
"background: #eee;\n"
"border-color: #999;\n"
"}\n"
"\n"
"QSlider::handle:horizontal:disabled {\n"
"background: #eee;\n"
"border: 1px solid #aaa;\n"
"border-radius: 4px;\n"
"}"));
        zoomingSlider->setMinimum(1);
        zoomingSlider->setMaximum(25);
        zoomingSlider->setSingleStep(1);
        zoomingSlider->setPageStep(1);
        zoomingSlider->setValue(5);
        zoomingSlider->setOrientation(Qt::Horizontal);

        horizontalLayout_2->addWidget(zoomingSlider);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        widget = new QWidget(TimeLine);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_4 = new QVBoxLayout(widget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QStringLiteral("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, -1, -1, -1);
        scrollArea = new QScrollArea(widget);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy2);
        scrollArea->setMinimumSize(QSize(1000, 395));
        scrollArea->setStyleSheet(QLatin1String("QScrollArea\n"
"{\n"
"border: 1px solid black;\n"
"\n"
"}\n"
"\n"
" QScrollBar:horizontal {\n"
"	background:rgb(238, 238, 238);\n"
"    height: 14px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"    background: rgb(58, 64, 85);\n"
"    min-width: 12px;\n"
"	border: 1px solid rgb(29, 0, 58);\n"
"	border-radius:5px;\n"
"	height: 8px;\n"
"}\n"
"QScrollBar::add-page:horizontal, QScrollBar::sub-page:horizontal {\n"
"background: none;\n"
"}\n"
"QScrollBar::right-arrow:horizontal, QScrollBar::left-arrow:horizontal\n"
"{\n"
"background:none;\n"
"color:none;\n"
"}\n"
"QScrollBar::add-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar::sub-line:horizontal {\n"
"      border: none;\n"
"      background: none;\n"
"}\n"
"\n"
"\n"
"\n"
" QScrollBar:vertical {\n"
"	background:rgb(238, 238, 238);\n"
"    width: 10px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: rgb(58, 64, 85);\n"
"    min-heigth: 6px;\n"
"	heigth:10px;\n"
"	max-heigth:15px;\n"
"	border: 1px solid r"
                        "gb(29, 0, 58);\n"
"	border-radius:5px;\n"
"}\n"
"QScrollBar::add-page:vertical, QScrollBar::sub-page:vertical {\n"
"background: none;\n"
"}\n"
"QScrollBar::right-arrow:vertical, QScrollBar::left-arrow:vertical\n"
"{\n"
"background:none;\n"
"color:none;\n"
"}\n"
"QScrollBar::add-line:vertical {\n"
"      border: none;\n"
"      background: none;\n"
"}\n"
"\n"
"QScrollBar::sub-line:vertical {\n"
"      border: none;\n"
"      background: none;\n"
"}"));
        scrollArea->setFrameShape(QFrame::Box);
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setLineWidth(0);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        scrollArea->setAlignment(Qt::AlignCenter);
        Content = new QWidget();
        Content->setObjectName(QStringLiteral("Content"));
        Content->setGeometry(QRect(0, 0, 1469, 393));
        QSizePolicy sizePolicy3(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(Content->sizePolicy().hasHeightForWidth());
        Content->setSizePolicy(sizePolicy3);
        Content->setMinimumSize(QSize(0, 0));
        Content->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:rgb(37,38,36);\n"
"border:0px solid black;\n"
"}"));
        verticalLayout = new QVBoxLayout(Content);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, -1, -1);
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalSpacer_2 = new QSpacerItem(85, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);

        horizontalSlider = new TimeLineSlider(Content);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy4(QSizePolicy::Minimum, QSizePolicy::Maximum);
        sizePolicy4.setHorizontalStretch(0);
        sizePolicy4.setVerticalStretch(0);
        sizePolicy4.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy4);
        horizontalSlider->setMinimumSize(QSize(150, 20));
        horizontalSlider->setAutoFillBackground(false);
        horizontalSlider->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:rgba(255, 255, 255, 0);\n"
"border:0px solid black;\n"
"}\n"
"QSlider::groove:horizontal {\n"
"\n"
"    height: 2px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"background:white;\n"
"\n"
"    margin: 2px 0;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: rgb(255, 170, 0);\n"
"    width:6px;\n"
"	height: 15px;\n"
"	margin: -5px 0 -1px 0;\n"
"}"));
        horizontalSlider->setMaximum(200);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(25);

        horizontalLayout_3->addWidget(horizontalSlider);


        verticalLayout->addLayout(horizontalLayout_3);

        scrollArea_2 = new QScrollArea(Content);
        scrollArea_2->setObjectName(QStringLiteral("scrollArea_2"));
        QSizePolicy sizePolicy5(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy5.setHorizontalStretch(0);
        sizePolicy5.setVerticalStretch(0);
        sizePolicy5.setHeightForWidth(scrollArea_2->sizePolicy().hasHeightForWidth());
        scrollArea_2->setSizePolicy(sizePolicy5);
        scrollArea_2->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
        scrollArea_2->setWidgetResizable(true);
        scrollArea_2->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);
        scrollAreaWidgetContents = new QWidget();
        scrollAreaWidgetContents->setObjectName(QStringLiteral("scrollAreaWidgetContents"));
        scrollAreaWidgetContents->setGeometry(QRect(0, 0, 1460, 349));
        verticalLayout_3 = new QVBoxLayout(scrollAreaWidgetContents);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, -1, -1, -1);
        timeline = new QVBoxLayout();
        timeline->setSpacing(1);
        timeline->setObjectName(QStringLiteral("timeline"));
        timeline->setSizeConstraint(QLayout::SetDefaultConstraint);

        verticalLayout_3->addLayout(timeline);

        scrollArea_2->setWidget(scrollAreaWidgetContents);

        verticalLayout->addWidget(scrollArea_2);

        scrollArea->setWidget(Content);

        verticalLayout_4->addWidget(scrollArea);


        horizontalLayout->addWidget(widget);


        verticalLayout_2->addLayout(horizontalLayout);


        retranslateUi(TimeLine);

        QMetaObject::connectSlotsByName(TimeLine);
    } // setupUi

    void retranslateUi(QWidget *TimeLine)
    {
        TimeLine->setWindowTitle(QApplication::translate("TimeLine", "TimeLine", nullptr));
        timeLabel->setText(QApplication::translate("TimeLine", "Media duration", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeLine: public Ui_TimeLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMELINE_H
