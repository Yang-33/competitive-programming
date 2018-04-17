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
#define FOR(i, s, e) for (LL(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (int(i) = (s); (i) > (e); (i)--)
#define debug(x) cerr << #x << ": " << x << endl
const int INF = 1e9;                          const LL LINF = 1e16;
const LL MOD = 1000000007;                    const double PI = acos(-1.0);
int DX[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };    int DY[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2018/04/17  Problem: yukicoder 087  / Link: http://yukicoder.me/problems/no/087  ----- */
/* ------問題------

2015 年~N年の間(2015やNも含む)で
yukicoder no.1の出題日（記事中に記載有り）が2014年と同じ曜日になる回数を求めてください。

カレンダーは現実世界と同じものを用いる。

うるう年は通常の判定方法を用いる。
・4で割れる年はうるう年である。
・ただし、100で割れるときは、うるう年ではない。
・ただし、400で割れるときは、うるう年である。
西暦N年の時点でもグレゴリオ暦を用いるとする。

-----問題ここまで----- */
/* -----解説等-----

2014年7月23日(水)
なんでFOR(i,2015,2015+(N-2014)%400)はOKで
FOR(i,2014 + t*400 + 1, N)はだめなんや？ -> mod400の値がずれるため

----解説ここまで---- */

LL N;

LL ans = 0LL;



int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);
	//400年分単位で計算し、のこりはシュミレーション

	cin >> N;

	LL t = (N - 2014) / 400;

	{// block
		LL K = 0; LL sum = 0;
		FOR(i, 2015, 2015 + 400) {
			if (i % 400 == 0)sum += 2;
			else if (i % 100 == 0)sum += 1;
			else if (i % 4 == 0)sum += 2;
			else sum += 1;
			if (sum % 7 == 0)K++;
		}
		ans += t * K;
	}
	LL s = 2014 + t * 400;
	
	{// sumilation
		LL K = 0; LL sum = 0;
		FOR(i, 2015 , 2015 + (N-2014)%400) {
			if (i % 400 == 0)sum += 2;
			else if (i % 100 == 0)sum += 1;
			else if (i % 4 == 0)sum += 2;
			else sum += 1;
			if (sum % 7 == 0)K++;
		}
		ans += K;
	}
	cout << ans << endl;

	return 0;
}
