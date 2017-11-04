#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <algorithm>
#include <set>
#include <sstream>
#include <utility>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cctype>
#include <climits>
#include <list>
#include <fstream>
using namespace std;

typedef long long LL;


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

/* -----  2017/11/04  Problem: POJ 2315 / Link: http://poj.org/problem?id=2315  ----- */
/* ------問題------

概要
N山のNimをする。あなたはK個の山を選択し、各山についてP個まで石を取り除ける。
このとき与えられる盤面は最適な動きをしたときどちらが必勝か。

-----問題ここまで----- */
/* -----解説等-----

Nim K むずかしいなあ
これはちゃんと証明できれば記事にしたいな。

今回のようなゲームをKこ平行ゲームとすると、いつものゲームは1個平行ゲームと呼べる。
XORをとっていたgrundy数の求める動作は、各桁について、ゲームの二進数の各桁の和について、mod2 をとっていた、
とみることができる。
ざっくりすると、これをK個に拡張した際にはmod (K+1)にすればよい。
これでゲームの値が分かるので、2進数の各桁についての和が全て０ならこれは必敗。
そうでなければこれは必勝の手が存在することになる。

----解説ここまで---- */



void solve(int N) {
	int M, L, R;
	cin >> M >> L >> R;
	int canmove = L / (2 * R*PI);
	vector<int>a(N);
	FOR(i, 0, N) {
		cin >> a[i];
		a[i] = ceil((double)a[i] / (2 * PI*R));
		a[i] %= canmove + 1;
	}
	vector<int> digitK(30, 0);
	FOR(i, 0, N) {
		int dg = 0;
		while (a[i]) {
			digitK[dg] += a[i] & 1;
			a[i] >>= 1;
			dg++;
		}
	}
	int K = M;
	int grundy = 0;
	FOR(i, 0, 30) {
		if (digitK[i] % (M + 1) != 0) {
			grundy = 1;
		}
	}
	cout << (grundy!=0?"Alice":"Bob") << endl;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int n;
	while (cin >> n) {
		solve(n);
	}

	return 0;
}
