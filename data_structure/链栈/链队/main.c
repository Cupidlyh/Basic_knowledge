//链队
#include <stdio.h>
#include <stdlib.h>
typedef struct qnode
{
    int data;
    struct qnode *next;
} qnode;
typedef struct
{
    qnode *front;
    qnode *rear;
} linkqueue;

int initqueue(linkqueue *q)
{
    q->front=q->rear=(qnode*)malloc(sizeof(qnode));
    q->rear->next=NULL;
    return 1;
}

int enqueue(linkqueue *q,int a)
{
    qnode *p=(qnode*)malloc(sizeof(qnode));
    p->data=a;
    p->next=NULL;
    q->rear->next=p;
    q->rear=p;
    return 1;
}

int dequeue(linkqueue *q)
{
    int i;
    if(q->front==q->rear)
        exit(0);
    qnode *p;
    p=q->front->next;
    i=p->data;
    q->front->next=p->next;
    free(p);
    return i;
}

int gethead(linkqueue q)
{
    if(q.front==q.rear)
        return 0;
    else
        return q.front->next->data;
}

int main()
{
    linkqueue q;
    int i,j;
    freopen("in.txt","r",stdin);
    initqueue(&q);
    printf("请输入想入链队的元素\n");
    for(i=0; i<5; i++)
    {
        scanf("%d",&j);
        enqueue(&q,j);
    }
    j=gethead(q);
    printf("链队队头元素是：%d\n",j);
    for(i=0; i<5; i++)
    {
        j=dequeue(&q);
        printf("%d ",j);
    }
    return 0;
}
