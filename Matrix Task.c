#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//#define ROWS 3
//#define COLS 3
int** insert_2d_array(int** array_2d,int rows,int cols);
int** create_2d_array(int rows, int cols);
void print_2d_array(int** array_2d, int rows, int cols);
void multiply_matrices(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) ;
int** create_2d_transposeMatrix(int **A,int rows, int cols);
void free_2D_array(int** array_2D,int rows);
int main()
{
	int baris_A,kolom_A;
    printf(" input ordo matriks baris :");scanf("%d",&baris_A);
    printf(" input ordo matriks kolom :");scanf("%d",&kolom_A);
    
    printf("_____ MATRIX A_____:\n");
    int** matriks_A = create_2d_array(baris_A, kolom_A);
    matriks_A = insert_2d_array(matriks_A,baris_A,kolom_A); 
    print_2d_array(matriks_A,baris_A,kolom_A); 
    
    int baris_B,kolom_B; 
     printf(" input ordo matriks baris :");scanf("%d",&baris_B);
     printf(" input ordo matriks kolom :");scanf("%d",&kolom_B);
    
    printf("____ MATRIX B____: \n");
    int** matriks_B = create_2d_array(baris_B,kolom_B);
    matriks_B = insert_2d_array(matriks_B,baris_B,kolom_B); 
    print_2d_array(matriks_B,baris_B,kolom_B);
    
    printf("_____PERKALIAN MATRIX____: \n");
	int** matriks_C  = create_2d_array(baris_A,kolom_B); 
	multiply_matrices(matriks_A,matriks_B,matriks_C,baris_A,kolom_A,kolom_B);
	print_2d_array(matriks_C,baris_A,kolom_B);

	//free_2d_array(matriks_C,kolom_A);
	//free_2d_array(matriks_B,kolom_B);
	//free_2d_array(matriks_A,kolom_A);
	return 0;
}
int** create_2d_array(int rows, int cols) {
	int i,j;
    // Alokasi memori untuk array 2 dimensi
    int** array_2d = (int**)malloc(rows * sizeof(int*));
    for (i = 0; i < rows; i++) {
        array_2d[i] = (int*)malloc(cols * sizeof(int));
    }
    return array_2d;
}
int** insert_2d_array(int** array_2d,int rows,int cols) {
	int i,j;
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("Value for Array:");scanf("%d",&array_2d[i][j]);
        }
        printf("Done\n");
    }
    return array_2d;
}
void print_2d_array(int** array_2d, int rows, int cols) {
	int i,j;
    // Menginput array 2 dimensi secara acak nilai
    printf("Display Array :\n");
    for (i = 0; i < rows; i++) {
        printf("|");
        for (j = 0; j < cols; j++) {
            printf("%d ", array_2d[i][j]);
        }
        printf("|");
        printf("\n");
    }
    printf("_\n");
}
void multiply_matrices(int **A, int **B, int **C, int rows_A, int cols_A, int cols_B) 
{
	int i,j,k;
    for (i = 0; i < rows_A; i++) {
        for (j = 0; j < cols_B; j++) {
            C[i][j] = 0; // Inisialisasi elemen matriks C menjadi 0 sebelum mengalikan

            for (k = 0; k < cols_A; k++) 
			{
                C[i][j] += A[i][k] * B[k][j]; // Melakukan perkalian dan penjumlahan
            }
        }
    }
}
int** create_2d_transposeMatrix(int **A,int rows, int cols) {
	int i,j;
    // Alokasi memori untuk array 2 dimensi
    int** array_2d_transposedMat = (int**)malloc(cols * sizeof(int*));
    for (i = 0; i < cols; i++) {
        array_2d_transposedMat[i] = (int*)malloc(rows * sizeof(int));
    }
    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            array_2d_transposedMat[j][i] = A[i][j];
        }
    }
	return array_2d_transposedMat;
}
void free_2D_array(int** array_2D,int rows)
{
	int i;
	for(i=0;i<rows;i++)
    {
      free(array_2D[i]);   
    }
    free(array_2D);
}
