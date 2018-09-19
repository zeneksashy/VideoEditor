#include "TimeLineSlider.h"

//TimeLineSlider::TimeLineSlider(QWidget *parent)
//	: QSlider(parent)
//{
//}

 void TimeLineSlider::paintEvent(QPaintEvent *)
{
	 QStylePainter p(this);
	 QPainter painter(this);
	 QStyleOptionSlider opt;
	 initStyleOption(&opt);
	 painter.setPen(Qt::white);
	 QRect handle = style()->subControlRect(QStyle::CC_Slider, &opt, QStyle::SC_SliderHandle, this);

	 // draw tick marks
	 // do this manually because they are very badly behaved with style sheets
	 int interval = tickInterval();
	 if (interval == 0)
	 {
		 interval = pageStep();
	 }
	 QString s;
	 if (tickPosition() != NoTicks)
	 {
		 int sec = 0;
		 for (int i = minimum(); i <= maximum(); i += interval)
		 {
			 int x = round((double)((double)((double)(i - this->minimum()) / (double)(this->maximum() - this->minimum())) * (double)(this->width() - handle.width()) + (double)(handle.width() / 2.0))) - 1;
			 int h = 4;
			 p.setPen(QColor("#a5a294"));
			 if (tickPosition() == TicksBothSides || tickPosition() == TicksAbove)
			 {
				 int y = this->rect().top();
				 if (i % 250 == 0 && i!=0)
				 {
					 p.setPen(Qt::black);
					 p.drawLine(x, y, x, y + 12);
					 painter.drawText(QPoint(x-20, y + 25), convertTime(sec));
				 }
				 else
				 {
					 p.drawLine(x, y, x, y + h);
				 }
				
			 }
			/* if (tickPosition() == TicksBothSides || tickPosition() == TicksBelow)
			 {
				 int y = this->rect().bottom();
				 p.drawLine(x, y, x, y - h);
			 }*/
			 ++sec;
		 }
	 }

	 // draw the slider (this is basically copy/pasted from QSlider::paintEvent)
	 opt.subControls = QStyle::SC_SliderGroove;
	 p.setPen(QColor("#a5a294"));
	 p.drawComplexControl(QStyle::CC_Slider, opt);

	 // draw the slider handle
	 opt.subControls = QStyle::SC_SliderHandle;
	 p.drawComplexControl(QStyle::CC_Slider, opt);
}

 QString TimeLineSlider::convertTime(int sec)
 {
	 std::stringstream s;
	 int min = sec / 60;
	 int h = min / 60;
	 if (sec >= 60)
		 sec %= 60;
	 if (min >= 60)
		 min %= 60;
	 (h > 10) ? s << h << ":" : s << "0" << h << ":";
	 (min > 10) ? s << min << ":" : s << "0" << min << ":";
	 (sec > 10) ? s << sec : s << "0" << sec;
	 std::string time = s.str();

	 return QString::fromStdString(time);
 }


