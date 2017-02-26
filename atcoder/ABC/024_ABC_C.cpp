#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/02/26  Problem: ABC024 C / Link: http://abc024.contest.atcoder.jp/tasks/abc024_c ----- */
/* ------問題------

高橋王国には N 個の街があり、それぞれ 1 〜 N の整数によって番号付けされています。
高橋王国には K 種類の民族が住んでおり、i 番目の民族は街 Si に住んでいます。
高橋王国の民族たちには、百年に一回住む街を変える「民族大移動」という文化が有ります。 基本的には全民族が同時期に「民族大移動」を行うのですが、全く同じ日に全民族が移動すると混雑が予想されるため、 以下の様な移動制限を毎日設けて、 D 日かけて行います。
i 日目は 街の番号が Li 以上 Ri 以下であるよう街の間を自由に行き来できる。それ以外の行き来は禁止される。
各民族はこの移動制限を守り、いくつかの街を経由しながら目的地の街まで移動します。
i 番目の民族の目的地は街 Ti です。どの民族もできるだけ早く目的地に到着したいと思っています。
各民族について、目的地に到着できる最も早い日を求めてください。
なお、どの民族も D 日以内に目的地に到着できることが保証されています。

-----問題ここまで----- */
/* -----解説等-----

区間をできるだけ移動しても問題ないことから、
町の番号が増加する方向に移動したいならば各日にちごとに最大の町の番号まで移動すればよい。
一方、町の番号が減少する方向に移動したいならば各日にちごとに最小の町の番号へ進めばよい。

きれいに実装できない。

 ----解説ここまで---- */

ll N, D, K;
pair<int, int>q[10000];
pair<int, int>x[100];
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> D >> K;

    FOR(i, 0, D) {
        cin >> q[i].first >> q[i].second;
    }
    FOR(i, 0, K) {
        cin >> x[i].first >> x[i].second;
    }

    FOR(i, 0, K) {
        if (x[i].first < x[i].second) {
            int m1 = x[i].first, m2 = x[i].second;
            FOR(j, 0, D) {
                if (q[j].first <= m1&&m1 <= q[j].second) {
                    m1 = q[j].second;
                    if (m1 >= m2) {
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
        }
        else {
            int m1 = x[i].first, m2 = x[i].second;
            FOR(j, 0, D) {
                if (q[j].first <= m1 && m1 <= q[j].second) {
                    m1 = q[j].first;
                    if (m1 <= m2) {
                        cout << j + 1 << endl;
                        break;
                    }
                }
            }
        }
    }

    return 0;
}