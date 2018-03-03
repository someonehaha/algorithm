#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"

int main(int argc, char * argv[])
{
	List *l1,*l2;
	int i;
	l1 = creatList();
	l2 = creatList();
	if(l1 == NULL || l2 == NULL){
		printf(" creat list error! \r\n");
		exit(0);
	}
	
	if(strcmp(argv[1], "printlist")==0)
	{
		srand((unsigned) time(NULL));
		for(i=0;i<10;i++){
			append(l1, rand()%100);
		}
		printlist(l1);	
	}
	else if(strcmp(argv[1],"printlots")==0)
	{
		for(i=0;i<10;i++){
			append(l1,i);
			append(l2, 2*i+1);
		}
		printf("l1: \r\n");
		printlist(l1);
		printf("l2: \r\n");
		printlist(l2);
		printLots(l1,l2);	
	}
	else if(strcmp(argv[1],"unionset")==0)
	{
		for(i=0;i<10;i++){
			append(l1,i);
			append(l2,i+5);
		}
		printf("l1: \r\n");
		printlist(l1);
		printf("l2: \r\n");
		printlist(l2);
		List * l=unionSet(l1,l2);
		if(l!=NULL){
			printf("l1 ∪ l2:\r\n");
			printlist(l);
		}		
	}
	else if(strcmp(argv[1],"intersect")==0)
	{
		for(i=0;i<10;i++){
			append(l1,i);
			append(l2,i+5);
		}
		printf("l1: \r\n");
		printlist(l1);
		printf("l2: \r\n");
		printlist(l2);
		List * l=intersect(l1,l2);
		if(l!=NULL){
			printf("l1 n l2:\r\n");
			printlist(l);
		}		
	}
	else {
		printf("invaild arguments!\r\n");
	}
	
	return 0;
}


