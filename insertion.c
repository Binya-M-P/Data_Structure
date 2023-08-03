#include<stdio.h>
void insertatbegining();
void insertatend();
void insertafteravalue();
void insertbeforeavalue();
void deletefrombeginning();
void deleteanelement();
void deletefromend();
void display();
int val,x;
struct node
{
    int data;
    struct node *add;
}*head=NULL,*newnode,*t,*prev;
int main()
{
    int c;

    do
    {
        printf("\n*********MENU*********\n1.Insert at beginning\n2.insert at end\n3.insert befor a value\n4.insert after a value");
        printf("\n5.Delete from beginning\n6.Delete a perticular element\n7.Delete from end\n8.Display\n9.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
        {
            insertatbegining();
            break;
        }
        case 2:
        {
            insertatend();
            break;
        }
        case 3:
        {
            insertbeforeavalue();
            break;
        }
        case 4:
        {
            insertafteravalue();
            break;
        }
        case 5:
        {
            deletefrombeginning();
            break;
        }
        case 6:
        {
            deleteanelement();
            break;
        }
        case 7:
        {
            deletefromend();
            break;
        }
        case 8:
        {
            display();
            break;
        }
        }
    }while(c!=9);
}
void insertatbegining()
{
    newnode=(struct node *)malloc(sizeof(struct node));
    printf("Enter data you want to insert : ");
    scanf("%d",&val);
    newnode->data=val;
    if(head==NULL)
    {
        head=newnode;
        newnode->add=NULL;
        printf("\nInserted successfully.....\n");
    }
    else
    {
        newnode->add=head;
        head=newnode;
        printf("\nInserted successfully.....\n");
    }
}
void insertatend()
{
    printf("Enter data you want to insert : ");
    scanf("%d",&val);
    newnode=(struct node *)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->add=NULL;
    if(head==NULL)
    {
        head=newnode;
        printf("\nInserted successfully.....\n");
    }
    else
    {
        t=head;
        while(t->add!=NULL)
        {
            t=t->add;
        }
        t->add=newnode;
        printf("\nInserted successfully.....\n");
    }
}
void insertafteravalue()
{
    int p;
    if(head==NULL)
    {
        printf("The list is empty ....");
    }
    else
    {
        printf("Enter location: ");
        scanf("%d",&p);
        newnode=(struct node *)malloc(sizeof(struct node));
        printf("Enter data you want to insert : ");
        scanf("%d",&val);
        newnode->data=val;
        int f=0;
        t=head;
        while(t!=NULL)
        {
            if(t->data==p)
            {
                newnode->add=t->add;
                t->add=newnode;
                f=1;
                printf("\nInserted successfully.....\n");
                break;
            }
            t=t->add;
        }
        if(f==0)
        {
            printf("The item not founded .....");
        }
    }
}
void insertbeforeavalue()
{
    int p,f=0;
    if(head==NULL)
    {
        printf("The list is empty ....");
    }
    else
    {
        printf("Enter the location: ");
        scanf("%d",&p);
        printf("Enter data you want to insert : ");
        scanf("%d",&val);
        newnode=(struct node *)malloc(sizeof(struct node));
        newnode->data=val;
        t=head;
        prev=head;
        while(t!=NULL)
        {
            f=1;
            if(t->data==p)
            {
                if(prev->data==p)
                {
                    newnode->add=head;
                    head=newnode;
                    break;
                }
                newnode->add=prev->add;
                prev->add=newnode;

                printf("\nInserted successfully.....\n");
                break;
            }
            prev=t;
            t=t->add;
        }
        if(f==0)
        {
            printf("\nThe element is not founded...\n");
        }
    }
}
void deletefrombeginning()
{
    if(head==NULL)
    {
        printf("\nlinked list is empty....\n");
    }
    else
    {
        head=head->add;
        printf("\nDeleted successfully.....\n");
    }
}
void deleteanelement()
{
    int val;
    printf("Enter the element which you want to delete : ");
    scanf("%d",&val);
    if(head==NULL)
    {
        printf("\nThe list is empty...\n");
    }

    else if(head->data==val)
    {
        t=head;
        head=head->add;
        free(t);
        printf("\nDeleted successfully.....\n");
    }
    else
    {
        t=head;
        prev=head;
        while(t!=NULL)
        {

            if(t->data==val)
            {

                    prev->add=t->add;
                    free(t);
                    printf("\nDeleted successfully.....\n");
                break;
            }
            prev=t;
            t=t->add;
        }
        if(t==NULL)
        {
            printf("\nThe element is not founded.\n");
        }
    }
}
void deletefromend()
{
    if(head==NULL)
    {
        printf("\nThe list is empty ....\n");
    }
    else
    {
        t=head;
        prev=head;
        while(t->add!=NULL)
        {
            prev=t;
            t=t->add;
        }
        if(prev==head)
        {
            t=head;
            head=head->add;
            free(t);
            printf("\nDeleted successfully.....\n");
        }
        else
        {
            prev->add=NULL;
            free(t);
            printf("\nDeleted successfully.....\n");
        }
    }
}
void display()
{
    if(head==NULL)
    {
        printf("List is empty...");
    }
    else{
        printf("\n\nElements in linked list : \n");
        newnode=head;
        while(newnode->add!=NULL)
        {
            printf("%d-->",newnode->data);
            newnode=newnode->add;
        }
        printf("%d-->NULL\n",newnode->data);
    }
}
