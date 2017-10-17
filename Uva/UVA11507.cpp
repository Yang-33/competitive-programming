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

/* -----  2017/10/17  Problem: Uva 11507  / Link: https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=27&page=show_problem&problem=2502  ----- */
/* ------問題------

(0,0,0)-(L,0,0)の直線がある。
これを(L-1,0,0)から(1,0,0)のL-1回、z,y軸に平行に捻じ曲げる。
最後には直線の先は何軸に平行になっているか。

-----問題ここまで----- */
/* -----解説等-----

ひとつ前に状態のみに依存しているのでこれを変更していけばよい。
さいころみたい！

----解説ここまで---- */

LL N;


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	enum { X, mX, Y, mY, Z, mZ };
	while (cin >> N, N) {
		int dir = 0;//+x
		FOR(i, 0, N-1) {
			string s;
			cin >> s;
			if (s == "No")continue;
			if (s == "+z") {
				if (dir == X)dir = Z;
				else if (dir == mX)dir = mZ;
				else if (dir == Z)dir = mX;
				else if (dir == mZ)dir = X;
			}
			else if (s == "-z") {
				if (dir == X)dir = mZ;
				else if (dir == mX)dir = Z;
				else if (dir == Z)dir = X;
				else if (dir == mZ)dir = mX;
			}
			else if (s == "+y") {
				if (dir == X)dir = Y;
				else if (dir == mX)dir = mY;
				else if (dir == Y)dir = mX;
				else if (dir == mY)dir = X;
			}
			else if (s == "-y") {
				if (dir == X)dir = mY;
				else if (dir == mX)dir = Y;
				else if (dir == Y)dir = X;
				else if (dir == mY)dir = mX;
			}
		}
		string ans = "";
		switch (dir) {
		case X:ans = "+x"; break;
		case mX:ans = "-x"; break;
		case Y:ans = "+y"; break;
		case mY:ans = "-y"; break;
		case Z:ans = "+z"; break;
		case mZ:ans = "-z"; break;
		}
		cout << ans << endl;

	}



	return 0;
}