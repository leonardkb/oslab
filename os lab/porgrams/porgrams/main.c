//cpu scheduling programs


#include<stdio.h>
int main()
{
    int p,bt[10],at[10],tat[10],wt[10],i,j,temp[10];
    float awt=0,atat=0;
    printf("enter the no of process\n");
    scanf("%d",&p);
    printf("enter the burst time\n");
    for(i=0;i<p;i++)
    {
        scanf("%d",&bt[i]);
    }
    
    printf("process \t burst time \t   waiting time \t turn around time \n");
    for(int i=0;i<p;i++)
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
        printf("\n%d  \t\t%d  \t\t%d \t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
    awt=awt/p;
    atat=atat/p;
    printf("average waiting time is %f",awt);
    printf("average turn around time is %f",atat);
    return 0;
}
