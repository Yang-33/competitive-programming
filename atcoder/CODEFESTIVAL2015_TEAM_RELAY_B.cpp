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

/* -----  2018/12/21  Problem: codefestival2015_team_relay B / Link: __CONTEST_URL__  ----- */
/* ------問題------

チーム戦では協力が大切である。現在あなたはチーム対抗早解きリレーに参加している。目指すはもちろん全完（全問完答）だ。
リレーは 10 人のチームで行い、 問題 1 から問題 10 までの 10 問が与えられる。必ず一人 1 問を担当しなければならず、複数の問題を同じ人が解くことはできない。各チームメンバーについて解くことの出来る問題のリストが与えられるので、チーム全体で全ての問題に正答出来るかを判定せよ。ただし各チームメンバーは、自分が解けない問題もその問題を解くことの出来るメンバーに解法を教えてもらうことによって必ず解くことが出来るようになる。また実際のリレーには時間制限があるが、この問題では無視する。



-----問題ここまで----- */
/* -----解説等-----

縦に存在するかを見れば良い。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N = 10;
	VS vs(N);
	FOR(i, 0, N) {
		cin >> vs[i];
	}
	int ok = 1;
	FOR(j, 0, N) {
		int ret = 0;
		FOR(i, 0, N) {
			ret |= vs[i][j] == 'o';
		}
		ok &= ret;
	}
	cout << (ok ? "Yes" : "No") << endl;

	return 0;
}
