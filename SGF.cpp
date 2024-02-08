#include <bits/stdc++.h>

using namespace std;

struct Process {
    int pid;
    int arrival_time;
    int burst_time;
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrival_time < p2.arrival_time;
}

void sjf_scheduling(vector<Process>& processes) {
    sort(processes.begin(), processes.end(), compareArrivalTime);

    int n = processes.size();
    vector<int> waiting_time(n, 0);
    int current_time = 0;

    cout << "PID\tArrival Time\tBurst Time\tWaiting Time" << endl;
    for (int i = 0; i < n; i++) {
        waiting_time[i] = max(current_time - processes[i].arrival_time, 0);
        cout << processes[i].pid << "\t" << processes[i].arrival_time << "\t\t"
             << processes[i].burst_time << "\t\t" << waiting_time[i] << endl;
        current_time += processes[i].burst_time;
    }

    int total_waiting_time = 0;
    for (int wt : waiting_time) {
        total_waiting_time += wt;
    }

    double average_waiting_time = (double)total_waiting_time / n;
    cout << "\nAverage Waiting Time: " << average_waiting_time << endl;
}

int main() {
    vector<Process> processes = {
        {1, 0, 5},
        {2, 2, 3},
        {3, 4, 1},
        {4, 6, 2}
    };

    sjf_scheduling(processes);

    return 0;
}
