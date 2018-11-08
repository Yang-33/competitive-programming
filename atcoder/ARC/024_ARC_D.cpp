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
//#pragma GCC optimize ("-O3") 
#ifdef YANG33
#include "mydebug.hpp"
#else
#define DD(x) 
#endif
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/11/10  Problem: ARC 024 D / Link: http://arc024.contest.atcoder.jp/tasks/arc024_d  ----- */
/* ------問題------

高橋国の高橋王は国内の交通の便を良くするためにいくつかバス停を設置することにしました。 高橋国には東西に走る道路と、南北に走る道路の 2 種類しかありません。ある基準点から東に i キロメートルの地点に i 番目の南北の道路が敷かれており、北に j キロメートルの地点に j 番目の東西の道路が敷かれています。 i 番目の南北の道路と j 番目の東西の道路の交差点を (i,j) と表すことにします。道路は無限に長いのでどの 2 つの直交する道をとってもどこかで交差します。 バス停は交差点にのみ設置し、同じ交差点にはたかだか 1 個までしかバス停を設置しません。
いまちょうど N 個のバス停を設置し終わりました。 しかし、ここで高橋王は重大なミスに気づきます。道路が狭すぎてバスが道を曲がれないのです。 つまり、どの路線も東西もしくは南北のどちらか一方にしか移動できないということになります。 これでは、バスのみで行き来ができないバス停ができてしまいます。 これでは不便なので、新たにいくつかのバス停を設置してどの 2 つのバス停間もバスの乗り換えを繰り返すことで移動できるようにします。なお、バスの乗り換えはバス停でしかできません。 また、その乗り換えが遠回りになっても不便なので、どの 2 つのバス停間も総移動距離がバス停間のマンハッタン距離と等しくなるようなバスの乗り換えが可能になるように設置します。 つまりどの 2 つのバス停 (a,b),(c,d) にも、総移動距離が |a−c|+|b−d| キロメートルとなるような乗り換え経路があるようにするということです。
予算の関係で合計で 10,000 個のバス停しか設置できません。つまり、残り 10,000−N 個しか設置できません。 その範囲で上記の条件をみたすようにバス停を追加するとき、新たに置くバス停の場所を求めてください。解が複数通り存在する場合はどれを求めても構いません。

-----問題ここまで----- */
/* -----解説等-----

分割統治。いい感じに柱を立てれば良い。フラクタルにやるまでしかわからなかったので、感動した。片軸だけでいいんですよね…
NlogN個でいける。

----解説ここまで---- */

vector<PII>ans;
bool exist[1003][1003];
// [L,R)
void f(int L, int R, const vector<PII>&a) {
	if (R - L < 1)return;
	int mid = (L + R) / 2;
	int x = a[mid].first;
	FOR(i, L, R) {
		if (a[i].first == x)continue;
		if (exist[x][a[i].second])continue;
		exist[x][a[i].second] = 1;
		ans.push_back(PII(x, a[i].second));
	}

	f(L, mid, a);
	f(mid + 1, R, a);
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	LL  N; cin >> N;
	VI x(N), y(N);
	vector<PII>a(N);
	FOR(i, 0, N) {
		cin >> x[i] >> y[i];
		exist[x[i]][y[i]] = 1;
		a[i] = PII(x[i], y[i]);
	}
	SORT(a);
	f(0, N, a);
	cout << SZ(ans) << endl;
	for (auto it : ans) {
		cout << it.first << " " << it.second << endl;
	}

	return 0;
}