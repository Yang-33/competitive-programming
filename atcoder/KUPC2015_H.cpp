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
const int INF = 1e9;                          const LL LINF = 1e17;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/11/19  Problem: kupc2015_h / Link: https://kupc2015.contest.atcoder.jp/tasks/kupc2015_h  ----- */
/* ------問題------

正整数 X を二進数で表したときに出現する 1 の個数を， X のビットカウントという．
与えられる正整数 N について， X と X+N のビットカウントが等しくなるような正整数 X は存在するだろうか?
存在するならばその最小値を，存在しないなら −1 を出力せよ．

-----問題ここまで----- */
/* -----解説等-----

むずかしいなあ…
実際にXを構成していくことを考える。
X,X+Nの1の数は一緒でない場合にはこれは構成失敗となる。
ここでX+Nのpopcountを数え、かつ目指すべきものに対してどれだけpopcount に差があるかを
持っておく。N,Xの組は4通りであり、これは場合分けをすることで何とかなる。
繰り上がりがあるので、これに影響を受けるものとウケないものを区別すれば構成ができる。
構成されたN+Xについて、11111{?}のとき、繰り上がりが起きると今までのdiffは消えて、1が減少する。
これについて遷移が上手くいくように、X,X+Nのdiffをとれるようにする。
具体的には連続している部分と影響が出ない1の数をきろくしておけばよい。

----解説ここまで---- */


LL dp[64][64][128];

LL f(LL n, int i, int one, int diff) {//今まで見たところに連続して1が何個立っているか
	assert(diff >= 0);
	if (i == -1) {
		if (one + diff == 63) {
		//	debug(one);
			return 0;
		}
		else return LINF;
	}
	if (dp[i][one][diff] != -1)return dp[i][one][diff];
	LL res = LINF;

	// x[i]:=0
	if (n&(1LL << i)) res = min(res, f(n, i - 1, one + 1, diff));
	else res = min(res, f(n, i - 1, 0, diff + one));

	// 1
	if (n&(1LL << i)) res = min(res, f(n, i - 1, 0, diff) | (1LL << i));//繰り上がり
	else res = min(res, f(n, i - 1, one + 1, diff - 1) | (1LL << i));//繰り上がらない



	return dp[i][one][diff] = res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;

	//reverse ? 

	FOR(_, 0, T) {
		LL n; cin >> n;
		fill(**dp, **dp + 64 * 64 * 128, -1);
		cout << f(n, 62, 0, 63) << endl;
	}

	return 0;
}
