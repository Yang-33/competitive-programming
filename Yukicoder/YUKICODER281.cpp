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

/* -----  2018/09/26  Problem: yukicoder 281  / Link: http://yukicoder.me/problems/no/281  ----- */
/* ------問題------

kamipeipaa君の家の庭には1列に並んだ3本の竹があります。
kamipeipaa君は
・3本の竹全ての高さが互いに異なり、真ん中の竹の高さが一番高いあるいは低い
という条件を満たすようにしたいと考えています。
kamipeipaa君は1つの竹を選び、"その竹が高さhならばmax(0,h−d)にする"という魔法を繰り返し使うことで、この条件を満たすようにしたいと考えています。

この条件を満たすように魔法を使うとき、最低何回使う必要があるかkamipeipaa君に教えてあげてください。

なお、高さ0の竹も竹とみなされます。

竹は並び替えずに、入力の順番のままであるとする。

-----問題ここまで----- */
/* -----解説等-----

減らすという動作しかできないので、真ん中を一番大きくするか、一番小さくするかを試せば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL D, h1, h2, h3;
	cin >> D >> h1 >> h2 >> h3;
	auto kadomatsu = [](LL D, LL h1, LL h2, LL h3) {
		if (h2 > h1 &&h2 > h3 && h1 != h3)return 1;
		if (h2 < h1 &&h2 < h3 && h1 != h3)return 1;
		return 0;
	};

	if (D == 0) {
		cout << (kadomatsu(D, h1, h2, h3) ? 0 : -1) << endl; return 0;
	}

	auto f = [&kadomatsu](LL D, LL h1, LL h2, LL h3) {
		if (h1 < h3)swap(h1, h3);
		if (h3 < 0)return -1LL;
		if (kadomatsu(D, h1, h2, h3))return 0LL;

		LL subA = h3 == 0 ? INF : (h2 - h3 + 1 + D - 1) / D;
		LL subB = (h1 - h2 + D) / D;
		if (max(h1 - subB * D, 0LL) == h3) {
			subB = h3 == 0 ? INF : (subB + 1);
		}
		subA = min(subA, subB);
		return subA == INF ? -1LL : subA;
	};

	if (h1 == h3) {
		LL res = f(D, h1, h2, h3 - D);
		cout << (res < 0 ? -1 : res + 1) << endl; return 0;
	}

	ans = f(D, h1, h2, h3);

	cout << ans << "\n";



	return 0;
}
