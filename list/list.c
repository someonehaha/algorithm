#include <stdlib.h>
#include "types.h"
#include "list.h"


struct Node{
	ElementType element;
	Position* next;
};

List* creatList(void)
{
	List *header = malloc(sizeof(struct Node));
	if(header == NULL){
		printf("malloc error\r\n");
		return NULL;
	}
	header -> element =0;
	header -> next = NULL;
	return header;
}

int isEmpty(List *l)
{
	return l->next == NULL;
}

int isLast(List *l, Position* p)
{
	return p->next==NULL;
}

Position* find(ElementType x, List *l)
{
	Position *p;
	p = l->next;
	while(p!= NULL && p->element != x){
		p = p->next;
	}	
	return p;	
}

Position* findPrevious(ElementType x, List *l)
{
	Position *p = l;
	while(p->next != NULL && p->next->element != x){
		p= p->next;
	}
	return p;
}

void insert(List *l,ElementType x,Position* p)
{
	Position* temp = malloc(sizeof(struct Node));
	if(temp == NULL){
		printf("malloc error");
		return;
	}
	temp->element = x;
	temp-> next = p->next;	
	p->next = temp;
}

void append(List *l,ElementType x)
{
	Position* p, *temp;
	p = l;
	while(!isLast(l,p)){
		p = p->next;
	}
	temp= malloc(sizeof(struct Node));
	if(temp == NULL){
		printf("malloc error");
		return ;
	}
	temp->element = x;
	temp->next = NULL;
	p->next = temp;
}

void delect(List *l,ElementType x)
{
	Position* p, *temp;
	p = findPrevious(x,l);
	if(!isLast(l,p)){
		temp = p->next;
		p->next = temp->next;
		free(temp);	
	}
}

void delectList(List *l)
{
	Position* p, *temp;
	p=l->next;
	l->next =NULL;
	while(p!=NULL){
		temp = p->next;
		free(p);
		p =temp;
	}
	
}

void printlist(List *l)
{
	Position* p;
	p = l->next;
	while(p != NULL ){
		printf("  %d", p->element);
		p = p->next;
	}
	printf("\r\n");
}

void printLots(List *l, List *p)
{
	Position *p1,*p2;
	int counter =1;
	
	p1 = l->next;
	p2 = p->next;
	
	while(p2 != NULL && p1 != NULL){
		if(p2->element == counter++){
			printf("  %d",p1->element);
			p2 = p2->next;		
		}
		p1=p1->next;
	}
	printf("\r\n");
}

/*排序表L1,L2, 求L1∪ L2*/

List * unionSet(List *l1,List *l2)
{
	List * result=creatList();
	if(result ==NULL){
		printf("creatList fail\r\n");
	}
	//Position* result_p ;
	//result->next = result_p;
	Position* l1_p = l1->next;
	Position* l2_p = l2->next;
	while(l1_p != NULL && l2_p !=NULL){
		
		//result_p = malloc(sizeof(struct Node));
		if(l1_p->element < l2_p->element){		
			//result_p->element = l1_p->element;
			//result_p = result_p->next;
			append(result,l1_p->element);
			l1_p = l1_p->next;		
		}else if(l1_p->element == l2_p->element){
			//result_p->element = l1_p->element;
			//result_p =  result_p->next;
			append(result,l1_p->element);
			l1_p = l1_p->next;
			l2_p = l2_p->next;		
		}else if(l1_p->element > l2_p->element){
			//result_p ->element = l2_p->element;
			//result_p = result_p->next;
			append(result,l2_p->element);
			l2_p = l2_p->next;		
		}
			
	}
	
	while(l1_p != NULL){
		//result_p = malloc(sizeof(struct Node));
		//result_p -> element = l1_p->element;
		//result_p = result_p->next;
		append(result,l1_p->element);
		l1_p = l1_p->next;
	}
	while(l2_p != NULL){
		//result_p = malloc(sizeof(struct Node));
		//result_p -> element = l2_p->element;
		//result_p = result_p->next;
		append(result,l2_p->element);
		l2_p = l2_p->next;
	}
	
	return result;
	
}

/*排序表L1,L2 求L1 ∩ L2*/
List *intersect(List *l1, List *l2)
{
	List * result=creatList();
	if(result ==NULL){
		printf("creatList fail\r\n");
	}
	
	Position* l1_p = l1->next;
	Position* l2_p = l2->next;
	while(l1_p != NULL && l2_p !=NULL){
		
		if(l1_p->element < l2_p->element){		
			l1_p = l1_p->next;		
		}else if(l1_p->element == l2_p->element){		
			append(result,l1_p->element);
			l1_p = l1_p->next;
			l2_p = l2_p->next;		
		}else if(l1_p->element > l2_p->element){
			l2_p = l2_p->next;		
		}
			
	}
	
	return result;
	
}

