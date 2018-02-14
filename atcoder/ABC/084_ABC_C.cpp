#include <bits/stdc++.h>
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

/* -----  2018/02/14  Problem: 084_abc_c / Link: https://abc084.contest.atcoder.jp/tasks/abc084_c?lang=en ----- */
/* ------問題------

Atcoder国に、 1 本の東西方向に走る鉄道が完成しました。
この鉄道には N 個の駅があり、西から順に 1,2,…,N の番号がついています。
明日、鉄道の開通式が開かれます。
この鉄道では、1≦i≦N−1 を満たす全ての整数 i に対して、駅 i から駅 i+1 に、Ci 秒で向かう列車が運行されます。ただし、これら以外の列車は運行されません。
駅 i から駅 i+1 に移動する列車のうち最初の列車は、開通式開始 Si 秒後に駅 i を発車し、その後は Fi 秒おきに駅 i を発車する列車があります。
また、Si は Fi で割り切れることが保証されます。
つまり、A％B で A を B で割った余りを表すとき、Si≦t,t％Fi=0 を満たす全ての t に対してのみ、開通式開始 t 秒後に駅 i を出発し、開通式開始 t+Ci 秒後に駅 i+1 に到着する列車があります。
列車の乗り降りにかかる時間を考えないとき、全ての駅 i に対して、開通式開始時に駅 i にいる場合、駅 N に到着できるのは最も早くて開通式開始何秒後か、答えてください。


-----問題ここまで----- */
/* -----解説等-----

適当に全部シュミレーションすればよい。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	N--;
	VL C(N), S(N), F(N);
	FOR(i, 0, N) {
		cin >> C[i] >> S[i] >> F[i];
	}


	FOR(j, 0, N) {
		LL t = 0;
		FOR(i, j, N) {
			if (t == S[i])t += C[i];
			else if (t > S[i]) {
				LL ret = t - S[i];
				ret = (ret + F[i] - 1) / F[i];
				t = S[i] + ret*F[i] + C[i];
			}
			else if (t < S[i])t = S[i] + C[i];
		}
		ans = t;
		cout << ans << "\n";
	}
	cout << 0 << endl;
	return 0;
}
