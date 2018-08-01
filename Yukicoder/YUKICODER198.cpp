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

/* -----  2018/07/31  Problem: yukicoder 198  / Link: http://yukicoder.me/problems/no/198  ----- */
/* ------問題------

キャンディーが入っている箱がN個ある。
i番目の箱にはCi個のキャンディーが入っている。
A君はキャンディーの箱に入ったキャンディーをすべて同じ数にするように言われた。
A君は手持ちのキャンディーをB個持っている。
A君ができる作業は次の2つである。

・手持ちのキャンディー1個をいずれかの箱に入れる。
・いずれかの箱のキャンディー1個を取り出し手持ちのキャンディーとする。

できるだけA君は作業の数を最少にしたい。
A君がする最少の作業の回数は何回か？

-----問題ここまで----- */
/* -----解説等-----

三分探索でも解けそう
なんかマンハッタン距離最小化に近いので、これをやる

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL B, N; cin >> B >> N;
	VL C(N);
	FOR(i, 0, N) {
		cin >> C[i];
	}

	LL ans = LINF;

	LL sum = accumulate(ALL(C), B);
	auto f = [&C,&B](LL parm) {
		LL cnt = 0;
		LL stock = B;
		FOR(i, 0, SZ(C)) {
			if (C[i] - parm>0)cnt += (C[i] - parm);
			if(C[i]-parm<0)cnt -= (C[i] - parm);
			stock += C[i] - parm;
		}
		if (stock < 0)return LINF;
		else return cnt;
	};
	ans = min(ans, f(sum/N));
	SORT(C);
	ans = min(ans, f(C[N / 2]));
	cout << ans << "\n";

	return 0;
}
