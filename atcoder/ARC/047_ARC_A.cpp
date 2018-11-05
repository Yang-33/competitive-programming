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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/05  Problem: ARC 047 A / Link: http://arc047.contest.atcoder.jp/tasks/arc047_a  ----- */
/* ------問題------

高橋君はブラウザでネットサーフィンをするのが大好きです。
しかし、タブを開きすぎる癖があるので、よくブラウザがクラッシュします。
高橋君が使っているブラウザは開かれているタブが L 個を超えるとクラッシュします。
ブラウザはクラッシュすると自動で再起動して、1 個のタブが開いている状態になります。
初め、高橋君のブラウザは 1 個のタブが開かれている状態です。
そのあとの高橋君の「新しいタブを開く」と「タブを閉じる」の履歴が与えられるので、高橋君が何回ブラウザをクラッシュさせるかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

シュミレーションすれば良い。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, L; cin >> N >> L;
	string s; cin >> s;
	int state = 1;
	for (char c : s) {
		if(c=='+')state++;
		else state--;
		if (L < state) {
			ans++;
			state = 1;
		}

	}
	
	
	cout << ans << "\n";

	return 0;
}
