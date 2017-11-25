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
#include <functional>

using namespace std;

typedef long long LL;
typedef vector<int> VI;
typedef vector<LL> VL;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef pair<int, int> PII;
typedef pair<LL, LL> PLL;
typedef vector<string> VS;

#define ALL(a)  a.begin(),a.end()
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

/* -----  2017/11/25  Problem: disco_nagano2017_e / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

しらん。不等式っぽい

----解説ここまで---- */
// 以下のデータを使用して問題を解いてください。
// 変数名・データ型は任意
// mainのローカル変数として定義してください。


LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int Q5[4][16] =
	{ { 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 1, 2, 5, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 },
	{ 4,42,42,43,43,44, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 } };
	// 	|  17.500, 17.125, 43.375, 171.000

	/*int Q5[4][16] =
	{ { 2, 3, 5, 8, 9, 10, 12, 14, 15, 19, 24, 27, 30, 33, 35, 0 },
	{ 1, 2, 3, 4, 5, 6, 7, 8, 9,10,11,12,13,14,15,16 },
	{ 3, 3, 3, 7, 8, 8,11,16,16,16,42,42,50,51,51,52 },
	{ 1, 1, 4, 4, 8, 8,10,12,14,16,16,16,40,40,50,50 } };*/

	N = 16; //16個の荷物を運ぶ。制約付き

	cout << ans << "\n";
	// 貪欲？
	//そう



	return 0;
}
