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

/* -----  2019/05/26  Problem: AOJ 2236 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2236  ----- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N; cin >> N;
	bool taosenai = 0;
	using tp = tuple<LL, LL, LL, LL>;
	vector<tp>A;
	LL mh, ma, md, ms; cin >> mh >> ma >> md >> ms;
	LL mhorigin = mh;
	FOR(i, 0, N) {
		LL h, a, d, s; cin >> h >> a >> d >> s;
		if (ma <= d && md < a)taosenai = 1;
		if (ma <= d)continue; // コレはいっていては永遠に無駄な攻撃をし合うが，何(34ケース目にある)
		A.push_back(tp(h, a, d, s));
	}

	if (taosenai || mh <= 0) {
		cout << -1 << endl;
		return 0;
	}
	DD(de(mh));
	// damege 最小で sort
	auto turn = [&](LL hp, LL defence) {
		return (hp + (ma - defence) - 1) / (ma - defence);
	};
	auto hidamege_per_turn = [&](LL atk) {
		return max(0LL, atk - md);
	};
	sort(ALL(A), [&](const tp &L, const tp &R) {
		return hidamege_per_turn(get<1>(R))*turn(get<0>(L), get<2>(L)) < hidamege_per_turn(get<1>(L))*turn(get<0>(R), get<2>(R));
	});

	// 順序が決まったのでシュミレーション
	LL turnsum = 0;
	FOR(i, 0, SZ(A)) {
		// 倒すのに必要なターンだけダメージを受ける
		LL t = turn(get<0>(A[i]), get<2>(A[i]));
		DD(de(t));
		turnsum += t;
		mh -= turnsum * hidamege_per_turn(get<1>(A[i]));
		if (get<3>(A[i]) < ms) { // 自分の方がはやい
			mh += hidamege_per_turn(get<1>(A[i]));
		}
		if (mh < 0)break;
	}




	if (mh <= 0) {
		cout << -1 << endl;
		return 0;
	}
	DD(de(mhorigin, mh));
	cout << mhorigin - mh << endl;

	return 0;
}
