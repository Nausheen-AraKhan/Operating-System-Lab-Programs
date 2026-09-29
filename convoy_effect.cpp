#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"Enter number of processes:\n";
    cin>>n;
    int BT[100];
    cout<<"Enter burst time:\n";
    for(int i=0;i<n;i++)
    {
        cout<<"P"<<i+1<<": ";
        cin>>BT[i];
    }
    // FCFS
    int WT_FCFS[100],time=0;
    for(int i=0;i<n;i++)
    {
        WT_FCFS[i]=time;
        time+=BT[i];
    }
    // SJF 
    int bt[100],pid[100];
    for(int i=0;i<n;i++)
    {
        bt[i]=BT[i];
        pid[i]=i+1;
    }
    // SORT ACCORDING TO BURST TIME
    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            if(bt[i]>bt[j]){
                swap(bt[i],bt[j]);
                swap(pid[i],pid[j]);
            }
        }
    }
    int WT_SJF[100],time1=0;
    for(int i=0;i<n;i++){
        WT_SJF[pid[i]-1]=time1;
        time1+=bt[i];
    }
    cout<<"\nProcess\tBT\tFCFS WT\tSJF WT\n";
    for(int i=0;i<n;i++){
        cout<<"P"<<i+1<<"\t"<<BT[i]<<"\t"<<WT_FCFS[i]<<"\t"<<WT_SJF[i]<<endl;
    }
    return 0;
}
