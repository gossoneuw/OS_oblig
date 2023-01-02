#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

int balance = 1000;

void *Deposit(void *deposit_ptr){
	int *deposit = (int *)deposit_ptr;
	balance += *deposit;
	printf("depositing %d kr\n", *deposit);
	printf("deposit completed\n");
	printf("new balance: %d\n", balance);
	return NULL;
}
void *Withdraw(void *withdraw_ptr){
	int *withdraw = (int *)withdraw_ptr;
	balance -= *withdraw;
	printf("withdrawing %d kr\n", *withdraw);
	printf("withdraw completed\n");
	printf("new balance: %d\n", balance);
	return NULL;
}


int main(){
	printf("inital value: Balance= %d\n", balance);
	int withdraw = 20;
	int deposit;
	pthread_t thread1;
        pthread_t thread2;

	printf("how much do you want to deposit?\n");
	
	scanf("%d", &deposit);
	pthread_create(&thread1, NULL, (void*)Deposit, &deposit);
	pthread_join(thread1, NULL);


	printf("how much do you want to withdraw?\n");
	scanf("%d", &withdraw);
	pthread_create(&thread2, NULL, (void*)Withdraw, &withdraw);
	pthread_join(thread2, NULL);

	pthread_exit(NULL);
	return 0;
} 
