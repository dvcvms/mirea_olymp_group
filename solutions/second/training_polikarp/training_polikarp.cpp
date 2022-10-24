// taskD


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
	
	int n, k; cin >> n >> k;

	vector<int> arr(n);
	for (auto& it : arr) cin >> it;

	vector<pair<int, int>> pairs;
	for (int i = 0; i < n; i++)
		pairs.push_back(make_pair(arr[i], i));

	sort(pairs.begin(), pairs.end(), greater<>());
	pairs.resize(k);

	int sum = 0;
	vector<int>indexes;
	for (auto& it : pairs) {
		sum += it.first;
		indexes.push_back(it.second);
	}

	sort(indexes.begin(), indexes.end());

	for (int i = indexes.size() - 1; i > 0; i--) 
		indexes[i] = indexes[i] - indexes[i - 1];

	indexes[0]++;

	int len = 0;
	for (auto& it : indexes) len += it;

	indexes.back() = indexes.back() + n - len;

	
	cout << sum << endl;
	for (auto& it : indexes) cout << it << ' ';


	return 0;
}