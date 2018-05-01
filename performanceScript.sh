# Performance of Octave
perf stat -r 10 -B -o results/octave50 octave t2_octave.m 50 > /dev/null
perf stat -r 10 -B -o results/octave400 octave t2_octave.m 400 > /dev/null
perf stat -r 2 -B -o results/octave1000 octave t2_octave.m 1000 > /dev/null
perf stat -r 1 -B -o results/octave5000 octave t2_octave.m 5000 > /dev/null

# Performance of GSL C
ulimit -s 100000000 # Increase Stack
gcc t2_gsl.c -o t2_gsl.o -lgsl -lgslcblas
perf stat -r 10 -B -o results/c50 ./t2_gsl.o 50 > /dev/null
perf stat -r 10 -B -o results/c400 ./t2_gsl.o 400 > /dev/null
perf stat -r 2 -B -o results/c1000 ./t2_gsl.o 1000 > /dev/null
perf stat -r 1 -B -o results/c5000 ./t2_gsl.o 5000 > /dev/null
ulimit -s 8192 # Set default Stack of my computer

# Performance of LAPACK C
gcc t2_lapack.c -o t2_lapack.o -llapacke
ulimit -s 100000000 # Increase Stack
perf stat -r 10 -B -o results/clapack50 ./t2_lapack.o 50 > /dev/null
perf stat -r 10 -B -o results/clapack400 ./t2_lapack.o 400 > /dev/null
perf stat -r 2 -B -o results/clapack1000 ./t2_lapack.o 1000 > /dev/null
perf stat -r 1 -B -o results/clapack5000 ./t2_lapack.o 5000 > /dev/null
ulimit -s 8192 # Set default Stack of my computer
