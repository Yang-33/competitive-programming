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

/* -----  2017/12/20  Problem: AOJ 0362 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0362  ----- */
/* ------問題------

複数台のトランポリンが、１０ｍ間隔で直線上に設置されています。それぞれのトランポリンについて、水平方向に跳ぶことができる最大距離が決まっています。
左端のトランポリンから始めて、跳ぶことができる範囲にあるトランポリンに跳び移っていきます。
これを繰り返して、まずは右端のトランポリンまで行ってから、左端のトランポリンに戻りたいと思います。
この間、一度もトランポリンから降りずに往復することができるでしょうか。

各トランポリンで水平方向に跳ぶことができる最大距離が与えられたとき、左端と右端の間を往復できるかを報告するプログラムを作成せよ。
ただし、トランポリンは大きさのない点とみなす。

-----問題ここまで----- */
/* -----解説等-----

愚直しかないが、遠いとこからやることで枝刈り的なことができる。
埋める場所はNだけなのでO(N)で実現できる

----解説ここまで---- */


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL d(N, 0);
	FOR(i, 0, N) {
		cin >> d[i];
	}
	VI go(N + 1, 0);
	VI re(N + 1, 0);
	int gof = 0;
	int ref = 0;
	go[0] = 1;

	FOR(i, 0, N) {
		if (go[i] == 0)continue;
		for (int j = i + (d[i]) / 10; j > i; j--) {
			if (j >= N)j = N - 1;
			if (go[j])break;
			go[j] = 1;
		}
	}


	if (go[N - 1])gof = 1;
	re[N - 1] = 1;
	for (int i = N - 1; i >= 0; i--) {
		if (re[i] == 0)continue;
		for (int j = i - (d[i]) / 10; j < i; j++) {
			if (j < 0)j = 0;
			if (re[j])break;
			re[j] = 1;
		}
	}
	if (re[0])ref = 1;

	if (gof == 1 && ref == 1) {
		cout << "yes" << endl;
	}
	else cout << "no" << endl;

	return 0;
}
