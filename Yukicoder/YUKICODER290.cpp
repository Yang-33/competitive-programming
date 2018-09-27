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

/* -----  2018/09/27  Problem: yukicoder 290  / Link: http://yukicoder.me/problems/no/290  ----- */
/* ------問題------

0と1のみで構成される長さNの文字列Sが与えられる。 S[a,b]によってSのa文字目からb文字目まで(両端も含める)を繋げた部分文字列を表すとする。
1≤i≤jかつj+(j+1−i)≤Nを満たす2つの整数i,jに対して、S[i,j]=S[j+1,j+(j+1−i)]となるようなものが存在するか？

-----問題ここまで----- */
/* -----解説等-----

連続している部分が一致することを考える。これは単に0101010101のとき一致しうることになり、最小の場合は00/11を含むことになる。
N≧4では必ず0101か、00/11が存在するのでYESとなる。
それ以外は連続する部分のみが条件を満たすので、調べれば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N;  cin >> N;
	int ans = 0;
	string s; cin >> s;
	if (N >= 4) {
		ans = 1;
	}
	else if(N>=1){
		char prev=0;
		for (char c : s) {
			if (!prev)prev = c;
			else if (prev == c)ans = 1;
			prev = c;
		}

	}
	cout <<(ans?"YES":"NO") << endl;

	return 0;
}
