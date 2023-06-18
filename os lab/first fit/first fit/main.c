#include<stdio.h>
int main(){
    int h,p,holes[20],process[20],ho[20],i,j,flag=0;
    printf("Enter the number of holes:");
    scanf("%d",&h);
    for(i=0;i<h;i++){
        printf("Enter the size of hole H%d:",i+1);
        scanf("%d",&holes[i]);
        ho[i]=holes[i];
    }
    printf("Enter the number of processes:");
    scanf("%d",&p);
    for(i=0;i<p;i++){
        printf("Enter the size of process P%d:",i+1);
        scanf("%d",&process[i]);
    }
    printf("Process\tpsize\thole\n");
    for(i=0;i<p;i++){
        flag=0;
        for(j=0;j<h;j++){
            if(holes[j]>=process[i]){
                holes[j]=holes[j]-process[i];
                printf("P%d\t%d\tH%d\n",i+1,process[i],j+1);
                flag=1;
                break;
            }
        }
        if(flag==0)
            printf("P%d\t%d\tNot allocated\n",i+1,process[i]);
        }
        printf("Space available after allocation\n");
printf("hole\tactual\tavailable\n");
for(i=0;i<h;i++)
printf("H%d\t%d\t%d\n",i+1,ho[i],holes[i]);
return 0;
}
