#include<stdio.h>
struct node
{
    int data;
    struct node *next;
}*temp;
int main()
{
    int c;
    do
    {
        printf("\n1.at beginning\n2.a perticular element\n3.end\n4.display\n5.exit\nEnter your choice : ");
        scanf("%d",&c);
    }while(c!=0);
}
atbeginning()
{
    if(head==NULL)
    {
        print("linked list is empty....");
    }
    else
    {
        head=head->temp;
    }
}
anelement()
{
    if(head==NULL)
    {
        printf("The list is empty...");
    }
    else
    {
        temp=head;
        while(temp!=NULL)
        {
            if()
        }
    }
}

