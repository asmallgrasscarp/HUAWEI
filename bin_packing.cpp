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
            bool ok = false;//看有没有匹配的重量
            if (a[i] == -1) { ok = true;continue; }//如果前面已经匹配过了，没必要在算了
            for (int j = i - 1;j >= 0;j--) {
                if (a[j] != -1 && a[i] + a[j] <= m) {
                    a[j] = -1;
                    ok = true;
                    ans++;break;
                }
            }
            if (!ok) ans++;//如果重量太大，只单独能一个包
        }
        printf("%d\n", ans);
    }
}

