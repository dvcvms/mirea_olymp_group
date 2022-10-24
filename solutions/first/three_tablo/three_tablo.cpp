// first_tree_tablo

#include <iostream>
#include <vector>

using namespace std;

const int INF = (int)3e8 + 10;

int main() {
	int n;
	int* s, * c;

	cin >> n;

	s = new int[n];
	c = new int[n];
	vector<int> suff_a(n + 1, INF);


	for (int i = 0; i < n; i++)
		cin >> s[i];

	for (int i = 0; i < n; i++)
		cin >> c[i];


	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] < s[j])
				suff_a[i] = min(suff_a[i], c[j]);

	int bestAnsw = INF;

	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (s[i] < s[j])
				bestAnsw = min(bestAnsw, c[i] + c[j] + suff_a[j]);


	cout << (bestAnsw >= INF ? -1 : bestAnsw);

	return 0;
}