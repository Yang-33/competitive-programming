#include<iostream>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define MOD 1000000007
typedef long long ll;

/* 2017/01/18 問題 -----  abc052 c /Link http://abc052.contest.atcoder.jp/tasks/arc067_a  */
/* -----解説等-----
問題:

1000!がでかすぎる。
約数の数は(素因数+1)の積。
N!に対して1*2*3*...*N-1*Nを順に素数で試し割していけばよい。

*/
 
ll N;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;

    //prime
    vector<int>primes;
    primes.push_back(2);
    for (int i = 3; i < 1001; i += 2) {
        int flag = 0;
        FOR(j, 2, i) {
            if (i%j==0) {
                flag = 1;
                break;
            }
        }
        if (flag == 0) {
            primes.push_back(i);
        }
    }

    ll ans = 1;

    FOR(i, 0, primes.size()) {
        int p = primes[i];
        int cnt = 0;
        while (p <= N) {
            cnt += N / p; //2,4,8,16,...
            p = p*primes[i];
        }
        ans = (ans*(cnt + 1)) % MOD;
    }

    cout << ans << endl;

    return 0;
}