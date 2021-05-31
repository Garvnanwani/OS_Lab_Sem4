#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
int n,head,i,j,k,seek=0,max,diff;
float avg;
printf("Enter the max range of disk\n");
scanf("%d",&max);
printf("Enter the size of queue request\n");
scanf("%d",&n);
int queue[n+1];
printf("Enter the queue of disk positions to be read\n");
for(i=1;i<=n;i++) {
    scanf("%d",&queue[i]);
}
printf("Enter the initial head position\n");
scanf("%d",&head);
queue[0]=head;
printf("Disk head moves from \t to \t with seek\n" );
for(j=0;j<=n-1;j++)
{
diff=abs(queue[j+1]-queue[j]);
seek+=diff;
printf("%d \t\t %d \t %d\n",queue[j],queue[j+1],diff);
}
printf("Total seek time is %d\n",seek);
avg=seek/(float)n;
printf("Average seek time is %f\n",avg);
return 0;
}
