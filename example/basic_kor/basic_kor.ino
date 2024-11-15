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

//핀 연결
//RTC_CLK, RTC_DAT, RTC_RST, SEG_DIO, SEG_CLK 
ClockForSeg clocks(7, 6, 5, 3, 2);

void setup(){
  //7-세그먼트와 RTC(Real-Time-Clock) 초기 설정
  clocks.init();
}
void loop(){
  //7-세그먼트에 시간 출력 (delay 1000ms)
  //BLINK - ":" 계속 깜빡이기 / NON_BLINK - ":"를 킨 상태로 유지
  clocks.displayTime(BLINK);
}