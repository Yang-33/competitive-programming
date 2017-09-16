#include "bits/stdc++.h"
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

/* -----  2017/09/16  Problem: 334_C_div1_codeforces  / Link: http://codeforces.com/problemset/problem/603/C  ----- */
/* ------問題------

n個のコインの山があり、それぞれの山iにはa[i]枚のコインがある。KevinとNickyは交互に以下の操作のいずれかを行う。

山を1つ選び、その山からコインを1枚取り除く
コインが偶数枚（2x枚）ある山を1つ選び、その山をコインがx枚あるk個の山に置き換える
操作を行えなくなったプレイヤーが負けとなる。両者が最善手を打ったときどちらが勝つだろうか。

-----問題ここまで----- */
/* -----解説等-----

Kが偶数のときは置き換えた盤面のgrundy数は何であろうと0になる。
Kが奇数のときはそうではなく、grundy数を計算しなくてはならない。
幸い遷移が2種類しかないので、これをよく解析してみると(手書きで実験)
ある程度の規則が見えてくる。
K偶数のときは、分割に意味がないのでgrundy(n)=mex(grundy(n-1))
K奇数のときは、N奇数でgrundy(n)=mex(grundy(n-1)),偶数で、grundy(n)=mex(grundy(n-1),grundy(n/2))
となる。
一桁の数はこれに当てはまらない場合があるので、うめこむ。
Nが大きいのでメモ化はできないが遷移を見ればlogNでgrundy数がわかるので、これでまにあう。

----解説ここまで---- */

LL N, K;

LL ans = 0LL;
LL even[3] = { 0,1,2 };
LL grundy_even(LL x) {
	if (x >= 3) {
		if (x % 2 == 0)return 1;
		else return 0;
	}
	else {
		return even[x];
	}
}
LL odd[5] = { 0,1,0,1,2 };

LL grundy_odd(LL x) {
	if (x <= 4)return odd[x];
	if (x % 2 == 1)return 0;
	else {
		set<int>se;
		se.insert(0);
		if (x % 2 == 0)se.insert(grundy_odd(x / 2));

		LL subg = 0;
		while (se.count(subg))subg++;
		return subg;
	}
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> K;
	LL g = 0;

	FOR(i, 0, N) {
		LL a; cin >> a;
		if (K % 2 == 0) {
			g ^= grundy_even(a);
		}
		else {
			g ^= grundy_odd(a);
		}
	}


	cout << ((g != 0) ? "Kevin" : "Nicky") << "\n";

	return 0;
}