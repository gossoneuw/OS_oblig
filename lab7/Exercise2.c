#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>

pthread_mutex_t mutex;
pthread_cond_t generic_condition;
int test_var;

void* print_Halden() {
	int i;
	for( i=0; i<5; ++i) {
		pthread_mutex_lock(&mutex);
		while(test_var == 0){
			pthread_cond_wait(&generic_condition, &mutex);
		}
		printf("Halden\n");
		pthread_cond_signal(&generic_condition);
		test_var = 0;
		pthread_mutex_unlock(&mutex);
		usleep(1);
	}
}

void* print_Fredrikstad() {
	int i;
        for( i=0; i<5; ++i) {
		pthread_mutex_lock(&mutex);
		while(test_var == 1){
                        pthread_cond_wait(&generic_condition, &mutex);
                }
		printf("Fredrikstad\n");
		pthread_cond_signal(&generic_condition);
		test_var = 1;
                pthread_mutex_unlock(&mutex);
		usleep(1);
        }
}

int main(int argc, char** argv) {
	int test_var = 0;

	pthread_t t1, t2;

	pthread_create(&t1, NULL, print_Halden, NULL);
	pthread_create(&t2, NULL, print_Fredrikstad, NULL);

	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	printf("Ostfold University College!\n");
	return 0;
}

