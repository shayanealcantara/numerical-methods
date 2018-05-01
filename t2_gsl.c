#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <gsl/gsl_math.h>
#include <gsl/gsl_eigen.h>
#define A 1
#define B 0.5

void displayMatrix(double *, int, int, char[]);

int main(int argc, char *argv[]) {
    int n = 10;

    if (argc >= 2) {
        n = atoi(argv[1]); // get n specified by command line argument
    } else {
        printf("Using default value of n: %d\n", n);
    }

    // Create matrix
    double *matrix;
    unsigned long sizeOfMatrix= n * n * sizeof(double);
    matrix = malloc(sizeOfMatrix);

    // Initialize matrix with 0
    memset(matrix, 0, sizeOfMatrix);

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

    displayMatrix(matrix, n, n, "matrix");

    // Reference: https://www.gnu.org/software/gsl/doc/html/eigen.html
    // Set parameters used in GSL function
    gsl_matrix_view m = gsl_matrix_view_array(matrix, n, n);
    gsl_vector *autovalores = gsl_vector_alloc(n);
    gsl_matrix *autovetor = gsl_matrix_alloc(n, n);

    // If you want autovalores and autovetores
    gsl_eigen_symmv_workspace * w = gsl_eigen_symmv_alloc(n); // create workspace
    gsl_eigen_symmv(&m.matrix, autovalores, autovetor, w); // calculate
    gsl_eigen_symmv_free(w); // free workspace pointer
    gsl_eigen_symmv_sort(autovalores, autovetor, GSL_EIGEN_SORT_ABS_ASC); // sort autovalores and autovetor

    // If you only want autovalores
    // gsl_eigen_symm_workspace * w = gsl_eigen_symm_alloc(n); // create workspace
    // gsl_eigen_symm(&m.matrix, autovalores, w); // calculate
    // gsl_eigen_symm_free(w); // free workspace pointer
    // gsl_eigen_symm_sort(autovalores, GSL_EIGEN_SORT_ABS_ASC); // sort autovalores and autovetor

    printf("autovalores = \n\n");
    for (int i = 0; i < n; i++) {
        double autovalores_i = gsl_vector_get (autovalores, i);
        printf (" %6.2f\n", autovalores_i);
    }
    printf("\n");

    printf("autovetor = \n\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf (" %6.2f", gsl_matrix_get (autovetor, i, j));
        }
        printf("\n");
    }
    printf("\n");

    // free pointers
    gsl_vector_free (autovalores);
    gsl_matrix_free (autovetor);
    free(matrix);

    return 0;
}

void displayMatrix(double *matrix, int numberOfLines, int numberOfColumns, char label[]) {
    printf("%s = \n\n", label);
    for (int i = 0; i < numberOfLines; i++) {
        for (int j = 0; j < numberOfColumns; j++) {
            printf("%7.2f ", matrix[i * numberOfColumns + j]);
        }
        printf("\n");
    }
    printf("\n");
}
