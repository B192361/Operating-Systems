#include<stdio.h>
int n;
int ct[10],t;
void sort(int at[],int bt[])
{
int i;
for(int i=0;i<n-1;i++)
{
for(int j=0;j<n-i-1;j++)
{
if(at[j]>at[j+1])
{
t=at[j];
at[j]=at[j+1];
at[j+1]=t;

t=bt[j];
bt[j]=bt[j+1];
bt[j+1]=t;
}
}
}
}
void fcfs(int at[],int bt[])
{
int i,v=0;
ct[0]=at[0]+bt[0];
for(i=1;i<n;i++)
{
if(at[i]>ct[i-1])
{
v=at[i]-ct[i-1];
ct[i]=ct[i-1]+v+bt[i];
}
else{
ct[i]=ct[i-1]+bt[i];
}
}
}
void turnaroundtime(int at[],int tat[])
{
for(int i=0;i<n;i++)
{
tat[i]=ct[i]-at[i];
}
}
void waittime(int tat[],int bt[],int wt[])
{
for(int i=0;i<n;i++)
{
wt[i]=tat[i]-bt[i];
}
}
int main()
{
int at[10],bt[10],tat[10],wt[10];
float atat=0;
float awt=0;
int i;
printf("enter the no of processes");
scanf("%d",&n);
printf("enter the at array");
for(int i=0;i<n;i++)
{
scanf("%d",&at[i]);
}
printf("enter the bt array");
for(int i=0;i<n;i++)
{
scanf("%d",&bt[i]);
}
sort(at,bt);
fcfs(at,bt);

turnaroundtime(at,tat);
waittime(tat,bt,wt);
for(int i=0;i<n;i++)
{
atat=atat+tat[i];
}
atat=atat/n;
for(int i=0;i<n;i++)
{
awt=awt+wt[i];
}
awt=awt/n;
printf("\n");
printf("at \t bt \t ct \t tat \t wt\t");
printf("\n");
for(int i=0;i<n;i++)
{
printf("%d \t %d \t %d \t %d \t %d\t",at[i],bt[i],ct[i],tat[i],wt[i]);
printf("\n");
}
printf("average tat is=%.2f",atat);
printf("\n");
printf("average wt is=%.2f",awt);
printf("\n");
}
