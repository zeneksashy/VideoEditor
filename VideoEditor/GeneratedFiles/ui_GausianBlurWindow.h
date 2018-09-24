/********************************************************************************
** Form generated from reading UI file 'GausianBlurWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GAUSIANBLURWINDOW_H
#define UI_GAUSIANBLURWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_GausianBlurWindow
{
public:
    QVBoxLayout *verticalLayout;
    QGridLayout *gridLayout;
    QSpinBox *SizeX;
    QLabel *SizeLabel;
    QSpinBox *SizeY;
    QHBoxLayout *horizontalLayout_2;
    QLabel *YLabel;
    QDoubleSpinBox *YParam;
    QHBoxLayout *horizontalLayout;
    QLabel *XLabel;
    QDoubleSpinBox *XParam;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *GausianBlurWindow)
    {
        if (GausianBlurWindow->objectName().isEmpty())
            GausianBlurWindow->setObjectName(QStringLiteral("GausianBlurWindow"));
        GausianBlurWindow->resize(204, 342);
        verticalLayout = new QVBoxLayout(GausianBlurWindow);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(-1, -1, 15, -1);
        SizeX = new QSpinBox(GausianBlurWindow);
        SizeX->setObjectName(QStringLiteral("SizeX"));
        SizeX->setToolTipDuration(1);
        SizeX->setMinimum(1);
        SizeX->setMaximum(31);
        SizeX->setValue(1);

        gridLayout->addWidget(SizeX, 0, 1, 1, 1);

        SizeLabel = new QLabel(GausianBlurWindow);
        SizeLabel->setObjectName(QStringLiteral("SizeLabel"));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(SizeLabel->sizePolicy().hasHeightForWidth());
        SizeLabel->setSizePolicy(sizePolicy);
        QFont font;
        font.setPointSize(16);
        SizeLabel->setFont(font);

        gridLayout->addWidget(SizeLabel, 0, 0, 1, 1);

        SizeY = new QSpinBox(GausianBlurWindow);
        SizeY->setObjectName(QStringLiteral("SizeY"));
        SizeY->setToolTipDuration(1);
        SizeY->setMaximum(31);
        SizeY->setValue(1);

        gridLayout->addWidget(SizeY, 0, 2, 1, 1);


        verticalLayout->addLayout(gridLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        YLabel = new QLabel(GausianBlurWindow);
        YLabel->setObjectName(QStringLiteral("YLabel"));
        QSizePolicy sizePolicy1(QSizePolicy::Minimum, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(YLabel->sizePolicy().hasHeightForWidth());
        YLabel->setSizePolicy(sizePolicy1);
        YLabel->setFont(font);

        horizontalLayout_2->addWidget(YLabel);

        YParam = new QDoubleSpinBox(GausianBlurWindow);
        YParam->setObjectName(QStringLiteral("YParam"));
        QSizePolicy sizePolicy2(QSizePolicy::MinimumExpanding, QSizePolicy::Fixed);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(YParam->sizePolicy().hasHeightForWidth());
        YParam->setSizePolicy(sizePolicy2);
        YParam->setMinimum(0);
        YParam->setValue(1);

        horizontalLayout_2->addWidget(YParam);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        XLabel = new QLabel(GausianBlurWindow);
        XLabel->setObjectName(QStringLiteral("XLabel"));
        sizePolicy1.setHeightForWidth(XLabel->sizePolicy().hasHeightForWidth());
        XLabel->setSizePolicy(sizePolicy1);
        XLabel->setFont(font);

        horizontalLayout->addWidget(XLabel);

        XParam = new QDoubleSpinBox(GausianBlurWindow);
        XParam->setObjectName(QStringLiteral("XParam"));
        sizePolicy2.setHeightForWidth(XParam->sizePolicy().hasHeightForWidth());
        XParam->setSizePolicy(sizePolicy2);

        horizontalLayout->addWidget(XParam);


        verticalLayout->addLayout(horizontalLayout);

        buttonBox = new QDialogButtonBox(GausianBlurWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(GausianBlurWindow);

        QMetaObject::connectSlotsByName(GausianBlurWindow);
    } // setupUi

    void retranslateUi(QDialog *GausianBlurWindow)
    {
        GausianBlurWindow->setWindowTitle(QApplication::translate("GausianBlurWindow", "GausianBlurWindow", nullptr));
#ifndef QT_NO_TOOLTIP
        SizeX->setToolTip(QApplication::translate("GausianBlurWindow", "Only Odd Numbers", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        SizeX->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        SizeLabel->setText(QApplication::translate("GausianBlurWindow", "Size", nullptr));
#ifndef QT_NO_TOOLTIP
        SizeY->setToolTip(QApplication::translate("GausianBlurWindow", "Only Odd Numbers", nullptr));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_STATUSTIP
        SizeY->setStatusTip(QString());
#endif // QT_NO_STATUSTIP
        YLabel->setText(QApplication::translate("GausianBlurWindow", "Y", nullptr));
        XLabel->setText(QApplication::translate("GausianBlurWindow", "X", nullptr));
    } // retranslateUi

};

namespace Ui {
    class GausianBlurWindow: public Ui_GausianBlurWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GAUSIANBLURWINDOW_H
