#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CHANNELS 15  

int generateRandom(int max) {
    return rand() % max;
}

int hopFrequency(int currentFrequency, int numChannels) {
    int newFrequency = generateRandom(numChannels);

    while (newFrequency == currentFrequency) {
        newFrequency = generateRandom(numChannels);
    }

    return newFrequency;
}

int main() {
    srand(time(NULL));

    int currentFrequency = generateRandom(NUM_CHANNELS);
    printf("Starting Frequency: %d\n", currentFrequency);

    for (int i = 0; i < 12; ++i) {
        int temp = currentFrequency;
        currentFrequency = hopFrequency(currentFrequency, NUM_CHANNELS);
       
        printf("Hop %d - Frequency hopped from %d to %d\n", i + 1, temp, currentFrequency);
    }

    return 0;
}