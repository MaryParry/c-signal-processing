"""Plot signal.csv (written by the C program) and save it as signal.png.

Each line of the CSV is: time, signal1, signal2, ...
Every signal column is drawn as its own line on the same plot.
"""

import csv

import matplotlib.pyplot as plt

LABELS = ["noisy", "filtered", "signal 3", "signal 4"]


def read_signals(path: str) -> tuple[list[float], list[list[float]]]:
    times: list[float] = []
    columns: list[list[float]] = []
    with open(path, newline="") as f:
        for row in csv.reader(f):
            times.append(float(row[0]))
            values = [float(v) for v in row[1:]]
            if not columns:
                columns = [[] for _ in values]
            for column, v in zip(columns, values):
                column.append(v)
    return times, columns


def main() -> None:
    times, columns = read_signals("signal.csv")
    plt.figure(figsize=(10, 4))
    for label, values in zip(LABELS, columns):
        plt.plot(times, values, label=label)
    plt.xlabel("time (seconds)")
    plt.ylabel("value")
    plt.grid(True)
    plt.legend()
    plt.tight_layout()
    plt.savefig("signal.png")
    plt.show()


if __name__ == "__main__":
    main()
