/********************************************************************************
** Form generated from reading UI file 'SingleTrack.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLETRACK_H
#define UI_SINGLETRACK_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleTrack
{
public:
    QHBoxLayout *horizontalLayout_2;
    QPushButton *TrackButton;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout;

    void setupUi(QWidget *SingleTrack)
    {
        if (SingleTrack->objectName().isEmpty())
            SingleTrack->setObjectName(QStringLiteral("SingleTrack"));
        SingleTrack->resize(1071, 155);
        horizontalLayout_2 = new QHBoxLayout(SingleTrack);
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        TrackButton = new QPushButton(SingleTrack);
        TrackButton->setObjectName(QStringLiteral("TrackButton"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(TrackButton->sizePolicy().hasHeightForWidth());
        TrackButton->setSizePolicy(sizePolicy);
        TrackButton->setMinimumSize(QSize(27, 27));
        QFont font;
        font.setFamily(QStringLiteral("Arial"));
        font.setPointSize(9);
        font.setBold(false);
        font.setWeight(50);
        TrackButton->setFont(font);
        TrackButton->setStyleSheet(QLatin1String("QPushButton{\n"
"background-color: qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(0, 0, 0, 255), stop:1 rgba(90, 181, 237, 255));\n"
"border: 1px solid ;\n"
"color:white;\n"
"border-color:qlineargradient(spread:pad, x1:0, y1:1, x2:1, y2:0, stop:0 rgba(0, 32, 75, 255), stop:1 rgba(221, 185, 167, 210));\n"
" border-radius: 5px;\n"
"font-family: Arial;\n"
"}"));

        horizontalLayout_2->addWidget(TrackButton);

        horizontalSpacer = new QSpacerItem(50, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));

        horizontalLayout_2->addLayout(horizontalLayout);


        retranslateUi(SingleTrack);

        QMetaObject::connectSlotsByName(SingleTrack);
    } // setupUi

    void retranslateUi(QWidget *SingleTrack)
    {
        SingleTrack->setWindowTitle(QApplication::translate("SingleTrack", "SingleLine", nullptr));
        TrackButton->setText(QApplication::translate("SingleTrack", "V1", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SingleTrack: public Ui_SingleTrack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLETRACK_H
