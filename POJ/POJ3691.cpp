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
#define UNIQ(c) (c).erase(unique(ALL((c))), (c).end())
#define FOR(i, s, e) for (int(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/01/24  Problem: POJ 3691 / Link: http://poj.org/problem?id=3691  ----- */
/* ------問題------

蟻本例題 4-7 string 1

-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */


int main() {
	int N;
	int Tc = 1;
	string ATGC = "ATGC";
	while(scanf("%d", &N),N){
		vector<string>p(N);
		FOR(i, 0, N){
			cin >> p[i];
		}
		string S; cin>>S;
		vector<string> pref;
		FOR(i,0,N){
			FOR(j,0,SZ(p[i])+1){
				pref.push_back(p[i].substr(0,j));
			}
		}

		SORT(pref);
		UNIQ(pref);
		int States = SZ(pref);

		VVI next(States,VI(4,0));
		VI dont(States,0);

		FOR(i, 0, States ){
			dont[i] = 0;
			FOR(n ,0 ,N ){
				dont[i] |= (SZ(pref[i]) >= SZ(p[n]) && pref[i].substr(SZ(pref[i]) - SZ(p[n]), SZ(p[n])) == p[n] );
			}


			FOR(k,0,4){
				string s = pref[i] + ATGC[k];
				int state;
				for(;;){
					state = lower_bound(ALL(pref),s) - pref.begin();
					if(state < States && pref[state] == s)break;
					s = s.substr(1);
				}
				next[i][k] = state;
			}	
		}



		VVI dp(SZ(S)+1,VI(States,INF));
		FOR(state,0,States)dp[0][state] = 0;
		dp[0][0] = 1;
		FOR(i,0,SZ(S)){
			FOR(state,0,States){
				if(dont[state])continue;
				FOR(k,0,4){
					int nxs = next[state][k];
					dp[i+1][nxs] = min(dp[i+1][nxs], dp[i][state] + (S[i]==ATGC[k]?0:1));
				}
			}
		}

		int ans = INF;
		FOR(state,0,States){
			if(dont[state])continue;
			ans = min(ans,dp[SZ(S)][state]);
		}

		if(ans == INF){
			ans = -1;
		}
		printf("Case %d: %d\n",Tc,ans);
		Tc++;

	}

	return 0;
}
