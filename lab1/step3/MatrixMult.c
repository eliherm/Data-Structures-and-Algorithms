// MATRIXMULT.C  [060421]
// Code provided for Lab 1, ELEC278.
// This code contains a number of errors - both syntax and logic.


// The following two lines allow a shorthand way of defining a 3x3
// array of integers.  The first line defines the symbol SIZE to be
// identical to 3, and the second line says that mnt is a shorthand
// way of declaring a two-dimensional array.  This means that instead
// of writing
//     int TwoDimArray[3][3];
// you can write
//     mnt TwoDimArray;
// and have the same effect.

#include <stdio.h>

#define SIZE 3
typedef int mtx[SIZE][SIZE];

void matrixMult(mtx a, mtx b, mtx result)
// matrix multiplication. result = a * b
{
	int i,j,k;
	// initialize result to all zeros
	for (i=0;i<SIZE;i++)
		for (j=0;j<SIZE;j++)
			result[i][j]=0;

	// multiplication

	for (i=0;i<SIZE;i++) {
        for (j=0;j<SIZE;j++) {
            for (k=0;k<SIZE;k++) {
                result[i][j] += a[i][k]*b[k][j];
            }
        }
    }
}// matrixMult()


void printMatrix(mtx m)
// Display contents of matrix on screen
{
	int i, j;
	for (i=0; i<SIZE; i++){
		for (j=0; j<SIZE; j++){
			printf("%4d ",m[i][j]);
			}
		printf("\n");
		}
}//printMatrix()


int main()
{
	mtx a,b,c;
	// initialize contents of arrays a and b
	a[0][0]=1, a[0][1]=2, a[0][2]=1;
	a[1][0]=0, a[1][1]=2, a[1][2]=6;
	a[2][0]=1, a[2][1]=2, a[2][2]=1;
	b[0][0]=1, b[0][1]=3, b[0][2]=6;
	b[1][0]=1, b[1][1]=1, b[1][2]=7;
	b[2][0]=5, b[2][1]=1, b[2][2]=2;
	matrixMult(a,b,c);
	printMatrix(c);
	return 0;
}//main()
