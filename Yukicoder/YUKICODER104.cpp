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

/* -----  2018/04/23  Problem: yukicoder 104  / Link: http://yukicoder.me/problems/no/104  ----- */
/* ------問題------

ユキコダ国には1からはじまる番号のついた国道がある。
国道を判別するため同じ番号の国道は2つ以上無い。
まずユキコダ城から国道1号線がスタートしている。
国道は必ずいつか左と右の道に分岐する。
国道はより小さな番号の国道から、使えるより小さな番号を使って分岐する。
分岐する際に左の国道のほうが右の国道よりかならず番号が小さい。
1号線は左の2号線と右の3号線に分岐する。
2号線は左の4号線と右の5号線に分岐する。
3号線は左の6号線と右の7号線に分岐する。
4号線は左の8号線と右の9号線に分岐する。
5号線は左の10号線と右の11号線に分岐する。
このようなルールで国道には番号がついている。

いまA君はユキコダ城を出て引き返すことなくいくつかの分岐点を通過した。
A君は順番に左と右のどちらに分岐したかを覚えている。
A君がいま何号線を歩いているかを答えよ。

-----問題ここまで----- */
/* -----解説等-----

二分木をたどる操作と一緒

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string s; cin >> s;
	ans = 1;
	FOR(i, 0, SZ(s)) {
		if (s[i] == 'L') {
			ans *= 2;
		}
		else {
			ans = 2 * ans + 1;
		}
	}
	cout << ans << "\n";

	return 0;
}
