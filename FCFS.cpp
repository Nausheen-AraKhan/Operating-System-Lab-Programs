#include<iostream>
using namespace std;
int main(){
    int n;
    cout<<"Enter the number of processes:\n";
    cin>>n;
    int pid[100],AT[100],BT[100],CT[100],TAT[100],WT[100];
    for(int i=0;i<n;i++){
        cout<<"Enter the Arrival and Burst time for process P"<<i+1<<":\n";
        cin>>AT[i]>>BT[i];
    }
    //Sort according to Arrival Time
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(AT[i]>AT[j]){
                swap(AT[i],AT[j]);
                swap(BT[i],BT[j]);
                swap(pid[i],pid[j]);
            }
        }
    }
    int time=0;
    //FCFS Calculation
    for(int i=0;i<n;i++){
        if(time<AT[i]){
            time=AT[i];
        }
        CT[i]=time+BT[i];
        time=CT[i];
        TAT[i]=CT[i]-AT[i];
        WT[i]=TAT[i]-BT[i];
    }
    //Table
    cout<<"\nPID\tAT\tBT\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<"\n";
    }
    //Gantt Chart
    cout<<"\nGantt Chart:\n";
    for(int i=0;i<n;i++){
        cout<<"----------";
    }
    cout<<"-"<<endl;
    cout<<"|";
    for(int i=0;i<n;i++){
        cout<<"  P"<<i+1<<"  |";
    }
    cout<<endl;
    for(int i=0;i<n;i++){
        cout<<"----------";
    }
    cout<<"-"<<endl;
    cout<<AT[0];
    for(int i=0;i<n;i++){
        cout<<"      "<<CT[i];
    }
    cout<<endl;
    return 0;
}
