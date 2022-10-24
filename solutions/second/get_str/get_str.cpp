// taskB


#include <iostream>
#include <vector>

using namespace std;


int main() {

	int n; cin >> n;

	string s, t;
	cin >> s; cin >> t;

	vector<int> answ;

	for (int i = 0; i < n; i++) {

		int p = (int)(find(s.begin() + i, s.end(), t[i]) - s.begin());

		if (p == n) {
			cout << -1;
			return 0;
		}

		while (p > i) {
			answ.push_back(p);
			swap(s[p - 1], s[p]);
			p--;
		}
	}

	cout << answ.size() << endl;
	for (auto & it : answ) cout << it << " ";

	return 0;
}