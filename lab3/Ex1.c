#include <stdio.h>

int i;
int j;
int main() {

printf("enter number: ");
scanf("%d", &i);

int array[i];

for(j=0; j<i; j++)
        scanf("%d", &array[j]);

for(j=0;j<i;j++){
        printf("%d ", array[j]);
        printf("%d\n ", &array[j]);
}
int size = sizeof array/ sizeof *array;

printf("\nlength: %d \n", size);

int g = array[0];
for (j=0;j<i;j++){
        int p = array[j];
        if (p<g){
                g=p;}
}
printf("smallest: %d ", g);

return 0;
}
