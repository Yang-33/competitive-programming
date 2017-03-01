#include<iostream>
#include<algorithm>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/01  Problem: ABC013 C / Link: http://abc013.contest.atcoder.jp/tasks/abc013_3 ----- */
/* ------問題------

セキュリティ意識が高く、最新鋭の錠を購入した高橋君ですが、財布の管理は甘かったらしくお金がピンチな状況です。
高橋君の収入は安定せず、次の収入があるのは今から N 日後です。高橋君は N 日間、できるだけ食費を抑えて節約生活を送ることにしました。
はじめ、高橋君の満腹度は H です。N 日間のそれぞれの日について、その日にとる食事を次の 3 種類の中から 1 つ選びます。
普通の食事: A 円の出費をして、満腹度が B 増える。
質素な食事: C 円の出費をして、満腹度が D 増える。（ただし、C<A かつ D<B）
食事抜き: 出費なしで、満腹度が E 減る。
厳しく節約すれば出費を抑えることができますが、あまりに節約しすぎて体調を崩してしまってはいけないため、
N 日間で一度も満腹度が 0 以下にならないようにしなければなりません。
高橋君は最低何円の食費で N 日間を乗り切ることができるでしょうか？
ただし、高橋君は超人級の胃袋を持っており、その満腹度には上限がないとする。すなわち、いくら食事をしても高橋君の満腹度が頭打ちになることはない。

-----問題ここまで----- */
/* -----解説等-----

最小の費用を決定する際に知りたいのは普通の食事と質素な食事をどれだけ食べるかであるが、
片側を決めてしまえばもう片側も選択されうる。
※( H + Bx + Dy - ( N - x - y  )*E ) > 0 となる x に対して最小の y は決定されうるため
片側を全探索していけばよい。
線形で解け！！！！！！！！！！！！！！！！！！！！！

 ----解説ここまで---- */

ll N, H, a, b, c, d, e;

ll ans = 0LL;

bool check(ll x, ll y) {
    return H + b*x + d*y - (N - x - y)*e > 0;
}

ll fy(ll x) {
    ll rec = (double)((N - x)*e - H - b*x) / (double)(d + e);
    rec++;
    if ((N - x)*e - H - b*x < 0) rec = 0;
    return rec;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> H >> a >> b >> c >> d >> e;

    ans = LLONG_MAX / 10;
    FOR(i, 0, N + 1) {
        if(check(i,fy(i)))
        ans = min(ans, a*i + c*fy(i));
    }

    cout << ans << endl;

    return 0;
}