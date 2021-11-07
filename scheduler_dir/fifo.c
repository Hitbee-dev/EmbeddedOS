#include<stdio.h>
 
int main()
{
    int n,bt[20],wt[20],tat[20],avwt=0,avtat=0,i,j;
    printf("프로세스 개수를 입력해 주세요.(최대 20개):");
    scanf("%d",&n);
 
    printf("\n수행시간을 입력 해 주세요.\n");
    for(i=0;i<n;i++)
    {
        printf("P[%d]:",i+1);
        scanf("%d",&bt[i]);
    }
 
    wt[0]=0; //첫번째 프로세스의 지연시간은 0이므로
 
    //대기시간
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
    }
 
    printf("\n프로세스\t수행시간\t대기시간\t처리시간");
 
    //처리시간
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];
        avwt+=wt[i];
        avtat+=tat[i];
        printf("\nP[%d]\t\t%d\t\t%d\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avwt/=i; //평균 대기시간을 프로세스개수만큼 나눠주기
    avtat/=i; //평균 처리시간을 프로세스개수만큼 나눠주기
    printf("\n\n평균 대기시간:%d",avwt);
    printf("\n평균 처리시간:%d",avtat);
 
    return 0;
}
