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

/* -----  2019/01/27  Problem: ARC 060 D / Link: http://arc060.contest.atcoder.jp/tasks/arc060_d  ----- */
/* ------問題------

x を長さ 1 以上の文字列とします。 いかなる文字列 y および 2 以上の整数 k に対しても、 y を k 回繰り返した文字列が x と異なるならば、 x を良い文字列であると呼ぶことにします。 例えば、a, bbc, cdcdc などは良い文字列ですが、 aa, bbbb, cdcdcd などは良い文字列ではありません。

w を長さ 1 以上の文字列とします。 m 項からなる列 F=( f1, f2, …, fm) について、 次の条件がともに満たされるならば、F を w の良い表現と呼ぶことにします。

すべての i (1≤i≤m) について、fi は良い文字列である。
f1, f2, …, fm をこの順に連結すると w になる。
例えば、w=aabb の場合、w の良い表現は次の 5 つとなります。

(aabb)
(a,abb)
(aab,b)
(a,ab,b)
(a,a,b,b)
文字列 w の良い表現のうち、項数 m が最小であるものを、 w の最良表現と呼ぶことにします。 例えば、w=aabb の最良表現は (aabb) の 1 つのみとなります。

文字列 w が与えられます。次の 2 つを求めてください。

w の最良表現の項数
w の最良表現の総数を 1000000007 (=109+7) で割った余り
なお、w に対し、良い表現が存在することは保証されます。

-----問題ここまで----- */
/* -----解説等-----

全部難しい．実装までアイディアがいるけど，わかれば簡単なので面白い．
答えの分割数は，(1,2,|w|)のいずれかである．
	1. 1 := wがそもそも周期1の文字列のとき
	2. 2 := wが周期>1の文字列であるとき
		* s1 + s2と分割すれば良い
		* 例えば，1文字 + |w|-1文字と分割すれば必ず大丈夫
		* というのも，残りの文字列が周期>1のとき，全部同じ文字の場合しか無い
	3. |w|:= 全部同じ文字列

したがって，文字列の周期判定ができれば良い．

1のとき: |w|の約数dを全部みて，s[0,...),s[d,...|w|)のLCPが|w|-d 以上ならば周期であるから，全ての約数でそうでなければ1．

2のとき: 適当な2分割が行われたときに，片側が周期>1の文字列ならダメ．
方針がたったときに，実装が分割点をみる→両側についての周期列判定をするとして，計算量がO(d(N)*N)から落ちなかった
以下のようにして改善する．
区切ってはだめな場所を見つける．
周期dとして，dを|w|回試す．左側についてみたとき，s[0,d)とs[d,k*d)(k>1)について，周期列ならk*dで分割してはダメ．
右側についてみたとき，s[|w|-d,|w|)とs[|w|-k*d,|w|-d)(k>1)について，周期列ならk*dで分割してはダメ．
とすると，調和級数になって，O(|w|log|w|*f(w)) (f(w)はLCPの計算量)として解ける．

----解説ここまで---- */


// uLLでやると危険ということがわかった
// 拝借しました
template< unsigned mod >
struct RollingHash {
	vector< unsigned > hashed, power;
 
	inline unsigned mul(unsigned a, unsigned b) const {
		unsigned long long x = (unsigned long long) a * b;
		unsigned xh = (unsigned)(x >> 32), xl = (unsigned)x, d, m;
		asm("divl %4; \n\t" : "=a" (d), "=d" (m) : "d" (xh), "a" (xl), "r" (mod));
		return m;
	}
 
	RollingHash(const string &s, unsigned base = 10007) {
		int sz = (int)s.size();
		hashed.assign(sz + 1, 0);
		power.assign(sz + 1, 0);
		power[0] = 1;
		for (int i = 0; i < sz; i++) {
			power[i + 1] = mul(power[i], base);
			hashed[i + 1] = mul(hashed[i], base) + s[i];
			if (hashed[i + 1] >= mod) hashed[i + 1] -= mod;
		}
	}
 
	unsigned get(int l, int r) const {
		unsigned ret = hashed[r] + mod - mul(hashed[l], power[r - l]);
		if (ret >= mod) ret -= mod;
		return ret;
	}
 
	unsigned connect(unsigned h1, int h2, int h2len) const {
		unsigned ret = mul(h1, power[h2len]) + h2;
		if (ret >= mod) ret -= mod;
		return ret;
	}
 
	int LCP(const RollingHash< mod > &b, int l1, int r1, int l2, int r2) {
		int len = min(r1 - l1, r2 - l2);
		int low = -1, high = len + 1;
		while (high - low > 1) {
			int mid = (low + high) / 2;
			if (get(l1, l1 + mid) == b.get(l2, l2 + mid)) low = mid;
			else high = mid;
		}
		return (low);
	}
};
 
 
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
 
	string s; cin >> s;
	// 全部一緒(N,1)
	{
		int same = 1;
		FOR(i, 0, SZ(s)) {
			same &= s.front() == s[i];
		}
		if (same) {
			cout << SZ(s) << endl;
			cout << 1 << endl;
			return 0;
		}
	}
	// 周期判定(1,1)
	{
		RollingHash<1'000'000'007> rh(s);
		int periodOne = 1;
		// どのような分割も周期をもたない
		FOR(i, 0, SZ(s) - 1) {
			int prefixsz = i + 1;
			if (SZ(s) % prefixsz == 0) {
 
				int periodLCP = rh.LCP(rh, 0, SZ(s), i + 1, SZ(s));
				periodOne &= (periodLCP < SZ(s) - prefixsz);
			}
		}
		if (periodOne) {
			cout << 1 << endl;
			cout << 1 << endl;
			return 0;
		}
	}
	// その他 (2,N-1-分割しちゃダメ)
	{
		// WA
		// 最後のケースはnodiv[k]=1が存在しない
		auto f = [](const string& s) {
			RollingHash<1'000'000'007>rh1(s);
			RollingHash<1'000'000'009>rh2(s);
			VI noDivide(SZ(s), 0);
			using uLL = unsigned long long;
			using PUU = pair<uLL, uLL>;
			FOR(prefixsz, 1, SZ(s)) {
				const auto prefixHash = PUU(rh1.get(0, prefixsz), rh2.get(0, prefixsz));
				for (int k = 2 * prefixsz; k <= SZ(s); k += prefixsz) {
					if (prefixHash == PUU(rh1.get(k-prefixsz, k), rh2.get(k - prefixsz, k))) {
						noDivide[k - 1] = 1;
						//DD(de(0, prefixsz));
					}
					else {
						break;
					}
				}
			}
			DD(de(accumulate(ALL(noDivide),0)))
			return noDivide;
		};
		// 前から
		auto prefixdiv = f(s);
		// 後ろから
		string t = s;
		reverse(ALL(t));
		auto suffixdiv = f(t);
		reverse(ALL(suffixdiv));
 
 
		int ans = SZ(s) - 1;
		DD(de(ans));
		FOR(i, 0, SZ(s) - 1) {
			ans -= (prefixdiv[i] || suffixdiv[i+1]);
		}
		cout << 2 << endl;
		cout << ans << endl;
	}
 
	
 
 
	return 0;
}