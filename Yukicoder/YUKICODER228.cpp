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

/* -----  2018/08/24  Problem: yukicoder 228  / Link: http://yukicoder.me/problems/no/228  ----- */
/* ------問題------

ゆきこちゃんは「15 パズル」というパズルで遊んでいる。15 パズルのルールを以下に示す。

4×4 マスの盤上に、1 から 15 までの数が書かれた駒を順に並べる（下図）。
空きマスの上下左右に隣接した駒を、空きマスにスライドして動かすことを繰り返す。
目標となる駒の配置を作ることができれば成功である。

ゆきこちゃんは 15 パズルの普通の遊び方に飽きてしまった。
そこで、新たに次のルールを追加して遊ぶことにした。

ルール : 一度スライドした駒は再びスライドできない

さて、目標となる駒の配置が与えられたとき、その配置を作ることができるか判定せよ。

-----問題ここまで----- */
/* -----解説等-----

計算量がわからないけど操作回数は少ないので通る

----解説ここまで---- */

bool checkRightState(const VVI& a, const VVI &state) {
	int ok = 1;
	FOR(i, 0, 4)FOR(j, 0, 4)ok &= a[i][j] == state[i][j];
	return ok;
}

bool f(PII posOfZero, VVI& a, VI& used, const VVI& state) {
	if (checkRightState(a, state))return 1;
	FOR(k, 0, 4) {
		int ty = posOfZero.first + DY[k], tx = posOfZero.second + DX[k];
		if (!(0 <= ty && ty < 4 && 0 <= tx && tx < 4))continue;
		// swap
		if (used[a[ty][tx]])continue;
		used[a[ty][tx]] = 1;
		swap(a[posOfZero.first][posOfZero.second], a[ty][tx]);
		if (f(PII(ty, tx), a, used, state))return 1;
		else { // 戻す
			swap(a[posOfZero.first][posOfZero.second], a[ty][tx]);
			used[a[ty][tx]] = 0;
		}
	}

	return 0;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	VVI state(4, VI(4));
	PII s = PII(3, 3);
	FOR(i, 0, 4)FOR(j, 0, 4) {
		cin >> state[i][j];
	}
	VVI a(4, VI(4));
	FOR(i, 0, 4) {
		FOR(j, 0, 4) {
			a[i][j] = i * 4 + j + 1;
		}
	}
	a[3][3] = 0;
	VI used(16, 0);
	cout << (f(s, a, used, state) ? "Yes" : "No") << endl;

	return 0;
}
