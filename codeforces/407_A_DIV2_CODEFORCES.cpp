#include<iostream>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/30  Problem: CodeForces407 A div2 / Link: http://codeforces.com/contest/789/problem/A ----- */
/* ------問題------

N種類のそれぞれ個数がAiの石がある。
ポケットが二つあり１つにKこ入れることができる。それぞれの中には異なる種類の石を入れてはいけない。
最短何日ですべてを回収できるか。

-----問題ここまで----- */
/* -----解説等-----

Aiの石をK個のサイズで分割する。異なる石は中に入れてはいかないのだから石の数をKで切り上げればよい。
２つポケットがあるので総運搬回数が２で割れなかったら割った後で１を足す。

----解説ここまで---- */

ll N;

ll ans = 0LL;

int main()
{
	cin.tie(0);
	ios_base::sync_with_stdio(false);
    ll K;
	cin>>N>>K;
    ll a[100010];
    FOR(i, 0, N) {
        cin >> a[i];
    }

    FOR(i, 0, N) {
        ll num = a[i] / K;
        ans += num;
        if (a[i] % K != 0)ans++;
    }
    if (ans % 2 == 1) {
        cout << ans / 2 + 1 << endl;
    }else
	cout<<ans/2<<endl;

	return 0;
}