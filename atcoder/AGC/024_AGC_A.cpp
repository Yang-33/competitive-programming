#include <bits/stdc++.h>
using namespace std;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long A, B, C, K;
	cin >> A>>B>>C>>K;
	long long  ans = 0;
	if (abs(A - B) >= 1e18) {
		cout << "Unfair" << endl;
	}
	else if (K % 2) cout << B - A << endl;
	else cout << A - B << endl;
	return 0;
}
