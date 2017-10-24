#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/06/17  Problem: CodeForces419 C div2 / Link: http://codeforces.com/contest/816/problem/C  ----- */
/* ------問題------

行列Ａが与えられる。全要素0の行列Bから行または列を全部1加算してAを構築できるか。また構築可能なら最小回数で作成する際の一例を示せ。

-----問題ここまで----- */
/* -----解説等-----

先に最小の値は削除できる。
これは縦横の短い方からやるとよい。
その後縦と横で同じことを行い、実際に値を取り除いていく。
これを終えても値が残る場合はそもそも作成不可能な値であることが分かるので-1.
そうでない場合は以上の情報をもとに復元すればよい。
ちょっと前にREPって書いててウケるね

!! base が大事(縦と横では小さい方がいいので)

----解説ここまで---- */

ll N, h, w;
ll ans = 0LL;
#define REP(i,t) FOR(i,0,t)
int g[110][110];

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> h >> w;
	FOR(i, 0, h) {
		FOR(j, 0, w)cin >> g[i][j];
	}
	int base = INT_MAX;
	REP(y, h) {
		REP(x, w) {
			base = min(base, g[y][x]);
		}
	}
	REP(y, h) {
		REP(x, w) {
			g[y][x] -= base;
		}
	}
	vector<int> row(h);
	REP(y, h) {
		int temp = INF;
		FOR(k, 0, w)temp = min(temp, g[y][k]);
		row[y] = temp;
		REP(x, w) g[y][x] -= row[y];
	}
	vector<int> col(w);
	REP(x, w) {
		col[x] = INT_MAX;
		REP(y, h) col[x]=min(col[x],g[y][x]);
		REP(y, h) g[y][x] -= col[x];
	}
	bool is_cleared = true;
	REP(y, h) {
		REP(x, w) {
			if (g[y][x] != 0) {
				is_cleared = false;
			}
		}
	}
	if (is_cleared) {
		int n = 0;
		n += base * min(h, w);
		REP(y, h) n += row[y];
		REP(x, w) n += col[x];
		printf("%d\n", n);
		if (h < w) {
			REP(y, h) REP(i, base) printf("row %d\n", y + 1);
		}
		else {
			REP(x, w) REP(i, base) printf("col %d\n", x + 1);
		}
		REP(y, h) REP(i, row[y]) printf("row %d\n", y + 1);
		REP(x, w) REP(i, col[x]) printf("col %d\n", x + 1);
	}
	else {
		printf("-1\n");
	}

	return 0;
}