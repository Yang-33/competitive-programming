#include <bits/stdc++.h>
using namespace std;


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

/* -----  2018/11/15  Problem: ARC 021 C / Link: http://arc021.contest.atcoder.jp/tasks/arc021_c  ----- */
/* ------問題------

高橋君は友人達ととあるゲームをしている。
このゲームでは、プレイヤーは建物を購入し、増改築し、できるだけ多くお金を稼ぐことが目的となる。
高橋君は現在 2 位であり、どうにかして首位の青木君より多くのお金を稼がなければならない。
高橋君は、最も多くの回数増築したものに与えられる称号「増築王」を手に入れることで、政府から受ける援助金を利用して勝利しようと計画した。長年の経験から、あと K 回増築することで増築王になれることが分かっている。
高橋君は現在 N 軒の建物を所有している。建物には 1 から N まで番号がついている。最初、どの建物も増築されていない。
建物 i(1≦i≦N) について、以下のことが分かっている。
建物 i の増築前の価格は Ai である。
建物 i を 1 回増築するには、建物 i の現在の価格に等しい費用が必要となる。
建物 i の価格は、1 回増築する度に Di だけ上昇する。
高橋君は他の戦略も同時並行で実施するので、増築にかけるお金の合計値ができるだけ少なくなるようにしたい。
あなたは高橋君の代わりに K 回増築するのに必要な価格の合計値として考えられる最小値を求めてほしい。

-----問題ここまで----- */
/* -----解説等-----

二分探索。
ある金額を最大値にしたときにK個買えるかを判定する。
(A-D)+k*D≦Xをみたす非負整数kだけ買えるので、これをN個やれば良い。
上限が決まった時、金額も分かる。
注意力がないとここで終わってしまうが、上限を満たすXは連続ではない。
X-1としたときに-1個ならいいが、ちょうどXがたくさんあると、連続ではないため、K個以上買うために定めた金額ではたくさん買ってしまう場合がある。
長いが、K個買うXをきめたとき、複数個justXになる場合がある。
最小金額であるから、多い分を引く必要がある。

----解説ここまで---- */

using LL = __int128;
LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	long long  k, n; cin >> k >> n;
	LL K = k, N = n;
	vector<LL> A(N), D(N);
	FOR(i, 0, N) {
		int a, d; cin >> a >> d;
		A[i] = a, D[i] = d;
		//		cin >> A[i] >> D[i];
	}

	auto f = [&](LL X) {
		LL cnt = 0;
		FOR(i, 0, N) {
			LL subk = (X - (A[i] - D[i])) / D[i];
			cnt += max((LL)0, subk);
		}
		return cnt;
	};
	LL L = 0, R = 1e12;
	while (R - L > 1) {
		LL mid = (L + R) / 2;
		if (f(mid) >= K) {
			R = mid;
		}
		else {
			L = mid;
		}
	}
	LL UpperX = R;
	// Over Kに対応できていなさそう
	ans = 0;
	LL cnt = 0;
	FOR(i, 0, N) {
		LL subk = (UpperX - (A[i] - D[i])) / D[i];
		subk = max((LL)0, subk);
		cnt += subk;
		LL cost = subk * A[i] + (subk * (subk - 1) / 2)*D[i];
		ans += cost;
	}
	if (cnt > K) {// 同じ値段で同列になる場合
		ans -= (cnt - K)*UpperX;
	}

	cout << (unsigned long long)ans << "\n";

	return 0;
}