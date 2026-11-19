#include <math.h>  // sin()
#include <stdio.h> // fopen(), fprintf(), fclose()

#define PI 3.14159265358979
#define SAMPLE_RATE 1000 // samples per second
#define NUM_SAMPLES 1000 // 1000 samples at 1000 per second = 1 second of signal
#define FREQ 5.0         // the wave goes up and down 5 times per second (5 Hz)

int main(void) {
  FILE *out = fopen("signal.csv", "w");
  if (out == NULL) {
    printf("could not open signal.csv\n");
    return 1;
  }

  // TODO: loop n from 0 to NUM_SAMPLES - 1. For each sample:
  //   1. work out the time:   t = n / SAMPLE_RATE
  //   2. work out the value:  value = sin(2 * PI * FREQ * t)
  //   3. write one line:      fprintf(out, "%f,%f\n", t, value);
  for (int n = 0; n < NUM_SAMPLES; n++) {
    double t = n / (double)SAMPLE_RATE;
    double value = sin(2 * PI * FREQ * t);
    fprintf(out, "%f,%f\n", t, value);
  }

  fclose(out);
  return 0;
}
