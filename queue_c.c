#include<stdio.h>
#include<stdlib.h>
#define ele 5

int top=-1;
int a[ele];

void enqueue(void)
{
if(top>=ele-1)
{
printf("the queue overflow\n");
return;
}

top++;
printf("enter the number\n");
scanf("%d",&a[top]);

}

void dequeue(void)
{
if(top<=-1)
{
printf("the queue underflow\n");
return;
}

printf("%d is dequeued\n",a[0]);
for(int i=0;i<top;i++)
a[i]=a[i+1];

top--;

}

void display(void)
{
if(top<=-1)
{
printf("the queue is empty\n");
return;
}

printf("*****\n");
for(int i=0;i<=top;i++)
printf("%d\n",a[i]);
printf("*****\n");

}

void main()
{
int op;
while(1)
{
printf("Enter the option\n");
printf("1.enqueue 2.dequeue 3.display 4.exit\n");
scanf("%d",&op);
switch(op)
{
	case 1:enqueue();break;
	case 2:dequeue();break;
	case 3:display();break;
	case 4:exit(0);
	default:printf("wrong option entered\n");
}
}
}
