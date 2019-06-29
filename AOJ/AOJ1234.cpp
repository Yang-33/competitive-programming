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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);

/* -----  2019/06/03  Problem: AOJ 1234 / Link: https://onlinejudge.u-aizu.ac.jp/challenges/search/volumes/1234  ----- */


char str[10][40];
int pt[10];
int ge[10];
int sh[10];
int hl[10];
double prob[10];
int val[10][10];
int to[10];

int main() {
	int T;
	scanf("%d", &T);
	for (int i = 0; i <= 8; i++) {
		double ks = 1;
		for (int j = 0; j < i; j++) {
			ks *= (8 - j);
			ks /= (j + 1);
		}
		for (int j = 0; j < 8 - i; j++)ks *= 3;
		for (int j = 0; j < 8; j++)ks /= 4;
		prob[i] = ks;
	}
	while (T--) {
		for (int i = 0; i < 5; i++)scanf("%s", str[i]);
		int num = 0;
		for (int i = 0; i < 4; i++)if (str[i + 1][0] == '*')num = i;
		for (int i = 0; i < 4; i++)for (int j = i + 1; j < 4; j++) {
			if (str[i + 1][6 + j * 5] == '_') {
				to[i] = j;
				to[j] = i;
				continue;
			}
			int l = str[i + 1][6 + j * 5] - '0';
			int r = str[i + 1][8 + j * 5] - '0';
			val[i][j] = l;
			val[j][i] = r;
		}
		double ret = 0;
		for (int i = 0; i <= 8; i++)for (int j = 0; j <= 8; j++)for (int k = 0; k <= 8; k++)for (int l = 0; l <= 8; l++) {
			double ks = prob[i] * prob[j] * prob[k] * prob[l];
			val[0][to[0]] = i;
			val[1][to[1]] = j;
			val[2][to[2]] = k;
			val[3][to[3]] = l;
			for (int x = 0; x < 4; x++)hl[x] = 0;
			bool chg = false;
			int rem = 4;
			int ue = 0;
			do {
				chg = false;
				for (int x = 0; x < 4; x++)pt[x] = ge[x] = sh[x] = 0;
				for (int x = 0; x < 4; x++)for (int y = x + 1; y < 4; y++) {
					if (hl[x] || hl[y])continue;
					if (val[x][y] > val[y][x])pt[x] += 3;
					else if (val[x][y] < val[y][x])pt[y] += 3;
					else { pt[x]++; pt[y]++; }
					ge[x] += val[x][y] - val[y][x];
					ge[y] += val[y][x] - val[x][y];
					sh[x] += val[x][y];
					sh[y] += val[y][x];
				}
				for (int x = 0; x < 4; x++) {
					if (hl[x])continue;
					if (x == num)continue;
					if (pt[x] > pt[num]) {
						chg = true; ue++; rem--;
						hl[x] = 1; continue;
					}
					if (pt[x] < pt[num]) {
						chg = true; rem--;
						hl[x] = 1; continue;
					}
					if (ge[x] > ge[num]) {
						chg = true; ue++; rem--;
						hl[x] = 1; continue;
					}
					if (ge[x] < ge[num]) {
						chg = true; rem--;
						hl[x] = 1; continue;
					}
					if (sh[x] > sh[num]) {
						chg = true; ue++; rem--;
						hl[x] = 1; continue;
					}
					if (sh[x] < sh[num]) {
						chg = true; rem--;
						hl[x] = 1; continue;
					}

				}
			} while (chg&&rem > 1);
			if (ue >= 2)continue;
			ret += ks * min(1.0, (2.0 - ue) / rem);
		}
		printf("%.7f\n", ret);
	}
}