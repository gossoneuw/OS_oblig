#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct PageFrame{
     int Id; /* Page ID */
     int ArrivalTime; /* Time that the page arrives */
     int LastRefTime; /* the Last time that the page was refered in the past */
     int Rbit; /* Referenced(R) bit */
     int Mbit; /* Modified(M) bit */
};
struct PageFrame page[100];
void first_in_first_out(int pages){
	int i;
	int first_in = (i+1);
	for (i=0; i<pages; i++){
		if (page[i].ArrivalTime < page[first_in].ArrivalTime){
			first_in = i;
	}}


	printf("Page selected: Page %d, Loaded at time %d, Last refered at time %d, Rbit %d, Mbit %d.\n", page[first_in].Id, page[first_in].ArrivalTime, page[first_in].LastRefTime, page[first_in].Rbit, page[first_in].Mbit);
}

void least_recently_used(int pages){
  /* Your code for LRU algorithm here */
	int i;
	int least = i+1;
	for(i=0; i<pages; i++){
		if ((page[i].LastRefTime - page[i].ArrivalTime) < (page[least].LastRefTime - page[least].ArrivalTime)){
			least = i;
	}}
	
	printf("Page selected: Page %d, Loaded at time %d, Last refered at time %d, Rbit %d, Mbit %d.\n", page[least].Id, page[least].ArrivalTime, page[least].LastRefTime, page[least].Rbit, page[least].Mbit);

}

void second_chance(int pages){
  /* Your code for Second Chance algorithm here */
	int i, u;
	int second = 0;
	for (i=0; i < pages; i++){
		if(page[i].Rbit == 0){
			second = i;
	for(u=0; u < pages; u++){
		if(page[u].ArrivalTime < page[second].ArrivalTime && page[u].Rbit == 0){
			second = u;
	}}}}

	printf("Page selected: Page %d, Loaded at time %d, Last refered at time %d, Rbit %d, Mbit %d.\n", page[second].Id, page[second].ArrivalTime, page[second].LastRefTime, page[second].Rbit, page[second].Mbit);
}

int main(){
   
     FILE *pFile= fopen("Testcase0.txt", "r");
     if (pFile == NULL) { 
        printf("Error! Could not open file\n"); 
        exit(-1);
    } 
    int i = 0;
    printf("Page\tArrival\tLastRef\tRbit\tMbit\n");
    while (fscanf(pFile, "%d%d%d%d%d", &page[i].Id, &page[i].ArrivalTime, &page[i].LastRefTime, &page[i].Rbit, &page[i].Mbit) != EOF){ 
        printf("%d\t%d\t%d\t%d\t%d\n", page[i].Id, page[i].ArrivalTime, page[i].LastRefTime, page[i].Rbit, page[i].Mbit);       
        i++;  
     }

    /* Run page replacement algorithms */
  printf("First-in-First-out...\n");
  first_in_first_out(i);

  printf("Least-Recently-Used...\n");
  least_recently_used(i);


  printf("Second-Chance...\n");
  second_chance(i);


  return 0;
}
