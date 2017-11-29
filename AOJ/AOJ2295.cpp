#include <bits/stdc++.h>
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/12/06  Problem: AOJ 2295 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2295  ----- */
/* ------問題------

ICPC で良い成績を収めるには修行が欠かせない．うさぎは ICPC で勝ちたいので，今日も修行をすることにした．
今日の修行は，非常に大きな数の計算を行って，計算力をつけて意識を高めようというものである．大きい数が簡単に出てくる演算として，累乗が挙げられる．
N 個の非負整数 A1, A2, ..., AN がある．これらの並べ替え B1, B2, ..., BN であって，B1B2...BN - 1BN が最大になるものを求めたい．うさぎたちにとってはもちろん常識であるが，この計算は右上から順に行う．また，00 = 1 であると約束することにする．
最大条件を満たす B1, B2, ..., BN は複数通りあるかもしれない．そのような場合は，そのうちで辞書順最小の列を選ぶことにしよう．

-----問題ここまで----- */
/* -----解説等-----

サンプルが弱すぎるため、考えると、0,1,2,3がやばそうであることがわかる。
2以降の数列を昇順に並び替えて、その後
その後は†気合†でなんとかする

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL a;
	int zero = 0; int one = 0; int cnt = 0;
	FOR(i, 0, N) {
		int x; cin >> x;
		if (x == 0)zero++;
		else if (x == 1)one++;
		else a.push_back(x);
	}
	SORT(a);
	int uni = SZ(a);
	FOR(i, 0, zero)a.push_back(0);
	FOR(i, 0, one)a.push_back(1);
	if (zero % 2 == 1) {
		if (one)swap(a[uni + zero - 1], a[uni + zero]);
		else if (uni) {
			int swm = a[0];
			FOR(i, 0, uni + zero - 2)a[i] = a[i + 1];
			a[uni + zero - 2] = swm;
			uni--;
		}
	}
	if (uni > 1 && a[uni - 2] == 2 && a[uni - 1] == 3)swap(a[uni - 2], a[uni - 1]);
	FOR(i, 0, SZ(a)) {
		cout << a[i] << endl;
	}

	return 0;
}
