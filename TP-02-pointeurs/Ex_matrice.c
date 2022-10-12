#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

#define SIZE 5

void matrix_mult(int64_t matriceResultat[SIZE][SIZE], int64_t matrice1[SIZE][SIZE], int64_t matrice2[SIZE][SIZE]){
	 for (int i=0; i<SIZE; i++){
	 	for (int j=0; j<SIZE ; j++){
	 		matriceResultat[i][j]=0;
	 		for (int k=0; k<SIZE ; k++){
	 			matriceResultat[i][j] += matrice1[i][k] * matrice2[k][j];
	 		}
	 	}
	 }
}
	 
void matrix_print(int64_t matrice[SIZE][SIZE]){
	for (int k=0; k<SIZE; k++){
		printf("%li\t %li\t %li\t %li\t %li\n", matrice[k][0], matrice[k][1], matrice[k][2], matrice[k][3], matrice[k][4]);
	}
}


int main(void){
	//matrices en lignes + colonne
	int64_t matrice1[][SIZE]={{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5},{1,2,3,4,5}};
	int64_t matrice2[][SIZE]={{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10},{6,7,8,9,10}};
	int64_t matriceResultat[SIZE][SIZE];
	
	matrix_mult(matriceResultat,matrice1,matrice2);
	matrix_print(matriceResultat);
	
	return 0;
	}
