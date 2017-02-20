#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
const int INF = 1e9;
typedef long long ll;


/* -----  2017/02/20  Problem: ABC031 C / Link: http://abc031.contest.atcoder.jp/tasks/abc031_c ----- */
/* ------問題------
高橋君と青木君は長さ N の数列 S を用いたゲームを行う。
ゲームは高橋君の手番と青木君の手番 1 回ずつからなる。
ゲームは以下の要領で行われる。

最初に高橋君が数列の要素のうち 1 つに丸をつける。
次に青木君が数列の要素で高橋君が丸を付けなかったもののうち 1 つに丸をつける。
高橋君と青木君が丸を付けた 2 つの要素に対して、その 2 つの要素およびそれらの間にあるすべての要素を残して、それ以外の要素をすべて削除する。残った数列を T と置く。
数列 T のうち、数列 T 内で左から奇数番目の要素の合計が高橋君の得点、偶数番目の要素の合計が青木君の得点となる。
青木君は、丸を付けられる要素の中で、青木君が得点を最も多く得られる要素に丸を付ける。そのような要素が複数あるならばそれらのうち最も左側にある要素に丸を付ける。

高橋君は青木君の丸の付け方を知っている。高橋君が得られる得点として考えられる得点の最大値を求めよ。
*/
/* -----解説等-----

区間の両端に対して問題となっている動作を行う。
Nが小さいのでN^3の全探索でまにあう。
尺取り法だとN^3?ではなくN^2で解ける気もする。

*/

ll N;
int a[50];
ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    ans = -INF;
    FOR(i, 0, N) {
        int _p2 = -INF; ll tmp;
        FOR(j, 0, N) {
            
            int l = min(i, j);
            int r = max(i, j);
            if (l == r)continue;
            
            int p1 = 0, p2 = 0;
            int prm = 1;
            
            FOR(k, l, r + 1) {
                if (prm % 2 == 1) p1 += a[k];
                else p2 += a[k];
                prm++;
            }
            
            if (p2 > _p2) {
                _p2 = p2;
                tmp = p1;
            }
        }
        ans = max(ans, tmp);
    }

    cout << ans << endl;

    return 0;
}