#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2010/00/00 問題 -----  Name/Link ----- */
/* -----解説等-----
問題: コインの組み合わせ II
N 枚のコインがあります。それぞれのコインの値段はai 円です。
E 君は, ちょうどK 個のコインを得たいと思っていて,
値段の合計はL 円以上 R 円以下にしたいと思っています。
このようなコインの選び方は何通りあるでしょうか?
ただし, それぞれのコインは区別するものとします。

半分全列挙を用いるが、値の部分では解事態に範囲を持たせるようにすることは容易である。
一方でコインの枚数をＮ枚以下のうちのＫ枚を使うようにしなければならず、
part_n1 + part_n2 = K をみたすようなものを捜索していけばよい。

前半部分では使用個数ごとにコインの価値を記録し、昇順にソートする。
後半部分では K - part_n2 をキーとして L 円以上 R 円以下となるように値を求めればよい。

*/
#define MAX_N 40
ll N, K, L, R;
ll a[MAX_N];
vector<ll> rec[MAX_N / 2 + 1];
ll ans = 0;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);


    cin >> N >> K >> L >> R;
    FOR(i, 0, N) {
        cin >> a[i];
    }

    int n1 = N / 2;
    FOR(i, 0, (1 << n1)) {
        int cnt1 = 0;
        ll s = 0;
        FOR(j, 0, n1) {
            if ((i >> j) & 1) {
                cnt1++;
                s += a[j];
            }
        }
        rec[cnt1].push_back(s);
    }

    FOR(i, 0, n1) {
        sort(rec[i].begin(), rec[i].end());
    }

    int n2 = N - n1;
    FOR(i, 0, (1 << n2)) {
        int cnt2 = 0;
        ll s = 0;
        FOR(j, 0, n2) {
            if ((i >> j) & 1) {
                cnt2++;
                s += a[n1 + j];
            }
        }

        //n1+cnt2=Kでありたい、加えて添え字は０以上でありたい
        if ((!(K - cnt2 >= 0)) || n1 + cnt2 < K)continue;
        // R-s円より大きい位置がでるので-1
        int UP = upper_bound(rec[K - cnt2].begin(), rec[K - cnt2].end(), R - s) - begin(rec[K - cnt2]) - 1;
        int LW = lower_bound(rec[K - cnt2].begin(), rec[K - cnt2].end(), L - s) - begin(rec[K - cnt2]);
    
        if (UP - LW < 0)continue;
        ans += UP - LW + 1;
    
    }

    cout << ans << endl;

    return 0;
}
