#include<stdio.h>  
void main()  
{  
   int i, NOP, sum=0,count=0, y, quant, wt=0, tat=0, at[10], bt[10], temp[10];  
   float avg_wt, avg_tat; 
   printf("Hitanshu 60009220164\n"); 
   printf("\n Total number of process in the system: ");  
   scanf("%d", &NOP);  
   y = NOP;  
   for(i=0; i<NOP; i++)  
   {  
   	printf("\n Enter the Arrival and Burst time of the Process[%d]", i+1);  
    	printf("\nArrival time is: ");  
    	scanf("%d", &at[i]);  
    	printf("\n Burst time is: ");  
    	scanf("%d", &bt[i]);  
    	temp[i] = bt[i];
    }  
    printf("Enter the Time Quantum for the process: ");  
    scanf("%d", &quant);  
    printf("\n Process No \t\t Burst Time \t\t TAT \t\t Waiting Time ");  
    for(sum=0, i = 0; y!=0; )  
    {  
    	if(temp[i] <= quant && temp[i] > 0)   
    	{  
        	sum = sum + temp[i];  
        	temp[i] = 0;  
        	count=1;  
        }     
        else if(temp[i] > 0)  
        {  
            temp[i] = temp[i] - quant;  
            sum = sum + quant;    
        }  
        if(temp[i]==0 && count==1)  
        {  
            y--;  
            printf("\nProcess No[%d] \t\t %d\t\t\t %d\t\t\t %d", i+1, bt[i], sum-at[i], sum-at[i]-bt[i]);  
            wt = wt+sum-at[i]-bt[i];  
            tat = tat+sum-at[i];  
            count =0;     
        }  
        if(i==NOP-1)  
        {  
            i=0;  
        }  
        else if(at[i+1]<=sum)  
        {  
            i++;  
        }  
        else  
        {  
            i=0;  
        }  
    }  
}
