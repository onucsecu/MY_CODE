/*****************************************************************************
Experiment No   : 01
Experiment Name: Given the list of processes,their CPU burst time and arrival times.
                  Display Gantt chart and for FCFS and SJF.For each scheduling policies,
                  compute the average waiting time and average turnaround time (2 sessions).
Course Code     : CSE 511
Submitted By:
        Name    :   Muhamamod Ibrahim Khalil
        ID No   :   15701041
        Session :   2014-2015
        Semester:   5th Semester
        Subject :   Operating System
            Department of CSE
Submitted to:
        Professor Md. Anawarul Azim
        Department of CSE

********************************************************************************/
#include<bits/stdc++.h>
#include<stdio.h>
using namespace std;
struct processes{
    double arrival_time,burst_time,st,wt,tt;
    int pid;

    char str[50];
};
bool comp1(processes A,processes B){
    return A.arrival_time<B.arrival_time;
}
bool comp2(processes A,processes B){
    return A.burst_time<B.burst_time;
}
bool comp3(processes A,processes B){
    return A.pid<B.pid;
}
int main(){
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);

    while(true){
    processes prcs[50];
    printf("Number of Processes: \n");
    int n;
    scanf("%d",&n);
    if(n==0)
        break;
    printf("Give process id - Arrival time-Burst Time\n");
    for(int i=0;i<n;i++){
        scanf("%s %lf %lf",&prcs[i].str,&prcs[i].arrival_time,&prcs[i].burst_time);
        prcs[i].pid=i+1;
    }

    /**FCFS Section**/
    sort(prcs,prcs+n,comp1);
    int k=0;
    double avg_waiting_time=0.0;
    double service_time=prcs[0].arrival_time;
    prcs[k].st=service_time;
    prcs[k].wt=service_time-prcs[0].arrival_time;
    k++;
    avg_waiting_time=service_time - prcs[0].arrival_time;
    for(int i=1;i<n;i++){
        service_time=service_time + prcs[i-1].burst_time;
        prcs[i].st=service_time;
        avg_waiting_time+=(service_time-prcs[i].arrival_time);
        prcs[i].wt=(service_time-prcs[i].arrival_time);
        k++;
    }
    double total_tt=0.0;

    for(int i=0;i<n;i++){
        prcs[i].tt=prcs[i].st+prcs[i].burst_time;
        total_tt+=prcs[i].tt;
    }
    sort(prcs,prcs+n,comp3);
    printf("Proccess | Arrival_Time | Burst_Time | Service_Time | Waiting_Time| Turn_Around_Time\n");
    for(int i=0;i<n;i++){
        printf("%s  %12.0lf  %10.0lf  %13.0lf %12.0lf %15.0lf\n",prcs[i].str,prcs[i].arrival_time,prcs[i].burst_time,prcs[i].st,prcs[i].wt,prcs[i].tt);

    }


    printf("Average Waiting Time For FCFS : %lf\n",avg_waiting_time/(double)n);
    printf("Average Turn Around Time For FCFS : %lf\n",total_tt/(double)n);

    /**SJF section**/
    sort(prcs,prcs+n,comp1);
    sort(prcs+1,prcs+n,comp2);
    k=0;//re-initiallize K

    service_time=prcs[0].arrival_time;
    prcs[k].st=service_time;
    prcs[k].wt=service_time-prcs[0].arrival_time;
    k++;
    avg_waiting_time=service_time - prcs[0].arrival_time;
    for(int i=1;i<n;i++){
        service_time=service_time + prcs[i-1].burst_time;
        prcs[i].st=service_time;
        avg_waiting_time+=(service_time-prcs[i].arrival_time);
        prcs[i].wt=(service_time-prcs[i].arrival_time);
        k++;
    }
    total_tt=0.0;//re-initializeing tt_total;

    for(int i=0;i<n;i++){
        prcs[i].tt=prcs[i].st+prcs[i].burst_time;
        total_tt+=prcs[i].tt;
    }
    sort(prcs,prcs+n,comp3);
        printf("Proccess | Arrival_Time | Burst_Time | Service_Time | Waiting_Time| Turn_Around_Time\n");
    for(int i=0;i<n;i++){
        printf("%s  %12.0lf  %10.0lf  %13.0lf %12.0lf %15.0lf\n",prcs[i].str,prcs[i].arrival_time,prcs[i].burst_time,prcs[i].st,prcs[i].wt,prcs[i].tt);

    }

    printf("Average Waiting Time For SJF : %lf\n",avg_waiting_time/(double)n);
    printf("Average Turn Around Time For SJF : %lf\n",total_tt/(double)n);

    }
    fclose(stdout);
    system("output.txt");
    return 0;
}

