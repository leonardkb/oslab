//
//  main.c
//  worst fit
//
//  Created by leonard kb on 08/06/2023.
//

#include<stdio.h>

void sort(int h, int holes[10])
{
    int swap;
    for(int i=0;i<h-1;i++)
    {
        for(int j=0;j<h-i-1;j++)
        {
            if(holes[j]<holes[j+1])
            {
                swap=holes[j];
                holes[j]=holes[j+1];
                holes[j+1]=swap;
            }
        }
    }
}

int main()
{
    int h,p,holes[10],process[10],actual[10],parallel[10],i,j,k,flag=0;
    printf("enter the no of holes");
    scanf("%d",&h);
    for(i=0;i<h;i++)
    {
        printf("enter the hole size h%d",i+1);
        scanf("%d",&holes[i]);
        actual[i]=holes[i];
        parallel[i]=holes[i];
    }
    printf("enter the no of process");
    scanf("%d",&p);
    for(i=0;i<p;i++)
    {
        printf("enter the process size p%d",i+1);
        scanf("%d",&process[i]);
    }
    printf("\nprocess\tpsize\tholes\n");
    for(i=0;i<p;i++)
    {
        flag=0;
        sort(h,holes);
        for(j=0;j<h;j++)
        {
            if(holes[j]>=process[i])
            {
                for(k=0;k<h;k++)
                {
                    if(parallel[k]==holes[j])
                    {
                        holes[j]=holes[j]-process[i];
                        parallel[k]=parallel[k]-process[i];
                        printf("\n%d\t%d\t%d\n",i+1,process[i],j+1);
                        flag=1;
                        break;
                    }
                }
                break;
            }
        }
        if(flag==0)
        {
            printf("\n%d\t%d\tnot allocated",i+1,process[i]);
        }
    }
    printf("available spaces");
    printf("\nholes\tactual\tavailable\n");
    for(i=0;i<h;i++)
    {
        printf("\n%d\t%d\t%d",i+1,actual[i],parallel[i]);
    }
    return 0;
}

