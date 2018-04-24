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

/* -----  2018/04/24  Problem: yukicoder 120  / Link: http://yukicoder.me/problems/no/120  ----- */
/* ------問題------

ここ数日で門松列に関する問題が頻出しております．
ここでは演習を通じて，門松列に対する理解を深め，門松列の問題が出題された時に解けるようになっておきましょう．
門松列対策講座を受講される皆様は既にご存知かと思いますが，門松列とは 3 個の要素からなる数列 a,b,c で以下の 2 つの条件を満たすものです．
・a,b,c は全て異なる
・3 つの要素の中で b が最も大きい，または，b が最も小さい
さて，雪さんは N 本の竹を持っていて，k 番目の竹の長さは Lk です．
雪さんは，この竹を使って，できるだけ多くの門松を作りたいです．
勿論，1 個の門松には，3 本の竹を使い，その竹の長さは門松列でなければいけません．
使う 3 本の竹は自由に選んでよく，また門松列にするために自由に並び替えて良いです．
雪さんは，最大でいくつの門松を作ることができるかを求めるプログラムを書いてください．
竹はすぐ育つとは言いますが，自然の宝であり，切ったり繋げたりすることはせず，雪さんはこれらの竹をそのまま使用します．

-----問題ここまで----- */
/* -----解説等-----

左右とかやるのは良くなくて、(ex:122223456789)  
頻度の高いものを使っていかないと行けなさそうなので、頻度の高いものから取り出していけば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int T; cin >> T;
	FOR(t, 0, T) {
		int N; cin >> N;
		VI a(N);
		map<int, int>Map;
		FOR(i, 0, N) {
			cin >> a[i];
			Map[a[i]]++;
		}
		priority_queue<int>pq;
		for (auto m : Map) {
			pq.push(m.second);
		}
		int ans = 0;

		while (pq.size() > 2) {
			int a = pq.top(); pq.pop();
			int b = pq.top(); pq.pop();
			int c = pq.top(); pq.pop();
			if (c<=0) {
				break;
			}
			ans++;
			if (a)pq.push(a - 1);
			if (b)pq.push(b - 1);
			if (c)pq.push(c - 1);

		}

		cout << ans << "\n";

	}

	return 0;
}
