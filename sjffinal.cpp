#include<bits/stdc++.h>
using namespace std;
int main()
{
    int  at[10],bt[10],ct[10],tat[10],wt[10],i,j,temp=0,n,
    prCount=0, gat[10], gbt[10], gct[10], gtat[10], gwt[10];
    string p[10],gpn[10],temp1;
    while(1){
    float awt=0,atat=0;
    printf("\n\nenter no of proccess you want:");
    scanf("%d",&n);
    printf("enter %d process:",n);
    for(i=0;i<n;i++)
    {
    cin>>p[i];
    }
    printf("enter %d arrival time:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&at[i]);
    }
    printf("enter %d burst time:",n);
    for(i=0;i<n;i++)
    {
    scanf("%d",&bt[i]);
    }

    for(i=0;i<n;i++)
    {
        gpn[i+prCount]=p[i];
        gat[i+prCount]=at[i];
        gbt[i+prCount]=bt[i];
    }

    for(i=0;i<n+prCount;i++)
    {
     for(j=0;j<(n+prCount-i);j++)
    {
      if(gbt[j]>gbt[j+1])
     {
        temp1=gpn[j+1];
        gpn[j+1]=gpn[j];
        gpn[j]=temp1;
        temp=gat[j+1];
        gat[j+1]=gat[j];
        gat[j]=temp;
        temp=gbt[j+1];
        gbt[j+1]=gbt[j];
        gbt[j]=temp;
      }
     }
    }

    gct[0]=gat[0]+gbt[0];
  
    for(i=1;i<n+prCount;i++)
    {  
   
      temp=0;
     if(gct[i-1]<gat[i])
     {
        temp=gat[i]-gct[i-1];
     }
     gct[i]=gct[i-1]+gbt[i]+temp;
   
    }

    printf("\nSequence\tProcessName\tTimeline\tTurnaround\t");
    for(i=0;i<n+prCount;i++)
    
    for(i=0;i<n+prCount;i++)
    {
    gtat[i]=gct[i]-gat[i];
    gwt[i]=gtat[i]-gbt[i];
    atat+=gtat[i];
    awt+=gwt[i];
    }
    atat=atat/(n+prCount);
    awt=awt/(n+prCount);
    for(i=0;i<n+prCount;i++)
    {   
    cout<<"\n"<<i+1<<"\t\t"<< gpn[i]<<"\t\t";
    if(i==0)
      cout<<"0-"<<gct[i];
      else
      cout<<gct[i-1]<<"-"<<gct[i];
    
        cout<<"\t\t"<<gtat[i]<<endl;
    
    }
    printf("\nATT: %f ",atat);

    printf("\nAWT: %f",awt);
    printf("\nART: %f ",awt);


    prCount+=n;
   
    }
    return 0;
}