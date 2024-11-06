#include<bits/stdc++.h>
using namespace std;

void avg_time(int p[],int bt[],int n)
{   int wt[n],tt[n];
    float  total_wt=0,total_tt=0;
    //for waiting time
    wt[0]=0;
    for(int i=1;i<n;i++){
        wt[i]=wt[i-1]+bt[i-1];
        total_wt+=wt[i];
    }
    float avg_wt= total_wt/(float)n;

    //for turnaround time
    
    for(int i=0;i<n;i++){
        tt[i]=wt[i]+bt[i];
        total_tt+=tt[i];
    }

    float avg_tt=total_tt/(float)n;

    printf("%.2f\n",avg_wt);
    printf("%.2f\n",avg_tt);
    


}

int main()
{
    int p[]={1,2,3};
    int n =sizeof(p)/sizeof(p[0]);
    int bt[]={10, 5, 8};
    avg_time(p,bt,n);
    return 0;
}