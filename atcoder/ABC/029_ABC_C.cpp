#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<map>
#include<list>
#include<stack>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define FORR(i,s,e) for(ll (i)=(s);(i)>(e);(i)--)
#define MOD 1000000007
#define debug(x) cout<<#x<<": "<<x<<endl
const int INF = 1e9;
typedef long long ll;
int dx[8] = { 1,1,1,0,0,-1,-1,-1 };
int dy[8] = { 1,0,-1,1,-1,1,0,-1 };

/* -----  2017/02/21  Problem: ABC029 C / Link: http://abc029.contest.atcoder.jp/tasks/abc029_c ----- */
/* ------問題------
あなたはスーパーハッカーです。高橋君を攻撃対象に定めたあなたは、
高橋君のパソコンのパスワードに関して次の事実を突き止めました。

長さは N 文字である。
a, b, c 以外の文字は含まれない。
高橋君のパソコンのパスワードの候補として考えられる文字列をすべて列挙してしまいましょう。
   ------    ------*/
/* -----解説等-----

総当たりをdfsで生成する。
実装が少し面倒になるけど3bitでもできそう。

 -----ここまで----- */

ll N;

ll ans = 0LL;

void brute(int n, string s) {
    if (n == 0) {
        cout << s << endl;
        return ;
    }

    brute(n - 1, s + 'a');
    brute(n - 1, s + 'b');
    brute(n - 1, s + 'c');


}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    brute(N,"");

    return 0;
}