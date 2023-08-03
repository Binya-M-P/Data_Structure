#include<stdio.h>
int main()
{
    int i,j,a[10],b[10],c[20],n1,n2,n,t;
    printf("Enter the number of elements in first array : ");
    scanf("%d",&n1);
    printf("Enter the elements in the first array : ");
    for(i=0;i<n1;i++)
    {
        scanf("%d",&a[i]);
    }
    printf("Enter the number of elements in second array : ");
    scanf("%d",&n2);
    printf("Enter the elements in the second array : ");
    for(i=0;i<n2;i++)
    {
        scanf("%d",&b[i]);
    }
    n=n1+n2;
    for(i=0;i<n1;i++)
    {
        c[i]=a[i];
    }
    j=0;
    for(i=n1;i<n;i++)
    {
        c[i]=b[j];
        j++;
    }
    for(i=0;i<n;i++)
    {
        for(j=i+1;j<n;j++)
        {
            if(c[j]<=c[i])
            {
                t=c[j];
                c[j]=c[i];
                c[i]=t;
            }
        }
    }
    printf("After merging :\n");
    for(i=0;i<n;i++)
    {
        printf("%d  ",c[i]);
    }
}
