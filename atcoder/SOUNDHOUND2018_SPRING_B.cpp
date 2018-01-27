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

/* -----  2018/01/27  Problem: soundhound2018_spring B / Link: https://soundhound2018.contest.atcoder.jp/tasks/soundhound2018_b  ----- */
/* ------問題------

kenkooooさんはSoundHound社で働いています。彼は今日、音量を調整する機能を作ることにしました。
この機能では、n 秒の間毎秒与えられる入力に対し、ある大きさの音量を出力します。i 秒目の入力を ai とします。
もし、 ai が出力の下限 L を下回っていた場合、出力は L とし、ai が上限 R を上回っていた場合、出力を R とします。
どちらでもないときは、出力を ai とします。n 秒間の入力 ai、L と R が与えられるので、n 個の出力 bi を得るプログラムを書いてください。

-----問題ここまで----- */
/* -----解説等-----

問題文をそのまま愚直に書きます。

----解説ここまで---- */

LL N,L,R;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	cin >> L >> R;
	VL a(N);
	FOR(i, 0, N) {
		cin >> a[i];
		if (a[i] < L)cout << L << endl;
		else if (a[i] > R)cout << R << endl;
		else cout << a[i] << endl;
	}

	return 0;
}
