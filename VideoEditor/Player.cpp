#include "Player.h"
#pragma region Player class
Player::Player(QObject *parent)
	: QThread(parent),audio(false),video(false)
{
	mediaplayer.reset(new QMediaPlayer);
	stop = true;
	capture.reset(new cv::VideoCapture);
	isEffectApplied = false;
	isFirstFrame = true;
	playerDelay = chrono::nanoseconds(0);
}
bool Player::loadFile(QString filename,MediaType type) 
{
	capture->open(filename.toStdString());
	if (CheckFile())
	{
		mediaplayer->setMedia(QUrl::fromLocalFile(filename));
		//connect(mediaplayer,&QMediaPlayer::durationChanged)
		CheckMediaType(type);
		if(video)
		{
			framceount = (int)capture->get(cv::CAP_PROP_FRAME_COUNT);
			frameRate = capture->get(CV_CAP_PROP_FPS);
			delay = (1000 / frameRate);
			auto mili = std::chrono::milliseconds(delay);
			del = std::chrono::duration_cast<std::chrono::nanoseconds> (mili);
			buffer.SetVideoCapture(*capture);
			worker = std::thread([this]() {buffer.LoadToBuffer(); });
			worker.detach();
		}
		this->filename = filename.toStdString();
		return true;
	}
	else
		return false;
}
void Player::Play()
{
	if (!isRunning()) {
		if (isStopped()) {
			stop = false;
		}
		if (video)
			start(LowPriority);
		if (audio)
		{
			connect(mediaplayer.data(), &QMediaPlayer::mediaStatusChanged, this, &Player::MediaStatusChanged);
			mediaplayer->play();
		}
	}
}
bool Player::CheckFile()
{
	if (capture->isOpened())
		return true;
	return false;

}
void Player::MediaStatusChanged(QMediaPlayer::MediaStatus status)
{
	if (status == QMediaPlayer::MediaStatus::EndOfMedia)
	{
		emit EndOfMedia();
	}
}
bool Player::CheckVideo()
{
	if (capture->read(frame))
	{
		return true;
		capture->set(cv::CAP_PROP_POS_FRAMES, 0);
	}
	stop = true;
	return false;
}
bool Player::CheckAudio()
{
	if (mediaplayer->error() == QMediaPlayer::NoError)
		return true;
	return false;
}
void Player::setVideoPosition(int pos)
{
	Pause();
	mediaplayer->setPosition(pos);
	buffer.SetCapturePosition(pos);
	capture->set(CV_CAP_PROP_POS_MSEC, pos);
	Play();
}

void Player::recieveTime(std::chrono::nanoseconds nano)
{
	playerDelay = nano;
}

void Player::run()
{
	while (true)
	{
		if (!buffer.GetNextFrame(frame) )
		{
			emit EndOfMedia();
			break;
		}
		if (stop)
		{
			break;
		}
		if (isEffectApplied)
		{
			PlayEffect();
		}
		else
		{
			CaptureNextFrame();
		}
		this->msleep(del);
		//this->msleep((del - nano) -chrono::nanoseconds(1077152)-playerDelay); //1077152 is time of singe while iteration 
	}
}

void Player::Stop()
{
	capture->set(cv::CAP_PROP_POS_FRAMES, 0);
	buffer.SetCapturePosition(0);
	mediaplayer->stop();
	stop = true;
	emit videoStopped();
}

void Player::Pause()
{
	mediaplayer->pause();
	stop = true;
}

void Player::PlayEffect()
{
	effects.Run(frame);
	cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
	img = QImage((const unsigned char*)(RGBframe.data),
	RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
	emit processedImage(std::move(img));
	emit positionChanged();
}

void Player::CaptureNextFrame()
{
	cv::cvtColor(frame, RGBframe, CV_BGR2RGB);
	img = QImage((const unsigned char*)(RGBframe.data), RGBframe.cols, RGBframe.rows, QImage::Format_RGB888);
	emit processedImage(std::move(img));
	emit positionChanged();
}

void Player::msleep(double ms) 
{
	std::this_thread::sleep_for(std::chrono::nanoseconds(((int)ms % 1000) * 1000 * 1000));
}

void Player::msleep(std::chrono::nanoseconds ms)
{
	std::this_thread::sleep_for(ms);
}

void Player::setFrameRate(float rate)
{
	// dynamic time warp ?
}

float Player::getFrameRate()
{
	return frameRate;
}

bool Player::isAudioAvaible()
{
	return audio;
}

bool Player::isVideoAvaible()
{
	return video;
}

long Player::getFrameCount() const
{
	return (long)capture->get(cv::CAP_PROP_FRAME_COUNT);
}

QMediaPlayer* Player::getMediaPlayer() const
{
	return mediaplayer.data();
}
void Player::setEffect(VideoEffect* effect)
{
	effects.AddEffect(effect);
	isEffectApplied = true;
}
void Player::setEffect(std::vector<cv::Mat> frames)
{
	isEffectApplied = true;
}
bool Player::isStopped() const {
	return this->stop;
}
void Player::Deserialize(std::vector<std::string>&x)
{
	effects.Deserialize(x);
}
void Player::CheckMediaType(MediaType type)
{
	if (type == MediaType::Audio)
	{
		audio = CheckAudio();
		if (!audio)
		{
			mediaplayer->~QMediaPlayer();
		}
	}
	else if (type == MediaType::Video)
	{
		video = CheckVideo();
		if (!video)
		{
			capture->release();
		}
	}
	else
	{
		audio = CheckAudio();
		video = CheckVideo();
	}
}
Player::~Player()
{
	mutex.lock();
	stop = true;
	capture->release();
	condition.wakeOne();
	mutex.unlock();
	wait();
}
std::ostream & operator<<(std::ostream & os, const Player & player)
{
	os << player.effects;
	return os;
}
std::istream & operator>>(std::istream & is, const Player & player)
{
	
	// TODO: insert return statement here
	return is;
}
#pragma endregion
#pragma region Buffer class
Buffer::Buffer():stop(false)
{
}
void Buffer::SetVideoCapture(cv::VideoCapture cap)
{
	capture = cap;
}

Buffer::~Buffer()
{

}
void Buffer::LoadToBuffer()
{	
	while (true)
	{
		//locker.lock();
		if (!stop)
		{
			if (buff.size() <= bufferMaxSize)
			{
				if (!capture.read(newFrame))
				{
					stop = true;
			//		locker.unlock();
					break;
				}
				else
				{
					buff.emplace(newFrame);
				}
			}
			else
			{
				break;
			}
		}
		//locker.unlock();
	}	
}
bool Buffer::GetNextFrame(cv::Mat & frame)
{
	locker.lock();
	if (buff.size() > 0)
	{
	    frame = buff.front();
		buff.pop();
		locker.unlock();
		LoadNext();
		return true;
	}
	locker.unlock();
	return false;
}
void Buffer::SetCapturePosition(int pos)
{
	locker.lock();
	stop = true;
	capture.set(CV_CAP_PROP_POS_MSEC, pos);
	stop = false;
	locker.unlock();
}
void Buffer::LoadNext()
{
	if(capture.read(newFrame))
		buff.emplace(newFrame);

}
#pragma endregion