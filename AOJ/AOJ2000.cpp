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

/* -----  2018/07/23  Problem: AOJ 2000 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/2000  ----- */
/* ------問題------

宇宙暦 1603～1867 年，人々はその時代のことを EDO 時代と呼ぶ．EDO とは当時最先端の宇宙航行技術，Enhanced Driving Operation のことであり、1603 年に Dr.Izy によって開発された．
あなたは宇宙冒険家であり，宇宙を飛び回って様々な惑星を冒険していた．その冒険の途中で，あなたはとても不思議な惑星を発見した．その惑星には，至るところに七色に輝く不思議な宝石が落ちていた．あなたはその惑星への降下を試みようと考えたが，重大な問題のためにそれは不可能であることがわかった．その惑星の空気には，人間が触れただけで即死してしまうような猛毒の成分が含まれていたのだ．
そこで，あなたはロボットを使って宝石を回収することを考えついた．あなたはその惑星の周回軌道にて待機する．そして，降下させたロボットを遠隔操作することによって宝石を回収するのだ．あなたは，ロボットに「移動する方向」と「移動する距離」の組からなる命令の列によってロボットを遠隔操作する．ロボットは移動経路上（到達点を含む）に宝石を見つけると，それらを全て回収する．
あなたの仕事は，ロボットが与えられた全ての命令の実行を終えたときに，全ての宝石を回収することができたかどうかを判定するプログラムを書くことである．
なお，ロボットが不思議な宝石を回収する範囲はそれほど広くない．そのため，ロボットが移動する範囲は全て 2 次元の平面で表すことができる．そして，ロボットが移動する範囲は (0,0) および (20,20) をそれぞれ左下隅および右上隅とする正方形の内部（境界線を含む）である．ロボットは常に範囲の中央，すなわち (10,10) の座標に降下する．また，全ての宝石は中央以外の格子点上にあることが保証されてい

-----問題ここまで----- */
/* -----解説等-----

シュミレーション

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		set<PII>gems;
		FOR(i, 0, N) {
			int x, y;
			cin >> x >> y;
			gems.insert(PII(x, y));
		}

		map<char, int>Map;
		string S = "NSEW";
		FOR(i, 0, SZ(S))Map[S[i]] = i;
		int Q; cin >> Q;
		PII pos = PII(10, 10);
		FOR(_, 0, Q) {
			char c; int x; cin >> c >> x;
			int T = Map[c];
			FOR(i, 0, x) {
				pos.first += DX[T];
				pos.second += DY[T];
				if (gems.find(pos) != gems.end())gems.erase(pos);
			}
		}

		cout << (gems.size()==0 ? "Yes" : "No") << endl;
	}

	return 0;
}
