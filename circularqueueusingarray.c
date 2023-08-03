#include<stdio.h>
void enqueue();
void dequeue();
void display();
int a[10],front=-1,rear=-1,val,i;
int main()
{
    int c;
    do
    {
        printf("\n************\n1.Enqueue\n2.Dequeue\n3.Display\n4.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
            {
                enqueue();
                break;
            }
        case 2:
            {
                dequeue();
                break;
            }
        case 3:
            {
                display();
                break;
            }
        }
    }while(c!=4);
}
enqueue()
{
    printf("Enter the value : ");
    scanf("%d",&val);
    if((front==0 && rear==9) || rear==front-1)
    {
        printf("Queue Overflow...");
        return 0;
    }
    if(front==-1 && rear==-1)
    {
        a[0]=val;
        front=0;
        rear=0;
        return 0;
    }
    if(rear==9)
    {
        a[0]=val;
        rear=0;
    }
    else
    {
        rear=rear+1;
        a[rear]=val;
    }

}
dequeue()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue Underflow....");
        return 0;
    }
    if(front==rear)
    {
        front=-1;
        rear=-1;
        return 0;
    }
    if(front>rear && front==9)
    {
        front=0;
        return 0;
    }
    front=front+1;
}
display()
{
    if(front==-1 && rear==-1)
    {
        printf("Queue is empty ....");
    }
    else
    {
        printf("\nQueue : ");
        if(rear<front)
        {
            for(i=front;i!=rear;i++)
            {
                printf("%d\t",a[i]);
                if(i==9)
                {
                    i=-1;
                }
            }
            printf("%d",a[i]);
        }
        else
        {
            for(i=front;i<=rear;i++)
            {
                printf("%d\t",a[i]);
            }
        }
    }
}


