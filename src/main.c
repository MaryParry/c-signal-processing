#include <math.h>   // sin()
#include <stdio.h>  // fopen(), fprintf(), fclose()
#include <stdlib.h> //rand()

#define PI 3.14159265358979
#define SAMPLE_RATE 1000 // samples per second
#define NUM_SAMPLES 1000 // 1000 samples at 1000 per second = 1 second of signal
#define FREQ 5.0         // the wave goes up and down 5 times per second (5 Hz)
#define NOISE 0.3
#define WINDOW 201

int main(void) {
  FILE *out = fopen("signal.csv", "w");
  if (out == NULL) {
    printf("could not open signal.csv\n");
    return 1;
  }

  double noisy_wave[NUM_SAMPLES];
  double denoised_wave[NUM_SAMPLES];

  for (int n = 0; n < NUM_SAMPLES; n++) {
    double random = (double)rand() / RAND_MAX * 2.0 -
                    1.0; // ensure rand_noise is within [-1;+1]
    double t = n / (double)SAMPLE_RATE;
    double value = sin(2 * PI * FREQ * t);
    value = value + (NOISE * random);
    noisy_wave[n] = value;
  }

  for (int i = 0; i < NUM_SAMPLES; i++) {
    double sum = 0.0;
    int count = 0;
    for (int k = i - WINDOW / 2; k <= i + WINDOW / 2; k++) {

      if (k < 0 || k >= NUM_SAMPLES) {
        continue;
      }
      sum += noisy_wave[k];
      count++;
    }
    denoised_wave[i] = sum / count;
  }
  for (int i = 0; i < NUM_SAMPLES; i++) {
    double t = i / (double)SAMPLE_RATE;
    fprintf(out, "%f,%f,%f\n", t, noisy_wave[i], denoised_wave[i]);
  }
  fclose(out);
  return 0;
}
