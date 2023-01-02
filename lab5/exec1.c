#include <stdio.h> 

#include <unistd.h> 

  

int main() { 

execl("/bin/ls", "ls -l", NULL); 

//execl("/bin/cat", "cat -l", NULL); 

//execl("/bin/ps", "ps -l", NULL); 

//execl("/bin/pwd", "pwd -l", NULL); 

printf("this is message"); 

} 
