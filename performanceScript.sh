# Performance of Octave
perf stat -r 10 -B -o results/octave50 octave T2.m 50 >/dev/null
perf stat -r 10 -B -o results/octave400 octave T2.m 400 >/dev/null
perf stat -r 2 -B -o results/octave1k octave T2.m 1000 >/dev/null
perf stat -r 1 -B -o results/octave10k octave T2.m 10000 >/dev/null
