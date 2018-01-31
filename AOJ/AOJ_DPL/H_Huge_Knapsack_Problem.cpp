#include<iostream>
#include<algorithm>
#include<vector>
#include<climits> //INT_MIN/MAX
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;
ll N, W;

/* 2017/01/10 ��� -----  Name AOJ_DPL_1_H /Link http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=DPL_1_H */
/* -----�����-----
���: ����i�b�v�U�b�N���
���l�� vi �d���� wi �ł���悤�� N �̕i���ƁA�e�ʂ� W �̃i�b�v�U�b�N������܂��B���̏����𖞂����悤�ɁA�i����I��Ńi�b�v�U�b�N�ɓ���܂��F
�I�񂾕i���̉��l�̍��v���ł��邾����������B
�I�񂾕i���̏d���̑��a�� W �𒴂��Ȃ��B
���l�̍��v�̍ő�l�����߂Ă��������B
1 ? N ? 40
1 ? v_i ? 10^15
1 ? w_i ? 10^15
1 ? W ? 10^15
�������|�I�ɑ����̂�nW�ł͓���s�\
N���������̂Ŕ����S�񋓂̍l������p���Čv�Z�ʂ𗎂Ƃ��Ă������Ƃ�O���ɒu���B
2^n �� 2^40 �ʂ�(Over)�ł��������̂� ���X 2^20��10^6 �ƂȂ���
�O�������̑S�񋓂ł�(�d���A���l)�Ń\�[�g���A�㔼�����ł͏d���� W-(���������d��)��0
�̂Ƃ��Ɍ��艿�l�̍ő�l���X�V���悤�Ƃ���΂悢
���̍ۂ� W-(���������d��)�̒l�ɍł��߂���������d�������Ȃ�����𖞂������ł̍ő�̉��l��
�\�[�g�ς݂ł��� ps ����񕪒T���ŋ��߂�΂悢�B
*/


#define MAX_N 40
#define INF (LLONG_MAX/10)
ll v[MAX_N], w[MAX_N]; /* ���l�Əd�� */

pair<ll, ll>ps[1 << (MAX_N / 2)];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    /* in */
    cin >> N >> W;
    FOR(i, 0, N) {
        cin >> v[i] >> w[i];
    }

    /* solve */
    ll fn = N / 2; /* first half N */

    for (ll i = 0; i < (1 << fn); i++) {
        ll sw1 = 0, sv1 = 0; /* part source w and source v */
        FOR(j, 0, fn) {
            if ((i >> j) & 1) {
                sw1 += w[j];
                sv1 += v[j];
            }
        }
        ps[i] = make_pair(sw1, sv1);
    }

    // Optimisation
    sort(ps, ps + (1 << fn));
    ll m = 1; /* new ps point => m */
    for (ll i = 0; i < (1 << fn); i++) {
        if (ps[m - 1].second < ps[i].second) {
            ps[m++] = ps[i];
        }
    }

    ll ans = 0;
    ll sn = N - fn; /*second half N */
    FOR(i, 0, (1 << sn)) {
        ll sw2 = 0, sv2 = 0;
        FOR(j, 0, sn) {
            if ((i >> j) & 1) {
                sw2 += w[fn + j];
                sv2 += v[fn + j];
            }
        }

        if (sw2 <= W) {
            ll tv; /* part target v */
            tv = (lower_bound(ps, ps + m, make_pair(W - sw2, INF)) - 1)->second;
            ans = max(ans, sv2 + tv);
        }
    }

    /* out */
    cout << ans << endl;

    return 0;
}
