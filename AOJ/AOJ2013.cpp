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

/* -----  2018/06/10  Problem: AOJ 2013 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2013  ----- */
/* ------問題------

English text is not available in this practice contest.

山手線は東京 23 区内に敷設されている環状鉄道路線である．総路線距離は 34.5km であり，1 周にはおよそ 1 時間を要する．駅は全部で 29 駅存在する．ラインカラーはウグイス色である．ピーク時の混雑率は 200% を超え，日本の鉄道路線の中で最も混雑している路線の 1 つである．最も混雑する時間帯では 3 分に 1 本の列車が走っており，東京に初めて来た人々はその光景に驚くものである．

鉄子さんは山手線を愛してやまない生粋の鉄道好きである．ある日，彼女は愛読書である JR 時刻表を読みながら次の疑問に至った．「山手線では一日に何台の車両が使われているのだろう？」

彼女は時刻表から運行に最低限必要な車両の台数を割り出そうとした．しかし，列車の本数が非常に多かったので，彼女一人の力では到底数え切れそうにない．そこで彼女は優秀なプログラマーであるあなたに助けを求めた．

あなたの仕事は与えられた時刻表から山手線の運行に要する車両の最低台数を求めるプログラムを書くことである．山手線は環状路線であることから，その時刻表は便宜上「大崎駅」を始発駅および終着駅として表記されることが多い．そのため，彼女から渡された時刻表にも各列車の大崎駅における発時刻および着時刻のみが記されている．

なお，実際の山手線では起こりえないが，状況設定を簡単にするため，ここでは大崎駅の到着直後に列車が大崎駅を出発可能であると考えることにする．また，鉄子さんが写した時刻に誤りがあったり，鉄子さんの妄想によって勝手に加えられた列車が時刻表に紛れ込んだりしている場合もあるが，あなたはそれらを見抜くことができないので，あくまでも書かれたとおりの時刻に対して台数を求めなければならない．

きちんと動作するプログラムを書けば，彼女が列車内デートに誘ってくれるかもしれない．もっとも，誘いに乗るか断るかはあなた次第であるが．

-----問題ここまで----- */
/* -----解説等-----

区間足しこみをしたいっぽい。
imos法で十分。

----解説ここまで---- */

LL N;

LL ans = 0LL;

#define N 86400
int main() {
	int n, time[N], max, num, h, m, s;
	while (cin >> n, n) {
		max = 0; num = 0;
		for (int i = 0; i < N; ++i) time[i] = 0;
		for (int i = 0; i < n; ++i) {
			scanf("%02d:%02d:%02d", &h, &m, &s);
			++time[h * 3600 + m * 60 + s];
			scanf("%02d:%02d:%02d", &h, &m, &s);
			--time[h * 3600 + m * 60 + s];
		}
		for (int i = 0; i < N; ++i) {
			num += time[i];
			if (max < num) max = num;
		}
		cout << max << endl;
	}
	return 0;
}