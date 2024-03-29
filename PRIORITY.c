#include<stdio.h>
void calculation(int process[],int burst_time[],int arrival_time[],int priority[],int n);
void main(){
    int process[100];
    int burst_time[100];
    int arrival_time[100];
    int priority[100];
    int n;
    printf("Hitanshu 60009220164\n");
    printf("enter the number of process:");
    scanf("%d",&n);
    for (int i = 1; i <= n; i++)
    {
        printf("enter the burst time for the given process %d:",i);
        scanf("%d",&burst_time[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("enter the arrival time for the given process %d:",i);
        scanf("%d",&arrival_time[i]);
    }
    for (int i = 1; i <= n; i++)
    {
        printf("enter the priority for the given process %d:",i);
        scanf("%d",&priority[i]);
    }
    printf("the table for SJF is as follows:\n");
    printf("pn\tbt\tat\tpri");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%d\t%d\t%d\t%d",process[i],burst_time[i],priority[i],arrival_time[i]);
    }
    
    calculation( process, burst_time, arrival_time, priority,n);
    
}
void calculation(int process[],int burst_time[],int arrival_time[],int priority[],int n){
    int gt[100] = {0};
    int temp1;
    int temp2;
    int temp3;
    int wt[100] = {0};
    int tt[100] = {0};
    int completion_time[100] = {0};
    int waiting_time = 0;
    float avg_waiting_time = 0.0;
    int turnaround_time = 0;
    float avg_turnaround_time = 0.0;
for ( int i = 0; i < n; i++)
{
    for (int j  = 0; j < n - i - 1; j++)
    {
        if(priority[j]>priority[j+1]){
            temp1 = burst_time[j];
            burst_time[j] = burst_time[j+1];
            burst_time[j+1] = temp1;
            temp2 = process[j];
            process[j] = process[j+1];
            process[j+1] = temp2;
            temp3 = priority[j];
            priority[j] = priority[j+1];
            priority[j+1] = temp3;
        }
    }
    
}
for (int i = 0; i < n+1; i++)
{
   gt[i + 1] = gt[i] + burst_time[i];
}
for (int i = 0; i < n; i++)
{if (i == 0) {
            completion_time[i] =  burst_time[i];
        } else {
            completion_time[i] = completion_time[i - 1] + burst_time[i];
        }

}
for (int i = 0; i < n; i++)
{
    tt[i] = completion_time[i] - arrival_time[i];
}
for (int i = 0; i < n; i++)
{
    turnaround_time = turnaround_time + tt[i];
}
for (int i = 0; i < n; i++)
{
   wt[i] = tt[i] - burst_time[i];
}
for (int i = 0; i < n; i++)
{
    waiting_time = waiting_time + wt[i];
}

printf("\n the gantt chart is as follows:\n");
for (int i = 0; i < n; i++)
{
    printf("%d \t",process[i]);
}
printf("\n");
for (int i = 0; i <= n; i++)
{
    printf("%d \t",gt[i]);
}

 printf("\n the table for SJF is as follows:\n");
 printf("pn\tbt\tprio\tat\twt\ttt\tct");
    for (int i = 0; i < n; i++)
    {
        printf("\n");
        printf("%d\t%d\t%d\t\t%d\t%d\t%d\t%d",process[i],burst_time[i],priority[i],arrival_time[i],wt[i],tt[i],completion_time[i]);
    }
    avg_turnaround_time = (float)turnaround_time/n;
    avg_waiting_time = (float)waiting_time/n;
    printf("\nThe Average waiting time is: %f", avg_waiting_time);
    printf("\nThe Average TurnAround time is:%f",avg_turnaround_time);
}
