#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>


void *PrintMessage1(){
	printf("Hello, the world is round and this is message 1.");
	printf("\n");
}
void *PrintMessage2(){
	printf("Hei, redbull gives you wings and this is message 2.");
	printf("\n");
}
int main(int argc, char *argv[]){
	int t1, t2;
	pthread_t thread1, thread2;
	t1 = pthread_create(&thread1,NULL, PrintMessage1, (void *)NULL);
	t2 = pthread_create(&thread2,NULL, PrintMessage2, (void *)NULL);
	pthread_join(thread1, NULL);
	printf("this is main\n");
	pthread_join(thread2, NULL);
	pthread_exit(NULL);
	return 0;
}
