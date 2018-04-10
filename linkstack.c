#include "linkstack.h"
#define TEST_HEADER printf("\n=======================%s===================\n",__FUNCTION__);
LinkStack* CreatNode(LinkStackType value)
{
    LinkStack* new_node=(LinkStack* )malloc(sizeof(LinkStack));
    new_node->data=value;
    new_node->next=NULL;
    return new_node;
}
void LinkStackInit(LinkStack** phead)
{
    if(phead==NULL)
    {
        return;//非法输入
    }
    *phead=NULL;
}

void LinkStackDestroy(LinkStack** phead)
{
    if(phead==NULL)
    {
        return;
    }
    LinkStack* cur=*phead;
    for(;cur!=NULL;cur=cur->next)
    {
        free(cur);
    }
    *phead=NULL;
}

void LinkStackPush(LinkStack** phead,LinkStackType value)
{
    if(phead==NULL)
    {
        return;//非法输入
    }
    LinkStack* new_node=CreatNode(value);
    new_node->next=*phead;
    *phead=new_node;
}
void LinkStackPop(LinkStack** phead)
{
    if(phead==NULL)
    {
        return;
    }
    if(*phead==NULL)
    {
        return;//空栈
    }
    LinkStack* to_delete=*phead;
    *phead=(*phead)->next;
    free(to_delete);
}


int LinkStackTop(LinkStack* head,LinkStackType* value)
{
    if(head==NULL)
    {
        return 0;
    }
    *value=head->data;
    return 1;
        
}
//////////////////////////////////////
//以下是测试函数 
//////////////////////////////////////
void LinkStackPrintChar(LinkStack* head,const char* msg)
{
    printf("%s\n",msg);
    LinkStack* cur=head;
    for(;cur!=NULL;cur=cur->next)
    {
        printf("[%c] ",cur->data);
    }
    printf("\n");
}
void TestInit()
{
    TEST_HEADER;
    LinkStack *linkstack;
    LinkStackInit(&linkstack);
    printf("head expect NULL,actual %p\n",linkstack);
}
void TestPush()
{   
    TEST_HEADER;
    LinkStack *linkstack;
    LinkStackInit(&linkstack);
    LinkStackPush(&linkstack,'a');
    LinkStackPush(&linkstack,'b');
    LinkStackPush(&linkstack,'c');
    LinkStackPush(&linkstack,'d');

    LinkStackPrintChar(linkstack,"入栈四个元素");
}
void TestPop()
{
    TEST_HEADER;
    LinkStack *linkstack;
    LinkStackInit(&linkstack);
    LinkStackPush(&linkstack,'a');
    LinkStackPush(&linkstack,'b');
    LinkStackPush(&linkstack,'c');
    LinkStackPush(&linkstack,'d');
    LinkStackPrintChar(linkstack,"入栈四个元素");
    LinkStackPop(&linkstack);
    LinkStackPrintChar(linkstack,"出栈一个元素");
    LinkStackPop(&linkstack);
    LinkStackPrintChar(linkstack,"出栈二个元素");
    LinkStackPop(&linkstack);
    LinkStackPrintChar(linkstack,"出栈三个元素");
    LinkStackPop(&linkstack);
    LinkStackPrintChar(linkstack,"出栈四个元素");
    LinkStackPop(&linkstack);
    LinkStackPrintChar(linkstack,"尝试对空栈出栈");
    
}
void TestTop()
{
    TEST_HEADER;
    LinkStack *linkstack;
    LinkStackType value;
    LinkStackInit(&linkstack);
    LinkStackPush(&linkstack,'a');
    LinkStackPush(&linkstack,'b');
    LinkStackPush(&linkstack,'c');
    LinkStackPush(&linkstack,'d');
    LinkStackPrintChar(linkstack,"入栈四个元素");
    int ret=LinkStackTop(linkstack,&value);
    printf("对栈取栈顶元素\n");
    printf("ret expect 1,actual %d\n",ret);
    printf("top expect d,actual %c\n",value);
    LinkStackInit(&linkstack);
    ret=LinkStackTop(linkstack,&value);
    printf("尝试对空栈取栈顶元素\n");
    printf("ret expect 0,actual %d\n",ret);
}
void TestDestroy()
{
    TEST_HEADER;
    LinkStack *linkstack;
    LinkStackInit(&linkstack);
    LinkStackPush(&linkstack,'a');
    LinkStackPush(&linkstack,'b');
    LinkStackPush(&linkstack,'c');
    LinkStackPush(&linkstack,'d');
    LinkStackPrintChar(linkstack,"入栈四个元素");
    LinkStackDestroy(&linkstack);
    LinkStackPrintChar(linkstack,"销毁栈");
}
int main()
{
    TestInit();
    TestPush();
    TestPop();
    TestTop();
    TestDestroy();
    return 0;
}
