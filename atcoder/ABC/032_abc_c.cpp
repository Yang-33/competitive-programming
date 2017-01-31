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

/* 2017/01/31 問題 ----- ABC032 C /Link http://abc032.contest.atcoder.jp/tasks/abc032_c */
/* -----解説等-----
問題: 長さ N の非負整数列 S=s1,s2,…,sN と整数 K があります。
あなたの仕事は、以下の条件を満たす S の 連続する 部分列のうち、最も長いものの長さを求めることです。
部分列の長さは 1 以上の列でないといけません。

その部分列に含まれる全ての要素の値の積は、K 以下である。
もし条件を満たす部分列が一つも存在しないときは、0 を出力してください。


しゃくとり法。伸ばして縮めればよい。
幅0の区間で条件を満たさないときは両方のインデックスを進めてしまえばよい。
バグらずにできたのは大きい。
対数をとれば和の問題に帰着できるらしい。まだ必要を感じないけどかっこいい。誤差が出そう。

*/

ll N, K;
ll s[100000];
int ans;
int l = 0, r = 0;
ll rec = 1;
bool flag = false;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> K;
    FOR(i, 0, N) {
        cin >> s[i];
        if (s[i] == 0)flag = true;
    }

    if (flag) {
        cout << N << endl;
        return 0;
    }

    while (r < N) {
        while (r < N&&rec*s[r] <= K) {
            rec *= s[r];
            r++;
        }
        ans = max(ans, r-l);
        if (l != r) {
            rec /= s[l];
            l++;
        }
        else {
            l++; r++;
        }
    }

    cout << ans << endl;

    return 0;
}