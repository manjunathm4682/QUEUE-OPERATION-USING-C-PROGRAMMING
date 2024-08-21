#include<stdio.h>
#include<stdlib.h>
#define ele 5

int top=-1;

typedef struct que
{
	int num;
	struct que *next;
}queue;

void enqueue(queue **);
void dequeue(queue **);
void display(queue *);

int main()
{
int op;
queue *headptr=0;			//head pointer
while(1)
{
printf("Enter the option\n");
printf("1.enqueue 2.dequeue 3.display 4.exit\n");
scanf("%d",&op);
switch(op)
{
	case 1:enqueue(&headptr);break;
	case 2:dequeue(&headptr);break;
	case 3:display(headptr);break;
	case 4:exit(0);
	default:printf("wrong option entered\n");
}
}
}

void enqueue(queue **ptr)
{
if(top>=ele-1)
{
printf("queue overflow\n");
return;
}
queue *new,*last;
new=malloc(sizeof(queue));
printf("enter the number\n");
scanf("%d",&new->num);
new->next=0;

top++;				//to monitor queue size
if(*ptr==0)
*ptr=new;

else				//add_end method in SLL
{
	last=*ptr;
	while(last->next)
		last=last->next;
	last->next=new;
}
}

void dequeue(queue **ptr)	//everytime delete first node only
{
if(top<=-1 && *ptr==0)
{
printf("queue underflow\n");
return;
}
top--;				//to monitor queue size
queue *del=*ptr;
*ptr=del->next;
printf("the number %d is deleted\n",del->num);
free(del);
}

void display(queue *ptr)
{
if(top<=-1 || ptr==0)
{
printf("queue is empty\n");
return;
}

printf("*****\n");
while(ptr)
{
printf("%d\n",ptr->num);
ptr=ptr->next;
}
printf("*****\n");
}
