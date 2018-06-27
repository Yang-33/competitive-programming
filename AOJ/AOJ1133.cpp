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

/* -----  2018/06/30  Problem: AOJ 1133 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1133  ----- */
/* ------問題------

伝次郎氏は理科の先生である． 彼は，水の流れに関する革新的な実験をするために水槽を注文していたのだが， 今日ちょうどその水槽が届いたところである．
水槽は，幅100cm，高さ50cm，奥行き30cmの大きさである(Figure 1 参照)． 水槽の内部を区切るために，数枚の「区切り板」を水槽の側面と 平行に水槽の底に設置する． 区切り板の横幅はどれも水槽の奥行きである 30cm と等しい． 板の高さは水槽の側板の高さである 50cm よりは低い． また，板の高さは，板ごとにどれも異なっている． 区切り板は十分に薄いので，その厚さは無視できるものとする．
水槽を正面から見ると Figure 2 のようになる．
水槽の上方にはいくつかの蛇口があり，実験開始と同時に蛇口を開いて 水を水槽へと注ぎ入れる．実験開始時に水槽は空である． あなたの仕事は，水槽内における水の流れを シミュレートするプログラムを書くことである．

-----問題ここまで----- */
/* -----解説等-----

気合550の問題気合をする


----解説ここまで---- */


// sumi h は変更される
// 最も低い隣接にまず注ぐ、変更は抑える
// [l,r]
double Func(double add, int pos, int l, int r, VI& shikiri, VI& b, vector<double>&hh) {
	double rest = add;
	if (l + 1 < r) {
		int target = l + 1;
		FOR(i, l + 1, r) {
			if (shikiri[target] < shikiri[i])target = i;
		}
		if (pos < target) {
			rest = Func(rest, pos, l, target, shikiri, b, hh);
			rest = Func(rest, pos, target, r, shikiri, b, hh);
		}
		else {
			rest = Func(rest, pos, target, r, shikiri, b, hh);
			rest = Func(rest, pos, l, target, shikiri, b, hh);
		}
	}
	double maxh = min(shikiri[l], shikiri[r]);
	double addh = rest / (b[r] - b[l]);
	FOR(i, l, r) {
		double preh = hh[i];
		if (addh + hh[i] > maxh) {
			hh[i] = maxh;
		}
		else {
			hh[i] += addh;
		}
		rest -= (b[i + 1] - b[i])*(hh[i] - preh);
	}
	return rest;
}

int main() {
	cin.sync_with_stdio(false);
	int cases;
	cin >> cases;
	while (cases--) {
		int N; cin >> N;
		VI b(N + 2, 0);
		VI shikiri(N + 2, 0);
		FOR(i, 1, N + 1)cin >> b[i] >> shikiri[i];
		// 番

		b[0] = 0; b[N + 1] = 100;
		shikiri[0] = INF; shikiri[N + 1] = INF;

		N += 2;
		int m; cin >> m;
		vector<double>addw(30, 0);
		FOR(i, 0, m) {
			int ff;	double aa;
			cin >> ff >> aa;
			FOR(j, 0, N - 1) {
				if (b[j] <= ff && ff <= b[j + 1]) {
					addw[j] += aa / 30.0;
				}
			}
		}
		int Q;	cin >> Q;
		FOR(i, 0, Q) {
			int pointx;	double ti;
			cin >> pointx >> ti;
			vector<double>hh(N, 0);
			FOR(j, 0, N - 1)Func(addw[j] * ti, j, 0, N - 1, shikiri, b, hh);
			FOR(j, 0, N - 1) {
				if (b[j] <= pointx && pointx <= b[j + 1]) {
					cout << fixed << setprecision(10) << min(hh[j], 50.0) << endl;
				}
			}
		}
	}
	return 0;
}