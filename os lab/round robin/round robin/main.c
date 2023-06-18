//
//  main.c
//  round robin
//
//  Created by leonard kb on 08/06/2023.
//

#include<stdio.h>
int main()
{
    int n,qt, bt[10],wt[10],tat[10],count=0,rem_bt[10],i,temp;
    int sq=0;
    float awt=0,atat=0;
    printf("enter the no of the process:\n");
    scanf("%d",&n);
    printf("enter thr burst time of the process:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("enter the quantum time");
    scanf("%d",&qt);
    while(1)
    {
        for(i=0,count=0;i<n;i++)
        {
            temp=qt;
            if(rem_bt[i]==0)
            {
                count++;
                continue;
            }
             if(rem_bt[i]>qt)
             {
                 rem_bt[i]=rem_bt[i]-qt;
             }
             else if(rem_bt[i]>0)
             {
                 temp=rem_bt[i];
                 rem_bt[i]=0;
             }
            sq=sq+temp;
            tat[i]=sq;
        }
        if(n==count)
            break;
    }
    printf("\nprocess\tburst time\tturnaround time\twaiting time\n");
    for(i=0;i<n;i++)
    {
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("\n%d\t%d\t\t%d\t\t%d",i+1,bt[i],tat[i],wt[i]);
    }
    
    awt=awt/n;
    atat=atat/n;
    printf("average the waiting time is %f",awt);
    printf("average turn around time is %f",atat);
    return 0;
}
