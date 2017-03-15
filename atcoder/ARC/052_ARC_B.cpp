#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const double PI = acos(-1.0);

/* -----  2017/03/15  Problem: ARC052 B / Link: http://arc052.contest.atcoder.jp/tasks/arc052_b ----- */
/* ------問題------

3次元空間( xyz 空間)上に N 個の円錐が互いに重なり合わないように浮いています。
どの円錐も底面が yz 平面と平行で、x 軸の正の方向にとがっています。
i 番目の円錐の底面の中心の x 座標の値は Xi で半径は Ri 、高さは Hi です。
以下のクエリに Q 個答えてください。
2 つの整数 A と B が与えられるので A≦x≦B となる空間の内いずれかの円錐の内側にある部分の体積をもとめよ。

-----問題ここまで----- */
/* -----解説等-----

各クエリごとにＮこの円錐全ての体積を求めていけばよい。
比を使って求めれば楽。

----解説ここまで---- */

int N, Q;
double x[100], r[100], h[100];
double A[100000], B[100000];
double ans = 0.0;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> N >> Q;
	FOR(i, 0, N) {
		cin >> x[i] >> r[i] >> h[i];
	}
	FOR(q, 0, Q) {
		cin >> A[q] >> B[q];
	}

	FOR(q, 0, Q) {
		ans = 0.0;
		FOR(i, 0, N) {
			if (B[q] < x[i] || x[i] + h[i] < A[q])continue;
			double a = max(x[i], A[q]) - x[i];
			double b = min(B[q], x[i] + h[i]) - x[i];
			ans += r[i] * (h[i] - a) / h[i] * r[i] * (h[i] - a) / h[i] * (h[i] - a)*PI / 3;
			ans -= r[i] * (h[i] - b) / h[i] * r[i] * (h[i] - b) / h[i] * (h[i] - b)*PI / 3;
		}
		printf("%.15f¥n", ans);
	}


	return 0;
}