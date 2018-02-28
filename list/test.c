#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "list.h"


void main(int argc, char * argv[])
{
	List *l,*p;
	int i;
	l = creatList();
	p = creatList();
	if(l == NULL || p == NULL){
		printf(" creat list error! \r\n");
		exit(0);
	}
	
	if(strcmp(argv[1], "printlist")==0)
	{
		srand((unsigned) time(NULL));
		for(i=0;i<10;i++){
			append(l, rand()%100);
		}
		printlist(l);	
	}else if(strcmp(argv[1],"printlots")==0)
	{
		for(i=0;i<10;i++){
			append(l,i);
			append(p, 2*i+1);
		}
		printlist(l);
		printlist(p);
		printLots(l,p);
		
	}
	else {
		printf("invaild arguments!\r\n");
	}
	
}
