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

/* -----  2018/04/11  Problem: yukicoder 049  / Link: http://yukicoder.me/problems/no/049  ----- */
/* ------問題------

太郎君は算数がとても苦手で、算数の宿題が出て困っています。
今日出た宿題は足し算と掛け算の問題で、明日までに解いていかなければならないので、
困っている太郎君の代わりに解いてあげてください。

太郎君の国では、足し算は'*'の記号で、また、掛け算は'+'の記号で表されます。
また、足し算と掛け算に優先度はなく、左から順番に計算します。

-----問題ここまで----- */
/* -----解説等-----

構文解析みたいなのを書く必要はなくて、状態遷移していけば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	LL ret = 0, sub = 0;
	int mode = 0;
	FOR(i, 0, SZ(s)) {
		if (isdigit(s[i])) {
			sub *= 10;
			sub += s[i] - '0';
		}
		else {
			if (mode == 1) { // +
				ret += sub;
			}
			else if(mode == 2){
				ret *= sub;
			}
			else {
				ret = sub;
			}

			sub = 0;
			if (s[i] == '+') {
				mode = 2;
			}
			else {
				mode = 1;
			}
		}
	}

	if (mode == 1) { // +
		ret += sub;
	}
	else if(mode == 2){
		ret *= sub;
	}
	else {
		ret = sub;
	}
	ans = ret;

	cout << ans << "\n";

	return 0;
}
