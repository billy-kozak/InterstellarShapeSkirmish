#ifndef GLOBAL
#define GLOBAL

//C++ STUFF
#include <iostream>
#include <cstdio>
#include <stdlib.h>

#include "PixelToaster.h"
using namespace PixelToaster;

#include "userIO.h"

#using <System.dll>

//using namespace System;
using namespace System::Threading;

	namespace Global{

		public ref class GlobalsEng abstract sealed{
			public:
			static Semaphore^ semVGA;
			static Semaphore^ controller1semaphore;
			static Semaphore^ controller2semaphore;
		};

}

extern Display disp;
#endif