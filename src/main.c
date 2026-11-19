#include <math.h>   // sin()
#include <stdio.h>  // fopen(), fprintf(), fclose()
#include <stdlib.h> //rand()

#define PI 3.14159265358979
#define SAMPLE_RATE 1000 // samples per second
#define NUM_SAMPLES 1000 // 1000 samples at 1000 per second = 1 second of signal
#define FREQ 5.0         // the wave goes up and down 5 times per second (5 Hz)
#define NOISE 0.3

double averageThreeNumbers(double num1, double num2, double num3) {
  return (num1 + num2 + num3) / 3;
}

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
  denoised_wave[0] =
      averageThreeNumbers(noisy_wave[0], noisy_wave[1], noisy_wave[2]);
  denoised_wave[NUM_SAMPLES - 1] = averageThreeNumbers(
      noisy_wave[NUM_SAMPLES - 1], noisy_wave[NUM_SAMPLES - 2],
      noisy_wave[NUM_SAMPLES - 3]);

  for (int i = 1; i < NUM_SAMPLES - 1; i++) {
    denoised_wave[i] = averageThreeNumbers(noisy_wave[i - 1], noisy_wave[i],
                                           noisy_wave[i + 1]);
  }

  for (int i = 0; i < NUM_SAMPLES; i++) {
    double t = i / (double)SAMPLE_RATE;
    fprintf(out, "%f,%f,%f\n", t, noisy_wave[i], denoised_wave[i]);
  }
  fclose(out);
  return 0;
}
