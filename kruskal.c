#include<stdio.h>
int i,j,v,a[10][10];
int main()
{

    printf("Enter the number of verices : ");
    scanf("%d",&v);
    printf("Enter the adacency matrix : ");
    for(i=1;i<=v;i++)
    {
        for(j=1;j<=v;j++)
        {
            scanf("%d",&a[i][j]);
            if(a[i][j]==0)
            {
                a[i][j]=999;
            }
        }
    }
    while
}
