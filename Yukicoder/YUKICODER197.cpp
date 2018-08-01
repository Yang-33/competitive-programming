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

/* -----  2018/07/31  Problem: yukicoder 197  / Link: http://yukicoder.me/problems/no/197  ----- */
/* ------問題------

A君は手品の練習をしている。手品は次のようなものである。

コインが1つ入っているか入っていない帽子が３つ並んでいる。
A君は最初にすべての帽子にコインが入っているかいないかを見せる。
1回の操作によって左側の2つか右側の2つの帽子を中身ごと入れ替えることができる。
A君はお客さんに頼んでちょうどN回だけ好きなように操作を行ってもらう。
（このとき操作の回数は明らかだが、どのように行ったかは見えない。）
A君がすべての帽子を開けたときにあり得ない状態になっていれば手品は成功である。

A君の手品が成功していれば"SUCCESS"、失敗なら"FAILURE"と言ってあげましょう。

-----問題ここまで----- */
/* -----解説等-----

場合分けをする。
2以上は任意の並び替えができるので、一致しうるかのみ判定

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string a, b;
	LL N;
	cin >> a >> N >> b;
	int ok = 1;
	if (N < 2) {
		if (N == 0) {
			ok &= (a != b);
		}
		else if (N == 1) {
			FOR(i, 0, 2) {
				string t = a;
				swap(t[i], t[i + 1]);
				if (t == b)ok = 0;
			}
		}
	}
	else {
		SORT(a), SORT(b);
		ok &= (a != b);
	}



	cout << (ok ? "SUCCESS" : "FAILURE") << endl;

	return 0;
}
