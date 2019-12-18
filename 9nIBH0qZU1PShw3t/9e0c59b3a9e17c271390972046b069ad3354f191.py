T = int(input())
MOD = int(1e9+7)
for _ in range(T):
    x = int(input())
    s = input()
    clip = ""
    l = 0

    flag = False
    ans = 0
    while l != x:
        l += 1
        if len(s) > 1e6+5:
            flag = True

        if (flag):
            ans += (ans - l) * (int(s[l]))
            ans %= MOD
        else:
            t = s[-l:]
            for i in range(1, int(s[l])):
                s += t
            ans = len(s)

    print(ans)
