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

/* -----  2018/08/02  Problem: yukicoder 210  / Link: http://yukicoder.me/problems/no/210  ----- */
/* ------問題------

探偵のコーデリアは老紳士から紛失したメガネの捜索を依頼された。
老紳士の邸宅には部屋がn個あり、それぞれの部屋に1からnまでの番号がふってある。そのうちi番目の部屋でメガネを紛失した確率はpi1000であることがわかっている。
また部屋は非常に散らかっておりその部屋にメガネがあっても一回捜索しただけでメガネが見つかるとは限らない。
i番目の部屋にメガネがあった時、過去に何回その部屋を捜索したかに関係なくその部屋を一回捜索してメガネが見つかる確率はqi100である。

コーデリアは茉莉音のライブに参加するため、できるだけ少ない回数、部屋を捜索してメガネを見つけたい。
コーデリアを助けるため、メガネが見つかるまでに部屋を捜索する回数の期待値を最小化してほしい。

-----問題ここまで----- */
/* -----解説等-----

貪欲に発見されやすい部屋をみていけばよい。

----解説ここまで---- */


int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int N; cin >> N;
	VI p(N), q(N);
	FOR(i, 0, N) {
		cin >> p[i];
	}
	FOR(i, 0, N) {
		cin >> q[i];
	}

	using tp = tuple<double, int>;
	priority_queue<tp> pq; //big
	FOR(i, 0, N) {
		pq.push(tp(1.0*p[i]*q[i]/100000,i));
	}
	double ans = 0;
	FOR(kth, 1,925000) {
		double pp; int id;
		tie(pp, id) = pq.top(); pq.pop();
		ans += 1.0*kth*pp;
		pp *= (100.0 - q[id]) / 100.0;
		pq.push(tp(pp,id));
	}


	cout << fixed << setprecision(10) << ans << "\n";

	return 0;
}
