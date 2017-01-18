#include<iostream>
#include<algorithm>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
#define llong long long
typedef long long ll;
ll N;
/* 2017/01/18 ��� -----  abc052 d Link http://abc052.contest.atcoder.jp/tasks/arc067_b */
/* -----�����-----
���:
�N���X�J��?�Ǝv�������Ԃɍ���Ȃ��B
���_�ړ��̏����ɂ��Ȃ�
ex:1=>2===>3
�e���|1->2+����2->3

ex:1=>3===>2
�e���|1->3+����3->2

�e���|�̃R�X�g���������߁A
�ȏ�̃R�X�g�͓����B
����ċA�[�I�ɏ����Ɉˑ����Ȃ�(��)
���Ȃ킿�ׂ荇�����_�̍ŏ��̔�J���Ƃ��Ă����΂悢�B

*/

ll ans = 0;
ll x[100001];

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    ll A, B;
    cin >> N >> A >> B;
    FOR(i, 1, N + 1)
        cin >> x[i];
    FOR(i, 1, N ) {
        ans += min(A*(x[i + 1] - x[i]), B);
    }
    cout << ans << endl;

    return 0;
}