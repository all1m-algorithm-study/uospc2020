#include <iostream>
#define MOD 1000000007

typedef long long Long;
Long a[100000], b[100000];
int aPos = -1, bPos = -1;
int n, m, p;

Long getA(int index)
{
    return n <= index ? 0 : a[index];
}

Long getB(int index)
{
    return m <= index ? 0 : b[index];
}

int main()
{
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < n; ++i)
        scanf("%lld", a+i);

    for (int i = 0; i < m; ++i)
        scanf("%lld", b+i);

    for (int i = 0; i < n && aPos == -1; ++i)
        if (a[i] % p != 0)
            aPos = i;

    for (int i = 0; i < m && bPos == -1; ++i)
        if (b[i] % p != 0)
            bPos = i;

    if (aPos == -1 || bPos == -1)
        printf("-1");
    else
    {
        int indexOfC = aPos + bPos;
        Long result = 0;
        for (int i = 0; i <= indexOfC; ++i)
        {
            result += getA(i)*getB(indexOfC-i);
            result %= MOD;
        }

        printf("%lld", result);
    }

    return 0;
}