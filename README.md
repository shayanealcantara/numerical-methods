# Description

Simple use and comparassion of algorithms to Symmetric Eigenproblems:

1. Octave
1. Linear Algebra PACKage: using LAPACKE_dstegr
1. GNU Scientific Library: using gsl_eigen_symmv

Results are locate on results/

# Dependencies

- Lapack
- GSL
- Octave (probably works with Matlab but there is no guarantee)
- perf utility (just if you want execute the performanceScript)

# Compilation and Execution
## C using GSL library

```bash
gcc t2_gsl.c -o t2_gsl.o -lgsl -lgslcblas # compile
./t2_gsl.o # run
```

## C using LAPACK library

```bash
gcc t2_lapack.c -o t2_lapack.o -llapacke # compile
./t2_lapack.o # run
```

## Octave

```bash
octave t2_octave.m # run
```

## Perfomance Script

If you want to execute all the implementations testing them with matrixes of orders:

- 50
- 400
- 1000
- 5000
- 10000 (only LAPACK implementation)

Execute the script performanceScript.sh:

```bash
chmod +x performanceScript.sh # run just once in life, is necessary to make the script runnable
./performanceScript.sh # run script
```

The script will run for aproximately 20 minutes. (so grab a coffee)

The script will generate a file to each test case in the folder results/.

You are free to change the script or just run some of the lines of the script. This script was made just to facilitate my life.

Is recommended that you execute this script while you computer is not being used. (of course running this script while you use your computer heavilly will influence deeply the results)

## Using command line arguments

All the implementations accept one and only one command line argument that has to be an integer value lower than 10000 (no validation of this is made)

The command line argument is to specify the matrix order to be processed.

If no value is passed as command line argument is assume the default value of 10. (in other words, is calculated a matrix of size 10x10).


Examples of use of command line arguments:

```bash
./t2_gsl.o 50
./t2_lapack.o 100
octave t2_octave.m 20
```
