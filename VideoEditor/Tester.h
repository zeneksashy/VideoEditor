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

class SerializationTest :QObject
{
	Q_OBJECT
public:
	bool PlayerTest();
	bool SettingsSerialization();
	bool SettingsDeserialization();

private:
	std::string settingsExpected = "#Project##Settings##Video##Width#1#W#Height#2#H#FrameRate# 3.5#F#V#S#P";
};