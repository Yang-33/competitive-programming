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

/* -----  2017/11/25  Problem: disco_nagano2017_c / Link: __CONTEST_URL__  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

シュミレーションはqueueでやると嬉しいって思い出すのに時間がかかった

----解説ここまで---- */

//	以下のデータを使用して問題を解いてください。
//	変数名・データ型は任意
//	mainのローカル変数として定義してください。
//	問題は４題

//	機種Xの装置がx台、機種Yの装置がy台ある。
//	また、カセットがN個あり、1カセット処理するのにかかる時間は、機種X:A分、機種Y:B分である。
//	カセットの入れ替えにかかる時間は、機種X:a分、機種Y:b分である。
//	すべてのウェーハを処理するのに必要な最短時間を求めよ。
//	ウェーハは全て同じであり、各装置での処理の結果も同じである。
//	一番最初にカセットを乗せる時間と、全完了時にカセットから下ろす時間は含まないとする。
//  {x,y,A,B,a,b,N}


LL ans = 0LL;

int main() {
	int	Q3_[4][7] = { { 10, 10, 50, 20, 150, 70, 50 },{ 100, 10, 10, 20, 15, 7, 500 },{ 100, 150, 15, 22, 20, 17, 200 },{ 1, 10, 20, 17, 19, 89, 29 } };

	/*int	Q3_2[7] = { 100, 10, 10, 20, 15, 7, 500 };

	int	Q3_3[7] = { 100, 150, 15, 22, 20, 17, 200 };

	int	Q3_4[7] = { 1, 10, 20, 17, 19, 89, 29 };
*/
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);

	FOR(cas, 0, 4) {
		int T = 0;
		int x = Q3_[cas][0];
		int y = Q3_[cas][1];
		int A = Q3_[cas][2];
		int B = Q3_[cas][3];
		int a = Q3_[cas][4];
		int b = Q3_[cas][5];
		int N = Q3_[cas][6];
		ans = 0;
		int acnt = 0;
		int bcnt = 0;
		priority_queue<PII, vector<PII>, greater<PII>>Q;
		if (B >= A) {
			N -= x;
			if (N <= 0) {
				ans = A;
				cout << ans << endl;
				continue;
			}
			N -= y;
			if (N <= 0) {
				ans = max(A, B);
				cout << ans << endl;
				continue;
			}
		}
		else {
			N -= y;
			if (N <= 0) {
				ans = B;
				cout << ans << endl;
				continue;
			}
			N -= x;
			if (N <= 0) {
				ans = max(A, B);
				cout << ans << endl;
				continue;

			}
		}
		ans = 0;
		if (x)Q.push(PII(A + a, 0));
		if (y)Q.push(PII(B + b, 1));
		LL ret = 0;
		while (!Q.empty()) {
			PII p = Q.top(); Q.pop();
			//debug(p.first);
			if (N <= 0) {
				if (p.second == 1) {
					p.first -= b;
				}
				else {
					p.first -= a;

				}
				ret = max(ret, (LL)p.first);
				continue;
			}

			if (p.second == 0) {//x
				N -= x;
				ans += a + A;
				Q.push(PII(p.first + A + a, 0));

			}
			else if (p.second == 1)//y
			{
				N -= y;
				ans += b + B;
				Q.push(PII(p.first + B + b, 1));


			}


		}
		ans = ret;
		cout << ans << endl;
	}
	return 0;
}
