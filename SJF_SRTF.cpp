#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of processes: ";
    cin>>n;
    int AT[100],BT[100];
    for(int i=0;i<n;i++){
        cout<<"Enter Arrival and Burst time for process P"<<i+1<<": ";
        cin>>AT[i]>>BT[i];
    }
    //SJF NON-PREEMPTIVE
    int CT1[100],WT1[100],done[100]={0},time=0,completed=0;
    while(completed<n){
        int index=-1;
        int shortest=9999;
        //Find the shortest job among the arrived processes
        for(int i=0;i<n;i++){
            if(AT[i]<=time && done[i]==0){
                if(BT[i]<shortest){
                    shortest=BT[i];
                    index=i;
                }
            }
        }
        //if no process has arrived
        if(index==-1){
            time++;
        }
        else{
            time+=BT[index];
            CT1[index]=time;
            WT1[index]=CT1[index]-AT[index]-BT[index];
            done[index]=1;
            completed++;
        }
    }
    //Calculate average WT for SJF
    float totWT1=0;
    for(int i=0;i<n;i++){
        totWT1+=WT1[i];
    }
    float avgWT1=totWT1/n;
    
    //SRTF PREEMPTIVE
    int RT[100],CT2[100],WT2[100];
    for(int i=0;i<n;i++){
        RT[i]=BT[i];
    }
    time=0;
    completed=0;
    while(completed<n){
        int index=-1;
        int shortest=9999;
        //find process with shortest remaining time among the arrived processes
        for(int i=0;i<n;i++){
            if(AT[i]<=time && RT[i]>0){
                if(RT[i]<shortest){
                    shortest=RT[i];
                    index=i;
                }
            }
        }
        //if no process has arrived
        if(index==-1){
            time++;
        }
        else{
            //run process for 1 unit
            RT[index]--;
            time++;
            //process finished
            if(RT[index]==0){
                CT2[index]=time;
                WT2[index]=CT2[index]-AT[index]-BT[index];
                completed++;
            }
        }
    }
        //Calculate average WT for SRTF
        float totWT2=0;
        for(int i=0;i<n;i++){
            totWT2+=WT2[i];
        }
        float avgWT2=totWT2/n;
        cout<<"Average Waiting Time for SJF: "<<avgWT1<<endl;
        cout<<"Average Waiting Time for SRTF: "<<avgWT2<<endl;
        return 0;
}
