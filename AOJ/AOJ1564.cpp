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

/* -----  2018/02/05  Problem: AOJ 1564 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1564  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

区間をぐいーんって伸ばすやつで、初期値を保っておくいつものやつ

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);


	string s;
	cin>>s;
	SORT(s);

	ans = SZ(s);
	int f = 0;
	VI num(11,0);
	VI al(26,0);
	FOR(i,0,SZ(s)){
		if(isalpha(s[i])){
			al[s[i]-'a']++;
		}else{
			num[s[i] -'0']++;
		}
	}
	FOR(k,0,200){
		int ren = 0;
		int s = -1;
		int del=0;
		FOR(i,0,26){
			if(al[i]>0){
				if(s==-1)s = i;
				ren++;
			
			}else {
				if(s!=-1&&ren>3){
					del+=ren-3;
					FOR(j,s,s+ren){
						al[j]--;
					}
				}
				s = -1;
				ren =0;
				
			}
		}
		if(s!=-1&&ren>3){
			del+=ren-3;
			FOR(j,s,s+ren){
				al[j]--;
			}
		}
		ans-=del;
	}
	FOR(k,0,200){
		int ren = 0;
		int s = -1;
		int del=0;
		FOR(i,0,10){
			if(num[i]>0){
				if(s==-1)s = i;
				ren++;
			
			}else {
				if(s!=-1&&ren>3){
					del+=ren-3;
					FOR(j,s,s+ren){
						num[j]--;
					}
				}
				s = -1;
				ren =0;
			}
		}
		if(s!=-1&&ren>3){
			del+=ren-3;
			FOR(j,s,s+ren){
				num[j]--;
			}
		}

		ans-=del;
	}
	cout << ans << "\n";

	return 0;
}
