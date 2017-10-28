//#include "bits/stdc++.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <cstdio>

using namespace std;

typedef  long long LL;

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

/* -----  2017/10/27  Problem: POJ 2926 / Link: http://poj.org/problem?id=2926  ----- */
/* ------問題------

5次元の座標がN点与えられる。
このマンハッタン距離が最遠点となる組の、マンハッタン距離を求めよ
N≦10^5
点の制約なし

-----問題ここまで----- */
/* -----解説等-----

POJはクソ

マンハッタン距離の式を変形していくとmaxをとる式になる。
これは場合分けを行うことでP次元に対して(2^P)回の場合分けでmaxを選択することができる。
したがってこれを求めればよい。
SIGMA(i,0,5)|X1i-X2i| = SIGMA(i,0,5)MAX(±(X1i-X2i))
から、場合分けを残したまま、X1,X2をまとめるとMHdist = MAX(±X11±X12±X13±X14±X15 ∓X21∓X22∓X23∓X24∓X25)となる。
これはX1のMaxとなるものからX2のMinとなるものをもってこれば最大値を得ることができる。
したがってこれは全探索することで、P次元にたいして(N*P*2^P)でできる。

あと、POJはクソ

----解説ここまで---- */

LL N;

double ans = 0;

int main() {
	//cin.tie(0);
	//ios_base::sync_with_stdio(false);

	//cin >> N;
	scanf("%lld", &N);
	vector<vector<double> > a(N, vector<double>(5, 0));
	FOR(i, 0, N) {
		FOR(j, 0, 5)scanf("%lf", &a[i][j]);
		//cin >> a[i][j];
	}
	ans = 0;
	FOR(i, 0, 1 << 5) {
		double M = -1e300;
		double m = 1e300;
		FOR(j, 0, N) {
			double ret = 0;
			FOR(k, 0, 5) {
				if (i&(1 << k)) ret += a[j][k];
				else ret -= a[j][k];
			}
			M = max(M, ret);
			m = min(m, ret);
		}
		ans = max(ans, M - m);
	}

	printf("%.2lf\n", ans);
	//cout<<fixed<<setprecision(2) << ans << "\n";
	return 0;
}
