#include<algorithm>
#include<iostream>
using namespace std;
int n, m, ans;
const int maxn = 100000 + 5;
int a[maxn];
int main() {
    int T;cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 0;i < n;i++)
            scanf_s("%d", &a[i]);
        sort(a, a + n);
        int  i;
        ans = 0;
        for (i = n - 1;i >= 0;i--) {
            bool ok = false;//����û��ƥ�������
            if (a[i] == -1) { ok = true;continue; }//���ǰ���Ѿ�ƥ����ˣ�û��Ҫ������
            for (int j = i - 1;j >= 0;j--) {
                if (a[j] != -1 && a[i] + a[j] <= m) {
                    a[j] = -1;
                    ok = true;
                    ans++;break;
                }
            }
            if (!ok) ans++;//�������̫��ֻ������һ����
        }
        printf("%d\n", ans);
    }
}

