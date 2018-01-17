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
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/01/17  Problem: AOJ 0321 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=0321  ----- */
/* ------問題------



-----問題ここまで----- */
/* -----解説等-----

順番も考えて(# ﾟДﾟ)

----解説ここまで---- */

int N,M,Q;

LL ans = 0LL;

#define int long long
/* Union Find */
struct UnionFind {
	vector<int> data;
	UnionFind(int n) { data.assign(n, -1); }
	bool unionSet(int x, int y) { // xが根ね 
		x = root(x); y = root(y);
		if (x != y) {
			if(y>N)swap(x,y); 
			//if (data[y] < data[x]) swap(x, y);
			data[x] += data[y]; data[y] = x;
		}
		return x != y;
	}
	bool same(int x, int y) { return root(x) == root(y); }
	int root(int x) { return data[x] < 0 ? x : data[x] = root(data[x]); }
	int size(int x) { return -data[root(x)]; }
};
// UnionFind uf(n); uf.unionSet(i,j); if(uf.same(x,y))
#define debug(x) cout<<#x<<" "<<x<<endl;
signed main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N>>M>>Q;
	UnionFind uf(N+M+2);
//	VI used(N+M+1,0);
	ans =0;

	FOR(i,0,Q){
		//cout << ans << endl;
		int a,b,c;
		cin>>c>>a>>b;
		if(c==1){
			if(uf.root(a)>N&&uf.root(b)>N&& !uf.same(a,b)){
				if(ans==0)ans = i+1;
			}
			
			uf.unionSet(a,b);
		}else { // club
			if(uf.root(a)>N && !uf.same(a,b+N)){
				if(ans==0)ans=i+1;
			}
			uf.unionSet(N+b,a);
			//cout << uf.root(a) << endl;
		}
		// FOR(i,0,N){
		// 	debug(uf.root(i+1));
		// }
		// FOR(i,0,M){
		// 	debug(uf.root(i+N+1));
		// }
	}
	cout << ans << "\n";

	return 0;
}
