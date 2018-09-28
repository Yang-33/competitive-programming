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

/* -----  2018/09/28  Problem: yukicoder 293  / Link: http://yukicoder.me/problems/no/293  ----- */
/* ------問題------

とある世界では地球上で人間が使うように10進数の数が扱われます。
しかし1つだけ違うのは、数字の4と7を評価する場合のみ4のほうが7より大きいということです。
異なる整数AとBが与えられるのでこの世界で大きいほうの数を答えよ。

単純に4と7が逆というわけでない。 この世界の数は、推移性が成り立たないと考えて良い。

ただし、桁数の比較については、地球上で人間が使うような判定と同じとする。

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string a, b; cin >> a >> b;
	int ans = 0;
	if (SZ(a) != SZ(b)) {
		ans = SZ(a) < SZ(b);
	}
	else {
		FOR(i, 0, SZ(a)) {
			if (a[i] != b[i]) {
				if (a[i] == '4' && b[i] == '7') {
					ans = 0;
				}
				else if (a[i] == '7' && b[i] == '4') {
					ans = 1;
				}
				else {
					ans = a[i] < b[i];
				}
				break;
			}
		}
	}

	cout << (ans == 0 ? a : b) << "\n";

	return 0;
}
