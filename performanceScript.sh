# Performance of Octave
perf stat -r 10 -B -o results/octave50 octave T2.m 50 > /dev/null
perf stat -r 10 -B -o results/octave400 octave T2.m 400 > /dev/null
perf stat -r 2 -B -o results/octave1k octave T2.m 1000 > /dev/null
# perf stat -r 1 -B -o results/octave5k octave T2.m 5000 > /dev/null

# Performance of C
ulimit -s 100000000 # Increase Stack
gcc T2.c -o t2.o -lgsl -lgslcblas
perf stat -r 10 -B -o results/c50 ./t2.o 50 > /dev/null
perf stat -r 10 -B -o results/c400 ./t2.o 400 > /dev/null
perf stat -r 2 -B -o results/c1k ./t2.o 1000 > /dev/null
# perf stat -r 1 -B -o results/c5k ./t2.o 5000 > /dev/null
ulimit -s 8192 # Set default Stack of my computer
