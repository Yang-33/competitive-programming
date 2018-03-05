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

/* -----  2018/03/04  Problem: 071_arc_c / Link: https://arc071.contest.atcoder.jp/tasks/arc071_c?lang=en  ----- */
/* ------問題------

A, B からなる文字列に対して、次の操作を考えます。
文字列中の 1 文字を選ぶ。それが A なら BB で、 B なら AA で置き換える。
AAA か BBB であるような部分文字列を選び、消す。
例えば、ABA という文字列で 1 番目の操作を 1 文字目に対して行うと、 BBBA となります。 また、BBBAAAA に対して 2 番目の操作を 4 文字目から 6 文字目に対して行うと、 BBBA となります。
これらの操作を何回でも好きな順で行うことができます。
文字列 S,T と q 個のクエリ ai,bi,ci,di が与えられます。 各クエリに対して、 S の部分文字列 SaiSai+1…Sbi を T の部分文字列 TciTci+1…Tdi にすることができるか判定してください。

-----問題ここまで----- */
/* -----解説等-----

規則性から、A->BB->AAAA->A, B->AA->BBBB->Bと環?になっている
AB->AAA->φ
BA->BBB->φ
から、状態は3種類しかない。
したがってこれは適当にセグ木や累積和で区間の状態を持つことができる。
あとはクエリO(1)で答えるのみ

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s, t; cin >> s >> t;
	VI sums(SZ(s) + 1, 0);
	VI sumt(SZ(t) + 1, 0);
	FOR(i, 0, SZ(s)) {
		sums[i + 1] = sums[i] + (s[i] == 'A' ? 1 : 2);
	}
	FOR(i, 0, SZ(t)) {
		sumt[i + 1] = sumt[i] + (t[i] == 'A' ? 1 : 2);
	}

	int Q; cin >> Q;
	FOR(i, 0, Q) {
		int a, b, c, d;
		cin >> a >> b >> c >> d; // [a,b] ? [c,d]
		int vals = (sums[b] - sums[a-1])%3;
		int valt = (sumt[d] - sumt[c-1])%3;
		if (vals == valt) {
			cout << "YES" << endl;
		}else{
			cout << "NO" << endl;
		}
	}

	return 0;
}
