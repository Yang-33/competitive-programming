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

/* -----  2017/10/16  Problem: nagoya_19_01 AGC003 A / Link: https://agc003.contest.atcoder.jp/tasks/agc003_a  ----- */
/* ------問題------

高橋君は無限に広い 2 次元平面上に住んでいて、N 日間の旅行をします。 高橋君の旅程は長さ N の文字列 S であり、はじめは家にいます。i(1≦i≦N) 日目には、
S の i 文字目が N なら北に
S の i 文字目が W なら西に
S の i 文字目が S なら南に
S の i 文字目が E なら東に
正の距離だけ移動します。
高橋君は、各日の移動距離は決めていません。各日の移動距離をうまく決めることで、 高橋君が N 日間の旅程をすべて消化したときに家にいるようにできるかどうか判定してください。

-----問題ここまで----- */
/* -----解説等-----

適当に移動できるので
対称なものがあればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;
int dir[4];
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string S;
	cin >> S;
	FOR(i, 0, SZ(S)) {
		if (S[i] == 'N')dir[0]++;
		if (S[i] == 'S')dir[1]++;
		if (S[i] == 'W')dir[2]++;
		if (S[i] == 'E')dir[3]++;
	}

	int f = 1;
	FOR(i, 0, 2) {
		if (dir[2 * i] > 0 && dir[2 * i + 1] == 0)f = 0;
		if (dir[2 * i] == 0 && dir[2 * i + 1] > 0)f = 0;
	}
	cout << (f?"Yes":"No")<< "\n";

	return 0;
}