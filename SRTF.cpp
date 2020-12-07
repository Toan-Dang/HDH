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
    vector<int> x(n);
    double average_waiting_time(0), average_turnaround_time(0);
    //           P:                res:
    // get<0>   burst time         completion
    // get<1>   arrival time       waiting
    // get<2>   name process       turnaround
    ////////////////////////////////////////////////////
    int a, b;
    int m_time = 0;
    for (int i = 0; i < n; i++) {
        cout << "Nhap arrival time va burst time cua process thu " << i + 1 << " : ";
        cin >> a >> b;
        p.push_back({b, a, i + 1});
        x[i] = b;
        m_time += b;
    }
    int count = 0;
    ////////////////////////////////////////////////////
    //find the Shortest Remaining Time at any "time"
    // if Remaining Time =0 then push it into queue (res) and ....
    for (int time = 0; time < m_time || count < n; time++) {
        int min = INT_MAX;
        for (int i = 0; i < p.size(); i++) {
            if (get<1>(p[i]) <= time && get<0>(p[i]) > 0 && get<0>(p[i]) < get<0>(p[min])) {
                min = i;
            }
        }
        --get<0>(p[min]);
        if (get<0>(p[min]) == 0) {
            get<0>(res[min]) = time + 1;
            get<1>(res[min]) = get<0>(res[min]) - get<1>(p[min]) - x[min];
            get<2>(res[min]) = get<0>(res[min]) - get<1>(p[min]);
            average_waiting_time += get<1>(res[min]);
            average_turnaround_time += get<2>(res[min]);
            ++count;
        }
    }
    //////////////////////////////OUT PUT////////////////////////////
    cout << "process\trespond\twaiting\tturnaround\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << "\t" << get<0>(res[i]) << "\t" << get<1>(res[i]) << "\t" << get<2>(res[i]) << "\n";
    }
    cout << "Average_waiting_time " << average_waiting_time / n;
    cout << "\nAverage_turnaround_time " << average_turnaround_time / n;

    return 0;
}