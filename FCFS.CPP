#include <iostream>
#include <iomanip>
#include <vector>
#include <string>

using namespace std;

struct Process {
    string process_id;
    int arrival_time;
    int burst_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n;
    cout << "How many processes do you want to enter? ";
    cin >> n;

    vector<Process> proc(n);

    cout << "Input Process ID (letters or numbers), Arrival Time, and Burst Time (separated by spaces):\n";
    for (int i = 0; i < n; i++) {
        cout << "Process " << (i + 1) << ": ";
        cin >> proc[i].process_id >> proc[i].arrival_time >> proc[i].burst_time;
    }

    int completion_time = 0;
    float total_waiting_time = 0;
    float total_turnaround_time = 0;

    for (int i = 0; i < n; i++) {
        
        if (completion_time < proc[i].arrival_time) {
            completion_time = proc[i].arrival_time; 
        }

        
        proc[i].completion_time = completion_time + proc[i].burst_time;
        proc[i].turnaround_time = proc[i].completion_time - proc[i].arrival_time;
        proc[i].waiting_time = proc[i].turnaround_time - proc[i].burst_time;
        completion_time = proc[i].completion_time; 

        total_waiting_time += proc[i].waiting_time;
        total_turnaround_time += proc[i].turnaround_time;
    }

    
    cout << "\nFinal Results of Processes:\n";
    cout << left << setw(12) << "Process ID"
         << setw(15) << "Arrival Time"
         << setw(12) << "Burst Time"
         << setw(18) << "Completion Time"
         << setw(18) << "Turnaround Time"
         << setw(12) << "Waiting Time" << endl;

    for (const auto& p : proc) {
        cout << setw(12) << p.process_id
             << setw(15) << p.arrival_time
             << setw(12) << p.burst_time
             << setw(18) << p.completion_time
             << setw(18) << p.turnaround_time
             << setw(12) << p.waiting_time << endl;
    }

    
    float avg_waiting_time = total_waiting_time / n;
    float avg_turnaround_time = total_turnaround_time / n;

    cout << "\nAverage Times:\n";
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;

    return 0;
}
    
