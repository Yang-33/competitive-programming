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

/* -----  2018/06/09  Problem: AOJ 2766 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2766  ----- */
/* ------問題------

Leading-zeros を含めた桁数が 
N
 の，符号なし 
2
 進数表記された整数 
X
 がある． 
X
 とのハミング距離が 
D
 となる 
N
 桁で 
2
 進数表記できる非負整数のうち， 値が最大のものを出力せよ．

2
 進数表記された整数間のハミング距離とは， 
2
 つの数において値が異なる桁の数である．例えば 
000
 と 
110
 のハミング距離は 
2
 である．

-----問題ここまで----- */
/* -----解説等-----

なるべく1にして、それでも変更しないといけないときは、下から1->0をすればよい。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL N, D;
	string X;  cin >> N >> X >> D;
	string preX = X;
	for (int i = 0; i < (int)X.length(); i++) {
		if (D == 0) break;
		if (preX[i] == '1') continue;
		X[i] = '1';
		D--;
	}
	for (int i = (int)X.length() - 1; i >= 0; i--) {
		if (D == 0)break;
		if (preX[i] == '0') continue;
		X[i] = '0';
		D--;
	}
	cout << X << endl;

	return 0;
}
