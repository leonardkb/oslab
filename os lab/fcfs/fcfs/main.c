//
//  main.c
//  fcfs
//
//  Created by leonard kb on 08/06/2023.
//
#include<stdio.h>
int main(){
int request_arr[20],request,head,seek=0,i;
printf("Enter the number of repuests:");
scanf("%d",&request);
printf("Enter the requests:\n");
for(i=0;i<request;i++)
    scanf("%d",&request_arr[i]);
printf("Enter the initial head position:");
scanf("%d",&head);
printf("%d->",head);
for(i=0;i<request;i++){
    if(request_arr[i]>head)
        seek+=(request_arr[i]-head);
    else
        seek+=(head-request_arr[i]);
    head=request_arr[i];
}
for(i=0;i<request-1;i++)
    printf("%d->",request_arr[i]);
printf("%d",request_arr[i]);
printf("\nTotal seek distance is:%d\n",seek);
return 0;
}
