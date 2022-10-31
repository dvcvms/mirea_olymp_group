// taskE


#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int>& a, int k) {

	if (k == 0) 

		if (a[0] == 1) return -1;
		
		else return 1;
	

	if (a[k - 1] == a[k]) return -1;
	
	else return a[k - 1];

}


int main() {

	int n, k; cin >> n >> k;

	vector<int> a(n); for (auto& it : a) cin >> it;

	sort(a.begin(), a.end());

	cout << solution(a, k);

	return 0;
}
