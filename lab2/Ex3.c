#include <stdio.h>
#include <math.h>

int main() {
int i,j,n,x;

printf("lines ");
scanf("%d", &n);
for(i = 0; i <= n; i++) {
	for (j = 0; j <= i; j++) {
		if(j == 0 || i == 0)
			x = 1;
		else
			x = x * (i-j+1)/j;
		printf("%d ", x);
	}
	printf("\n");
}
return 0;
}
