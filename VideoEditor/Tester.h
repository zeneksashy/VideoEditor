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
//
//class Tester : public QObject
//{
//	Q_OBJECT
//
//public:
//	Tester(QObject *parent);
//	~Tester();
//private slots:
//	void AudioFormatRegonitionTest_SampleRate8();
//};
class SerializationTest :QObject
{
	Q_OBJECT
public:
	bool PlayerTest();
	bool SettingsSerialization();
	bool SettingsDeserialization();
	/*{
		Player p;
		p.loadFile(tr("C:\\Users\\gzeniuk\\Downloads\\SampleVideo_720x480_30mb.mp4"));

		std::cout << " mediaplayer pointer\n";
		std::cout << p;

	}*/
private:
	std::string settingsExpected = "#Project##Settings##Video##Width#1#W#Height#2#H#FrameRate# 3.5#F#V#S#P";
};