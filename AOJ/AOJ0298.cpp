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

/* -----  2018/07/23  Problem: AOJ 0298 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0298  ----- */
/* ------問題------

バスマニアの健次郎君は、Ａ市内のバスをよく利用しています。ある日ふと、健次郎君の家の前のバス停から出発するすべてのバスを写真に収めることを思い立ちました。このバス停には飯盛山行きと鶴ケ城行きの２つのバス路線が通ります。各路線の時刻表は手に入れましたが、１つの時刻表としてまとめた方がバス停で写真が撮りやすくなります。
健次郎君を助けるために、２つの路線の時刻表を、０時０分を基準として出発時刻が早い順に１つの時刻表としてまとめるプログラムを作成してください。

-----問題ここまで----- */
/* -----解説等-----

setで良くないですか????

----解説ここまで---- */

template<class T> using V = vector<T>; template<class T> using VV = V<V<T>>;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	using PII = pair<int, int>;
	V<PII>a;
	FOR(i, 0, N) {
		int h, m; cin >> h >> m;
		a.push_back(PII(h, m));
	}
	cin >> N;
	FOR(i, 0, N) {
		int h, m; cin >> h >> m;
		a.push_back(PII(h, m));
	}
	SORT(a);
	UNIQ(a);
	FOR(i, 0, SZ(a)) {
		int h = a[i].first; int m = a[i].second;
		printf("%d:%02d", h, m);
		printf("%c", " \n"[i == (SZ(a) - 1)]);
	}


	return 0;
}