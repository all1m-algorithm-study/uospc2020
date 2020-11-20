#include <iostream>
#include <string>

using namespace std;

int main() {
    int n;
    string a;
    cin >> n;
    cin >> a;

    int cnt = 0;
    for (int i = 0; i < n - 1; i++)
        if (a[i] == '0') {
            cnt++;
            a[i] = '1';
            a[i + 1] = a[i + 1] == '0' ? '1' : '0';
        }

    cout << cnt;
}