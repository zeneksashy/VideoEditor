/********************************************************************************
** Form generated from reading UI file 'ProjectSettingsWIndow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROJECTSETTINGSWINDOW_H
#define UI_PROJECTSETTINGSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ProjectSettingsWIndow
{
public:
    QFormLayout *formLayout;
    QLabel *projNameLab;
    QLineEdit *nameEdit;
    QLabel *projNameLab_2;
    QLineEdit *pathEdit;
    QDialogButtonBox *buttonBox;
    QLabel *videoFormatLab;
    QComboBox *videoFormatCombo;
    QWidget *horizontalWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *heightLab;
    QLineEdit *heightEdit;
    QSpacerItem *horizontalSpacer;
    QLabel *widthLab;
    QLineEdit *widthEdit;
    QLabel *frameRateLab;
    QComboBox *frameRateCombo;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *ProjectSettingsWIndow)
    {
        if (ProjectSettingsWIndow->objectName().isEmpty())
            ProjectSettingsWIndow->setObjectName(QStringLiteral("ProjectSettingsWIndow"));
        ProjectSettingsWIndow->resize(324, 332);
        formLayout = new QFormLayout(ProjectSettingsWIndow);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setVerticalSpacing(12);
        formLayout->setContentsMargins(-1, -1, -1, 3);
        projNameLab = new QLabel(ProjectSettingsWIndow);
        projNameLab->setObjectName(QStringLiteral("projNameLab"));

        formLayout->setWidget(0, QFormLayout::LabelRole, projNameLab);

        nameEdit = new QLineEdit(ProjectSettingsWIndow);
        nameEdit->setObjectName(QStringLiteral("nameEdit"));

        formLayout->setWidget(0, QFormLayout::FieldRole, nameEdit);

        projNameLab_2 = new QLabel(ProjectSettingsWIndow);
        projNameLab_2->setObjectName(QStringLiteral("projNameLab_2"));

        formLayout->setWidget(1, QFormLayout::LabelRole, projNameLab_2);

        pathEdit = new QLineEdit(ProjectSettingsWIndow);
        pathEdit->setObjectName(QStringLiteral("pathEdit"));
        pathEdit->setToolTipDuration(-1);

        formLayout->setWidget(1, QFormLayout::FieldRole, pathEdit);

        buttonBox = new QDialogButtonBox(ProjectSettingsWIndow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Apply|QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(false);

        formLayout->setWidget(12, QFormLayout::FieldRole, buttonBox);

        videoFormatLab = new QLabel(ProjectSettingsWIndow);
        videoFormatLab->setObjectName(QStringLiteral("videoFormatLab"));

        formLayout->setWidget(3, QFormLayout::LabelRole, videoFormatLab);

        videoFormatCombo = new QComboBox(ProjectSettingsWIndow);
        videoFormatCombo->setObjectName(QStringLiteral("videoFormatCombo"));

        formLayout->setWidget(3, QFormLayout::FieldRole, videoFormatCombo);

        horizontalWidget = new QWidget(ProjectSettingsWIndow);
        horizontalWidget->setObjectName(QStringLiteral("horizontalWidget"));
        horizontalLayout = new QHBoxLayout(horizontalWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        heightLab = new QLabel(horizontalWidget);
        heightLab->setObjectName(QStringLiteral("heightLab"));

        horizontalLayout->addWidget(heightLab);

        heightEdit = new QLineEdit(horizontalWidget);
        heightEdit->setObjectName(QStringLiteral("heightEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(heightEdit->sizePolicy().hasHeightForWidth());
        heightEdit->setSizePolicy(sizePolicy);
        heightEdit->setMinimumSize(QSize(5, 5));

        horizontalLayout->addWidget(heightEdit);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Fixed, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        widthLab = new QLabel(horizontalWidget);
        widthLab->setObjectName(QStringLiteral("widthLab"));

        horizontalLayout->addWidget(widthLab);

        widthEdit = new QLineEdit(horizontalWidget);
        widthEdit->setObjectName(QStringLiteral("widthEdit"));
        widthEdit->setMinimumSize(QSize(5, 5));

        horizontalLayout->addWidget(widthEdit);


        formLayout->setWidget(5, QFormLayout::FieldRole, horizontalWidget);

        frameRateLab = new QLabel(ProjectSettingsWIndow);
        frameRateLab->setObjectName(QStringLiteral("frameRateLab"));

        formLayout->setWidget(8, QFormLayout::LabelRole, frameRateLab);

        frameRateCombo = new QComboBox(ProjectSettingsWIndow);
        frameRateCombo->setObjectName(QStringLiteral("frameRateCombo"));
        frameRateCombo->setEditable(true);

        formLayout->setWidget(8, QFormLayout::FieldRole, frameRateCombo);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        formLayout->setItem(10, QFormLayout::FieldRole, verticalSpacer);


        retranslateUi(ProjectSettingsWIndow);

        QMetaObject::connectSlotsByName(ProjectSettingsWIndow);
    } // setupUi

    void retranslateUi(QDialog *ProjectSettingsWIndow)
    {
        ProjectSettingsWIndow->setWindowTitle(QApplication::translate("ProjectSettingsWIndow", "ProjectSettingsWIndow", nullptr));
        projNameLab->setText(QApplication::translate("ProjectSettingsWIndow", "Project name", nullptr));
        projNameLab_2->setText(QApplication::translate("ProjectSettingsWIndow", "Project path", nullptr));
#ifndef QT_NO_TOOLTIP
        pathEdit->setToolTip(QString());
#endif // QT_NO_TOOLTIP
        videoFormatLab->setText(QApplication::translate("ProjectSettingsWIndow", "Video Format", nullptr));
        videoFormatCombo->setCurrentText(QString());
        heightLab->setText(QApplication::translate("ProjectSettingsWIndow", "Height:", nullptr));
        widthLab->setText(QApplication::translate("ProjectSettingsWIndow", "Width:", nullptr));
        frameRateLab->setText(QApplication::translate("ProjectSettingsWIndow", "Frame rate", nullptr));
    } // retranslateUi

};

namespace Ui {
    class ProjectSettingsWIndow: public Ui_ProjectSettingsWIndow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROJECTSETTINGSWINDOW_H
