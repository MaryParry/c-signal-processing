"""Plot signal.csv (written by the C program) and save it as signal.png."""

import csv

import matplotlib.pyplot as plt


def read_signal(path: str) -> tuple[list[float], list[float]]:
    times: list[float] = []
    values: list[float] = []
    with open(path, newline="") as f:
        for t, v in csv.reader(f):
            times.append(float(t))
            values.append(float(v))
    return times, values


def main() -> None:
    times, values = read_signal("signal.csv")
    plt.figure(figsize=(10, 4))
    plt.plot(times, values)
    plt.xlabel("time (seconds)")
    plt.ylabel("value")
    plt.grid(True)
    plt.tight_layout()
    plt.savefig("signal.png")
    plt.show()


if __name__ == "__main__":
    main()
