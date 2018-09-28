/********************************************************************************
** Form generated from reading UI file 'StartPageWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STARTPAGEWINDOW_H
#define UI_STARTPAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QToolButton>

QT_BEGIN_NAMESPACE

class Ui_StartPageWindow
{
public:
    QFormLayout *formLayout;
    QToolButton *openToolButton;
    QDialogButtonBox *buttonBox;
    QPushButton *newProjectButton;
    QLabel *projectPath;
    QListWidget *pathsList;

    void setupUi(QDialog *StartPageWindow)
    {
        if (StartPageWindow->objectName().isEmpty())
            StartPageWindow->setObjectName(QStringLiteral("StartPageWindow"));
        StartPageWindow->resize(304, 299);
        formLayout = new QFormLayout(StartPageWindow);
        formLayout->setSpacing(6);
        formLayout->setContentsMargins(11, 11, 11, 11);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        openToolButton = new QToolButton(StartPageWindow);
        openToolButton->setObjectName(QStringLiteral("openToolButton"));

        formLayout->setWidget(1, QFormLayout::LabelRole, openToolButton);

        buttonBox = new QDialogButtonBox(StartPageWindow);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setStandardButtons(QDialogButtonBox::Close|QDialogButtonBox::Ok);

        formLayout->setWidget(6, QFormLayout::FieldRole, buttonBox);

        newProjectButton = new QPushButton(StartPageWindow);
        newProjectButton->setObjectName(QStringLiteral("newProjectButton"));

        formLayout->setWidget(3, QFormLayout::FieldRole, newProjectButton);

        projectPath = new QLabel(StartPageWindow);
        projectPath->setObjectName(QStringLiteral("projectPath"));

        formLayout->setWidget(1, QFormLayout::FieldRole, projectPath);

        pathsList = new QListWidget(StartPageWindow);
        pathsList->setObjectName(QStringLiteral("pathsList"));

        formLayout->setWidget(2, QFormLayout::FieldRole, pathsList);


        retranslateUi(StartPageWindow);

        QMetaObject::connectSlotsByName(StartPageWindow);
    } // setupUi

    void retranslateUi(QDialog *StartPageWindow)
    {
        StartPageWindow->setWindowTitle(QApplication::translate("StartPageWindow", "StartPageWindow", nullptr));
        openToolButton->setText(QApplication::translate("StartPageWindow", "...", nullptr));
        newProjectButton->setText(QApplication::translate("StartPageWindow", "New Project", nullptr));
        projectPath->setText(QApplication::translate("StartPageWindow", "TextLabel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class StartPageWindow: public Ui_StartPageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STARTPAGEWINDOW_H
