#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int main() {
    int n, a, b, flag(0);
    cout << "Nhap so luong Process: ";
    cin >> n;
    vector<tuple<int, int, int>> p;
    for (int i = 1; i <= n; i++) {
        cout << "Nhap Arrival time va Burst time cua process thu " << i << ": ";
        cin >> a >> b;
        int c = i;
        p.push_back({b, a, c});
    }
    int m = n;
    queue<tuple<int, int, int>> q;
    vector<tuple<int, int, int, int, int, int>> res(n);
    // if arrival time = 0 then push into queue
    // else push the Shortest Remaining Time First
    for (int i = 0; i < n; i++) {
        if (get<1>(p[i]) == 0) {
            q.push(p[i]);
            p.erase(p.begin() + i);
            --i;
            --n;
        } else {
            if (flag == 0) {
                sort(p.begin(), p.end());
                flag = 1;
            }
            q.push(p[i]);
        }
    }
    double average_waiting_time(0), average_turnaround_time(0);
    /////////////////////////////////////////////////////////////////////////////
    //              res:                   p,q:
    // get<0> time                  burst time
    // get<1> arrival time          arrival time
    // get<2> process name          number process
    // get<3> response time,
    // get<4> waiting time,
    // get<5> turnaround time,
    //////////////////////////////////////////////
    res.push_back({0, 0, 0, 0, 0, 0});
    for (int i = 1; i <= m; i++) {
        auto t = q.front();
        get<0>(res[i]) = get<0>(t);
        get<1>(res[i]) = get<1>(t);
        get<2>(res[i]) = get<2>(t);

        get<0>(res[i]) = get<0>(res[i]) + get<0>(res[i - 1]);
        get<3>(res[i]) = get<0>(res[i - 1]) - get<1>(res[i]);
        get<4>(res[i]) = get<3>(res[i]);
        get<5>(res[i]) = get<0>(res[i]) - get<1>(res[i]);

        average_waiting_time += get<4>(res[i]);
        average_turnaround_time += get<5>(res[i]);
        q.pop();
    }
    /////////////////////OUT PUT//////////////////////////////
    cout << "GANTT\nProcess name\ttime\n";
    for (const auto& it : res) {
        cout << get<2>(it) << "\t" << get<0>(it) << "\n";
    }
    cout << "Process name\tresponse time\twaiting time\tturnaround time \n";
    for (int i = 1; i <= n; ++i) {
        for (const auto& it : res) {
            if (get<2>(it) == i)
                cout << get<2>(it) << "\t" << get<3>(it) << "\t" << get<4>(it) << "\t" << get<5>(it) << "\n";
        }
    }
    cout << "average waiting time: " << average_waiting_time / n
         << "\naverageturnaround time: " << average_turnaround_time / n;
    return 0;
}
