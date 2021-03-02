#include<stdio.h>
int main()
{
    int n;
printf(" -------Shortest Job First Scheduling ( NP )-------\n");
printf("\nEnter the No. of processes :");
scanf("%d",&n);
int bt[n],temp,i,j,at[n],wt[n],ct[n],ta[n],pid[n],f[n];
int st=0,tot=0;
float avgwt=0,avgta=0;
for(i=0;i<n;i++)
{
printf("Enter the arrival time of %d process :",i+1);
scanf(" %d",&at[i]);
printf("Enter the burst time of %d process :",i+1);
scanf(" %d",&bt[i]);
pid[i]=i+1;
f[i]=0;
}
while(1)
        {
            int c=n, min = 999999;

            if (tot == n)
                break;

            for (i=0; i<n; i++)
            {

                if ((at[i] <= st) && (f[i] == 0) && (bt[i]<min))
                {
                    min=bt[i];
                    c=i;
                }
            }
            if (c==n)
                st++;
            else
            {
                ct[c]=st+bt[c];
                st+=bt[c];
                ta[c]=ct[c]-at[c];
                wt[c]=ta[c]-bt[c];
                f[c]=1;
                pid[tot] = c + 1;
                tot++;
            }
        }
    for(i=0;i<n;i++)
    {
        avgwt+= wt[i];
        avgta+= ta[i];
    }
printf("************************");
printf("\nProcess       Burst         Arrival        Completion         Waiting          Turn-around" );
for(i=0;i<n;i++)
{
printf("\np%d\t\t%d\t\t%d\t\t%d\t\t%d\t\t%d",pid[i],bt[i],at[i],ct[i],wt[i],ta[i]);
}

printf("\n\nAVERAGE WAITING TIME : %f",(avgwt/n));
printf("\nAVERAGE TURN AROUND TIME : %f",(avgta/n));
return 0;
}
