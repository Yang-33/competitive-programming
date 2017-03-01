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

/* -----  2017/03/01  Problem: ABC015 C / Link: http://abc015.contest.atcoder.jp/tasks/abc015_3 ----- */
/* ------問題------

高橋くんは上司からあるアンケートアプリにバグがあるかどうか調べて欲しいと頼まれました。
このアプリは、ユーザに選択肢が K 個ある質問を N 回答えさせることにより、ユーザの性格を判定します。 
質問や選択肢はユーザの回答によって変わらず一定であり、ユーザは全ての質問にちょうど 1 つの選択肢を選ぶことで、結果を閲覧できます。
全ての選択肢はある整数値を持ちます。このアプリは、ユーザによって選ばれた、全ての回答がそれぞれ保持する整数値の排他的論理和（XOR）を使って結果を算出します。
計算の最後でこの値が 0 になってしまうと、結果が表示されずバグが発生してしまいます。
あなたには全ての選択肢が持つ整数値が与えられるので、高橋くんの代わりに、ユーザの選択によってはバグが発生する可能性があるかどうかを判定してください。

-----問題ここまで----- */
/* -----解説等-----

0^x=xであることからdfsをして間に合う。
bool dfsのほうがきれい感がある。

 ----解説ここまで---- */

ll N, K;
int t[10][10];
ll ans = 0LL;

void dfs(int i, int x) {
    if (i == N) {
        if (x == 0) {
            cout << "Found" << endl;
            exit(0);
        }
        return;
    }
    FOR(j, 0, K) {
        dfs(i + 1, x ^ (t[i][j]));
    }

}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> K;
    
    FOR(i, 0, N)FOR(j, 0, K)cin >> t[i][j];
    
    dfs(0, 0);
    
    cout << "Nothing" << endl;

    return 0;
}