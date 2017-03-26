#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;

typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl

/* -----  2017/03/27  Problem: ABC 057 D / Link: http://abc057.contest.atcoder.jp/tasks/abc057_d ----- */
/* ------蝠城｡---

N 個の品物が与えられます。
i 番目の品物の価値は vi(1≦i≦N) です。
これらの品物から、A 個以上、B 個以下を選ばなければなりません。
この制約下において、選んだ品物の価値の平均の最大値を求めてください。
また、選んだ品物の平均が最大となるような品物の選び方が何通りあるかを求めてください。

-----問題ここまで----- */
/* -----解説等-----

典型で解こうとしてしまったので半分全列挙や二分探索だと決めつけてしまったが、
ただの平均の取り方の問題。
降順に並べて先頭から撮っていく場合、A個とるのはかなり最適である。というのもA+1個めがA個目よりも小さいときには平均値が下がるので
これは最適ではなくなるからである。
A+1個めが前のものと同じであるときに組み合わせを考える。
また、選んだk個≧Aがすべて同じときには別の場合分けをすればよい。

----解説ここまで---- */

ll N, A, B;
ll v[60];
ll ans = 0;
ll comb[100][100];

double ave = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> A >> B;
    FOR(i, 0, N) {
        cin >> v[i];
    }


    for (int i = 0; i <= 60; i++) {
        for (int j = 0; j <= i; j++) {
            if (j == 0 || j == i)
                comb[i][j] = 1;
            else
                comb[i][j] = comb[i - 1][j - 1] + comb[i - 1][j];
        }
    }


    sort(v, v + N);
    reverse(v, v + N);

    if (v[0] != v[A - 1]) {
        int cnt = 0, ne = 0;
        FOR(i, 0, N) {
            if (v[A - 1] == v[i]) {
                cnt++;
                if (i < A) {
                    ne++;
                }
            }
            if (i < A)ave += v[i];
        }
        //debug(cnt);
        ave /= A;
        ans = comb[cnt][ne];
    }
    else if (v[0] == v[A - 1]) {
        int cnt = 0;
        FOR(i, 0, N) {
            if (v[0] == v[i])cnt++;
        }
        ave = v[0];
        FOR(i, A, B + 1) {
            if (cnt>=i) {
                ans += comb[cnt][i];
            }
        }

    }

    printf("%.10f\n", ave);
    cout << ans << endl;
    return 0;
}
