#include <stdio.h>
#include <stdlib.h>
int j = 1;
int main () {
	FILE* matrixA;
	matrixA = fopen("Input.dat","r");
	int Array[j];

	for (int i = 0; i < j; i++) {
		fscanf(matrixA, "%d", Array[i]);
		printf("%d", Array[i]);
	}
	fclose(matrixA);
	return 0;
}

