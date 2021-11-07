#include<stdio.h>
 
int main() {
 
  int count,j,n,time,remain,flag=0,time_quantum;
  int wait_time=0,turnaround_time=0,at[10],bt[10],rt[10];
  printf("프로세스 개수를 입력해 주세요.(최대 20개):");
  scanf("%d",&n);
  remain=n;
  for(count=0;count<n;count++)
  {
    printf("p[%d]의 도착시간과 수행시간을 입력 해 주세요.\n",count+1);
		scanf("%d %d",&at[count], &bt[count]);
    rt[count]=bt[count];
  }
  printf("\n타임퀀텀: "); //얼만큼의 시간동안 작업하고 다른 프로세스와 교체할 지
  scanf("%d",&time_quantum);
  printf("\n\프로세스\t처리시간\t대기시간\n");
  for(time=0,count=0;remain!=0;)
  {
    if(rt[count]<=time_quantum && rt[count]>0)
    {
      time+=rt[count];
      rt[count]=0;
      flag=1;
    }
    else if(rt[count]>0)
    {
      rt[count]-=time_quantum;
      time+=time_quantum;
    }
    if(rt[count]==0 && flag==1)
    {
      remain--;
      printf("P[%d]\t\t%d\t\t%d\n",count+1,time-at[count],time-at[count]-bt[count]);
      wait_time+=time-at[count]-bt[count];
      turnaround_time+=time-at[count];
      flag=0;
    }
    if(count==n-1)
      count=0;
    else if(at[count+1]<=time)
      count++;
    else
      count=0;
  }
  printf("\n평균 대기시간 = %f\n",wait_time*1.0/n);
  printf("평균 처리시간 = %f",turnaround_time*1.0/n);
  
  return 0;
}
