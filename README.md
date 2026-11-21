# DSP in C

Digital signal processing written from scratch in C. Signals are generated or loaded,
filtered, analysed, and plotted.

## The big picture

Real-world signals (sound, sensor readings, radio) always arrive with **noise** mixed in.
DSP is about getting the useful part back out. This project builds that up one step at a time:

```
make a clean signal  →  add noise  →  filter it  →  see which frequencies are in it
     (step 1)           (step 2)      (steps 3-4)          (steps 5-6)
```

## Progress

- [x] **1. Sine wave.** A signal is just a list of numbers (samples). Generated a 5 Hz sine wave.
- [x] **2. Add noise.** Add a small random number to every sample, to imitate real-world interference.
- [x] **3. Moving-average filter.** Replace each sample with the average of its neighbours, which smooths out the noise.
- [x?] **4. Low-pass and high-pass filters.** Keep the slow wiggles and remove the fast ones (or the other way round).
- [ ] **5. Fourier transform (DFT).** Find which frequencies a signal contains, e.g. "5 Hz wave + noise".
- [ ] **6. FFT.** The same answer as the DFT, but enormously faster.
- [ ] **7. Fixed-point vs floating-point.** How cheap chips do this maths without decimals, and what it costs.
- [ ] **8. Extension:** process real audio.
## Run

```sh
nix develop
make run    # build, run (writes signal.csv), and plot it
```
