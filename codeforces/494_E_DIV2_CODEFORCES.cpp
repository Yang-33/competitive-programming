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

/* -----  2018/07/03  Problem: CodeForces494 E div2 / Link: http://codeforces.com/contest/1003/problem/E  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


bool check(int N, int D, int K) {
	LL sum = 2;
	LL ret = 1;
	FOR(i, 1, (D - 1) / 2 + 1) {
		sum += 2 * ((K - 2) * ret + 1);
		ret = (K - 1) * ret + 1;
	}
	if ((D + 1) % 2 == 1) {
		sum += ret*(K - 2) + 1;
	}
	LL nn = N;
	return nn <= sum;
}

// 残りN点、D個のパス
int Left;
int idx = 1;

void dfs(int id, int N, int D, int K) { //  直径D->
			


}


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N, D, K; cin >> N >> D >> K;
	if (K == 1) {
		if (D == 1 && N == 2) {
			cout << "YES" << endl;
			cout << "1 2" << endl;
		}
		else {
			cout << "NO" << endl;
		}

	}
	else if (K == 2) {
		if (D + 1 == N) {
			cout << "YES" << endl;
			FOR(i, 0, D) {
				cout << i + 1 << " " << i + 2 << endl;
			}
		}
		else {
			cout << "NO" << endl;
		}
	}
	else {
		if (check(N, D, K)) {
			cout << "YES" << endl;
			Left = N;
		}
		else {
			cout << "NO" << endl;
		}



	}


	return 0;
}
