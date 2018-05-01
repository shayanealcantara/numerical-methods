# Performance of Octave
perf stat -r 10 -B -o results/octave_50 octave t2_octave.m 50 > /dev/null
perf stat -r 10 -B -o results/octave_400 octave t2_octave.m 400 > /dev/null
perf stat -r 2 -B -o results/octave_1000 octave t2_octave.m 1000 > /dev/null
perf stat -r 1 -B -o results/octave_5000 octave t2_octave.m 5000 > /dev/null

# Performance of GSL C
gcc t2_gsl.c -o t2_gsl.o -lgsl -lgslcblas
perf stat -r 10 -B -o results/c_gsl_50 ./t2_gsl.o 50 > /dev/null
perf stat -r 10 -B -o results/c_gsl_400 ./t2_gsl.o 400 > /dev/null
perf stat -r 2 -B -o results/c_gsl_1000 ./t2_gsl.o 1000 > /dev/null
perf stat -r 1 -B -o results/c_gsl_5000 ./t2_gsl.o 5000 > /dev/null

# Performance of LAPACK C
gcc t2_lapack.c -o t2_lapack.o -llapacke
perf stat -r 10 -B -o results/c_lapack_50 ./t2_lapack.o 50 > /dev/null
perf stat -r 10 -B -o results/c_lapack_400 ./t2_lapack.o 400 > /dev/null
perf stat -r 2 -B -o results/c_lapack_1000 ./t2_lapack.o 1000 > /dev/null
perf stat -r 1 -B -o results/c_lapack_5000 ./t2_lapack.o 5000 > /dev/null
perf stat -r 1 -B -o results/c_lapack_10000 ./t2_lapack.o 10000 > /dev/null
