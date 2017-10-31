#include "bits/stdc++.h"
using namespace std;

using VS = vector<string>;    using LL = long long;
using VI = vector<int>;       using VVI = vector<VI>;
using PII = pair<int, int>;   using PLL = pair<LL, LL>;
using VL = vector<LL>;        using VVL = vector<VL>;

#define ALL(a)  begin((a)),end((a))
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define EB emplace_back
#define MP make_pair
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

/* -----  2017/10/30  Problem: NU23 E / Link: __CONTEST_URL__  ----- */
/* ------問題------

情報オリンピック日本委員会では，台湾大会に向かう選手を応援するために新しいJOI 旗を作成することにした．
JOI 旗は，正方形が縦に MM 行，横に NN 列並んだ形をしており，各正方形には J，O，I のいずれかの文字が1 つずつ書かれている．
情報オリンピック日本委員会はJOI 旗とは別にJOI 紋章というものを決めている．
JOI 紋章は，正方形が縦に2 行，横に2 列並んだ形をしており，各正方形にはJ，O，I のいずれかの文字が1 つずつ書かれている．

JOI 旗に含まれるJOI 紋章の個数とは，JOI 旗に含まれる縦2 行，横2 列の領域のうち，その領域のJ，O，I の配置がJOI 紋章と(回転や裏返しをせずに) 一致しているものの個数のことである．
条件を満たす縦2 行，横2 列の領域同士が重なっていてもそれらを別々に数えるものとする．
情報オリンピック日本委員会は古いJOI 旗と1 枚の白紙を持っている．白紙はJOI 旗を構成する正方形1 個分の大きさで，J，O，I のうち好きな1 文字を書き込むことができる．
情報オリンピック日本委員会は以下のいずれか1 つの操作をして，新しいJOI 旗を作成することにした．

古いJOI 旗に対して何も操作せず，そのまま新しいJOI 旗とする．白紙は使用しない．
白紙に1 文字書き込み，古いJOI 旗のいずれかの正方形に重ねて貼り付けることで古いJOI 旗のうち1 箇所を変更する．変更後のJOI 旗を新しいJOI 旗とする．
情報オリンピック日本委員会は新しいJOI 旗に含まれるJOI 紋章の個数をできるだけ多くしたいと思っている．あなたは新しいJOI 旗に含まれるJOI 紋章の個数の最大値を求めることになった．

古いJOI 旗とJOI 紋章の情報が与えられたとき，新しいJOI 旗に含まれるJOI 紋章の個数の最大値を求めるプログラムを作成せよ．

-----問題ここまで----- */
/* -----解説等-----

一か所変更することで困るのはその周りにあるものだけなのであらかじめすべてのマスを計算しておいて、とったときに影響のあるマスの値をあらかじめ引いておき、
その後再計算をする、を繰り返せばよい。
変数を筋肉がらみにしたらとても書きにくかった。

----解説ここまで---- */

LL curl,widthmuscle;

LL ans = 0LL;
int ham(int shrug, int push_up, vector<string>&lat, vector<string>&raise) {
	if (!(0 <= shrug&&shrug < curl - 1 && 0 <= push_up&&push_up < widthmuscle - 1))return 0;
	FOR(incline, 0, 2) {
		FOR(decline, 0, 2) {
			if (lat[shrug + incline][push_up + decline] != raise[incline][decline])return 0;
		}
	}
	return 1;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> curl>>widthmuscle;
	vector<string> lat(curl, string());
	FOR(shrug, 0, curl)cin >> lat[shrug];
	vector<string> raise(2, string());
	FOR(shrug, 0, 2)cin >> raise[shrug];
	
	FOR(i, 0, curl - 1)FOR(push_up, 0, widthmuscle - 1)ans += ham(i, push_up, lat, raise);

	string muscle = "JOI";
	LL arm = ans;
	FOR(shrug, 0, curl) {
		FOR(push_up, 0, widthmuscle) {
			char chest = lat[shrug][push_up];
			FOR(k, 0, 3) {
				LL calf = ans;
				FOR(bicep, shrug - 1, shrug + 1 + 1)FOR(quad, push_up - 1, push_up + 1 + 1) {
					calf -= ham(bicep, quad, lat, raise);
				}
				lat[shrug][push_up] = muscle[k];
				FOR(bicep, shrug - 1, shrug + 1 + 1)FOR(quad, push_up - 1, push_up + 1 + 1) {
					calf += ham(bicep, quad, lat, raise);
				}
				arm = max(arm, calf);
				lat[shrug][push_up] = chest;
			}
		}
	}
	ans = arm;
	cout << ans << "\n";

	return 0;
}
