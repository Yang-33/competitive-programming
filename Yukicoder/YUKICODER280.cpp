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

/* -----  2018/09/25  Problem: yukicoder 280  / Link: http://yukicoder.me/problems/no/280  ----- */
/* ------問題------

N個の歯車で減速機構を作ることにしました。
なお、問題の内容にはあまり関係ありませんが、この問題で扱われる歯車は理想的なインボリュート歯車(参考)として構いません。
すなわち、歯車は損失や誤差なく動力を伝達でき、回転の途中で減速比が変化することはないものとします。

今、歯数がz1,z2,...,zNの歯車が一列に並べられ、それぞれ隣りあった歯車のみと噛み合っています。
1番目の歯車を入力として、N番目の歯車を出力として使用することが決まっています。
この減速機構の減速比はいくらでしょうか？

ここで、ある隣り合って噛み合っている2つの歯車a,bについて、歯数をza,zbとして、aをθaだけ回転させたとき,bが回転した角度をθbとしたとき、
|θb|=|θa|zazb
であり、入力となるi番目の歯車をθiだけ回転させたとき、出力となるj番目の歯車がθjだけ回転したときに減速比grは
gr=|θi||θj|
で表されます。

-----問題ここまで----- */
/* -----解説等-----

式変形をすると、θn = z1/znなのでこれをそのまま出力すれば良い。

----解説ここまで---- */

LL N;

LL ans = 0LL;

int main() {
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	VL z(N);
	FOR(i, 0, N) {
		cin >> z[i];
	}
	cout<<z.back()<<"/"<<z.front()<<"\n";

	return 0;
}
