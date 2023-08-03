#include<stdio.h>
void Insertatbeginning();
void Insertafteravalue();
void Insertatend();
void Deletefrombeginning();
void Deleteaparticularelement();
void Deletefromend();
void search();
void Display();
int val,k;
struct node
{
    int data;
    struct node *next;
    struct node *prev;
}*head,*temp,*nn;
int main()
{
    int c;
    do
    {
        printf("\n*********MENU*********\n1.Insertion at beginning\n2.Insertion after a value\n3.Insertion at end");
        printf("\n4.Deletion from beginning\n5.Delete a particular element\n6.Delete from end\n7.Search\n8.Display\n9.Exit\nEnter your choice : ");
        scanf("%d",&c);
        switch(c)
        {
            case 1:
            {
                Insertatbeginning();
                break;
            }
            case 2:
            {
                Insertafteravalue();
                break;
            }
            case 3:
            {
                Insertatend();
                break;
            }
            case 4:
            {
                Deletefrombeginning();
                break;
            }
            case 5:
            {
                Deleteaparticularelement();
                break;
            }
            case 6:
            {
                Deletefromend();
                break;
            }
            case 7:
            {
                search();
                break;
            }
            case 8:
            {
                Display();
                break;
            }
            case 9:
            {
                exit(0);
            }
            default:
            {
                printf("Invalid choice.....");
                break;
            }
        }
    }while(c!=9);
}
void Insertatbeginning()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&val);
    nn->data=val;
    nn->prev=NULL;
    if(head==NULL)
    {
        head=nn;
        nn->next=NULL;
    }
    else
    {
        nn->next=head;
        head->prev=nn;
        head=nn;
    }
}
void Insertafteravalue()
{
    printf("Enter the key : ");
    scanf("%d",&k);
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&val);
    nn->data=val;
    if(head==NULL)
    {
        printf("list is empty...so element not founded.");
        return 0;
    }
    temp=head;
    while(temp->data!=k)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            break;
        }
    }
    if(temp==NULL)
    {
        printf("\nThe element not founded ....\n");
        return 0;
    }
    if(temp->next==NULL)
    {
        nn->next=NULL;
        temp->next=nn;
        nn->prev=temp;
        return 0;
    }
    nn->next=temp->next;
    temp->next->prev=nn;
    temp->next=nn;
    nn->prev=temp;
}
void Insertatend()
{
    nn=(struct node *)malloc(sizeof(struct node));
    printf("Enter the value : ");
    scanf("%d",&val);
    nn->data=val;
    nn->next=NULL;
    if(head==NULL)
    {
        head=nn;
        nn->prev=NULL;
    }
    else
    {
        temp=head;
        while(temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next=nn;
        nn->prev=temp;
    }
}
void Deletefrombeginning()
{
    if(head==NULL)
    {
        printf("Linked list is empty.....");
    }
    else if(head->next==NULL)
    {
        temp=head;
        head=NULL;
        free(temp);
    }
    else
    {
        temp=head;
        head=head->next;
        head->prev=NULL;
        free(temp);
    }
}
void Deleteaparticularelement()
{
    printf("Enter the element which you want to delete : ");
    scanf("%d",&k);
    if(head==NULL)
    {
        printf("The list is empty ...so the element is not founded...\n");
        return 0;
    }
    temp=head;
    while(temp->data!=k)
    {
        temp=temp->next;
        if(temp==NULL)
        {
            printf("The element not founded...\n");
            return 0;
        }
    }
    if(temp->next==NULL && temp->prev==NULL)
    {
        head=NULL;
        free(temp);
        return 0;
    }
    if(temp->prev==NULL)
    {
        head=temp->next;
        temp->next->prev=NULL;
        free(temp);
        return 0;
    }
    if(temp->next==NULL)
    {
        temp->prev->next=NULL;
        free(temp);
    }
}
void Deletefromend()
{
    if(head==NULL)
    {
        printf("List is empty...\n");
        return 0;
    }
    temp=head;
    if(temp->next==NULL)
    {
        head=NULL;
        free(temp);
        return 0;
    }
    while(temp->next!=NULL)
    {
        temp=temp->next;
    }
    temp->prev->next=NULL;
    free(temp);
}
void Display()
{
    if(head==NULL)
    {
        printf("Linked list is empty....");
    }
    else
    {
        temp=head;
        printf("Linked list : ");
        while(temp->next!=NULL)
        {
            printf("%d->",temp->data);
            temp=temp->next;
        }
        printf("%d->NULL",temp->data);
    }
}
void search()
{
    printf("Enter the element : ");
    scanf("%d",&k);
    temp=head;
    while(temp!=NULL)
    {
        if(temp->data==k)
        {
            print("\nThe element is founded...\n");
            return;
        }
        temp=temp->next;
    }
    printf("\nThe element is not founded...\n");
}
