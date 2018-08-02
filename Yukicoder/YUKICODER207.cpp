#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define SZ(a) int((a).size())
#define SORT(c) sort(ALL((c)))
#define RSORT(c) sort(RALL((c)))
#define UNIQ(c) (c).erase(unique(ALL((c))), end((c)))
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/08/02  Problem: yukicoder 207  / Link: http://yukicoder.me/problems/no/207  ----- */
/* ------問題------

A以上B以下の整数のうち、3の倍数および3の付く数を、小さい順に出力してください。
なお、「3の付く数」とは、10進数表記にした時、少なくとも1つの桁が3であるような数のことです。

-----問題ここまで----- */
/* -----解説等-----

B-A<=100なので全部調べる。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL A, B;
	cin >> A >> B;
	auto check = [](LL a) {
		string s = to_string(a);
		int sum = 0;
		FOR(i, 0, SZ(s))if (s[i] == '3')return true;

		FOR(i, 0, SZ(s))sum += s[i] - '0';
		return sum % 3 == 0;
	};
	for (LL i = A; i <= B; i++) {
		if (check(i)) {
			cout << i << "\n";
		}
	}

	return 0;
}
