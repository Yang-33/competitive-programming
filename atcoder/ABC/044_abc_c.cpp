#include<iostream>
#include<algorithm>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 問題 ----- ABC044 C /Link http://abc043.contest.atcoder.jp/tasks/arc059_a */
/* -----解説等-----
問題: N 個の整数 a1,a2,..,aN が与えられます。えび君はこれらを書き換えて全て同じ整数にしようとしています。
各ai(1≦i≦N)は高々一回しか書き換えられません(書き換えなくても良い)。
整数xを整数yに書き換えるとき、コストが(x?y)^2かかります。
仮にai=aj(i≠j)だとしても、ひとつ分のコストで同時に書き換えることは出来ません(入出力例2 を参照)。
えび君が目的を達成するのに必要なコストの総和の最小値を求めてください。

制約
1≦N≦100
?100≦ai≦100

平均値から出せるかなと思ったがこれはデータの散らばり方によるので厳しいかなあということで全探索した。
最小値の全探索。
数学的に解こうとして少し時間がかかってしまったが基本は全探索であるという事に忠実でありたい！

全探索しなくても
avg = sum / N
d = sum % Nとして
d > N / 2 ならavg++で求められる。
つまりデータの半分に対して１を乗っけられるかどうかをみる。
割り切れるかどうかでも場合分けできそう。


*/

int N;
int a[100];
ll ans = INT_MAX;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    FOR(i, -100, 101) {
        ll minn = 0;
        FOR(j, 0, N) {
            minn += (a[j] - i)*(a[j] - i);
        }
        ans = min(minn, ans);
    }

    cout << ans << endl;

    return 0;
}