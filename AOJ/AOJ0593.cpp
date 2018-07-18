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

/* -----  2018/07/23  Problem: AOJ 0593 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/0593  ----- */
/* ------問題------

20XX年に東京で世界的なスポーツ大会が開かれることになった．プログラミングコンテストはスポーツとして世界で楽しまれており，競技として採用される可能性がある．採用される競技を決める審査委員会について調べたところ，次のようなことが分かった．
審査委員会のために，候補となる N 個の競技を面白い方から順番に並べたリストが作成された．リストの上から i 番目には i 番目に面白い競技が書かれている．それを競技 i とする．さらに競技 i の開催に必要な費用 Ai が書かれている．
また，審査委員会は委員 1 から委員 M までの M 人の委員で構成されている．委員 j は自分の審査基準 Bj をもっており，開催に必要な費用が Bj 以下の競技のうち最も面白いものに 1 票を投票した．
どの委員の審査基準に対しても，少なくとも 1 つの競技は開催に必要な費用が審査基準以下であった．したがって，委員は全員 1 票を投票した．
最も多く票を獲得した競技は 1 つだけであった．
競技のリストと委員の情報が与えられたとき，最も多く票を獲得した競技の番号を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

日本語の理解を頑張る。

----解説ここまで---- */


template<class T> using V = vector<T>;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, M; cin >> N >> M;
	V<int>A(N), B(M);
	FOR(i, 0, N) {
		cin >> A[i];
	}
	FOR(i, 0, M) {
		cin >> B[i];
	}
	V<int>cnt(N + 1);
	FOR(i, 0, M) {
		FOR(j, 0, N) {
			if (B[i] >= A[j]) {
				cnt[j]++;
				break;
			}
		}
	}
	int ans = 0;
	int id = 0;
	FOR(i, 0, N) {
		if (ans < cnt[i]) {
			ans = cnt[i];
			id = i + 1;
		}
	}

	cout << id << endl;

	return 0;
}