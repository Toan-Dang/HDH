#include <algorithm>
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;
int main() {
	int n;
	cout << "Nhap so luong process: ";
	cin >> n;
	int a, b, count(0), m_time(0);
	vector<tuple<int, int, int>> p, res(n);
	vector<int> x(n);
	queue<pair<int, int>> q;
	double average_waiting_time(0), average_turnaround_time(0), average_respond_time(0);
	//           P:                res:                      q:
	// get<0>   burst time         completion/respond     name process
	// get<1>   arrival time       waiting                time
	// get<2>   name process       turnaround
	//////////////////////////////////////////////////////////////////////
	for (int i = 0; i < n; i++) {
		cout << "Nhap vao arrival time va burst time cua process thu " << i+1 << " : ";
		cin >> a >> b;
		m_time += b;
		x[i] = b;
		p.push_back({ b, a, i + 1 });
	}
	/////////////////////////////////
	p.push_back({ 1000,0,0 });
	for (int time = 0; time < m_time || count < n;) {
		int min = p.size() - 1;
		for (int i = 0; i < p.size() - 1; i++) {
			if (get<1>(p[i]) <= time && get<0>(p[i]) > 0 && get<0>(p[i]) < get<0>(p[min])) {
				min = i;
			}
		}
		time += get<0>(p[min]);
		get<1>(res[min]) = time - get<1>(p[min]) - x[min];
		get<2>(res[min]) = time - get<1>(p[min]);
		get<0>(res[min]) = get<1>(res[min]);
		average_respond_time += get<0>(res[min]);
		average_waiting_time += get<1>(res[min]);
		average_turnaround_time += get<2>(res[min]);
		++count;
		get<0>(p[min]) = 0;
		q.push({ get<2>(p[min]), time });
	}
	//////////////////////////OUTPUT//////////////////////////////
	cout << "\nGANTT\nProcess\tTime\n";
	while (q.size()) {
		auto t = q.front();
		cout << t.first << "\t" << t.second << "\n";
		q.pop();
	}
	cout << "\nprocess\trespond\twaiting\tturnaround\n";
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "\t" << get<0>(res[i]) << "\t" << get<1>(res[i]) << "\t" << get<2>(res[i]) << "\n";
	}
	cout << "average_respond_time " << average_respond_time / n
		<< "\nAverage_waiting_time " << average_waiting_time / n
		<< "\nAverage_turnaround_time " << average_turnaround_time / n;

	return 0;
}
