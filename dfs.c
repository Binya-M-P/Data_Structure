#include<stdio.h>
int main()
{
    int v,i,j,k,g[20][20],visited[20],top=-1,f,m,visit[20];
    printf("Enter the number of vertices : ");
    scanf("%d",&v);
    printf("Enter the graph in adjacency matrix form : ");
    for(i=0;i<v;i++)
    {
        for(j=0;j<v;j++)
        {
            scanf("%d",&g[i][j]);
        }
    }
    printf("Enter the starting vertex : ");
    scanf("%d",&i);
    top=top+1;
    visited[top]=i;

    visit[0]=i;
    m=1;
    printf("\nDepth first traversal for the graph : %d \t",visited[0]);
    //i=0;
    j=0;
    while(top!=-1)
    {
        if(g[i][j]==1)
        {
            f=0;
            for(k=0;k<m;k++)
            {
                if(visit[k]==j)
                {
                    f=1;
                    break;
                }

            }
            if(f==0)
            {

                top=top+1;
                visited[top]=j;
                visit[m]=j;
                m=m+1;
                printf("%d\t",visited[top]);

                i=j;
                j=-1;
            }

        }
        j=j+1;
        if(j==v)
        {
            top=top-1;
            i=visited[top];
            j=0;

        }

    }

}
