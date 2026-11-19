CC      := gcc
CFLAGS  := -std=c17 -Wall -Wextra -Wpedantic -g -O0
LDLIBS  := -lm   # the math library: sin(), cos(), sqrt(), ...

build/dsp: src/main.c | build
	$(CC) $(CFLAGS) $< -o $@ $(LDLIBS)

build:
	mkdir -p build

# Build, run the program (writes signal.csv), then plot it
run: build/dsp
	./build/dsp
	python3 plot.py

clean:
	rm -rf build signal.csv signal.png

.PHONY: run clean
