#include<iostream>
#include<queue>
#include<functional>
#define FOR(i,s,t) for(int (i)=(s);(i)<(t);i++)
typedef long long ll;
using namespace std;

const ll INF = 1e17;

int n, m, v0, a, b, c;
typedef pair<ll, ll> pll;
typedef pair<ll, pll> plll;

vector<pair<int, int>>G[505];
ll d[50][505], cp[50][505];

/* -----  2017/03/25  Problem: RUPC2017 day3 D / Link: http://judge.u-aizu.ac.jp/onlinejudge/cdescription.jsp?cid=RitsCamp17Day3&pid=D ----- */
/* ------���------

�����N�Q��

-----��肱���܂�----- */
/* -----�����-----

�g���_�C�N�X�g��
�ړ���̑��x��%c�ŕ\�����̂Ŋe���_�ւ̍ŒZ������c��ޑ��݂��邱�ƂɂȂ�B
���̂��߂��̃O���t�����݂��Ă���Ƃ݂āA�܂�Ԃ��n�_�ł̍ŏ����������A�_�C�N�X�g���@�ŋ��߁A
���̂悤�Ȓ��_���n�_�Ƃ��Ē��_�O�܂ł̍ŏ��l�����߂�΂悢�B
d[���̒��_�ɓ��������ۂ̑̊��ړ����x][���_] := �ŒZ�̊��ړ������@�Ƃ��ċ��߂�B
c^2*n*log m �ŊԂɍ����H

----��������܂�---- */

ll dijkstra(int s, int t, int vv) {
    FOR(i, 0, c)FOR(j, 0, n) {
        d[i][j] = INF;
    }
    priority_queue<plll, vector<plll>, greater<plll>>q;
    q.push(plll(0, pll(vv, s)));
    d[vv][s] = 0;
    while (!q.empty()) {
        plll tmp = q.top(); q.pop();
        ll cost = tmp.first;
        ll v = tmp.second.first;
        ll node = tmp.second.second;
        if (d[v][node] < cost)continue;
        FOR(i, 0, G[node].size()) {
            ll ncost = cost + G[node][i].second*v;
            ll nnode = G[node][i].first;
            ll nv = (a*v + b) % c;
            if (d[nv][nnode] > ncost) {
                d[nv][nnode] = ncost;
                q.push(plll(ncost, pll(nv, nnode)));
            }
        }
    }
    ll res = INF;
    FOR(i, 0, c) {
        res = min(res, d[i][t]);
    }
    return res;

}

int main() {

    cin >> n >> m;
    FOR(i, 0, m) {
        int x, y, z;
        cin >> x >> y >> z;
        G[x - 1].push_back(make_pair(y - 1, z));
        G[y - 1].push_back(make_pair(x - 1, z));
    }
    cin >> v0 >> a >> b >> c;

    dijkstra(0, n - 1, v0);

    FOR(i, 0, c) {
       // cout << d[i][n - 1] << endl;
        cp[i][n - 1] = d[i][n - 1];
    }
    ll ans = INF;
    FOR(i, 0, c) {
        if (cp[i][n - 1] == INF)continue;
        ans = min(ans, cp[i][n - 1] + dijkstra(n - 1, 0, i));
    }

    cout << ans << endl;

    return 0;
}
