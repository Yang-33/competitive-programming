#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/15  Problem: ARC049 B / Link: http://arc049.contest.atcoder.jp/tasks/arc049_b ----- */
/* ------問題------

高橋ノルム君の可能性は無限大です。高橋ノルムという名前の人物はこの世界にたくさんいます。
2 次元平面上に N 人の高橋ノルム君がいます。i(1≦i≦N) 人目の高橋ノルム君は座標 (xi,yi) にいます。 
各高橋ノルム君には正整数定数 ci が割り当てられており、i 人目の高橋ノルム君がある点 (X,Y) に移動するためには ci*max(|xi−X|,|yi−Y|) の時間がかかります。
あなたの仕事は、全ての高橋ノルム君が一点に集まるために必要な最小の時間を求めることです。
ここで、一点に集まるために必要な最小の時間とは最も遅くその点に到着する高橋君の移動にかかった時間とします。
高橋ノルム君は一斉に動き出し、お互いに干渉せず動くものとします。

-----問題ここまで----- */
/* -----解説等-----

T秒かけてもいいなら移動しうる、ことが確定しているので最大値の最小値を二分探索可能。区間は(l,r]
t=c*max(|xi-X|,|yi-Y|)であるが、t/c=max(|xi-X|,|yi-Y|)とみれば
これは i 人目がt秒で移動できる範囲を表していることになり、全員が同じ共通範囲を持っていればいいことになる。
max(|xi-X|,|yi-Y|)は、(xi,yi)を中心とした一辺2*t/cの正方形であるから
全ての点にこれと共通範囲を持つ、すなわちtびょうで到達可能な範囲にあるかを判定すればよい。
時間が厳しいので精度が低いが解答では許されうる。

----解説ここまで---- */

ll N;
int x[1000], y[1000], c[1000];
double ans = 0.0;

bool f(double t) {
	FOR(i, 0, N)FOR(j, i + 1, N) {
		int X = abs(x[i] - x[j]);
		if ((double)X > t / c[i] + t / c[j])return false;
		int Y = abs(y[i] - y[j]);
		if ((double)Y > t / c[i] + t / c[j])return false;
	}
	return true;
}

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N;
	FOR(i, 0, N) {
		cin >> x[i] >> y[i] >> c[i];
	}

	double l = 0, r = 1e15;
	FOR(i, 0, 100) {
		double mid = (l + r) / 2;
		if (f(mid))r = mid;
		else l = mid;
	}
	ans = r;
	printf("%.15f\n", ans);
	return 0;
}