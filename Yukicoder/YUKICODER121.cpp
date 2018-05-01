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

/* -----  2018/04/26  Problem: yukicoder 121  / Link: http://yukicoder.me/problems/no/121  ----- */
/* ------問題------

ここ数日で門松列に関する問題が頻出しております．
ここでは演習を通じて，門松列に対する理解を深め，門松列の問題が出題された時に解けるようになっておきましょう．
門松列対策講座を受講される皆様は既にご存知かと思いますが，門松列とは 3 個の要素からなる数列 a,b,c で以下の 2 つの条件を満たすものです．
・a,b,c は全て異なる
・3 つの要素の中で b が最も大きい，または，b が最も小さい
さて，友紀さんは N 要素の整数列 A1,A2,…,AN を持っています．
友紀さんはこの配列の部分列として，門松列が何箇所出現するかを知りたいと思っています．
門松列の数を求めるプログラムを書いてください．
つまり，以下の条件を満たす整数の 3 つ組 (i,j,k) の数を求めるプログラムを書いてください．
・1≤i<j<k≤N かつ Ai,Aj,Ak が門松列

-----問題ここまで----- */
/* -----解説等-----

a,b,cがあったとき、aとcに、bからの条件しか与えられない時を考える。(a==cを許容した門松?列)  
これはbと同じ値でないa,cが存在して、a>b∧c>bまたはa<b∧c<bである数え上げを行えば良い。
数え上げは座標圧縮+BIT,bを決定することでO(NlogN)でできる。 
最後にa==cを除けば良い。純粋に式を書くとO(N^2)になるが、初期値0なので式の差分から更新していけばO(N)でできる。 (非直感的だと思う)
(個人的にはこれが一番ミソだと思った、指摘などお願いします)

----解説ここまで---- */

template<typename type>
struct BIT { // 1-index
	int N;
	int nn;
	vector<type> data;
	BIT(int n) {
		N = n + 1;
		data = vector<type>(n + 1, 0);
		nn = 1;
		while (nn * 2 <= N)nn *= 2;
	}
	void add(int i, type w) { // a[i] += w
		for (int x = i; x <= N; x += x & -x) {
			data[x] += w;
		}
	}
	type sum(int i) { // iまでの和 [1,i]
		type ret = 0;
		for (int x = i; x > 0; x -= x & -x) {
			ret += data[x];
		}
		return ret;
	}
	// [l, r]
	type sum(int l, int r) {
		if (l > r) return 0;
		return sum(r) - sum(l - 1);
	}
};


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VI a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI b = a;
	SORT(b);
	UNIQ(b);
	FOR(i, 0, N) {
		a[i] = lower_bound(ALL(b), a[i]) - b.begin() + 1;
	}

	BIT<LL>bitL(N), bitR(N);
	VL cntL(N, 0), cntR(N, 0);
	FOR(i, 0, N) {
		bitR.add(a[i], 1);
		cntR[a[i]]++;
	}

	FOR(i, 0, N) {
		bitR.add(a[i], -1);

		ans += bitL.sum(a[i] - 1)*bitR.sum(a[i] - 1);
		ans += bitL.sum(a[i] + 1, N)*bitR.sum(a[i] + 1, N);

		bitL.add(a[i], 1);
	}

	LL sum = 0;
	FOR(i, 0, N) { // a==cみたいなのを除く
		ans -= sum - cntL[a[i]] * cntR[a[i]];

		LL before = cntL[a[i]] * cntR[a[i]];
		cntL[a[i]]++;
		cntR[a[i]]--;

		LL diff = before - cntL[a[i]] * cntR[a[i]];
		sum -= diff;
	}

	cout << ans << "\n";

	return 0;
}
