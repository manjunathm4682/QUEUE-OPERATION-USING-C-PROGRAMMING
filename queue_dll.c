#include<stdio.h>
#include<stdlib.h>
#define ele 5
int top=-1;

typedef struct que
{
struct que *prev;
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

	top++;				//to monitor
queue *new,*last;
new=malloc(sizeof(queue));
printf("enter the number\n");
scanf("%d",&new->num);
new->prev=0;
new->next=0;

if(*ptr==0)
	*ptr=new;
else					//add_end method using DLL
{
	last=*ptr;
	while(last->next)
		last=last->next;
	last->next=new;
	new->prev=last;
}
}

void dequeue(queue **ptr)
{
	if(top<=-1 || *ptr==0)
	{
	printf("queue underflow\n");
	return;
	}

	queue *del;
	del=*ptr;
	printf("the num %d is deleted\n",del->num);
	if(del->next !=0)
		del->next->prev=0;

	*ptr=del->next;
	free(del);
	top--;				//to monitor
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
