#include<iostream>
#include<string>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/27 ��� ----- ABC039 C /Link http://abc039.contest.atcoder.jp/tasks/abc039_c */
/* -----�����-----
���:�@�����N�͐،N�ɓˑR���@�ŏ���������A�s�A�m�̏�ɏ悹���Ă��܂��܂����B
�����N�́A���s�A�m�̂��錮�Ղ̏�ɗ����Ă��܂����A�ǂ̌��Ղ̏�ɂ���̂���m�肽���ł��B
�����N�́A�����̍����錮�Ղ���E 20 �̌��Ղ̐F�𒲂ׂ܂����B�����N�̂��錮�Ղ̉��K�𒲂ׂĂ��������B
���ׂ����Ղ̐F�́AW�AB ����Ȃ镶���� S �Ƃ��ė^�����AW �͔��F�AB �͍��F��\���܂��B
�����āA��������̂��錮�Ղ̐F�͕�����̐擪�ɑΉ����܂��B
�Ȃ��A�s�A�m�̌��Ղ͉��}�̂悤�ɁA�F��"������������������������"�A
���K�� "�h �h# �� ��# �~ �t�@ �t�@# �\ �\# �� ��# �V" ���J��Ԃ��Ă��܂��B

WBWBWWBWBWBWWBWBWWBW do
WWBWBWWBWBWBWWBWBWWB si
WBWWBWBWWBWBWBWWBWBW ra
WBWBWWBWBWWBWBWBWWBW so
WBWBWBWWBWBWWBWBWBWW fa
WWBWBWBWWBWBWWBWBWBW mi
WBWWBWBWBWWBWBWWBWBW re

�炵���BWBWBWWBWBWBW��1�Z�b�g�ł��邩�炱��𔭌����悤�Ǝv���������ꂪ�܂܂�Ȃ��Ƃ��������̂�
�����ɑ��WBWBWBW�ɒ��ڂ���B����𔭌����擪�t�߂̗v�f�܂�W�𐔂��グ�A�K�؂Ȉʒu��Ԃ��΂悢�B

*/

string S;
string ans[7] = { "Do","Re","Mi","Fa","So","La","Si" };
int X = 0, cnt = 3;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    X = S.find("WBWBWBW");
    FOR(i, 0, X) {
        if (S[i] == 'W')cnt--;
    }

    cout << ans[(7+cnt)%7] << endl;

    return 0;
}