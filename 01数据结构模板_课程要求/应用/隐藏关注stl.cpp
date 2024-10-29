#include<bits/stdc++.h>
using namespace std;
int main() {
	map<string, int>M;
	set<string>S, res;
	int n, score;
	double ave;
	string man;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> man;
		S.insert(man);
	}
	int m;
	cin >> m;
	for (int i = 1; i <= m; i++) {
		cin >> man;
		cin >> score;
		ave += score;
		M[man] = score;
	}
	ave /= m;
	map<string, int>::iterator it;
	for (it = M.begin(); it != M.end(); it++) {
		if (!S.count(it->first) && it->second > ave) {
			res.insert(it->first);
		}
	}
	set<string>::iterator resit;
	for (resit = res.begin(); resit != res.end(); resit++) {
		cout << *resit << endl;
	}
	if (res.empty()) {
		cout << "Bing Mei You" <<endl;
	}
	return 0;
}
