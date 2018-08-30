/********************************************************************************
** Form generated from reading UI file 'PreviewPlayer.ui'
**
** Created by: Qt User Interface Compiler version 5.11.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PREVIEWPLAYER_H
#define UI_PREVIEWPLAYER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QSlider>
#include <QtWidgets/QToolButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PreviewPlayer
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QToolButton *playButton;
    QToolButton *pauseButton;
    QToolButton *stopButton;
    QSlider *timeLine;
    QHBoxLayout *horizontalLayout_2;
    QSlider *volumeSlider;
    QLabel *previewLabel;

    void setupUi(QWidget *PreviewPlayer)
    {
        if (PreviewPlayer->objectName().isEmpty())
            PreviewPlayer->setObjectName(QStringLiteral("PreviewPlayer"));
        PreviewPlayer->resize(878, 406);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(PreviewPlayer->sizePolicy().hasHeightForWidth());
        PreviewPlayer->setSizePolicy(sizePolicy);
        PreviewPlayer->setLayoutDirection(Qt::LeftToRight);
        PreviewPlayer->setStyleSheet(QStringLiteral(""));
        gridLayout_2 = new QGridLayout(PreviewPlayer);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setSpacing(6);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        playButton = new QToolButton(PreviewPlayer);
        playButton->setObjectName(QStringLiteral("playButton"));

        horizontalLayout->addWidget(playButton);

        pauseButton = new QToolButton(PreviewPlayer);
        pauseButton->setObjectName(QStringLiteral("pauseButton"));

        horizontalLayout->addWidget(pauseButton);

        stopButton = new QToolButton(PreviewPlayer);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        horizontalLayout->addWidget(stopButton);

        timeLine = new QSlider(PreviewPlayer);
        timeLine->setObjectName(QStringLiteral("timeLine"));
        timeLine->setStyleSheet(QLatin1String("QSlider{\n"
"background-color:rgb(104, 104, 104)\n"
"}\n"
"QSlider::groove:horizontal {\n"
"height: 5px;\n"
"border: 0px solid;\n"
"margin: 2px 0;\n"
"}\n"
"QSlider::handle:horizontal {\n"
"background: orange;\n"
"height: 5px;\n"
"width: 8px;\n"
"margin: -10px 0;\n"
"border-radius: 18px;\n"
"}l"));
        timeLine->setMaximum(15000);
        timeLine->setOrientation(Qt::Horizontal);
        timeLine->setInvertedAppearance(false);
        timeLine->setInvertedControls(false);

        horizontalLayout->addWidget(timeLine);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        volumeSlider = new QSlider(PreviewPlayer);
        volumeSlider->setObjectName(QStringLiteral("volumeSlider"));
        volumeSlider->setStyleSheet(QLatin1String("QSlider{\n"
"background-color: \"white\";\n"
"}"));
        volumeSlider->setMaximum(100);
        volumeSlider->setPageStep(5);
        volumeSlider->setSliderPosition(70);
        volumeSlider->setOrientation(Qt::Vertical);
        volumeSlider->setTickPosition(QSlider::TicksAbove);
        volumeSlider->setTickInterval(5);

        horizontalLayout_2->addWidget(volumeSlider);

        previewLabel = new QLabel(PreviewPlayer);
        previewLabel->setObjectName(QStringLiteral("previewLabel"));
        previewLabel->setStyleSheet(QLatin1String("QLabel{\n"
"background-color:\"black\";\n"
"border-style: solid;\n"
"    border-width: 5px;\n"
"    border-color: rgb(63, 63, 70)\n"
"}"));

        horizontalLayout_2->addWidget(previewLabel);


        gridLayout->addLayout(horizontalLayout_2, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);


        retranslateUi(PreviewPlayer);
        QObject::connect(playButton, SIGNAL(clicked()), PreviewPlayer, SLOT(onPlayButtonClicked()));
        QObject::connect(pauseButton, SIGNAL(clicked()), PreviewPlayer, SLOT(onPauseButtonCLicked()));
        QObject::connect(stopButton, SIGNAL(clicked()), PreviewPlayer, SLOT(onStopButtonClicked()));

        QMetaObject::connectSlotsByName(PreviewPlayer);
    } // setupUi

    void retranslateUi(QWidget *PreviewPlayer)
    {
        PreviewPlayer->setWindowTitle(QApplication::translate("PreviewPlayer", "PreviewPlayer", nullptr));
        playButton->setText(QApplication::translate("PreviewPlayer", "...", nullptr));
        pauseButton->setText(QApplication::translate("PreviewPlayer", "...", nullptr));
        stopButton->setText(QApplication::translate("PreviewPlayer", "...", nullptr));
        previewLabel->setText(QApplication::translate("PreviewPlayer", "Video", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PreviewPlayer: public Ui_PreviewPlayer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PREVIEWPLAYER_H
