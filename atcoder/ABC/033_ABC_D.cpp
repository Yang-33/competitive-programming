
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX

#include<cstdlib>
#include<utility>
#include<complex>
#include<functional>
#include<cassert>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/29 問題 ----- ABC033 D /Link http://abc033.contest.atcoder.jp/tasks/abc033_d */
/* -----解説等-----
問題: 2 次元平面上の N 個の点が与えられます。
i 番目の点の座標は (xi,yi) です。ただし、このうちのどの 3 点も同一直線上にありません。

N 点のうち 3 点を選ぶことによってこの 3 点を頂点とした三角形を作ることを考えます。
三角形は全部で N*(N?1)*(N?2)?6 個できます。
これらの三角形のうち、鋭角三角形の個数、直角三角形の個数、鈍角三角形の個数を求めてください。

ただし、鋭角三角形とは、3 つの角が全て 90° より小さい三角形で、
直角三角形とは、ある 1 つの角が 90° である三角形で、
鈍角三角形とは、ある 1 つの角が 90° より大きい三角形のことをいいます。


Ｏ( N^3 )をいかに落とすか考えていたが分からなかった。
偏角ソート。
ある頂点に対する頂点対をみて、その偏角を保存し昇順に並び替える。
このとき現在みている偏角+π/2ちょうどのものが存在すれば直角三角形が存在することがわかる。
固定頂点を選ぶのにN, 頂点と偏角をみるのにN, ソート済みのものから値を検索するのにlog N
で、Ｏ( N^2 log N )として解ける。
うまく組を見つけるために現在着目している値にさらに値を加えるという手法が肝かな。とおもった。

あとpi/2により誤差が生じるためepsで誤差丸め込みが必要。
負の角に対しては2πを加えても同じ角を示すことができるので二周分角をもつ。
何故落ちたのかよくわからん。15回投げたら通った。

*/

ll x[3000], y[3000];
const double eps = 1e-10;
ll cntc = 0, cntd = 0, sum = 0;
const double pi = acos(-1);


int main()
{


    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll N;
    cin >> N;

    for (int a = 0; a < N; a++) {
        cin >> x[a] >> y[a];
    }

    for (int i = 0; i < N; i++) {
        vector<double>argv;

        for (int j = 0; j < N; j++) {
            if (j == i)continue;
            argv.push_back(atan2(y[j] - y[i], x[j] - x[i]));
        }

        sort(argv.begin(), argv.end());

        for (int c = 0; c < (N - 1); c++) {
            argv.push_back(argv[c] + 2 * pi);
        }

        for (int j = 0; j < N - 1; j++) {
            cntc += upper_bound(argv.begin(), argv.end(), argv[j] + pi / 2 + eps) - lower_bound(argv.begin(), argv.end(), argv[j] + pi / 2 - eps);
            cntd += lower_bound(argv.begin(), argv.end(), argv[j] + pi) - upper_bound(argv.begin(), argv.end(), argv[j] + pi / 2 + eps);
        }

    }

    sum = N*(N - 1)*(N - 2) / 6;

    sum = sum - (cntd + cntc);
    printf("%lld %lld %lld¥n", sum, cntc, cntd);

    return 0;
}
