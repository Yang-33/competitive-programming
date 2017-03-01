#include<iostream>
#include<vector>
#include<set>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* -----  2017/03/01  Problem: ABC016 C / Link: https://abc016.contest.atcoder.jp/tasks/abc016_3 ----- */
/* ------問題------

高橋くんはSNSの管理者をしています。このSNSではユーザ同士が友達という関係で繋がることができます。
高橋くんはそれぞれのユーザの「友達の友達」が何人いるかを調べることにしました。
友達関係が与えられるので、各ユーザの「友達の友達」の人数を求めてください。
ただし、自分自身や友達は、「友達の友達」に含みません。

-----問題ここまで----- */
/* -----解説等-----

友達の友達が自分の友達である可能性を排除すればよい。

 ----解説ここまで---- */

ll N, M;
vector<int>G[10];

ll ans = 0LL;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M;
    FOR(i, 0, M) {
        int a, b; cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }

    FOR(i, 0, N) {
        set<int>s1;
        s1.insert(i);
        set<int>s2;
        FOR(j, 0, G[i].size()) {
            s1.insert(G[i][j]);
            FOR(k, 0, G[G[i][j]].size()) {
                s2.insert(G[G[i][j]][k]);
            }
        }
        auto it = s1.begin();
        while (it != s1.end()) {
            s2.erase(*it);
            it++;
        }

            cout << s2.size() << endl;
    }

    return 0;
}