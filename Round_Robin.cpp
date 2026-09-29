#include<iostream>
using namespace std;
int main()
{
    int n,quantum;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int BT[100],RT[100],CT[100],TAT[100],WT[100];
    cout<<"Enter Burst time:\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<": ";
        cin>>BT[i];
        RT[i]=BT[i]; //Remaining time is initialized to burst time
    }
    cout<<"Enter Time Quantum: ";
    cin>>quantum;
    int time=0;
    int completed=0;
    while(completed<n){
        for(int i=0;i<n;i++){
            if(RT[i]>0){ //if remaining time is greater than 0.
                if(RT[i]>quantum){
                    cout<<"P"<<i+1<<" ";
                    time+=quantum;
                    RT[i]-=quantum;
                }
                else{
                    //process finishes before quantum expires
                    cout<<"P"<<i+1<<" ";
                    time+=RT[i];
                    RT[i]=0;
                    CT[i]=time; //Completion time
                    completed++;
                }
            }
        }
    }
    //Calculating Turn Around Time and Waiting Time
    for(int i=0;i<n;i++){
        TAT[i]=CT[i]; //AT=0
        WT[i]=TAT[i]-BT[i];
    }
    //Table
    cout<<"\nProcess\tBurst Time\tCompletion Time\tTurn Around Time\tWaiting Time\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t"<<BT[i]<<"\t\t"<<CT[i]<<"\t\t"<<TAT[i]<<"\t\t\t"<<WT[i]<<"\n";
    }
    return 0;
}
