/********************************************************************************
** Form generated from reading UI file 'AudioFrame.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_AUDIOFRAME_H
#define UI_AUDIOFRAME_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AudioFrame
{
public:

    void setupUi(QWidget *AudioFrame)
    {
        if (AudioFrame->objectName().isEmpty())
            AudioFrame->setObjectName(QStringLiteral("AudioFrame"));
        AudioFrame->resize(400, 300);

        retranslateUi(AudioFrame);

        QMetaObject::connectSlotsByName(AudioFrame);
    } // setupUi

    void retranslateUi(QWidget *AudioFrame)
    {
        AudioFrame->setWindowTitle(QApplication::translate("AudioFrame", "AudioFrame", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioFrame: public Ui_AudioFrame {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOFRAME_H
