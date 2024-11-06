#include<bits/stdc++.h>
using namespace std;
struct Process{
    int pid;
    int bt;
    int art;

};
void waiting(Process proc[],int n,int wt[]){
    int rem[n];
    for(int i=0;i<n;i++){
        rem[i]= proc[i].bt;
    }

    int com=0,time=0,sortindx=0,minimum=INT_MAX,completing_time;
    bool flag=false;
    while(com!=n){
        for(int i=0;i<n;i++){
            if(( proc[i].art<=time) &&(rem[i]<minimum)&&rem[i]>0)
            {
                minimum=rem[i];
                sortindx=i;
                flag=true;
            }
        }
        if(flag==false){
            time++;
            continue;
        }
        rem[sortindx]--;
        minimum=rem[sortindx];
        if(minimum==0)
            minimum=INT_MAX;
        if(rem[sortindx]==0){
            com++;
            flag=false;

            completing_time=time+1;
            wt[sortindx]=completing_time-proc[sortindx].bt-proc[sortindx].art;
            if(wt[sortindx]<0)
                wt[sortindx]=0;

        }
        time++;
    }
}
void turnaround(Process proc[],int n,int wt[],int tt[]){
    for(int i=0;i<n;i++){
        tt[i]=wt[i]+proc[i].bt;
    }
}

void avg(Process proc[],int n){
    int wt[n],tt[n],total_w=0,total_tt=0;
    waiting(proc,n,wt);
    turnaround(proc,n,wt,tt);
    cout<<"PID\t\t BT\t\t WT\t\t TAT\t\t\n";
    for(int i=0;i<n;i++){
        total_w+=wt[i];
        total_tt+=tt[i];
        cout<<" "<<proc[i].pid<<"\t\t"<<proc[i].bt<<"\t\t"<<wt[i]<<"\t\t"<<tt[i]<<"\n";
    }
    cout<<"Avg Waiting time: "<<(float)total_w/(float)n<<endl;
    cout<<"Avg Turnaround time: "<<(float)total_tt/(float)n<<endl;

}

int main(){
    Process proc[]={ { 1, 6, 2 }, { 2, 2, 5 },{ 3, 8, 1 }, { 4, 3, 0}, {5, 4, 4} };
    int n=sizeof(proc)/sizeof(proc[0]);
    avg(proc,n);
    return 0;
}
