// task_A


#include <iostream>
#include <vector>

using namespace std;

int countA(vector<int>& pref_a, int l, int r)
{
	// l, r - 0 индексация

	if (l > r) return 0;
	return pref_a[r + 1] - pref_a[l];
}

int countB(vector<int>& pref_a, int l, int r)
{
	if (l > r) return 0;
	return r - l + 1 - countA(pref_a, l, r);
	return 0;
}


void solve()
{
	string s;
	cin >> s;

	int n = s.size();
	int min_trash = int(1e9);

	vector<int> pref_a(n + 1, 0);

	for (int i = 0; i < n; i++) {
		pref_a[i + 1] = pref_a[i] + (s[i] == 'a');
	}


	for (int l = 0; l < n; l++)
	{
		for (int r = l; r < n; r++)
		{
			int trash = countB(pref_a, 0, l - 1) + countA(pref_a, l, r) + countB(pref_a, r + 1, n - 1);
			min_trash = min(min_trash, trash);
		}
	}

	min_trash = min(min_trash, n - pref_a[n]);


	cout << n - min_trash;

}


int main()
{

	solve();

	return 0;
}