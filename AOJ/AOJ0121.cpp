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

/* -----  2017/11/11  Problem: AOJ 0121 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0121  ----- */
/* ------問題------

7 パズルは 8 つの正方形のカードとこれらのカードがぴたりと収まる枠で構成されています。それぞれのカードには、互いに区別できるように 0, 1, 2, ..., 7 と番号がつけられています。枠には、縦に 2 個、横に 4 個のカードを並べることができます。
7 パズルを始めるときには、まず枠にすべてのカードを入れます。枠のなかで 0 のカードだけは、上下左右に隣接するカードと位置を交換することができます。たとえば、枠の状態が図(a) のときに、0 のカードの右に隣接した、7 のカードと位置を交換すれば、図(b) の状態になります。あるいは、図(a) の状態から 0 のカードの下に隣接した 2 のカードと位置を交換すれば図(c) の状態になります。図(a) の状態で 0 のカードと上下左右に隣接するカードは 7 と 2 のカードだけなので、これ以外の位置の入れ替えは許されません。
ゲームの目的は、カードをきれいに整列して図(d) の状態にすることです。最初の状態を入力とし、カードをきれいに整列するまでに、必要な最小手数を出力するプログラムを作成してください。ただし、入力されたカードの状態からは図(d) の状態に移ることは可能であるとします。
入力データは、1 行に 8 つの数字が空白区切りで与えられます。これらは、最初の状態のカードの並びを表します。例えば、図(a) の数字表現は0 7 3 4 2 5 1 6 に、図(c) は 2 7 3 4 0 5 1 6 となります。

-----問題ここまで----- */
/* -----解説等-----

状態は8^8通りしかないので、前もって完成系からの採点距離を計算をしておけばよい。
その後はクエリにO(1)で答えられてうれしい。

----解説ここまで---- */

int t[8][8][8][8][8][8][8][8];
int dx[] = { 1,-1,4,-4 };
void plu(string x, int p) {
	t[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]] = p;
}
bool ret(string x) {
	return t[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]];
}
int get(int x[8]) {
	return t[x[0]][x[1]][x[2]][x[3]][x[4]][x[5]][x[6]][x[7]];
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	string v, a, x;
	FOR(i, 0, 8)v += i;
	queue<pair<string, int> >q;
	plu(v, 0);
	q.push(MP(v, 0));
	while (!q.empty()) {
		pair<string, int>p = q.front(); q.pop();
		x = p.first;
		plu(p.first, p.second);
		FOR(i, 0, 8)if (!x[i])FOR(j, 0, 4) {
			if (j == 0 && i == 3)continue;
			if (j == 1 && i == 4)continue;
			int y = i + dx[j];
			if (y >= 0 && y < 8) {
				a = x;
				swap(a[i], a[y]);
				if (!ret(a)) {
					q.push(MP(a, p.second + 1));
					plu(a, p.second + 1);
				}
			}
		}
	}
	int qq[8];
	while (cin >> qq[0]) {
		FOR(i, 1, 8)cin >> qq[i ];
		cout << get(qq) << endl;
	}
	return 0;
}
