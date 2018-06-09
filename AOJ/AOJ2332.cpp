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

/* -----  2018/06/10  Problem: AOJ 2332 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2332  ----- */
/* ------問題------

全時空統一ディメンション・スゴロク・トーナメント。500 兆人を超える参加者の中から、ただ１人 のスゴロク絶対王者を決定するその大会に、あなたは２１世紀の地球代表として参加している。

今あなたが挑戦している課題は、自分自身をコマとした１次元スゴロク。端のスタートマスから出発 して、１から６までの目が一つずつ書かれた巨大な６面ダイスを振って出た目の数だけ進むことを繰 り返す、あなたもよく知っている形式のスゴロクだ。スタートマスとは反対の端にあるゴールマスに 止まるとゴールとなる。もちろん、ゴールするまでにサイコロを振った回数が少なければ少ないほど 良い成績となる。

マスの中には特殊な効果を持ったマス「○マス進む」と「○マス戻る」が存在し、そこに止まってし まうと、指定されたマス数だけ進む、もしくは戻らなければならない。マスの効果で動いた結果、ふ たたび効果のあるマスに止まった場合は、続けて指示どおりに移動する。

しかし、これは一筋縄では攻略できない時空スゴロクだ。恐るべきことに、たとえば「３マス進む」 の３マス先に「３マス戻る」が置かれていることもありうる。このようなマスに止まり、マスの効果 で無限ループに陥ってしまった場合は、永遠にマスを往復し続けなければならない。

だが幸いなことに、あなたの身体には、望んだ事象を全事象に変えることのできる異能『確率湾曲』 が宿っている。この能力を使えば、サイコロの出目を自由に操ることも可能。このアドバンテージを 活かして、無限ループに陥らないようにしながら進んでいくとき、ゴールするまでにサイコロを振る 回数の最小値はいくつになるだろうか。

-----問題ここまで----- */
/* -----解説等-----

bfsの基本は"更新できたら遷移を追加"であることをおもいだせば、やるだけ

----解説ここまで---- */

int main(void) {
	int N;
	cin >> N;
	vector<int>a(N);
	FOR(i, 0, N) {
		cin >> a[i];
	}
	VI m(N + 1, 1e9);
	queue<int>q;
	q.push(0);
	m[0] = 0;
	while (!q.empty()) {
		int pos = q.front(); q.pop();
		if (a[pos] == 0) {
			FOR(k, 1, 6 + 1) {
				int nx = min(N - 1, pos + k);
				if (m[nx] > m[pos] + 1) {
					m[nx] = m[pos] + 1;
					q.push(nx);
				}
			}
		}
		else {
			int nx = pos + a[pos];
			if (m[nx] > m[pos]) {
				m[nx] = m[pos];
				q.push(nx);
			}
		}
	}

	cout << m[N - 1] << endl;

	return 0;
}