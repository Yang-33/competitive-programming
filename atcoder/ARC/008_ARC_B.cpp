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

/* -----  2018/12/06  Problem: ARC 008 B / Link: http://arc008.contest.atcoder.jp/tasks/arc008_b  ----- */
/* ------問題------

あなたはたこ焼きを買いに来たところ、伝説のたこ焼きマスター高橋社長に認められ、新しく作るたこ焼き屋さんの店長を任されました。
店長に任命されたあなたに与えられた最初の仕事は、お店の看板を作成することでした。
ところが高橋社長は使えない時間がないので、たこ焼き屋さんの名前は決めましたが、看板を作るのはあなたに任せて去って行きました。
その際に看板を作るための英字ブロックが入ったいくつかのキットを渡されました。
英字キットとは、ランダムな英字ブロックが含まれている袋のことです。
例えば英字キットを表す文字列が ABCC であるような英字キットの場合、
英字ブロックAが1つ含まれている。
英字ブロックBが1つ含まれている。
英字ブロックCが2つ含まれている。
とみなすことができます。
つまり、英字キット ABCC 1 袋につき、英字ブロックAと英字ブロックBを1つずつ、英字ブロックCを2つを看板に用いることができます。
高橋社長から渡された英字キットは全て同じ英字キットだったので、どのキットを開けても中身は全く同じです。
あなたは看板にお金をかけるわけにもいかないので、開封する英字キットを最小にして残りは返品したいです。
どれだけの英字キットを使うことで、お店の看板を作ることができるでしょうか。

-----問題ここまで----- */
/* -----解説等-----

あるアルファベットCについて、つくりたい数A,素材あたりの数Bがわかっている。
A/Bの切り上げを求めれば良い、B=0にだけ気をつける。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	string s, t; cin >> s >> t;
	map<char, int>Scnt, Tcnt;
	FOR(i, 0, SZ(s)) {
		Scnt[s[i]]++;
	}
	FOR(i, 0, SZ(t)) {
		Tcnt[t[i]]++;
	}
	int ans = 0;
	for (auto it : Scnt) {
		int res = Tcnt[it.first];
		if (res == 0)ans = -1;
		if (ans == -1)break;
		ans = max(ans, (res + it.second - 1) / res);
	}
	if (ans == 0)ans = -1;

	cout << ans << endl;

	return 0;
}
