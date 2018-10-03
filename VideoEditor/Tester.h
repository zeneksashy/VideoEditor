#pragma once
#include <QtTest/QtTest>
#include<Player.h>
#include <iostream>
#include "GausianBlur.h"
#include "AudioRecognition.h"
#include <qaudioformat.h>
#include"AudioAnalyser.h"
#include <QtWidgets/QApplication>
#include<QtQml/qqmlapplicationengine.h>
#include <QObject>
#include "MedianBlur.h"

class SerializationTest :QObject
{
	Q_OBJECT
public:
	bool PlayerTest();
	bool SettingsSerialization();
	bool EffectsSerialization();
	bool SettingsDeserialization();
	bool EffectsDeserialization();
	bool EffectContainerSerialization();

private:
	std::string gaussianExpected = "#GaussianBlur##Parameters##XParam#3.5#X#YParam#4.2#Y#XSize#5#X#YSize#11#Y#P#G";
	std::string settingsExpected = "#Project##Settings##Video##Width#1#W#Height#2#H#FrameRate# 3.5#F#V#S#P";
	std::string effectContainerExpected = "#GaussianBlur##Parameters##XParam#3.5#X#YParam#4.2#Y#XSize#5#X#YSize#11#Y#P#G#MedianBlur##Kernel#5#K#M";
};