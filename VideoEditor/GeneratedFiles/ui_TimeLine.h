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
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QScrollArea>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TimeLine
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QFrame *frame;
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
        TimeLine->resize(800, 330);
        TimeLine->setMinimumSize(QSize(800, 200));
        TimeLine->setMaximumSize(QSize(4000, 500));
        TimeLine->setStyleSheet(QLatin1String("QWidget\n"
"{\n"
"background: rgb(36, 36, 36);\n"
"}\n"
""));
        verticalLayout = new QVBoxLayout(TimeLine);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(TimeLine);
        label->setObjectName(QStringLiteral("label"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setMinimumSize(QSize(110, 0));

        horizontalLayout_2->addWidget(label);

        horizontalSpacer = new QSpacerItem(146, 20, QSizePolicy::Preferred, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        frame = new QFrame(TimeLine);
        frame->setObjectName(QStringLiteral("frame"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(frame->sizePolicy().hasHeightForWidth());
        frame->setSizePolicy(sizePolicy1);
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);

        horizontalLayout_2->addWidget(frame);


        verticalLayout->addLayout(horizontalLayout_2);

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
        sizePolicy1.setHeightForWidth(scrollArea->sizePolicy().hasHeightForWidth());
        scrollArea->setSizePolicy(sizePolicy1);
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
        Content->setGeometry(QRect(0, 0, 516, 280));
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
        timeline = new QVBoxLayout();
        timeline->setSpacing(11);
        timeline->setObjectName(QStringLiteral("timeline"));
        timeline->setSizeConstraint(QLayout::SetMaximumSize);
        timeline->setContentsMargins(-1, 1, -1, -1);

        verticalLayout_2->addLayout(timeline);

        scrollArea->setWidget(Content);

        horizontalLayout->addWidget(scrollArea);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(TimeLine);

        QMetaObject::connectSlotsByName(TimeLine);
    } // setupUi

    void retranslateUi(QWidget *TimeLine)
    {
        TimeLine->setWindowTitle(QApplication::translate("TimeLine", "TimeLine", nullptr));
        label->setText(QApplication::translate("TimeLine", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class TimeLine: public Ui_TimeLine {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TIMELINE_H
