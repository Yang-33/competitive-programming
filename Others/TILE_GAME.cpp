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

/* -----  2017/09/17  Problem: tile_game  / Link: 出典無し  ----- */
/* ------問題------

1*Nのマス目に二人で交互に1*2のタイルを置いていく。タイルを重ねるのが禁止なときの、
この盤面のgurndy数は。

-----問題ここまで----- */
/* -----解説等-----

Dawson's Kaylesというらしい。grundy数は計算して埋め込んだ。
周期が34なのがおもしろい。(52以降の周期34の証明は直和の帰納法でできる)
他に列があってもそれは直和なので簡単。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int grundy_memo[34] = { 4,8,1,1,2,0,3,1,1,0,3,3,2,2,4,4,5,5,9,3,3,0,1,1,3,0,2,1,1,0,4,5,3,7 };
int grundy(int n) {
	if (n == 0)return 0;
	if (n == 1 || n == 35)return 0;
	if (n == 15)return 0;
	if (n == 17)return 2;
	if (n == 18 || n == 52)return 2;
	if (n == 32)return 2;

	return grundy_memo[n % 34];
}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	while (1) {
		cin >> N;
		cout << N<<": "<<grundy(N) << endl;
	}

	cin >> N;
	int g = grundy(N);
	cout << ((g) ? "Firse" : "Second") << "\n";

	return 0;
}
