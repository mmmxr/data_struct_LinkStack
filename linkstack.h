#pragma once
#include <stdio.h>
#include <stddef.h>
#include <stdlib.h>

typedef char LinkStackType;

typedef struct LinkStack{
    LinkStackType data;
    struct LinkStack* next; 
}LinkStack;

void LinkStackInit(LinkStack** phead);

void LinkStackDestroy(LinkStack** phead);

void LinkStackPush(LinkStack** phead,LinkStackType value);

void LinkStackPop(LinkStack** phead);

int LinkStackTop(LinkStack* head,LinkStackType* value);
