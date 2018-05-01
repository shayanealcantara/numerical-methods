#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <lapacke.h>

#define A 1
#define B 0.5

void displayMatrix(double *, int, int);
void displayVector(double *, int);

int main(int argc, char *argv[]) {
    lapack_int n = 10;

    if (argc >= 2) {
        n = atoi(argv[1]); // get n specified by command line argument
    } else {
        printf("Using default value of n: %d\n", n);
    }

    // Create vector with diagonal values of matriz T
    double diagonal[n];
    // Create vector with subdiagonal values of matriz T
    double subdiagonal[n];

    // Set values of diagonal and subdiagonal vectors
    for (int i = 0; i < n; i++) {
        subdiagonal[i] = B;
        diagonal[i] = A;
    }

    // If you want to display values of diagonal and subdiagonal vectors
    // displayVector(diagonal, n);
    // displayVector(subdiagonal, n);

    // Reference: http://www.netlib.org/lapack/explore-html/da/dba/group__double_o_t_h_e_rcomputational_gac5fa1f1c4eeb2f78df2ea644641392f6.html
    // Set parameters used in LAPACK function
    char JOBZ = 'V';
    char RANGE = 'A';
    double unusedDouble; // not used
    lapack_int unusedInt; // not used
    lapack_int M;
    lapack_int LDZ = n;
    lapack_int ISUPPZ[2 * n];



    // Define array of autovalores and autovetores
    double autovalores[n];
    double autovetor[n * n];
    // Set autovalores and autovetor to 0 (just to be sure)
    memset(autovalores, 0, sizeof(autovalores));
    memset(autovetor, 0, sizeof(autovetor));

    // Set parameter to know success of LAPACKE function
    lapack_int info;

    info = LAPACKE_dstegr(LAPACK_ROW_MAJOR, JOBZ, RANGE,
                    n, diagonal, subdiagonal, unusedDouble,
                    unusedDouble, unusedInt, unusedInt,
                    unusedDouble, &M, autovalores, autovetor, LDZ, ISUPPZ);

    if (info) { // info is zero if operation was successfully
        printf("Unable to operate operation, error: %d\n", info);
        return info; // abort program and return info
    }

    printf("autovalores = \n\n");
    for (int i = 0; i < n; i++) {
        printf (" %6.2f\n", autovalores[i]);
    }
    printf("\n");

    printf("autovetor = \n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf (" %6.2f", autovetor[i * n + j]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}

void displayMatrix(double *matrix, int numberOfLines, int numberOfColumns) {
    printf("matriz = \n\n");
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            printf("%7.2f ", matrix[i * numberOfColumns + j]);
        }
        printf("\n");
    }
    printf("\n");
}

void displayVector(double *matrix, int numberOfColumns) {
    printf("vector = \n\n");
    for (int i = 0; i < numberOfColumns; i++) {
        printf("%5.2f\n", matrix[i]);
    }
    printf("\n");
}
