#include<stdio.h>
 
void main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    printf("프로세스 개수를 입력해 주세요.(최대 20개):");
    scanf("%d",&n);
 
    printf("\n수행시간을 입력 해 주세요.:\n");
    for(i=0;i<n;i++)
    {
        printf("p[%d]:",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;           //contains process number
    }
 
    //선택정렬을 이용하여 수행시간을 오름차순으로 정렬
    for(i=0;i<n;i++)
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
 
    wt[0]=0; //첫번째 프로세스의 지연시간은 0이므로
 
    //대기시간
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=(float)total/n;      //평균대기시간
    total=0;
 
    printf("\n프로세스\t수행시간\t대기시간\t처리시간");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\np[%d]\t\t%d\t\t%d\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/n;     //average turnaround time
    printf("\n\n평균 대기시간=%f",avg_wt);
    printf("\n평균 처리시간=%f\n",avg_tat);
}
