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

ドワンゴのコンテンツ配信基盤システム Dwango Media Cluster は、略して DMC と呼ばれています。
この名前をかっこ良いと感じたニワンゴくんは、文字列の DMC らしさを数値として定義することにしました。
具体的には、長さ N のある文字列 S と3以上の整数 k が与えられた時、以下を満たす整数の3つ組 (a,b,c) の個数を S の k-DMC 数と呼ぶことにします。

0≤a<b<c≤N−1
S[a] = D
S[b] = M
S[c] = C
c−a<k
ここで、S[a] は S の a 番目の文字を表します。先頭の文字は 0 文字目として扱います (つまり、0≤a≤N−1 です)。

ある文字列 S と Q 個の整数 k0,k1,…,kQ−1 に対して、ki-DMC 数をそれぞれ計算してください。

-----問題ここまで----- */
/* -----解説等-----

真ん中でみがちだけど違う。
Dを見る。DからK以内のMCがカウントできれば良い。
あるCの手前にあるMの数と、DまでのMの数がわかるので、
累積和を持ったときに、
あるC[D,..,C]のMの総和がわかればこれの累積和から数を求めることができる。
これは累積和をつくってDまでの分をCの個数だけ引くと楽。

----解説ここまで---- */



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	string s; cin >> s;
	int Q; cin >> Q;
	vector<LL> csum(N + 1, 0);
	vector<LL> cMsum(N + 1, 0);
	vector<int>dpos;
	FOR(i, 0, N) {
		csum[i + 1] = csum[i] + (s[i] == 'C');
		cMsum[i + 1] = cMsum[i] + (s[i] == 'M');
		if (s[i] == 'D') {
			dpos.push_back(i);
		}
	}
	vector<LL>csumcsum(N + 1, 0);
	FOR(i, 0, N) {
		csumcsum[i + 1] = csumcsum[i];
		if (s[i] == 'C') {
			csumcsum[i + 1] += cMsum[i];
		}
	}
	DD(De(csum, cMsum, csumcsum, dpos));
	auto query = [&N](const vector<LL>&data, int l, int r) {
		r = min((int)N, r);
		return data[r] - data[l];
	};
	FOR(_, 0, Q) {
		int k; cin >> k;
		LL ans = 0;
		for (int i : dpos) {
			LL Ccnt = query(csum, i, i + k);
			LL msumsum = query(csumcsum, i, i + k);
			LL fron = query(cMsum, 0, i);
			LL ret = msumsum - Ccnt * fron;
			DD(de(Ccnt, msumsum, fron, ret));
			ans += ret;
		}
		cout << ans << endl;
	}
	return 0;
}
