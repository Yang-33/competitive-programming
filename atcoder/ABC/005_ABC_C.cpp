#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)

/* -----  2017/03/06  Problem: ABC005 C / Link: https://abc005.contest.atcoder.jp/tasks/abc005_3 ----- */
/* ------問題------

高橋君は、たこ焼きをどの順番で売るか悩んでいました。というのも、作り置きされたたこ焼きは美味しくないとわかっているので、高橋君はそのようなたこ焼きを売りたくないのですが、できたてばかり売ってしまうと売れるたこ焼きの数が減ってしまいます。
また、お客さんを待たせてばかりだと、次第にお客さんが離れてしまうだろうと高橋君は考えています。
そこで、彼は T 秒以内に作成されたたこ焼きを売り続けることで、お客さんを捌ききれるかどうかを調べることにしました。
たこ焼きは A1、A2、…、AN 秒後に焼きあがります。
お客さんは B1、B2、…、BM 秒後にやってきます。
1 人のお客さんに対して、たこ焼きを 1 つ売るとします。すべてのお客さんにたこ焼きを売れるならyes、売れないならnoを出力して下さい。

-----問題ここまで----- */
/* -----解説等-----

各たこ焼きについて焼きあがってからT秒以内に販売できるかを考える。
焼きあがっている　かつ　焼きあがってT秒以内に客が来ている　を、昇順に並んだデータから比較していけばよい。

 ----解説ここまで---- */

ll T, M, N;
int a[100];
int b[100];

ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> T >> N;
    FOR(i, 0, N)cin >> a[i];
    cin >> M;
    FOR(i, 0, M)cin >> b[i];

    if (N < M) {
        cout << "no" << endl;
        return 0;
    }

    int x = 0;
    bool flag = true;

    FOR(i, 0, M) {
        if (a[x]>b[i]) {
            flag = false;
            break;
        }
        x = lower_bound(a + x, a + N, b[i] - T) - a + 1;
        if (x > N) {
            flag = false;
            break;
        }
    }

    if (flag==false) {
        cout << "no" << endl;
        return 0;
    }

    cout << "yes" << endl;

    return 0;
}