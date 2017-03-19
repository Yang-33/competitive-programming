#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
using namespace std;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
typedef long long ll;

/* -----  2017/03/20  Problem: ABC029 D / Link: http://abc029.contest.atcoder.jp/tasks/abc029_d ----- */
/* ------問題------

高橋君は 1 以上 N 以下のすべての整数を十進表記で一回ずつ紙に書きました。
この作業で、高橋君は 1 という数字を何個書いたでしょうか。
整数 N (1 ≦ N < 10^9) が与えられる。

-----問題ここまで----- */
/* -----解説等-----

数える。
1の出現回数は N に対して N / 10 * 1 + N/10で切り捨てられた部分に出現する１
10の出現回数は N に対して N / 100 * 10 + N/100で切り捨てられた部分に出現する１0
となっているので
あとは切り捨てられた部分の数を数えればよい。
切り捨て部分の数が２以上であれば切り捨て部分には１回その数が登場し、78の10なら10かい
1ならば切り捨ての余った数分だけ数が登場する 16の10なら 10‾16の7かい 
dpがなくてもできる。

 ----解説ここまで---- */



int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    //memset(dp, -1, sizeof(dp));

    //cin >> N;
    int n;
    cin >> n;
    ll ans = 0;
    int x = (int)log10((double)n);
    FOR(i, 0, 10)
    {
        int d = pow(10, i + 1);
        int wantd=pow(10,i);
        int modulod = (n / wantd) % 10;

        ans += n / d * wantd; // n / 10^(i+1) が 10^i 回

        if(modulod==1){
            ans += n%(wantd)+1;
        }
        else if(modulod>1){
            ans += wantd;
        }
    }
    cout << ans << endl;

    return 0;
}