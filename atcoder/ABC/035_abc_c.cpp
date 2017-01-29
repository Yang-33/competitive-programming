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
typedef long long ll;

/* 2017/01/29 問題 ----- ABC035 C /Link http://abc035.contest.atcoder.jp/tasks/abc035_c */
/* -----解説等-----
問題: 黒の面に0、白の面に1が書かれた N 個のオセロの駒が、どの駒も黒の面が上を向くように一列に並べられています。
その後、ある区間にある駒を全て裏返すという操作が Q 回だけ行なわれました。
具体的には i 回目の操作においては、左から li 番目の駒から ri 番目の駒までの駒全てが裏返されました。
最終的な盤面を求めてください。

ON/OFFのような操作ではいもす法で区間を管理し、結局何回ひっくり返ったかを最後に区間和として表現しなおせばよい。



*/

int N, Q;
int x[200001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> Q;
    FOR(i, 0, Q) {
        int a, b; cin >> a >> b;
        x[--a]--; x[b]++;
    }
    
    int ans = 0;
    FOR(i, 0, N) {
        ans += x[i];
        cout << (abs(ans)) % 2;
    }
    cout << endl;
    return 0;
}