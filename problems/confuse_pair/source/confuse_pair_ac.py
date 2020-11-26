def convert(a, number_str):
    N = len(number_str)
    ret = 0
    for i in range(N):
        if int(number_str[-i-1]) >= a: return -1
        ret += int(number_str[-i-1]) * (a ** i)
    return ret

if __name__ == "__main__":
    S, T = input().split()
    ans = 0
    for i in range(1, 11):
        for j in range(1, 11):
            a = convert(i, S)
            b = convert(j, T)
            if a != -1 and b != -1 and a == b:
                ans += 1
    print(ans)