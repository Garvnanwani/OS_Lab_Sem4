#include<stdio.h>
int main()
{
int i,j,n,frame_no,k,avail,count=0;
printf("\n ENTER THE NUMBER OF PAGES:\n");
scanf("%d",&n);
int page[n];

printf("\n ENTER THE PAGE NUMBER :\n");
for(i=1;i<=n;i++)
scanf("%d",&page[i]);

printf("\n ENTER THE NUMBER OF FRAMES :");
scanf("%d",&frame_no);

int frame[frame_no];
for(i=0;i<frame_no;i++)
    frame[i]= -1;

j=0;

printf("ref string\t page frames\n");

for(i=1;i<=n;i++)
{
    printf("%d\t\t",page[i]);
    avail=0;
    for(k=0;k<frame_no;k++)
    if(frame[k]==page[i])
        avail=1;
    if (avail==0)
    {
        frame[j]=page[i];
        j=(j+1)%frame_no;
        count++;
        for(k=0;k<frame_no;k++)
        printf("%d\t",frame[k]);
    }
    printf("\n");
}
printf("Page Fault Is %d",count);
return 0;
}
