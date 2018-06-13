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

/* -----  2018/06/14  Problem: AOJ 2198 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2198  ----- */
/* ------問題------

あなたは大人気webゲーム「ムーンライト牧場」に熱中している．このゲームの目的は，畑で作物を育て，それらを売却して収入を得て，その収入によって牧場を大きくしていくことである．
あなたは速く畑を大きくしたいと考えた．そこで手始めにゲーム中で育てることのできる作物を，時間あたりの収入効率にもとづいて並べることにした．
作物を育てるには種を買わなければならない．ここで作物 i の種の名前は Li ，値段は Pi でそれぞれ与えられる．畑に種を植えると時間 Ai 後に芽が出る．芽が出てから時間 Bi 後に若葉が出る．若葉が出てから時間 Ci 後に葉が茂る．葉が茂ってから時間 Di 後に花が咲く．花が咲いてから時間 Ei 後に実が成る．一つの種から Fi 個の実が成り，それらの実は一つあたりSi の価格で売れる．一部の作物は多期作であり，計 Mi 回実をつける．単期作の場合は Mi = 1で表される．多期作の作物は，Mi 回目の実が成るまでは，実が成ったあと葉に戻る．ある種に対する収入は，その種から成った全ての実を売った金額から，種の値段を引いた値である．また，その種の収入効率は，その収入を，種を植えてから全ての実が成り終わるまでの時間で割った値である．
あなたの仕事は，入力として与えられる作物の情報に対して，それらを収入効率の降順に並べ替えて出力するプログラムを書くことである．

-----問題ここまで----- */
/* -----解説等-----

問題文を整理して書けば良い。
誤差が発生する場合は、分母と分子を持って計算すればよい。

----解説ここまで---- */

using tp = tuple<double, string>;
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N;
	while (cin >> N, N) {
		vector<tp>se;
		string st; LL p, a, b, c, d, e, f, s, m;
		FOR(i, 0, N) {
			cin >> st >> p >> a >> b >> c >> d >> e >> f >> s >> m;
			double XX = s * f*m - p;
			double term = (a + b + c + (d + e)*m);
			double val = XX / term;
			se.push_back(tp(-val, st));
		}
		SORT(se);
		FOR(i, 0, N) {
			double val; string str;
			tie(val, str) = se[i];
			cout << str << endl;
		}
		cout << "#" << endl;
	}


	return 0;
}