#include <iostream>
#define MOD 1000000007

typedef long long Long;
Long a[100000], b[100000];
int n, m, p;

Long getA(int index)
{
    return n <= index ? 0 : a[index];
}

Long getB(int index)
{
    return m <= index ? 0 : b[index];
}

Long calcElement(int index)
{
    Long sum = 0;
    for (int i = 0; i <= index; ++i)
        sum += getA(i)*getB(index-i);
    return sum;
}

int main()
{
    scanf("%d %d %d", &n, &m, &p);

    for (int i = 0; i < n; ++i)
        scanf("%lld", a+i);

    for (int i = 0; i < m; ++i)
        scanf("%lld", b+i);

    Long result = -1;
    for (int i = 0; i < n+m-1 && result == -1; ++i)
    {
        Long element = calcElement(i);
        if (element % p != 0)
            result = element % MOD;
    }

    printf("%lld", result);

    return 0;
}