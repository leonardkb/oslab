//
//  main.c
//  SJF
//
//  Created by leonard kb on 04/06/2023.
//

#include<stdio.h>
int main()
{
    int n,p[10],bt[10],tt[10],wt[10],i,j,t;
    float awt=0,atat=0;
    printf("enter the no of process");
    scanf("%d",&n);
    printf("enter the process number");
    for(i=0;i<n;i++)
    {
        scanf("%d",&p[i]);
    }
    printf("enter the burst time");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    
    //applying sorting
    
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i-1;j++)
        {
            if(bt[j]>bt[j+1])
            {
                t=bt[j];
                bt[j]=bt[j+1];
                bt[j+1]=t;
                
                t=p[j];
                p[j]=p[j+1];
                p[j+1]=t;
            }
        }
    }
    
    printf("process \t burst time \t waiting time \t turnaround time \n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tt[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tt[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+wt[i];
        printf("\n%d\t\t%d\t\t%d\t\t%d /n",i+1,bt[i],wt[i],tt[i]);
    }
    awt=awt/n;
    atat=atat/n;
    printf("average waiting time is %f",awt);
    printf("average turn around time is %f",atat);
    return 0;
}
