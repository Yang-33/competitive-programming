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

/* -----  2018/07/31  Problem: yukicoder 200  / Link: http://yukicoder.me/problems/no/200  ----- */
/* ------問題------

「カードファイト！」というゲームが流行っているらしい。
このゲームのプレーヤーをカードファイターと呼ぶ。
まずカードファイターは数字が1つ書かれたカードを何枚か持っている。
そして、1つの試合ごとに手持ちのカードを自由に1枚出しその数字の大小を競う。
（数字が同じ場合には引き分けであり、勝ち負けは発生しない。）
カードファイターは試合のたびに使用したカードを場に出す。
カードファイターはすべてのカードを出し終わると、
いままでに自分が出した場のカードをすべて回収し再び使うことができる。

A君はキング・オブ・カードファイターである。
A君とC君は「カードファイト！」大会の決勝で戦うことになった。
キング・オブ・カードファイターであるA君はどうしてもC君により多く勝ちたい。
(問われるのは勝ち数であり、引き分けと負けの数は問わない。)
C君に話をもちかけるとC君はあっさりとA君が勝てるようにすることを承諾した。
A君はより多くの試合に勝てるようにC君とカードを出す順番を話しあった。
A君もC君もA君の勝ち数が最多になるようにカードを出す順番を決めた。
A君はC君に最大何試合勝てるだろうか？

-----問題ここまで----- */
/* -----解説等-----

貪欲にとって、捨てるときは貪欲に捨てる。
ギリギリ勝つか、大きく負けるのが良い。

0/1の最小費用流でも解けるっぽい。(そう)

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, A, C;
	cin >> N;
	cin >> A;
	VI B(A);
	FOR(i, 0, A) {
		cin >> B[i];
	}
	cin >> C;
	VI D(C);
	FOR(i, 0, C) {
		cin >> D[i];
	}

	int ans = 0;
	SORT(B), SORT(D);
	multiset<int>Bs(ALL(B)), Ds(ALL(D));

	FOR(i, 0, N) {
		if (*Bs.rbegin()> *Ds.begin()) {
			auto itb = Bs.upper_bound(*Ds.begin());
			auto itd = Ds.lower_bound(*itb);
			itd--;
			Bs.erase(itb);
			Ds.erase(itd);
			ans++;
		}
		else {
			Bs.erase(Bs.begin());
			auto erad = Ds.end();
			erad--;
			Ds.erase(erad);
		}

		if (!SZ(Bs))Bs.insert(ALL(B));
		if (!SZ(Ds))Ds.insert(ALL(D));
	}

	cout << ans << "\n";

	return 0;
}
