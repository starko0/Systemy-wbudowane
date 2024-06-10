#include "../lib/LedGame.h"
#include "../lib/defines.h"
#include "../lib/EEPROMController.h"

volatile uint16_t timeDifference;
volatile bool buttonPressed;

    ISR(TIMER1_OVF_vect) {
    // Increment the time difference by 65536
    timeDifference += 65536;
    }

    // PCINT0 Interrupt Service Routine (button press)
    ISR(PCINT0_vect) {
    // Check if the button is pressed (low state)
    if (!(PINB & (1 << BUTTON_ENTER_PIN))) {
        // Add the current Timer1 counter value to the time difference
        timeDifference += TCNT1;

        // Indicate that the button has been pressed
        buttonPressed = true;
    }
    }

uint16_t LedGame::play() {


    // Configure Timer1 with no prescaler
    TCCR1B |= (1 << CS10);

    // Enable Timer1 overflow interrupt
    TIMSK1 |= (1 << TOIE1);

    unsigned long interval = beginGame() + millis();
    noInterrupts();

    while (true) {
        if (millis() > interval) {
            break;
        } else {
            if (!digitalRead(BUTTON_ENTER_PIN) == HIGH) {
                return 1;
            }
        }
    }

    // Enable pin change interrupt PCINT0
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT0);

    // Enable global interrupts
    interrupts();

    TCNT1 = 0;

  // Clear the time difference
    timeDifference = 0;

  // Clear the button pressed flag
    buttonPressed = false;
    turnOnLed(); 
  // Wait for the button to be pressed
    while (!buttonPressed);

  // Disable the interrupt for the button pin
    PCICR &= ~(1 << PCIE0);
    turnOffLed();
    return timeDifference;

}


void LedGame::turnOnLed() {
    analogWrite(LED_GAME_LED_PIN, LED_ON_VALUE);
}

void LedGame::turnOffLed() {
    analogWrite(LED_GAME_LED_PIN, LED_OFF_VALUE);
}