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
#include <TM1637.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <Wire.h>

//public
ClockForSeg::ClockForSeg(int _r1, int _r2, int _r3, int _s1, int _s2){
	RTC_CLK = _r1;
	RTC_DAT = _r2;
	RTC_RST = _r3;
	SEG_DIO = _s1;
	SEG_CLK = _s2;
	
	static ThreeWire wires(RTC_DAT,RTC_CLK,RTC_RST); // IO, SCLK, CE
	TW = &wires;
	static RtcDS1302<ThreeWire> Rtc((*TW));
	RTC = &Rtc;
	static TM1637 tm(SEG_CLK, SEG_DIO);
	SEG = &tm;
};

void ClockForSeg::init(){
	Wire.begin();
	RTC->Begin();
	RTC->SetIsWriteProtected(false);
	RTC->SetIsRunning(true);
	RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
	RTC->SetDateTime(compiled);
	//setTime();
	//RTC->SetIsWriteProtected(true);
	SEG->begin();
	SEG->setBrightness(4);
};

void ClockForSeg::displayTime(int _m){
	if(_m){
		SEG->display(makeTimeStr(1), 0, 0);
		delay(500);
		SEG->display(makeTimeStr(0), 0, 0);
		delay(500);
	} else {
		SEG->display(makeTimeStr(1), 0, 0);
		delay(1000);
	}	
};

void ClockForSeg::setBright(int _b){
	SEG->changeBrightness(_b);
};

//private
void ClockForSeg::setNow(){
	RtcDateTime now = RTC->GetDateTime();
};

void ClockForSeg::setTime(){
	RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);
	RTC->SetDateTime(compiled);
};

#define countof(a) (sizeof(a) / sizeof(a[0]))
String ClockForSeg::makeTimeStr(int _p){
	//setNow();
	RtcDateTime t = RTC->GetDateTime();
	
	char _str[10];
	snprintf_P(_str, 
            countof(_str),
            (_p)? PSTR("%02u.%02u\0"):PSTR("%02u%02u\0"),
            t.Hour(),
            t.Minute());
    return (String)_str;
};
