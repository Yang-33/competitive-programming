#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/02/20  Problem: ABC030 D / Link: http://abc030.contest.atcoder.jp/tasks/abc030_d ----- */
/* ------問題------
ミカミくんは怪しい英単語帳を使っています。その単語帳には N 個の単語の意味が載っており、単語 i の説明には「単語 bi と同じ意味である」とだけ書いてあります。
ここで、i 番目の単語を単語 i と呼ぶことにします。 ミカミくんはまだ一つの英単語も知らないので、
単語 i の意味を調べようとしたとき、単語 bi の意味を調べようとします。ミカミくんは真面目なので、
今までにすでに調べようとしたことのある単語でも同じように単語帳をひき続けます。 
しかし、残念ながらこの単語帳では英単語の意味自体はどこにも書いていないため、意味を知ることはできません。 
ある単語 i を調べようとして、単語帳を参照し、単語 bi を調べようとするまでを1ステップとします。

ミカミくんが単語 i を調べようとして、k ステップ経ったとき、ミカミくんはどの単語を調べようとしているでしょうか？
*/
/* -----解説等-----

単語の検索に時間がかかる場合、≧10^9
閉路が存在し、またこれは余分な枝分かれのない閉路であるからそのサイズがわかれば
 閉路の大きさを mod としてk を計算可能な回数まで削減することができる。
 （本来の到達点に行く前の状態まで削減してしまわないように注意　ここで 1WA）
サイズが小さいときや k が小さいときの分岐はめんどくさいのでそのまま実行してしまった方が楽。
閉路長を出すのに苦戦してしまったが番兵を置くなり印をはっきりさせるといいという経験をした。

多長倍整数にも昇順または降順でmodをとることができる。
具体的には26桁のabcdef...xyzという数が存在するときにa*10^25+b*10^24+c*10^23+...+x*10^2+y*10^1+zと現わすことができるので
桁を上げていく段階でmodをとればよい。（加法）
thanks to quora.

*/

ll N, a;
string k;
ll b[100001];
ll id[100001];
ll ans = 0LL;

ll digitsmod(string s, ll mod) {
    ll reminder = 0;
    FOR(i, 0, s.size()) {
        reminder = (reminder * 10 + (s[i] - '0')) % mod;
    }
    return reminder;
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> a >> k;
    FOR(i, 1, N + 1) {
        cin >> b[i];
    }

    if (k.size() < 6) {
        int kk = stoi(k);
        FOR(i, 0, kk) {
            a = b[a];
        }
        cout << a << endl;
        return 0;
    }


    /* dig */
    FOR(i, 1, N + 1) {
        id[i] = -1;
    }
    
    ll pos = a;
    ll cnt = 1;

    while (id[pos] == -1) {
        id[pos] = cnt++;
        pos = b[pos];
    }

    /*for (; id[cnt] < 0; cnt++) {
        id[pos] = cnt;
        pos = b[pos];
    }*/

    ll loop = cnt - id[pos];
    ll knum = digitsmod(k, loop);
    knum += loop * 20;

    FOR(i, 0, knum) {
        a = b[a];
    }

    cout << a << endl;

    return 0;
}