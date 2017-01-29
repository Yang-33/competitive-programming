#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define debug(x) cout<<#x<<": "<<x<<endl
typedef long long ll;

/* 2017/01/29 ��� ----- ABC035 D /Link http://abc035.contest.atcoder.jp/tasks/abc035_d */
/* -----�����-----
���: �����N���Z�ލ��ɂ� N �ӏ��̒��ƒ����m���Ȃ�����ʍs�̓��� M �{����A���ꂼ��̒��ɂ� 1 ���� N �̔ԍ�������ӂ��Ă��܂��B
i �Ԗڂ̓��� ai �Ԃ̒����� bi �Ԃ̒��ֈړ����邱�Ƃ��\�ł���A�ړ��� ci ������������܂��B

�������� 0 �~�̍����N�� T ���Ԃ̃g���W���[�n���g�ɏo�����邱�Ƃɂ��܂����B�����N�͊J�n 0 ���̎��_�� 1 �Ԃ̒��ɂ��܂��B
�܂��A�J�n���� T ���̎��_�ɂ� 1 �Ԃ̒��ɂ��Ȃ��Ă͂Ȃ�܂���B
�����N�� i �Ԃ̒��� 1 ���ԑ؍݂���ƁA Ai �~�������N�̏������ɉ��Z����܂��B
T ���Ԃ̃g���W���[�n���g�ɂ���č����N�̏������͍ő傢����ɂȂ邩���߂Ă��������B


���_�؍݂œ����邨���ɂ��čl�����Ƃ��A�ǂ̒��_�ł����l��1���ł����𓾂邱�Ƃ��ł���B(����ōő�ƂȂ�)
����Ē��_1�ɖ߂�܂ł̎��Ԃ����������Ďc�������Ԃł��钸�_�ɑ؍݂������邱�Ƃ��l����B

�܂�1->K->1�ƂȂ�ŒZ�o�H���l���邪�A������𒼂ɋ��߂悤�Ƃ����MNlogM�ŊԂɍ���Ȃ��B
K->1�ɂ��āA����͗L���O���t�ł��邩��t�ӂ𐶐�����Έ������ŒZ�H��
1->K(�L�����O���t) + K->1(�L���t�ӃO���t)�ŋ��߂邱�Ƃ��ł���B
���Ȃ킿�_�C�N�X�g���@����s���΂悢�B
���̌�A���_1����ړ������钸�_�ő؍݂����Ƃ��ɂ����͂������ɓ���̂���S�T������΂悢�B

���C�u�������������Ǝv���ď������������B
c++�̕׋������ʂɑ���Ȃ��B

*/


/* �񒸓_�Ǘ� Dijkstra */
struct edge {
    int v; ll w;
    edge() {}
    edge(int v, ll w) : v(v), w(w) {};
};

/* �񒸓_�Ǘ� Dijkstra
edge G, ���_�� N, �n�_ s
return vector<ll> ���_�ɑ΂���s����̋���
�S���_�T���\ O(MlogN)?
�o�H�����@�\: ������
*/
vector<ll> Dijkstra(int n, vector<vector<edge> >& G, int s) {
    vector<ll> d(n, LLONG_MAX / 10); // ���_������
    d[s] = 0; // ���_s��0�ŏ�����
    priority_queue<pair<ll, int> > que; //�D��x�t��queue �~��(�����A���_)
    que.push(make_pair(0ll, s)); // push(����,���_)
    while (!que.empty()) {
        pair<ll,int> p = que.top(); que.pop(); //pair
        int u = p.second; //���_
        ll dist = -p.first; //���_u�܂ł̋���
        if (dist > d[u]) continue; //�œK�łȂ��Ȃ�΍l�����Ȃ�
        FOR(i, 0, G[u].size()) { //���_u�����i�{�̕ӂ�����
            int vv = G[u][i].v; // u->vv
            if (d[vv] > d[u] + G[u][i].w) { //�o�H�Z�k�\=>�X�V
                d[vv] = d[u] + G[u][i].w;
                que.push(make_pair(-d[vv], vv)); //push(-����,���_) //�����͂��̂܂܂ŗ���
            }
        }
    }
    return d;
}


#define MAX_N 100000
int N, M, T;
int a[MAX_N];
vector<vector<edge>>G(MAX_N);
vector<vector<edge>>rG(MAX_N);
ll ans = 0;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> N >> M >> T;
    FOR(i, 0, N) {
        cin >> a[i];
    }
    FOR(i, 0, M) {
        int s, t, c; cin >> s >> t >> c;
        s--; t--;
        G[s].push_back(edge(t, c));
        rG[t].push_back(edge(s, c));
    }

    vector<ll>d = Dijkstra(N, G, 0);
    vector<ll>rd = Dijkstra(N, rG, 0);

    FOR(i, 0, N) {
        ll tt = d[i] + rd[i];
        if (tt > T)continue;
        ans = max(ans, (T - tt)*a[i]);
    }

    cout << ans << endl;

    return 0;
}