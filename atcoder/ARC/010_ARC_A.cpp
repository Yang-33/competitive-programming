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

/* -----  2018/12/14  Problem: ARC 010 A / Link: http://arc010.contest.atcoder.jp/tasks/arc010_a  ----- */
/* ------問題------

青木君は就職活動をおこなっている大学生で、名刺を N 枚持っています。
これから M 日間の就職活動を予定しており、 i 日目には名刺を ci 枚消費することがわかっています。
就職活動を行うにあたり、名刺が足りなくなると非常に困ります。
そこで、青木君はそれぞれの日のはじめに名刺の所持枚数を確認し、A 枚以下ならば B 枚名刺を補充することにしました。
B 枚補充しても A 枚以下にしかならないような場合でも、それ以上の補充はできません。

最初から持っている N 枚とこのような補充で、就職活動の最後の日まで乗りきれるかどうか判定してください。
もし、足りなくなる場合は、その日付を青木君に教えてあげてください。

-----問題ここまで----- */
/* -----解説等-----

シュミレーションすれば良い。

----解説ここまで---- */

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	int dame = 0;
	LL N, M, A, B; cin >> N >> M >> A >> B;
	VL a(M);
	FOR(i, 0, M) {
		cin >> a[i];
	}
	FOR(i, 0, M) {
		if (dame)break;
		if (N <= A)N += B;
		N -= a[i];
		if (N < 0)dame = i + 1;
		DD(de(N, a[i], dame));
	}

	cout << (!dame ? "complete" : to_string(dame)) << endl;
	return 0;
}