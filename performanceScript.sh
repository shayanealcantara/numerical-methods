# Performance of Octave
perf stat -r 10 -B -o results/octave50 octave T2.m 50 >/dev/null
perf stat -r 10 -B -o results/octave400 octave T2.m 400 >/dev/null
perf stat -r 2 -B -o results/octave1k octave T2.m 1000 >/dev/null

# Performance of C
gcc T2.c -o t2.o -lgsl -lgslcblas
perf stat -r 10 -B -o results/c50 t2.o 50 >/dev/null
perf stat -r 10 -B -o results/c400 t2.o 400 >/dev/null
perf stat -r 2 -B -o results/c1k t2.o 1000 >/dev/null
