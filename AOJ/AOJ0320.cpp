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

/* -----  2018/01/17  Problem: AOJ 0320 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0320  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----



----解説ここまで---- */

LL C,N;

LL ans = 0LL;
int val0=0;
int val15=0;
inline void change(int y,int x,VVI& masu){
	if(y<=N/2&&x<=N/2){
		if(masu[y][x]==0)val0--;
		else if(masu[y][x]==15)val15--;
		masu[y][x]^=1;
		if(masu[y][x]==0)val0++;
		else if(masu[y][x]==15)val15++;
	}else if(x<=N/2){
		y = N-y+1;
				if(masu[y][x]==0)val0--;
		else if(masu[y][x]==15)val15--;

		masu[y][x]^=2;
				if(masu[y][x]==0)val0++;
		else if(masu[y][x]==15)val15++;

	}else if(y<=N/2){
		x = N-x+1;
				if(masu[y][x]==0)val0--;
		else if(masu[y][x]==15)val15--;

		masu[y][x]^=4;
				if(masu[y][x]==0)val0++;
		else if(masu[y][x]==15)val15++;

	}else{
		x = N-x+1;
		y = N- y+1;
				if(masu[y][x]==0)val0--;
		else if(masu[y][x]==15)val15--;

		masu[y][x]^=8;
				if(masu[y][x]==0)val0++;
		else if(masu[y][x]==15)val15++;

	}
	//cout<<"nene "<<y << ", "<<x<<endl;
}
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> C>>N;
	VVI masu(N/2+2,VI(N/2+2,0));
	val0 = (N*N)/4;
	LL kim = val0;
	//debug(val0);
	FOR(i,0,N){
		string s;
		cin>>s;
		FOR(j,0,N){
			if(s[j] == '1')
			change(i+1,j+1,masu);
		}
	}
	if(val0+val15==kim)ans++;
	FOR(i,0,C-1){
		int d;
		cin>>d;
		FOR(j,0,d){
			int a;int b;
			cin>>a>>b;
			change(a,b,masu);
			
		}
		if(val0+val15==kim){
			ans++;
		}
	}

	cout << ans << "\n";

	return 0;
}
