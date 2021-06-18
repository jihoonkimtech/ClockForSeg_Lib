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

#include <Arduino.h>
#include <TM1637.h>
#include <ThreeWire.h>  
#include <RtcDS1302.h>
#include <Wire.h>

enum mode {NON_BLINK, BLINK};

class ClockForSeg{
	public :
		ClockForSeg(int _r1, int _r2, int _r3, int _s1, int _s2);
		void init();
		void displayTime(int _m);
		void setBright(int _b);
		//String strTime;
	//private :
		void setNow();
		void setTime();
		String makeTimeStr(int _p);
		int RTC_CLK, RTC_DAT, RTC_RST;
		int SEG_DIO, SEG_CLK;
		
		RtcDS1302<ThreeWire>* RTC;
		TM1637* SEG;
		ThreeWire* TW;
};
