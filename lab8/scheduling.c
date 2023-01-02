#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct process{
  /* Values initialized for each process */
  int id;
  int arrivaltime;  /* Time process arrives and wishes to start */
  int runtime;      /* Time process requires to complete job */

  /* Values algorithm may use to track processes */
  int starttime;
  int endtime; 
};

struct process proc[100];

int read_file (char fileName[14]) {
    FILE *pFile;
    pFile = fopen(fileName, "r");

    if (pFile == NULL) { 
        printf("Error! Could not open file\n"); 
        exit(-1);
    } 
    int i = 0;
    while (fscanf(pFile, "%d%d%d", &proc[i].id, &proc[i].arrivaltime, &proc[i].runtime) != EOF) {
        proc[i].starttime = 0;
        proc[i].endtime = 0;
        i++;
    }
    fclose(pFile);
    return i;
}

void first_come_first_served (char argv[14]) {
    char readFileName[14]= "";
    strcat(readFileName, argv); 
  
    int numberOfProcesses = read_file(readFileName);
  
    char writeFileName[] = "FCFS";
    strcat(writeFileName, readFileName);

    FILE *FCFSfile;

    FCFSfile = fopen("FCFSfile.txt", "w");
    // YOUR CODE FOR FCFS HERE
	int i = 0;
	for( i = 0; i <numberOfProcesses; i++) {
		int endtime = proc[i].starttime + proc[i].runtime;
		

		printf("Process %d started at time %d and finished at time %d\n", proc[i].id, proc[i].starttime, endtime);
		fprintf(FCFSfile, "Process %d started at time %d and finished at time %d\n", proc[i].id, proc[i].starttime, endtime);
		if(proc[i+1].arrivaltime >= endtime){
			proc[i+1].starttime = proc[i+1].arrivaltime;
		}else{
			proc[i+1].starttime = endtime;
		}}
	

    fclose(FCFSfile);
}


void shortest_remaining_time (char argv[14]) {

    char readFileName[14]= "";
    strcat(readFileName, argv);    
  
    int numberOfProcesses = read_file(readFileName);
  
    char writeFileName[] = "STRN";
    strcat(writeFileName, readFileName);
    
    FILE *STRNfile; 

    STRNfile = fopen("STRNfile.txt", "w");
   // YOUR CODE FOR SRTN HERE
	int i = 0;
        for( i = 0; i <numberOfProcesses; i++) {
                int endtime = proc[i].arrivaltime + proc[i].runtime;
		if(proc[i].arrivaltime >= endtime){
                	proc[i].starttime = (proc[i].endtime - proc[i].runtime);
                }else{
                        proc[i].starttime = (proc[i].arrivaltime);

		}
		printf("Process %d started at time %d and finished at time %d\n", proc[i].id, proc[i].starttime, endtime);
		fprintf(STRNfile, "Process %d started at time %d and finished at time %d\n", proc[i].id, proc[i].starttime, endtime);
		}
    fclose(STRNfile);
}


int main(int argc, char *argv[]) {

    int i = 0;
    char readFileName0[14];

    
    // how the output is supposed to look
    // printf("Process %d started at time %d and finished at time %d\n", proc[i].id, proc[i].starttime, proc[i].endtime);
    printf("First come first served...\n");
    first_come_first_served(argv[1]);
    printf("Shortest remaining time next...\n");
    shortest_remaining_time(argv[1]);    

    return 0;
}
