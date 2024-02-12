#include <stdio.h>
#include <math.h>
int size = 8;
void FCFS(int arr[],int head)
{
	int seek_count = 0;
	int cur_track, distance;
   	for(int i=0;i<size;i++)
	{
		cur_track = arr[i];
       		distance = fabs(head - cur_track);
        	seek_count += distance;
		head = cur_track;
  	}
   	printf("Total number of seek operations: %d\n",seek_count);
    	printf("Seek Sequence is\n");
   	for (int i = 0; i < size; i++) 
   	{
        	printf("%d\n",arr[i]);
    	}
}
int main()
{
    int arr[11];
    int head = 50,n,i;
    printf("FCFS disk scheduling\n");
    printf("Enter number of requests ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
    	printf("Enter a value ");
    	scanf("%d",&arr[i]);
    }
    	FCFS(arr,head);
    	return 0;
}
