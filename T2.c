#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#define A 1
#define B 0.5

void displayMatrix(double *, int, int);

int main(int argc, char *argv[]) {
    int n = 10;

    if (argc >= 2) {
        n = atoi(argv[1]); // get n specified by command line argument
    } else {
        printf("Using default value of n: %d\n", n);
    }
    double matrix[n * n];

    // Initialize matrix with 0
    memset(matrix, 0, sizeof(matrix));

    // Set a and b in matrix
    matrix[0] = A; // Set [0,0] = 1
    matrix[1] = B; // Set [0,1] = 0.5

    matrix[(n-1) * n + (n-1)] = A; // Set [n-1, n-1] = 1
    matrix[(n-1) * n + (n-2)] = B; // Set [n-1, n-2] = 0.5

    // Set remains
    for (int coluna = 1; coluna < (n - 1); coluna ++){
        matrix[coluna * n + coluna] = A;
        matrix[coluna * n + (coluna - 1)] = B;
        matrix[coluna * n + (coluna + 1)] = B;
    }

    displayMatrix(&matrix[0], n, n);

    gsl_matrix_view m = gsl_matrix_view_array(matrix, n, n);
    gsl_vector *eval = gsl_vector_alloc(n);
    gsl_matrix *evec = gsl_matrix_alloc(n, n);

    gsl_eigen_symmv_workspace * w = gsl_eigen_symmv_alloc(n);
    gsl_eigen_symmv(&m.matrix, eval, evec, w);
    gsl_eigen_symmv_free(w);
    gsl_eigen_symmv_sort(eval, evec, GSL_EIGEN_SORT_ABS_ASC);

    // gsl_eigen_symm_workspace * w = gsl_eigen_symm_alloc(n);
    // gsl_eigen_symm(&m.matrix, eval, w);
    // gsl_eigen_symm_free(w);
    // gsl_eigen_symm_sort(eval, GSL_EIGEN_SORT_ABS_ASC);

    printf("autovalor = \n\n");
    for (int i = 0; i < n; i++) {
        double eval_i = gsl_vector_get (eval, i);
        printf (" %6.2f\n", eval_i);
    }
    printf("\n");

    printf("autovetor = \n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf (" %6.2f", gsl_matrix_get (evec, i, j));
        }
        printf("\n");
    }
    printf("\n");

    gsl_vector_free (eval);
    gsl_matrix_free (evec);

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
