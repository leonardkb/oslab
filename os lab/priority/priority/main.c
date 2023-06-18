//
//  main.c
//  priority
//
//  Created by leonard kb on 04/06/2023.
//

#include<stdio.h>
int main()
{
    int i,j,bt[10],wt[10],tat[10],n,pr[10],pos,temp;
    float awt=0, atat=0;
    
    printf("enter the no of process");
    scanf("%d",&n);
    
    printf("enter the burst time");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&bt[i]);
    }
    
    printf("enter the priority of the process");
    for(int i=0;i<n;i++)
    {
      scanf("%d",&pr[i]);
    }
    
    //applying sorting
    for(i=0;i<n;i++)
    {
        pos=i;
        
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])
            {
                pos=j;
            }
        }
            temp=pr[i];
            pr[i]=pr[pos];
            pr[pos]=temp;
            
            temp=bt[i];
            bt[i]=bt[pos];
            bt[pos]=temp;
        
    }
    wt[0]=0;
    printf("process\tbursttime\tpriority\twaitingtime\turnaroundtime\n");
    for(i=0;i<n;i++)
    {
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++)
        {
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("\n %d\t\t%d\t\t%d\t\t%d\t\t%d\n",i+1,bt[i],pr[i],wt[i],tat[i]);
    }
    
    awt=awt/n;
    atat=atat/n;
    printf("average waiting time is %f\n",awt);
    printf("average turn ariund time is %f\n",atat);
    return 0;
}
