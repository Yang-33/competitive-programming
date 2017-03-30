#include<iostream>
#include<algorithm>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl

/* -----  2017/03/30  Problem: CodeForces407 C div2 / Link: http://codeforces.com/contest/789/problem/C ----- */
/* ------問題------

f(l,r)=Σ(i=[l,r-l]) |a[i]-a[i+1]|*(-1)^(i-l)
とanが与えられる。関数fの最大値を求めよ。


-----問題ここまで----- */
/* -----解説等-----

絶対値部分のみを前計算し、基準にしたところから +,-,+,-,...,+,- となるので基準を決めたら
現在の値を０としてそこに+を足す=> 次がマイナスでも現在値にその値を加えても＋ならこれをとって次を見ることができる
ということを利用して尺取り法のような形で端から端まで見ていく。
現在の値を０以上に保つことで、もしマイナスの値で値が負になった後に加える値がプラスでも、これはその新たなプラスの値のみを
取った方が最適となるような尺取り法を実現することができる。
現在値のみが肝心なのでindexは不要。

----解説ここまで---- */

ll N;

ll ans = 0LL;
ll b[100010], c[100010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    ll a[100010];
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, N - 1) {
        int x = 1; if ((i + 1) % 2 == 0)x = -1;
        b[i] = abs(a[i + 1] - a[i])*x;
        int y = -1; if ((i + 1) % 2 == 0)y = 1;
        c[i] = abs(a[i + 1] - a[i])*y;

    }
   /* FOR(i, 0, N - 1) {
        cout << b[i] << " " << c[i] << endl;
    }*/
    ll sum = 0;
    FOR(i, 0, N - 1) {
        ans = max(ans, sum + b[i]);
        if (b[i] + b[i + 1] >= 0)sum += b[i] + b[i + 1], ans = max(ans, sum);
        else {
            ans = max(ans, sum);
            if (sum + b[i] + b[i + 1] >= 0)sum += b[i] + b[i + 1];
            else sum = 0;
        }

        i++;
        ans = max(ans, sum);

    } 
    sum = 0;
    FOR(i, 1, N - 1) {
        ans = max(ans, sum + c[i]);

        if (c[i] + c[i + 1] >= 0)sum += c[i] + c[i + 1], ans = max(ans, sum);
        else {
            ans = max(ans, sum);
            if (sum + c[i] + c[i + 1] >= 0)sum += c[i] + c[i + 1];
            else sum = 0;
        }

        i++;

    }
    cout << ans << endl;

    return 0;
}