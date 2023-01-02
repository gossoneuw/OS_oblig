#include <stdio.h>
#include <math.h>


int f(int i)
{
	if (i <= 1)
		return i;
	return f(i-1) + f(i -2);
}

int main()
{
	int i = 0;
	for (i = 0; i<20; i ++)
		printf("%d ", f(i));
		getchar();
		return 0;
}

