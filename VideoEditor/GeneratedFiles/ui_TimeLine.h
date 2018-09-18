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
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSlider>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeLine
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *timeLabel;
    QSpacerItem *horizontalSpacer;
    QSlider *horizontalSlider;
    QHBoxLayout *horizontalLayout;
    QListWidget *sourcesList;
    QScrollArea *scrollArea;
    QWidget *Content;
    QVBoxLayout *verticalLayout_2;
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
"}\n"
""));
        gridLayout = new QGridLayout(TimeLine);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
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

        horizontalSpacer = new QSpacerItem(140, 20, QSizePolicy::Maximum, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalSlider = new QSlider(TimeLine);
        horizontalSlider->setObjectName(QStringLiteral("horizontalSlider"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(horizontalSlider->sizePolicy().hasHeightForWidth());
        horizontalSlider->setSizePolicy(sizePolicy1);
        horizontalSlider->setStyleSheet(QLatin1String("QSlider::groove:horizontal {\n"
"\n"
"    height: 1px; /* the groove expands to the size of the slider by default. by giving it a height, it has a fixed size */\n"
"    background: qlineargradient(x1:0, y1:0, x2:0, y2:1, stop:0 #B1B1B1, stop:1 #c4c4c4);\n"
"    margin: 2px 0;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"    background: rgb(255, 170, 0);\n"
"    width:2px;\n"
"	height: 15px;\n"
"	border:1px solid red;\n"
"}"));
        horizontalSlider->setMaximum(200);
        horizontalSlider->setOrientation(Qt::Horizontal);
        horizontalSlider->setTickPosition(QSlider::TicksAbove);
        horizontalSlider->setTickInterval(5);

        horizontalLayout_2->addWidget(horizontalSlider);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        sourcesList = new QListWidget(TimeLine);
        sourcesList->setObjectName(QStringLiteral("sourcesList"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Expanding);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(sourcesList->sizePolicy().hasHeightForWidth());
        sourcesList->setSizePolicy(sizePolicy2);
        sourcesList->setStyleSheet(QLatin1String("QListWidget\n"
"{\n"
"background-color: rgb(62, 62, 66)\n"
"}\n"
"QListWidget::item:selected\n"
"{\n"
"    background: rgb(128,128,255);\n"
"}\n"
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
"	border: 1px solid rgb(29, 0, 58);\n"
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
"}\n"
" QScrollBar:horizontal {\n"
"	background:rgb(238, 238, 238);\n"
"    height: 10px;\n"
"}\n"
"QScrollBar::handle:horizontal {\n"
"    background: rgb(58, 64, 85);\n"
"    m"
                        "in-width: 6px;\n"
"	width:10px;\n"
"	max-width:15px;\n"
"	border: 1px solid rgb(29, 0, 58);\n"
"	border-radius:5px;\n"
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
" "));

        horizontalLayout->addWidget(sourcesList);

        scrollArea = new QScrollArea(TimeLine);
        scrollArea->setObjectName(QStringLiteral("scrollArea"));
        QSizePolicy sizePolicy3(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy3);
        scrollArea->setMinimumSize(QSize(1000, 400));
        scrollArea->setStyleSheet(QLatin1String("QScrollArea\n"
"{\n"
"background-color:rgb(37, 37, 38)\n"
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
" QScrollBar:vertical {\n"
"	background:rgb(238, 238, 238);\n"
"    width: 10px;\n"
"}\n"
"QScrollBar::handle:vertical {\n"
"    background: rgb(58, 64, 85);\n"
"    min-heigth: 6px;\n"
"	heigth:10px;\n"
"	max-heigth:15px;\n"
"	border: 1px solid rgb"
                        "(29, 0, 58);\n"
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
        scrollArea->setFrameShadow(QFrame::Sunken);
        scrollArea->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        scrollArea->setSizeAdjustPolicy(QAbstractScrollArea::AdjustToContents);
        scrollArea->setWidgetResizable(true);
        Content = new QWidget();
        Content->setObjectName(QStringLiteral("Content"));
        Content->setGeometry(QRect(0, 0, 1216, 443));
        Content->setMinimumSize(QSize(0, 400));
        Content->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background-color:rgb(37, 37, 38)\n"
"}\n"
"QFrame\n"
"{\n"
"background-color:rgb(134, 95, 197)\n"
"\n"
"}"));
        verticalLayout_2 = new QVBoxLayout(Content);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(5, -1, -1, -1);
        timeline = new QVBoxLayout();
        timeline->setSpacing(11);
        timeline->setObjectName(QStringLiteral("timeline"));
        timeline->setSizeConstraint(QLayout::SetMaximumSize);
        timeline->setContentsMargins(-1, 1, -1, -1);

        verticalLayout_2->addLayout(timeline);

        scrollArea->setWidget(Content);

        horizontalLayout->addWidget(scrollArea);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


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
