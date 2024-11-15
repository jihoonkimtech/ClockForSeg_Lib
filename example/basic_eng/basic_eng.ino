/*
 * ClockForSeg Library
 * Clock For 7-Segment(TM1637) Library
 * 
 * version V1.0.0
 * 
 * author jihoonkimtech (jihoonkimtech@naver.com)
 *        (Republic of Korea)
 */

#include <ClockForSeg.h>

//pin Connect
//RTC_CLK, RTC_DAT, RTC_RST, SEG_DIO, SEG_CLK
ClockForSeg clocks(7, 6, 5, 3, 2);

void setup(){
  //TM1637 & DS1302 initialize
  clocks.init();
}
void loop(){
  //display time to TM1637 (delay 1000ms)
  //BLINK - Blinking ":" / NON_BLINK - Keep ":" on
  clocks.displayTime(BLINK);
}