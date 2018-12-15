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

/* -----  __MAKE_TIME__  Problem: __PROBLEM__ / Link: __CONTEST_URL__  ----- */
/* ------問題------

ドワンゴ社員のニワンゴくんは、投稿された動画からサムネイルを生成する機能を実装することになりました。
動画からサムネイルとするフレームを選択する手順は以下の通りです。

動画の総フレーム数 N と、動画の各フレームを1つの整数で表現した長さ N の整数列 a を入力として受け取る
各フレームには、先頭から順番に 0,1,…,N−1 のフレーム番号が付いており、フレーム番号 i を表現する整数は ai である
a の平均値に最も近いフレームをサムネイルとする
そのようなフレームが複数ある場合、それらの中で最もフレーム番号の小さいものをサムネイルとする
この手順で得られる、サムネイルとして選択されるフレーム番号を出力してください。

-----問題ここまで----- */
/* -----解説等-----

誤差が怖いのでちゃんと割り算を使わない形に変形する。
average - a[i]の差が最小→sum - N*a[i]の差が最小

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	vector<int>a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	int sum = accumulate(a.begin(), a.end(), 0);
	using PII = pair<int, int>;
	vector<PII>b(N);
	int sub = 1000000; 
	int id = 0;
	FOR(i, 0, N) {
		b[i] = PII(abs(sum - N * a[i]), i);
		if (sub > b[i].first) {
			sub = b[i].first;
			id = i;
		}
	}

	cout << id << endl;

	return 0;
}
