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

/* -----  2018/06/10  Problem: AOJ 2424 / Link: http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2424  ----- */
/* ------問題------

太郎君はかけざんを習いたての小学生です。なんとなく、彼はかけざんを気に入っているので、数字を見かけるとかけざんをしたくなります。そんな彼はここのところ、次のような処理を0以上の整数に施すことが好きなようです。 (処理の流れ)

手順1. ある0以上の整数nが10進数表示で一けたならばそこで処理を終了する。そうでなければ手順2に進む
手順2. 10以上の整数nを10進数表示をするとどこかの桁の間に切れ目を入れて二つの数字に分解することが可能である(例えば2012-> 20,12)。このような切り方としてありうるものに対して,得られた二つの数字を掛け合わせて最も大きいものを次のnとして手順1に戻る。(詳しくは下記の"手順2に関する補足を参照")
太郎君はこの処理を気に入っているようですが、何回手順2の操作を繰り返せばよいのか大きい数字だと予想ができず、もしかしたら無限回行われなければならないかもしれないと思っています。そこで、太郎君の兄であり大学生であるあなたに0以上の整数nに対してこの手順2を何回しなければならないかを聞いてきました。

あなたの仕事は、Q個の0以上の整数N1..NQが与えられるので、それぞれの整数で処理の終了までに何回の手順2が施されるかを求めることです。その際にもし無限回の手順が必要ならば、-1を出力してください。

-----問題ここまで----- */
/* -----解説等-----

シュミレーションします

----解説ここまで---- */

using LL = long long; using ll = LL;
using VI = vector<int>; using VL = vector<LL>;
using VVI = vector<VI>; using VVL = vector<VL>;


// problem : a

ll getnext(ll N) {
	ll Max = -1;
	ll ten = 10;
	while (N%ten != N) {
		Max = max(Max, (N%ten)*(N / ten));
		ten *= 10;
	}
	return Max;
}
ll solve() {
	ll res = 0;
	map<ll, bool> mp;
	ll N; cin >> N;
	while (true) {
		if (mp.count(N)) return -1;
		mp[N] = true;
		if (N <= 10) break;
		N = getnext(N);
		res++;
	}
	return res;
}

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	ll Q; cin >> Q;
	while (Q--) {
		cout << solve() << endl;
	}

	return 0;
}