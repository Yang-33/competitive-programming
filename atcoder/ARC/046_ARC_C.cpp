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

/* -----  2018/11/04  Problem: ARC 046 C / Link: http://arc046.contest.atcoder.jp/tasks/arc046_c  ----- */
/* ------問題------

高橋君と青木君は合コンを企画しました。 2 人は N 人の男性と、 M 人の女性を集めることに成功しました。男性には 1 から N の、女性には 1 から M の番号がそれぞれ割り当てられています。企画者である高橋君と青木君の目的はこの合コンで成立するカップルの数を最大化することです。 ここで、カップルとは 1 組の男女のことです。また、それぞれの人は 2 つ以上のカップルに含まれていてはいけません。
i(1≦i≦N) 番の男性は年収が Ai 円であり、年収が Bi 円以上の女性とカップルになりたいと考えています。 j(1≦j≦M) 番の女性は年収が Cj 円であり、年収が Dj 円以上の男性とカップルになりたいと考えています。
高橋君と青木君は i 番の男性と j 番の女性の要求が同時に満たされるとき、すなわち Bi≦Cj かつ Dj≦Ai が満たされるとき、 i 番目の男性と j 番目の女性によるカップルを成立させることが可能です。
この合コンで成立させることができるカップルの数の最大値を調べるのがあなたの仕事です。

-----問題ここまで----- */
/* -----解説等-----

double keyの貪欲的な解法はone key sort + set/priority_queueが王道ってそれ一番言われているから
ということで実装する。
問題を以下のように言い換える。
希望金額順に女性が待っているので男性は年収順に並んで自分の希望にしたがう女性を選択する。(人権)
これはmatchingにほぼ近いことをしており正しい。
正しくないとするとよりよい選択が存在することになるが、それはない(?????)

>> これは、二次元にmapするととてもわかり易い。
A,Dの軸とB,Cの軸を見ればわかって、条件を満たすものを片方の軸についてシュミレーションしながら貪欲をすればよい。

----解説ここまで---- */

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, M; cin >> N >> M;
	VI A(N), B(N), C(M), D(M);
	vector<PII>events;
	FOR(i, 0, N) {
		cin >> A[i] >> B[i];
		events.push_back(PII(A[i], i + M));
	}
	FOR(i, 0, M) {
		cin >> C[i] >> D[i];
		events.push_back(PII(D[i], i));
	}
	SORT(events);
	multiset<int>se;
	for (PII it : events) {
		int id, val;
		tie(val, id) = it;
		if (id >= M) { // man
			auto iter = se.lower_bound(B[id-M]);
			if (iter != se.end()) {
				ans++;
				se.erase(iter);
			}
		}
		else { // women
			se.insert(C[id]);
		}

	}



	
	cout << ans << "\n";

	return 0;
}
