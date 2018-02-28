#ifndef _LIST_H
#define _LIST_H
#include "types.h"

struct Node;
typedef struct Node List;
typedef struct Node Position;

List* creatList();
int isEmpty(List *l);
int isLast(List *l, Position* p);
Position* find(ElementType x, List *l);
Position* findPrevious(ElementType x, List *l);
void insert(List *l,ElementType x,Position* p);
void append(List *l,ElementType x);
void delect(List *l,ElementType x);
void delectList(List *l);
void printlist(List *l);
void printLots(List *l, List *p);
#endif