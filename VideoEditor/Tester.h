#pragma once

#include <QObject>

class Tester : public QObject
{
	Q_OBJECT

public:
	Tester(QObject *parent);
	~Tester();
private slots:
	void AudioFormatRegonitionTest_SampleRate8();
};
