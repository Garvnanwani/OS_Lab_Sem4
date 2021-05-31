#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
int n,head,i,j,k,curr,seek=0,max,diff,complete;
float avg;
printf("Enter the max range of disk\n");
scanf("%d",&max);
printf("Enter the size of queue request\n");
scanf("%d",&n);
complete=n;
int queue[n];
printf("Enter the queue of disk positions to be read\n");
for(i=0;i<n;i++)
scanf("%d",&queue[i]);
printf("Enter the initial head position\n");
scanf("%d",&head);
curr=head;
printf("Disk head movmes from \t to \t with seek\n" );
while(complete-->0)
{
int index=-1;
int min = max+1;
for(int j =0;j<n;j++){
if(queue[j]!=-1)
{
int mn = abs(curr-queue[j]);
if(mn<min)
{
min = mn;
index = j;
}
}
}
diff=abs(curr-queue[index]);seek+=diff;
printf("%d \t\t %d \t %d\n",curr,queue[index],diff);
curr=queue[index];
queue[index]=-1;
}
printf("Total seek time is %d\n",seek);
avg=seek/(float)n;
printf("Average seek time is %f\n",avg);
return 0;
}
