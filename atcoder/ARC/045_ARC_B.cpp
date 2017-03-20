#include <algorithm>
#include <climits> //INT_MIN/MAX
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define FOR(i, s, e) for (ll(i) = (s); (i) < (e); (i)++)
#define FORR(i, s, e) for (ll(i) = (s); (i) > (e); (i)--)
#define debug(x) cout << #x << ": " << x << endl
#define mp make_pair
#define pb push_back
const ll MOD = 1000000007;
const int INF = 1e9;
const ll LINF = 1e16;
const double PI = acos(-1.0);
int dx[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dy[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

/* -----  2017/03/20  Problem:  / Link:
 * http://arc045.contest.atcoder.jp/tasks/arc045_b ----- */
/* ------問題------

高橋君の通っている学校で大掃除が行われることになりました．学校には N 個の教室があり，各教室は 1 から N まで順番に番号付けられており，左から右に並んでいます．
高橋君の学校には高橋君を含め M 人の生徒がおり，掃除すべき連続した教室の区間(掃除区間と呼ぶ)は M 個既に決まっています．
しかし，それらの掃除区間を誰が担当するかは決まっていません． 
異なる生徒には異なる掃除区間が割り当てられ，割り当てられた生徒はそれに含まれる全ての教室を掃除しなければなりません．
1 つの教室が複数の掃除区間に含まれることがあります．
高橋君は大掃除の日に女の子とのデートの約束をしていることに気づきました．
デートをサボってしまうと何が起こるか分からないので大掃除をサボることに決めました． 
前述の通りいくつかの教室については複数の掃除区間に含まれていることがあるので，高橋君の担当分をサボっても全ての教室を誰かが掃除してくれさえすれば，
サボったことがバレないことに気づきました． 掃除されていない教室があった場合には，サボったことがバレます．
あなたの仕事は高橋君のために，サボってもバレない掃除区間を全て教えてあげることです．
なお，この学校の生徒は高橋君を除きみんな真面目なので，高橋君以外がサボることは無いと仮定してください．

-----問題ここまで----- */
/* -----解説等-----

一人の担当しているお掃除区間に１を足しこみ、それを全員分で作り終えたら、
完成したテーブルに対して一人のお掃除区間内に１が含まれていたらその区間は必ずその人が掃除しなければいけないことになる。
以上のことからこれを確認する方法で実装をすればよい。
最初は遅延segtreeかimosで１をたしこんで区間最小値が１かを確認しようと思ったが、2以上の値か1のみにしか値として意味を持たない
ということに気が付いたので生成された区間テーブルを変換してから累積和をとり区間幅になるかそれ未満かをチェックすることに落とし込むことができた。
segtreeでもやります。

----解説ここまで---- */

ll N, M;
int s[100010],t[100010];
int m[300010],a[300010];
int sum[300010];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    FOR(i, 0, M)
    {
        cin >> s[i] >> t[i];
        m[s[i]]++; m[t[i]+1]--;
    }
    a[0]=0;
    FOR(i, 0, N + 3){
        a[i+1] = a[i] + m[i+1];
    }
    FOR(i,0,N+3){
        if(a[i]>=2)a[i]=1;
        else a[i]=0;
    }
    FOR(i,0,N+3){
        sum[i+1]=sum[i]+a[i+1];
    }

    vector<int>ans;
    FOR(i,0,M){
        if(sum[t[i]]-sum[s[i]-1]==t[i]-s[i]+1)
        ans.push_back(i+1);
    }

    cout << ans.size() << endl;

    FOR(i,0,ans.size()){
        cout << ans[i] << endl;
    }


    return 0;
}