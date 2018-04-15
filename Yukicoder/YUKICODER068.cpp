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

/* -----  2018/04/15  Problem: yukicoder 068  / Link: http://yukicoder.me/problems/no/068  ----- */
/* ------問題------

ユウキさんは N 本の棒を持っていて、i 番目の棒の長さは Li です。
棒は（長さを分割する方向に）自由に切ることができますが、繋げることはできません。
ユウキさんは同じ長さの棒を作りたいのですが、何本であればどのぐらいの長さにできるかが気になっています。
同じ長さの棒を K1,K2,…,KQ 本作るとしたら、その時の棒の長さの最大値をそれぞれ求めるプログラムを書いて下さい。

-----問題ここまで----- */
/* -----解説等-----

解説を見ました。  
ある棒L[i]について、これをP本使うとする。次使うときはP+1本のときで、長さも確定する。  
今0本使うとして、1本使うときは集合から最大値を持ってこれば良い。その後L[i]はL[i]/(自身を使った回数+1)だけの長さに更新しておくと、  
2本使うときの最大値は、もとの長さのL[i]を割って2回使うあるいは、他の大きなL[j]を使うことで得られる。
最大値の選択が解を保証するため、順番に動作を行っていけばp本使うときの最大値を求めることができる。
このようにして順番にp本使うときの長さを先に求めることでクエリO(1)を達成できる。  


O(K[i]logN+Q)

----解説ここまで---- */

LL N;
struct frac {
	LL x, c;
	bool operator< (const frac& a) const {
		return a.c*x < c*a.x;
	}
};
int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	priority_queue<frac, vector<frac>>pq;
	FOR(i, 0, N) {
		int L; cin >> L;
		pq.emplace(frac{ L,1 });
	}
	vector<double>res(5e5 + 5);
	FOR(k, 1, 5e5 + 1) {
		frac a = pq.top(); pq.pop();
		res[k] = 1.*a.x / a.c;
		pq.emplace(frac{ a.x,a.c + 1 });
	}



	LL Q; cin >> Q;
	FOR(i, 0, Q) {
		int k; cin >> k;
		double ans = res[k];
		cout << fixed << setprecision(10) << ans << "\n";
	}

	return 0;
}
