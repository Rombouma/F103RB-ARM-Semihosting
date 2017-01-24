/*
 * Application.cpp
 *
 *  Created on: 24 jan. 2017
 *      Author: rombouma
 * Description: Start of the program after the lowes HAL-layer is initialized.
 */

#include "Application.hpp"

#include <BlinkLed.h>
#include <diag/Trace.h>
#include <stdint-gcc.h>
#include <Timer.h>

// Definitions visible only within this translation unit.
namespace
{
  // ----- Timing definitions -------------------------------------------------

  // Keep the LED on for 2/3 of a second.
  constexpr Timer::ticks_t BLINK_ON_TICKS = Timer::FREQUENCY_HZ * 3 / 4;
  constexpr Timer::ticks_t BLINK_OFF_TICKS = Timer::FREQUENCY_HZ
      - BLINK_ON_TICKS;
}


Application::Application()
{

	  Timer timer;
	  timer.start();

	  BlinkLed blinkLed;

	  // Perform all necessary initialisations for the LED.
	  blinkLed.powerUp();

	  uint32_t seconds = 0;

	  // Infinite loop
	  while (1)
	    {
	      blinkLed.turnOn();
	      timer.sleep(seconds== 0 ? Timer::FREQUENCY_HZ : BLINK_ON_TICKS);

	      blinkLed.turnOff();
	      timer.sleep(BLINK_OFF_TICKS);

	      ++seconds;

	      // Count seconds on the trace device.
	      trace_printf("Second %u\n", seconds);
	    }
	  // Infinite loop, never return.


}
