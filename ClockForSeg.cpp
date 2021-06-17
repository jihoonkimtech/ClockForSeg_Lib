/*
 * -ClockForSeg Lib-
 *
 * source code file for ClockForSeg Library
 *
 * author jihoonkimtech (jihoonkimtech@naver.com)
 *			(Republic of Korea)
 * version  V1.0.0
 * date  2021-06-18
*/

#include "ClockForSeg.h"

//public
ClockForSeg::ClockForSeg(int _r1, int _r2, int _r3, int _s1, int _s2){
	RTC_CLK = _r1;
	RTC_DAT = _r2;
	RTC_RST = _r3;
	SEG_DIO = _s1;
	SEG_CLK = _s2;
	
	ThreeWire wires(RTC_DAT,RTC_CLK,RTC_RST); // IO, SCLK, CE
	RTC = RtcDS1302<ThreeWire> Rtc(wires);
	SEG = TM1637 tm(SEG_CLK, SEG_DIO);
};
void ClockForSeg::init(){
	RTC.Begin();
	RTC.SetIsWriteProtected(false);
	RTC.SetIsRunning(true);
	setTime();
	delay(10);
	RTC.SetIsWriteProtected(true);
	SEG.begin();
	SEG.setBrightness(4);
};
void ClockForSeg::displayTime(int _m = BLANK){
	SEG.display(strTime);
};
void ClockForSeg::changeBright(int _b){
	SEG.setBrightness(_b);
};

//private
void ClockForSeg::setNow(){
	NOW_TIME = RTC.GetDateTime();
};
void ClockForSeg::setTime(){
	RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
	RTC.SetDateTime(compiled);
};
void ClockForSeg::makeTimeStr(){
	char _str[6];
	snprintf_P(_str, 
            countof(_str),
            PSTR("%02u.%02u"),
            dt.Hour(),
            dt.Minute());
    strTime = _str;
};
