#include "mbed.h"

// Define LEDs with their connected pin names
DigitalOut led1(LED1);
DigitalOut led2(LED2);

// Define Tickers for timing
Ticker toggle_led1_ticker;
Ticker toggle_led2_ticker;

// Function to toggle LED1
void toggle_led1() {
    led1 = !led1; // Toggle the state of LED1
}

// Function to toggle LED2
void toggle_led2() {
    led2 = !led2; // Toggle the state of LED2
}

int main() {
    // Initial state for LEDs
    led1 = 0;
    led2 = 0;

    // Attach the toggle functions to the tickers
    toggle_led1_ticker.attach(&toggle_led1, 2.0); // Toggle every 2 seconds
    toggle_led2_ticker.attach(&toggle_led2, 5.0); // Toggle every 5 seconds

    while (true) {
        ThisThread::sleep_for(1000); // Sleep the main thread. This keeps the main thread idle.
    }
}