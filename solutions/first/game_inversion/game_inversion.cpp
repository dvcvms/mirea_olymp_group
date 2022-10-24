// first_game_inversion


#include <iostream>
#include <vector>

using namespace std;


int count1(vector<int>& pref_sum, int l, int r) {

	if (l > r)
		return 0;

	return pref_sum[r + 1] - pref_sum[l];
}

int count0(vector<int>& pref_sum, int l, int r) {
	if (l > r)
		return 0;

	return r - l + 1 - count1(pref_sum, l, r);
}


int main()
{
	int n;
	cin >> n;

	vector<int>a(n);
	vector<int>pref_sum(n + 1, 0);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	for (int i = 0; i < n; i++)
		pref_sum[i + 1] = pref_sum[i] + a[i];


	int bestAnsw = -1;

	for (int l = 0; l < n; l++)
		for (int r = l; r < n; r++) {
			int curAnsw = count1(pref_sum, 0, l - 1) + count0(pref_sum, l, r) + count1(pref_sum, r + 1, n - 1);
			if (curAnsw > bestAnsw)
				bestAnsw = curAnsw;
		}

	cout << bestAnsw;

	return 0;
}

