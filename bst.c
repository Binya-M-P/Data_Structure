#include<stdio.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
}*nn,*temp,*root=NULL,*prev;
int c,val,f;
int main()
{
    do{
        printf("1.root2.node3.search4.delete5.inorder :");
        scanf("%d",&c);
        switch(c)
        {
        case 1:
        {
            iroot();
            break;
        }
        case 2:
        {
            insert();

            break;
        }
        case 3:
        {
            //iroot();
        }
        case 4:
        {
            //iroot();
        }case 5:
        {
            display(root);
            break;
        }case 6:
        {
            exit(0);
        }
        }
    }while(c!=6);
}
int iroot()
{
    nn=(struct node*)malloc(sizeof(struct node));
    root=nn;
    printf("Enter the value :");
    scanf("%d",&val);
    nn->data=val;
    nn->left=NULL;
    nn->right=NULL;
}
int insert()
{

    nn=(struct node*)malloc(sizeof(struct node *));
    temp=root;
    printf("Enter the value :");
    scanf("%d",&val);
    nn->left=NULL;
    nn->right=NULL;
    nn->data=val;
    temp=root;
    while(temp!=NULL)
    {

        prev=temp;
        if(val>temp->data)
        {
            temp=temp->right;
            f=1;
        }
        if(val<temp->data)
        {
            temp=temp->left;
            f=0;
        }
        printf("Enter");
    }

    if(f==1)
    {
        prev->right=nn;
    }
    if(f==0)
    {
        prev->left=nn;
    }

}
int display(struct node *temp)
{
    if(temp!=NULL)
    {
        display(temp->left);
        printf("%d\t",temp->data);
        display(temp->right);
    }
}
