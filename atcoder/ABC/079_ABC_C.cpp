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

/* -----  2017/11/18  Problem: ABC 079 C / Link: http://abc079.contest.atcoder.jp/tasks/abc079_c  ----- */
/* ------問題------

駅の待合室に座っているjoisinoお姉ちゃんは、切符を眺めています。
切符には 4 つの 0 以上 9 以下の整数 A,B,C,D が整理番号としてこの順に書かれています。
A op1 B op2 C op3 D = 7 となるように、op1,op2,op3 に + か - を入れて式を作って下さい。
なお、答えが存在しない入力は与えられず、また答えが複数存在する場合はどれを出力してもよいものとします。

-----問題ここまで----- */
/* -----解説等-----

全探索、区切りに注意

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	VI a(4);
	FOR(i, 0, 4)a[i] = s[i] - '0';
	FOR(i, 0, 1 << 3) {
		int ret = a[0];
		FOR(j, 0, 3) {
			if (i&(1 << j)) {
				ret += a[j+1];
			}
			else ret -= a[j+1];
		}
		if (ret == 7) {
			FOR(k, 0, 4) {
				cout << s[k];
				if (k < 3) {
					if(i&(1<<k)){
						cout << "+";
					}
					else {
						cout << "-";
					}
				}
			}
			cout << "=7\n";
			return 0;
		}
	}

	return 0;
}
