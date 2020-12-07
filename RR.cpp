#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;
int main() {
    int n, qtime, totaltime(0);
    cout << "Nhap so luong process va quantium time: ";
    cin >> n >> qtime;
    queue<pair<int, int>> q;
    vector<pair<int, int>> res;
    res.push_back({0, 0});
    int a, b;
    // a, first,get<0>: process name
    // b, second: burst time
    // get<1> time
    ////////////////////////////////////////////
    // asume all arrival time = 0 then input only brust time
    pair<int, int> p;
    for (int i = 0; i < n; i++) {
        cout << "Nhap brust time cua process thu " << i + 1 << " : ";
        cin >> b;
        a = i + 1;
        totaltime += b;
        q.push({a, b});
    }
    // each process will allow run in quantium time
    // after excute the next process will be excute and the pre process will be enqueue
    // if it end before quantium time, the next process will be excute in this quantium time
    for (int i = 0; i < totaltime;) {
        if (q.front().second == 0)
            q.pop();
        p = q.front();
        for (int j = 0; j < qtime; j++) {
            --p.second;
            ++i;
            if (p.second == 0) {
                q.pop();
                res.push_back({p.first, i});
                p = q.front();
            }
        }
        if (q.size() == 1) {
            res.push_back({p.first, totaltime});
            q.pop();
            break;
        }
        if (q.size()) {
            q.push(p);
            res.push_back({p.first, i});
            q.pop();
        }
    }
    /////////////////////OUT PUT//////////////////////
    cout << "GANTT\nPROCESS\tTIME\n";
    for (auto it : res) {
        cout << get<0>(it) << "\t" << get<1>(it) << "\n";
    }
    double average_waiting_time(0), average_turnaround_time(0);
    cout << "processor_name\tstart_processor_time\tstop_processor_time\n";
    for (int i = 1; i <= n; i++) {
        //start time
        for (int j = 0; j < res.size(); j++) {
            if (get<0>(res[j]) == i) {
                cout << i << "\t" << get<1>(res[j - 1]) << "\t";
                break;
            }
        }
        // stop time
        for (int j = res.size() - 1; j >= 0; j--) {
            if (get<0>(res[j]) == i) {
                cout << get<1>(res[j]) << "\n";
                break;
            }
        }
    }
    // sort process name
    vector<vector<pair<int, int>>> temp(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j < res.size(); j++) {
            if (get<0>(res[j]) == i)
                temp[i - 1].push_back({get<1>(res[j - 1]), get<1>(res[j])});
        }
    }
    // count waiting time and turnaround time per process
    for (int i = 0; i < temp.size(); i++) {
        average_waiting_time += temp[i][0].first;
        for (int j = 1; j < temp[i].size(); j++) {
            average_waiting_time += temp[i][j].first - temp[i][j - 1].second;
        }
        for (int k = temp[i].size() - 1; k >= 0; k--) {
            average_turnaround_time += temp[i][k].second;
            break;
        }
    }
    cout << "average_waiting_time: " << average_waiting_time / n
         << "\naverage_turnaround_time: " << average_turnaround_time / n;

    return 0;
}