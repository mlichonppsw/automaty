#include <LPC21xx.H>
#include "led.h"
#include "keyboard.h"

void Delay(int iTimeCounter){
	
	int iDelayCounter;
	iTimeCounter = (12500 * iTimeCounter);
	for (iDelayCounter=0;iDelayCounter<iTimeCounter;iDelayCounter ++) {}
}

unsigned char ucChecker = 0;

int main(){
	
	enum LedState{STOP, LED_LEFT, LED_RIGHT};
	enum LedState eLedState = STOP;

	LedInit();
	KeyboardInit();
	
	while(1){
		
		switch(eLedState){
			
			case STOP:
				if (eKeyboardRead()==BUTTON_0){
					eLedState = LED_LEFT;
				} 
				else if (eKeyboardRead()==BUTTON_2){
					eLedState = LED_RIGHT;
				} 
				else {
					eLedState = STOP;
				}
				break;
				
			case LED_LEFT:
				LedStepLeft();
				if(eKeyboardRead()==BUTTON_1){
					eLedState = STOP;
				}
				else{
					eLedState = LED_LEFT;
				}
				break;
				
			case LED_RIGHT:
				LedStepRight();
				if(eKeyboardRead()==BUTTON_1){
					eLedState = STOP;
				}
				else{
					eLedState = LED_RIGHT;	
				}
				break;
			
			default: 
				break;
		}
		Delay(100);
	}
}
