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

/* -----  2018/06/23  Problem: AOJ 2826 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2826  ----- */
/* ------問題------

あなたは冒険ゲームを作成している．このゲームのプレイヤーは，主人公を操作して敵モンスターを倒し，主人公のレベルを上げることで冒険を進めていく．主人公の初期レベルは 1 である．
このゲームには N 種類の敵モンスターが用意されており，弱い順で i 番目の種類の敵モンスターの強さは si である．主人公が 1 回の戦闘を行うときには，次に戦う敵モンスターの種類を自由に選び，ちょうど 1 体の敵モンスターと戦闘を行う．主人公は同じ種類の敵モンスターと何回でも戦うことができ，何回でも倒すことができる．
あなたはいま，このゲームのバランスを調整するために，あるパラメーター X を決めようとしている．パラメーター X は正の整数であり下記のように使われる．
主人公のレベルが L のとき，強さ si が L+X 未満の敵は倒せるが，それより強い敵モンスターは倒せない．
主人公のレベルが L のとき，強さ si の敵を倒すと max(1, X-|L-si|) だけ主人公のレベルが上がる．
このゲームは，最も強い（N 種類目の）敵モンスターを初めて倒したときにゲームクリアとなる．あなたは，ゲームクリアまでに必要となる戦闘の回数が最低でも M 回以上となるようにパラメーター X を決めたいと考えている．ただし，敵モンスターの強さの設定によっては，X をどのように設定しても M 回未満の戦闘回数でゲームクリアできてしまうか，ゲームをクリアできなくなってしまう場合があることに注意せよ．
パラメーター X を決めるとき，上記の条件を満たす範囲で最大のパラメーター値 Xmax を計算するプログラムを作ってほしい．

-----問題ここまで----- */
/* -----解説等-----

考察をすると、区間は3つだけど最初に2つにできる。
[永久に倒せない][適切][M回未満で倒せる]
となっているが、そもそもs[0]を倒せないと始まらないので、これで判定をすればよい。
したがって最初に判定して、あとは二分探索をすればよい。

----解説ここまで---- */

int f(LL x, VL a) {

	LL lv = 1;
	int cnt = 1;
	while (lv + x <= a.back()) {
		LL uplv = 1;
		// あがるのはにとおりのみ
		int over = lower_bound(a.begin(), a.end(), lv) - a.begin();
		if (over != SZ(a)) {
			uplv = max(uplv, x - abs(lv - a[over]));
		}
		if (over) {
			uplv = max(uplv, x - abs(lv - a[over - 1]));
		}
		lv += uplv;
		cnt++;
	}
	return cnt;


}



void solve() {

	int N, M;
	while (cin >> N >> M, N || M) {
		VL a(N);
		FOR(i, 0, N) {
			cin >> a[i];
		}

		int L = a[0], R = INF;
		if (f(L, a)<M) { //条件を満たせない
			cout << -1 << endl;
		}
		else {
			FOR(i, 0, 40) {
				int mid = (R + L) / 2;
				if (f(mid, a) >= M) {
					L = mid;
				}
				else {
					R = mid;
				}
			}
			cout << L << endl;
		}
	}


}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	solve();
	return 0;
}