#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "message.h"

static const char* message[] = {
	"hi im here",
	"bye",
	"see you never",
	"this is a school section."
};

void print_message() {
	int index;
	srand(time(NULL));
	index = rand()%4;
	printf("linking multiple c files...\n");
	printf("%s\n", message[index]);
}
