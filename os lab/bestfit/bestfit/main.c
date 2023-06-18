//
//  main.c
//  bestfit
//
//  Created by leonard kb on 08/06/2023.
//

#include<stdio.h>
void sort();
int main(){
    int h,p,holes[20],parray[20],ho[20],process[20],i,j,flag=0;
    printf("Enter the number of holes:");
    scanf("%d",&h);
    for(i=0;i<h;i++){
        printf("Enter the size of hole H%d:",i+1);
        scanf("%d",&holes[i]);
        ho[i]=holes[i];
        parray[i]=holes[i];
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
        sort(h,holes);
        for(j=0;j<h;j++){
            if(holes[j]>=process[i]){
                for(int k=0;k<h;k++){
                    if(parray[k]==holes[j]){
                        holes[j]=holes[j]-process[i];
                        parray[k]=parray[k]-process[i];
                        printf("P%d\t%d\tH%d\n",i+1,process[i],k+1);
                        flag=1;
                        break;
                }
                
              }
            break;
            }
        }
        if(flag==0)
            printf("P%d\t%d\tNot allocated\n",i+1,process[i]);
        }
printf("Space available after allocation\n");
printf("hole\tactual\tavailable\n");
for(i=0;i<h;i++){
printf("H%d\t%d\t%d\n",i+1,ho[i],parray[i]);
}
return 0;
}
void sort(int h, int holes[20]){
    int swap;
    for(int i=0;i<h-1;i++){
        for(int j=0;j<h-i-1;j++){
            if(holes[j]>holes[j+1]){
            swap=holes[j];
            holes[j]=holes[j+1];
            holes[j+1]=swap;
            }
        }
    }
}
