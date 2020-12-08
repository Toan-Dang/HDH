#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Nhap so luong process: ";
    cin >> n;
    vector<tuple<int, int, int>> p, res(n);
    vector<pair<int, int>> x(n, {INT_MAX, 0}), d;
    queue<pair<int, int>> q;
    double average_waiting_time(0), average_turnaround_time(0), average_respond_time(0);
    //           P:                res:                      x:             q,d:
    // get<0>   burst time         completion/respond     respond time    process name
    // get<1>   arrival time       waiting                brust time      time
    // get<2>   process name       turnaround
    ////////////////////////////////////////////////////////////////////////
    int a, b;
    int m_time = 0;
    for (int i = 0; i < n; i++) {
        cout << "Nhap arrival time va burst time cua process thu " << i + 1 << " : ";
        cin >> a >> b;
        p.push_back({b, a, i + 1});
        x[i].second = b;
        m_time += b;
    }
    int count = 0;
    ////////////////////////////////////////////////////
    //find the Shortest Remaining Time at any "time"
    // if Remaining Time =0 then push it into queue (res) and ....
    for (int time = 0; time < m_time || count < n; time++) {
        int mins = INT_MAX;
        for (int i = 0; i < p.size(); i++) {
            if (get<1>(p[i]) <= time && get<0>(p[i]) > 0 && get<0>(p[i]) < get<0>(p[mins])) {
                mins = i;
            }
        }
        d.push_back({get<2>(p[mins]), time});
        x[mins].first = min(time, x[mins].first);
        --get<0>(p[mins]);
        if (get<0>(p[mins]) == 0) {
            get<0>(res[mins]) = time + 1;
            get<1>(res[mins]) = get<0>(res[mins]) - get<1>(p[mins]) - x[mins].second;
            get<2>(res[mins]) = get<0>(res[mins]) - get<1>(p[mins]);
            get<0>(res[mins]) = x[mins].first - get<1>(p[mins]);

            average_waiting_time += get<1>(res[mins]);
            average_turnaround_time += get<2>(res[mins]);
            average_respond_time += get<0>(res[mins]);
            ++count;
        }
    }
    ///////////////////////GANTT/////////////////////
    for (int i = 0; i < d.size(); i++) {
        if (d[i].first == d[i + 1].first) {
        } else {
            q.push({d[i].first, d[i].second + 1});
        }
    }
    cout << "\nGANTT\nProcess\tTime\n";
    while (q.size()) {
        auto t = q.front();
        cout << t.first << "\t" << t.second << "\n";
        q.pop();
    }
    //////////////////////////////OUT PUT////////////////////////////
    cout << "process\trespond\twaiting\tturnaround\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << get<0>(res[i]) << "\t" << get<1>(res[i]) << "\t" << get<2>(res[i]) << "\n";
    }

    cout << "Average_respond_time " << average_respond_time / n;
    cout << "\nAverage_waiting_time " << average_waiting_time / n;
    cout << "\nAverage_turnaround_time " << average_turnaround_time / n;

    return 0;
}
