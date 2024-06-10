#include "../lib/LedGame.h"
#include "../lib/defines.h"
#include "../lib/EEPROMController.h"

volatile uint16_t timeDifference;

    ISR(TIMER1_OVF_vect) {
    // Increment the time difference by 65536
    timeDifference += 65536;
    }

uint16_t LedGame::play() {

    // Configure Timer1 with no prescaler
    TCCR1B |= (1 << CS10);

    // Enable Timer1 overflow interrupt
    TIMSK1 |= (1 << TOIE1);

    unsigned long interval = beginGame() + previousMillis;

    while (true) {
        if (millis() > interval) {
            break;
        } else {
            if (!digitalRead(BUTTON_ENTER_PIN) == HIGH) {
                return 1;
            }
        }
    }


    // Configure button pin as input and enable pull-up resistor
    // Enable pin change interrupt PCINT0
    PCICR |= (1 << PCIE0);
    PCMSK0 |= (1 << PCINT0);

    // Enable global interrupts
    sei();

    TCNT1 = 0;

  // Clear the time difference
    timeDifference = 0;

  // Clear the button pressed flag
    bool buttonPressed = false;
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