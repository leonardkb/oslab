//
//  main.c
//  sample
//
//  Created by leonard kb on 08/06/2023.
//
#include<stdio.h>
int main()
{
    int n,pgno[10],frames,frsize[10],hit=0,fault=0,i,j,k=0,flag=0;
    printf("enter the no of pages");
    scanf("%d",&n);
    printf("enter the page numbers");
    for(i=0;i<n;i++)
    {
        scanf("%d",&pgno[i]);
    }
    printf("enter the no of frames:\n");
    scanf("%d",&frames);
    for(i=0;i<frames;i++)
    {
        frsize[i]=-1;
    }
    printf("ref string \t Page frames\n");
    for(i=0;i<n;i++)
    {
        flag=0;
        for(j=0;j<frames;j++)
        {
            if(frsize[j]==pgno[i])
            {
                flag=1;
                hit++;
            }
        }
        if(flag==0)
        {
            frsize[k]=pgno[i];
            k=(k+1)%frames;
            fault++;
        }
        printf("%d\t\t",pgno[i]);
        for(j=0;j<frames;j++)
        {
            printf("%d\t",frsize[j]);
            
        }
        printf("\n");
    }
    printf("fault:%d",fault);
    printf("hit:%d",hit);
    return 0;
}
