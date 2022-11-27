#include<stdio.h>
struct process
{
    int WT,AT,BT,TAT;
};
struct process a[10];
int main()
{
    int n,temp[10];
    int count=0,t=0,short_P;
    float total_WT=0, total_TAT=0,Avg_WT,Avg_TAT;
    printf("Enter the number of the process\n");
    scanf("%d",&n);
    for(int i = 0; i < n; i++)
    {
            printf("\nEnter Details of process[%d]\n", i + 1);
            printf("Arrival Time:\t");
            scanf("%d", &a[i].AT);
            printf("Burst Time:\t");
            scanf("%d", &a[i].BT);
            temp[i] = a[i].BT;
    }
    a[9].BT=10000;
    for(t=0;count!=n;t++)
    { 
        short_P=9;
        for(int i=0;i<n;i++)
        {
            if(a[i].BT<a[short_P].BT && (a[i].AT<=t && a[i].BT>0))
            {
                short_P=i;
            }
        }
        a[short_P].BT=a[short_P].BT-1;
        if(a[short_P].BT==0)
        {
            count++;
            a[short_P].WT=t+1-a[short_P].AT-temp[short_P];
            a[short_P].TAT=t+1-a[short_P].AT;
            total_WT=total_WT+a[short_P].WT;
            total_TAT=total_TAT+a[short_P].TAT;
        }
    }
    Avg_WT=total_WT/n;
    Avg_TAT=total_TAT/n;
    printf("\nProcess ID\t\tBurst Time\t Turnaround Time\t Waiting Time\n");
    for(int i=0;i<n;i++)
    {
        printf("\nprocess[%d]\t\t%d\t\t %d\t\t\t %d",i+1,a[i].BT,a[i].TAT,a[i].WT);
    }
    printf("Avg waiting time of the process is %f\n",Avg_WT);
    printf("Avg turn around time of the process %f\n",Avg_TAT);
}
