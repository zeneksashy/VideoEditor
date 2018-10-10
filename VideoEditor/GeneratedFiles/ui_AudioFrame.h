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

class Ui_AudioTrack
{
public:

    void setupUi(QWidget *AudioTrack)
    {
        if (AudioTrack->objectName().isEmpty())
            AudioTrack->setObjectName(QStringLiteral("AudioTrack"));
        AudioTrack->resize(400, 300);

        retranslateUi(AudioTrack);

        QMetaObject::connectSlotsByName(AudioTrack);
    } // setupUi

    void retranslateUi(QWidget *AudioTrack)
    {
        AudioTrack->setWindowTitle(QApplication::translate("AudioTrack", "AudioTrack", nullptr));
    } // retranslateUi

};

namespace Ui {
    class AudioTrack: public Ui_AudioTrack {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_AUDIOFRAME_H
