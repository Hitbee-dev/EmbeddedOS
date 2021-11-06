#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <stdlib.h>

void Error(const char *mes);
void *sem_snd(void *arg);
void *sem_rev(void *arg);
sem_t bin_sem;
int number = 0;

int main()
{
        int state = 0;
        pthread_t t1,t2,t3;
        char thread1[] = "Thread_A";
        char thread2[] = "Thread_B";
        char thread3[] = "Thread_C";
        void * result_t = NULL;

        state = sem_init(&bin_sem,0,0);
        if(state != 0)  Error("sem_init Error\n");
        pthread_create(&t1,NULL,sem_snd,thread1);
        pthread_create(&t2,NULL,sem_rev,thread2);
        pthread_create(&t3,NULL,sem_rev,thread3);
        pthread_join(t1,&result_t);
        pthread_join(t2,&result_t);
        pthread_join(t3,&result_t);
        printf("Finale Number : %d\n",number);
        sem_destroy(&bin_sem);
        return 0;
}
void *sem_snd(void *arg)
{
        int i = 0;
        for(i=0; i<4; i++)
        {
                while(number != 0)
                sleep(1);
                number++;
                printf("%s Running : %d\n",(char*)arg,number);
                sem_post(&bin_sem);
        }
}
void *sem_rev(void *arg)
{
        int i = 0;
        for(i=0; i<2; i++)
        {
                sem_wait(&bin_sem);
                number--;
                printf("%s Running : %d\n",(char*)arg,number);
        }
}
void Error(const char *mes)
{
        printf("%s\n",mes);
        exit(0);
}
