//
//  main.c
//  scan
//
//  Created by leonard kb on 09/06/2023.
//
#include<stdio.h>
int main()
{
    int req[10],request,seek=0,i,j,head,size,direction;
    printf("enter the no of requests");
    scanf("%d",&request);
    printf("enter the request:\n");
    for(i=0;i<request;i++)
    {
        scanf("%d",&req[i]);
    }
    printf("enter the initial head");
    scanf("%d",&head);
    
    printf("enter the total disk size:\n");
    scanf("%d",&size);
    printf("enter the direction\n 0 from the begining\n 1 from the end");
    scanf("%d",&direction);
    
    for(i=0;i<request-1;i++)
    {
        for(j=0;j<request-i-1;j++)
        {
            if(req[j]>req[j+1])
            {
                int temp;
                temp=req[j];
                req[j]=req[j+1];
                req[j+1]=temp;
            }
        }
    }
    printf("%d->",head);
    //
    if(direction==0)
    {
        int start=0;
        for(i=0;i<request;i++)
        {
            if(req[i]<head)
            {
                start=i;
            }
            else {
                break;
            }
        }
        for(i=start;i>0;i--)
        {
            seek+=(head-req[i]);
            head=req[i];
            printf("%d->",req[i]);
        }
        seek+=head;
        printf("0->");
        head=0;
        for(i=start+1;i<request-1;i++)
        {
            seek+=(req[i]-head);
            head=req[i];
            printf("%d->",req[i]);
        }
        seek+=req[i]-head;
        printf("%d",req[i]);
    }
    else{
            int start=0;
            for(i=0;i<request;i++)
            {
                if(req[i]<head)
                {
                start=i;
                }
                    else{
                        break;
                    }
            
            }
                for(i=start+1;i<request;i++)
                    {
                            seek+=req[i]-head;
                            head=req[i];
                            printf("%d->",req[i]);
                    }
                    printf("%d->",size-1);
                    seek+=((size-1)-head);
                    head=size-1;
                    for(i=start;i>0;i--)
                            {
                                    seek+=head=req[i];
                                    head=req[i];
                                    printf("%d->",req[i]);
                            }
                                seek+=head-req[i];
                                printf("%d\n",req[i]);
    }
    printf("seek distance %d",seek);
    return 0;
}
