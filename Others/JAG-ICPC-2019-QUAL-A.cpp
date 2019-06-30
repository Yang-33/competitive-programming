#include <bits/stdc++.h>

using namespace std;

int main() {
	int n, m;
	while (cin >> n >> m and n != 0) {
		vector<int> a(n);
		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}
		int sum = 0;
		for (int i = 0; i < n; i++) {
			sum += min(a[i], m / n);
		}
		cout << sum << endl;
	}
}