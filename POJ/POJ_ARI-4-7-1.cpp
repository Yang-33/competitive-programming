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
typedef pair<int,int> PII;
typedef pair<LL,LL> PLL;
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

/* -----  2018/01/24  Problem: POJ _ari-4-7-1 / Link: http://poj.org/problem?id=_ari-4-7-1  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


int main() {
	int N;

	string S; cin>>S;
	cin>>N;

	string AGCT = "AGCT";

	int mod = 10009;

	VVI dp(N+1,VI(SZ(S),0));
	
	int K = SZ(S);

	VVI next(K,VI(4,0));
	FOR(i,0,K){
		FOR(j,0,4){
			string s = S.substr(0,i) + AGCT[j];
			while(S.substr(0,SZ(s))!=s){
				s = s.substr(1);
			}
			next[i][j] = SZ(s);
		}
	}

	dp[0][0] = 1;
	FOR(i,0,N){
		FOR(k,0,K){
			FOR(j,0,4){
				int nxs = next[k][j]; // 文字列の遷移先を求める
				if(nxs == K)continue;
				dp[i+1][nxs] += dp[i][k];
				dp[i+1][nxs] %= mod;
			}
		}
	}

	LL ans = 0;
	FOR(i,0,K){
		ans += dp[N][i];
		ans %= mod;
	}

	cout<<ans<<endl;

	return 0;
}
