#include<iostream>
#include<string>
//#include<bitset>
using namespace std;

#define FOR(i,s,e) for(ll (i)=(s);(i)<(e);(i)++)
typedef long long ll;

/* 2017/01/21 ��� ----- ABC045 C /Link http://abc045.contest.atcoder.jp/tasks/arc061_a  */
/* -----�����-----
���: 1 �ȏ� 9 �ȉ��̐����݂̂���Ȃ镶���� S ���^�����܂��B
���̕�����̒��ŁA���Ȃ��͂���當���ƕ����̊Ԃ̂����A�������̏ꏊ�� + �����邱�Ƃ��ł��܂��B
�������Ȃ��Ă����܂��܂���B �������A+ ���A�����Ă͂����܂���B

���̂悤�ɂ��ďo����S�Ă̕�����𐔎��Ƃ݂Ȃ��A�a���v�Z���邱�Ƃ��ł��܂��B

���肤��S�Ă̐����̒l���v�Z���A���̍��v���o�͂��Ă��������B

����
1?|S|?10
S �Ɋ܂܂�镶���͑S�� 1 ? 9 �̐���


S���������B
�S�񋓂�����B=> 2^10��10^3
now = now*10 + s[i] �Ƃ��ē��̐����瑫������ł����A
�u+�v������ꏊ�Ɋւ��đ����������Z�b�g���đ������ނ��Ƃ��J��Ԃ��B

(1<<(-1))�̓R�[�i�[���Ȃ��Ǝv�������Ǘ����Ȃ������B
�m�F������ 1<<-1�͖���`�łO
j=0 �� 1<<(j-1)�� INT_MIN �ł����� => -2,147,483,648
���A��i���\���͂O�ł����� => 0
���������񕉐����ŃV�t�g����̂�����@��O�▢��`�ɂ��@1<<n (n={x|x��0}) �� �O �Ƃ��č��͂Ƃ肠�����悢���낤�B

*/

string S;
ll ans = 0;
int n;

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(false);

    cin >> S;
    n = S.size();
    
    /*int j = 0;
    cout << "1<<(-1) : " << (1 <<( j-1)) << endl;
    cout << static_cast<bitset<8> >(1<<(j-1)) << endl;
�@�@*/

    for (int i = 0; i < (1 << (n - 1)); i++) {
        ll sum = 0; ll cur = 0;

        FOR(j, 0, n) {
            if (j == 0) {
                cur = S[j] - '0';
                continue;
            }
            if (i & (1 << (j - 1))) {
                sum += cur;
                cur = 0;
            }
            cur = cur * 10 + (S[j] - '0');
        }
        sum += cur;
        ans += sum;
    }

    cout << ans << endl;

    return 0;
}