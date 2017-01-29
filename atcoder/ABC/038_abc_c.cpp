#include<iostream>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/28 問題 ----- ABC038 C Link http://abc038.contest.atcoder.jp/tasks/abc038_c */
/* -----解説等-----
問題: N個の数からなる数列が与えられます。i番目の数をaiと呼びましょう。
al,al+1,…,ar が単調増加、すなわち l≦r であって ai<ai+1 がl≦i<r を満たす全てのiに対して成り立つような(l,r)の数を求めてください。

単調増加区間を保持し、そうでなければ区間に対する組を数える。1+2+3+4+...+k=k*(k+1)/2
ansをint型にしていたら墜ちた。競プロにおけるllは最強！

*/

#define MAX_N 100000
int N;
int a[MAX_N + 1];
ll cnt = 0, ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    a[N] = -1;

    FOR(i, 0, N) {
        cnt++;
        if (a[i] >= a[i + 1]) {
            ans += (cnt*(cnt + 1) / 2);
            cnt = 0;        
        }
    }

    cout << ans << endl;

    return 0;
}