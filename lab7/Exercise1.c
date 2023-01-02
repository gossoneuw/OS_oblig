#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int count = 0; 
pthread_mutex_t mutex; 

void* Increase(void) { 
	int i; 
	for(i=0; i<1e8; ++i) {
	pthread_mutex_lock(&mutex);
        count++;
	pthread_mutex_unlock(&mutex);
	}
}
void* Decrease(void) {  
	int i;
	for(i=0; i<1e8; ++i){
	pthread_mutex_lock(&mutex);
	count--;
	pthread_mutex_unlock(&mutex);
	}

}
int main() { 
    pthread_t thread1, thread2; 
    

    
    pthread_create(&thread1, NULL, (void*)Increase, NULL);
    pthread_create(&thread2, NULL, (void*)Decrease, NULL); 
    pthread_join(thread1, NULL); 
    pthread_join(thread2, NULL); 
  
    printf("Count is %d\n", count); 
   
    return 0; 
}
