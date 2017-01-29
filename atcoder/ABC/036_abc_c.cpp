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

/* 2017/01/29 問題 ----- ABC036 C /Link http://abc036.contest.atcoder.jp/tasks/abc036_c */
/* -----解説等-----
問題: N 人の人が座っています。 i 番目の人の座圧は ai です。 すぬけ君は、大小関係を保存したまま座圧のデータを圧縮して保存することにしました。 以下の条件を満たす数列 b1,…,bN を求めてください。
bi はすべて非負整数である。
ai<aj ならば bi<bj である。
ai=aj ならば bi=bj である。
上の条件を満たす配列のうち、bi の最大値が最小となる。
このような条件をみたす b は一意に定まることが知られています。

制約
1?N?10^5
0?ai?10^9
ai は整数である。

座標圧縮だ！おわり！
別配列にその圧縮座標を書き込むが今回はそれを出力してしまえばよい。

*/

int N;
int a[100000];
vector<int>x;


int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N;
    FOR(i, 0, N) {
        cin >> a[i];
        x.push_back(a[i]);
    }

    sort(x.begin(), x.end());
    x.erase(unique(x.begin(), x.end()), x.end());

    int p;
    FOR(i, 0, N) {
        p = lower_bound(x.begin(), x.end(), a[i]) - x.begin();
        cout << p << endl;
    }

    return 0;
}