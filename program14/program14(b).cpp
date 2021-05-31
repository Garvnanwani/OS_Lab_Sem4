#include<stdio.h>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;
int main()
{
int n,head,i,j,k,seek=0,max,diff,curr;
float avg;
string direction;
vector<int> left, right;
printf("Enter the max range of disk\n");
scanf("%d",&max);
printf("Enter the size of queue request\n");
scanf("%d",&n);
int queue[n];
printf("Enter the queue of disk positions to be read\n");
for(i=0;i<n;i++)
scanf("%d",&queue[i]);
printf("Enter the direction\n");
cin>>direction;
printf("Enter the initial head position\n");
scanf("%d",&head);
for (i = 0; i < n; i++)
{
if (queue[i] <= head)
left.push_back(queue[i]);
if (queue[i] > head)
right.push_back(queue[i]);
}
std::sort(left.begin(), left.end());
std::sort(right.begin(), right.end());
printf("Disk head moves from \t to \t with seek\n" );
int run = 2;
while (run-->0) {
if (direction == "left") {
for ( i = left.size() - 1; i >= 0; i--) {curr = left[i];
diff = abs(curr - head);
printf("%d \t\t %d \t %d\n",head,curr,diff);
seek += diff;
head = curr;
}
direction = "right";
}
else if (direction == "right") {
for ( i = 0; i < right.size(); i++) {
curr = right[i];
diff = abs(curr - head);
printf("%d \t\t %d \t %d\n",head,curr,diff);
seek += diff;
head = curr;
}
direction = "left";
}
}
printf("Total seek time is %d\n",seek);
avg=seek/(float)n;
printf("Average seek time is %f\n",avg);
return 0;
}
