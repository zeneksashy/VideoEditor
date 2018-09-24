/********************************************************************************
** Form generated from reading UI file 'MedianBlurWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MEDIANBLURWINDOW_H
#define UI_MEDIANBLURWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_MedianBlurWindow
{
public:
    QFormLayout *formLayout;
    QLabel *KernelSize;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;
    QSpinBox *kernel;

    void setupUi(QDialog *MedianBlurWindow)
    {
        if (MedianBlurWindow->objectName().isEmpty())
            MedianBlurWindow->setObjectName(QStringLiteral("MedianBlurWindow"));
        MedianBlurWindow->resize(194, 144);
        formLayout = new QFormLayout(MedianBlurWindow);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        KernelSize = new QLabel(MedianBlurWindow);
        KernelSize->setObjectName(QStringLiteral("KernelSize"));

        formLayout->setWidget(0, QFormLayout::LabelRole, KernelSize);

        buttonBox = new QDialogButtonBox(MedianBlurWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(buttonBox->sizePolicy().hasHeightForWidth());
        buttonBox->setSizePolicy(sizePolicy);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        formLayout->setWidget(2, QFormLayout::LabelRole, buttonBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(1, QFormLayout::LabelRole, verticalSpacer);

        kernel = new QSpinBox(MedianBlurWindow);
        kernel->setObjectName(QStringLiteral("kernel"));

        formLayout->setWidget(0, QFormLayout::FieldRole, kernel);


        retranslateUi(MedianBlurWindow);

        QMetaObject::connectSlotsByName(MedianBlurWindow);
    } // setupUi

    void retranslateUi(QDialog *MedianBlurWindow)
    {
        MedianBlurWindow->setWindowTitle(QApplication::translate("MedianBlurWindow", "MedianBlurWindow", nullptr));
        KernelSize->setText(QApplication::translate("MedianBlurWindow", "kernel label", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MedianBlurWindow: public Ui_MedianBlurWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MEDIANBLURWINDOW_H
