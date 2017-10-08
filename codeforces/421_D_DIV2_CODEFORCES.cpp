#include "bits/stdc++.h"
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define debug(x) cout<<#x<<": "<<x<<endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0,0,1,-1,1,1,-1,-1 };
int dy[8] = { 1,-1,0,0,1,-1,1,-1 };

/* -----  2017/06/27  Problem: CodeForces421 D div2 / Link: http://codeforces.com/contest/820/problem/D  ----- */
/* ------問題------

N項の数列Pが与えられる。
ここでsum=sigma[i=1,N] |p[i]-i| と定義する。
またkを定義しk=0のとき、これを行いk=1のとき数列Pを左にひとつずらす。
K=[0,N-1]のとき、このsumを最小化するようなkとそのsumを求めよ。

-----問題ここまで----- */
/* -----解説等-----

三分探索したが間に合わない。(三分探索ではない)

[2017/10/08]
ARC077E を解いたとき思い出したので解いた。
これはグラフにすると三分探索ができない形になっている。
Kをひとつずらしたとき、これは各要素について-1or1,N-1となることが分かる。
したがってひとつずらしたときの差分を考えれば解くことができる。
これはBITなどのデータ構造があればうれしい気持ちになる。
また、別解としてp[i]に注目したとき、これはある軸を対象とした区間に三角形を足しこんだような値をとる。
これを一つO(logN)ほどで実現できればよいがあとから処理すれば一つ当たりO(1)、全体でO(N)でできる。
したがってこの加算された区間に対して最小値をもつidをとってくればよい。
2Nの区間でやると反転処理を飛ばせてうれしい。

----解説ここまで---- */

int N;
int a[1000006];



template<typename T>// LL がよさそう
struct triangle_cumulativesum {
	vector<T> data;
	const int width = 3;
	triangle_cumulativesum(int N) :data(2*N+10, 0) {}//大体ぐるぐる使うので
	void build() {
		FOR(i, 0, (int)data.size() - 1) {
			data[i + 1] += data[i];
		}
	}
	void query_add(T s, T t, T a, T k) {
		data[s] += a + k;
		data[s + 1] += -k;
		data[t] += -(a*(t - s + 1) + k);
		data[t + 1] += a*(t - s) + k;
	}
};


int main()
{
	scanf("%d", &N);
	FOR(i, 0, N) {
		scanf("%d", &a[i]);
	}

	triangle_cumulativesum<ll> tri(N + 10);
	FOR(i, 0, N) {
		int P = a[i];
		int I = i + 1;
		int F = (N - I + 1) % N; // start
		int zeroP = F + (a[i] - 1); // 0
		int E = F + N - 1;//0,1,2,...,E番目が最後 end
		// [F,zeroP,E]
		//cout << "DB. " << F << " " << zeroP << " " << E << endl;
		tri.query_add(F, zeroP + 1, -1, a[i]);
		tri.query_add(zeroP, E + 1, 1, -1);


	}

	tri.build();
	tri.build();
	FOR(i, 0, N) {
		tri.data[i + N] += tri.data[i];
	}

	ll ans = LINF;
	ll id = -1;
	FOR(i, N, 2 * N) {
		if (ans > tri.data[i]) {
			ans = tri.data[i];
			id = i - N;
		}
	}
	cout << ans << " " << id << endl;
	return 0;
}