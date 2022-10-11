#include <stdio.h>

void echangeContenu(int *A, int *B){
	int tmp=*A;
	*A=*B;
	*B=tmp;
}

int main(void){
	int A=5;
	int B=3;
	printf("A=5 et B=3\n");
	echangeContenu(&A,&B);
	printf("Et maintenant A=%d\n",A);
	printf("Et B=%d\n",B);
	return 0;
}	
