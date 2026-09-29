#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter the number of processes: ";
    cin>>n;
    int AT[100],BT[100],Priority[100],CT[100],TAT[100],WT[100];
    int done[100]={0};
    for(int i=0;i<n;i++){
        cout<<"Enter Arrival Time,Burst Time and Priority of process "<<i+1<<": ";
        cin>>AT[i]>>BT[i]>>Priority[i];
    }
    int time=0;
    int completed=0;
    while(completed<n){
        int index=-1,highest=9999;
        for(int i=0;i<n;i++){
            if(AT[i]<=time && done[i]==0){
                int waiting=time-AT[i];
                int newpriority=Priority[i]-waiting;
                if(newpriority<1)
                   newpriority=1;
                if(newpriority<highest){
                    highest=newpriority;
                    index=i;
                }
            }
        }
        if(index==-1)
           time++;
        else{
            time+=BT[index];
            CT[index]=time;
            TAT[index]=CT[index]-AT[index];
            WT[index]=TAT[index]-BT[index];
            done[index]=1;
            completed++;
        }
    }
    cout<<"\nPID\tAT\tBT\tPriority\tCT\tTAT\tWT\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t"<<AT[i]<<"\t"<<BT[i]<<"\t"<<Priority[i]<<"\t\t"<<CT[i]<<"\t"<<TAT[i]<<"\t"<<WT[i]<<endl;
    }
    return 0;
    
}
