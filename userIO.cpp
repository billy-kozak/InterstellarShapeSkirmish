/**
This file will recieve and interpret
data from the wireless controller
*/

#include "userIO.h"

#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <errno.h>


#include "global.h"
using namespace Global;

#define M_PI 3.1415

ControllerState controller1state;
ControllerState controller2state;


class Application : public Listener
{
public: 
	int up1;
	int down1;
	int left1;
	int right1;
	int fire1;
	int start1;

	int up2;
	int down2;
	int left2;
	int right2;
	int fire2;

	int run(){
		disp.listener( this );
		return 0;
	}

protected:
    void onKeyDown( DisplayInterface & display, Key key )
    {
		if(key == Key::W){
			up1 = 2; 
		}
		else if(key == Key::S){
			down1 = 2; 
		}
		else if(key == Key::A){
			left1 = 2;
		}
		else if(key == Key::D){
			right1 = 2;
		}
		else if(key == Key::Space){
			fire1 = 1; 
		}
		else if(key == Key::Shift){
			start1=1;
		}
    }

    void onKeyPressed( DisplayInterface & display, Key key )
    {

    }

    void onKeyUp( DisplayInterface & display, Key key )
    {
		if(key == Key::W){
			up1 = 0; 
		}
		else if(key == Key::S){
			down1 = 0; 
		}
		else if(key == Key::A){
			left1 = 0;
		}
		else if(key == Key::D){
			right1 = 0;
		}
		else if(key == Key::Space){
			fire1 = 0; 
		}
		else if(key == Key::Shift){
			start1=0;
		}
    }


};

Application keyTrack;


void controller1_task( System::Object ^ )
{
	keyTrack.run();

	GlobalsEng::controller1semaphore->WaitOne();
	controller1state.quit = 0;
	GlobalsEng::controller1semaphore->Release();
	short int quit; 
	while(1){
		GlobalsEng::controller1semaphore->WaitOne();
		controller1state.roll = keyTrack.right1-keyTrack.left1;
		controller1state.pitch = keyTrack.down1-keyTrack.up1;
		controller1state.fire = keyTrack.fire1;
		controller1state.start = keyTrack.start1;
		quit = controller1state.quit;
		GlobalsEng::controller1semaphore->Release();

		GlobalsEng::semVGA->WaitOne();

		GlobalsEng::semVGA->Release();

		if(quit){
			break;
		}
	}
}

void controller2_task( System::Object ^ )
{
	GlobalsEng::controller2semaphore->WaitOne();
	controller2state.quit = 0;
	GlobalsEng::controller2semaphore->Release();
	short int quit; 
	while(1){
		GlobalsEng::controller2semaphore->WaitOne();
		controller2state.roll = 0;
		controller2state.pitch = 0;
		controller2state.fire = 0;
		controller2state.start = 0;
		quit = controller2state.quit;
		GlobalsEng::controller2semaphore->Release();

		GlobalsEng::semVGA->WaitOne();

		GlobalsEng::semVGA->Release();

		if(quit){
			break;
		}
	}
       
}



