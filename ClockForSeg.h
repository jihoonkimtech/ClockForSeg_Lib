/*
 * -ClockForSeg Lib-
 *
 * header file for ClockForSeg Library
 *
 * author jihoonkimtech (jihoonkimtech@naver.com)
 *			(Republic of Korea)
 * version  V1.0.0
 * date  2021-06-18
*/

#ifndef _UltraSonic_H_
#define _UltraSonic_H_

#include <Arduino.h>
#include <TM1637.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>

enum mode{NONBLANK, BLANK};

class ClockForSeg{
	public :
		ClockForSeg();
		void init();
		void displayTime(int _m = BLANK);
		void changeBright(int _b);
	private :
		void setNow();
		void setTime();
		char* makeTimeStr();
		int RTC_CLK, RTC_DAT, RTC_RST;
		int SEG_DIO, SEG_CLK;
		RtcDateTime* NOW_TIME;
		char* strTime;
		RtcDS1302<ThreeWire>* RTC;
		TM1637* SEG;
};
