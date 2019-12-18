#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops,fast-math")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4.1,sse4.2,avx,avx2,popcnt,tune=native")

#include "bits/stdc++.h"

#define mem(x) memset((x), 0, sizeof((x)))
#define il __attribute__((always_inline))

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

#if __cplusplus > 201403L
#define r
#else
#define r register
#endif

#define c const

namespace _c
{
c double pi = acos(-1.0);
namespace min
{
c int i8 = -128;
c int i16 = -32768;
c int i = -2147483647 - 1;
c ll l = -9223372036854775807LL - 1;
} // namespace min

namespace max
{
c int i8 = 127;
c int i16 = 32767;
c int i = 2147483647;
c ll l = 9223372036854775807LL;
} // namespace max
} // namespace _c

namespace _f
{
template <typename T>
inline c T gcd(T m, T n)
{
    while (n != 0)
    {
        T t = m % n;
        m = n;
        n = t;
    }
    return m;
}

template <typename T>
inline c T abs(c T &a)
{
    return a > 0 ? a : -a;
}

template <typename T>
inline T pow(T a, T b)
{
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a;
        }
        a = a * a;
        b >>= 1;
    }
    return res;
}

template <typename T>
inline T pow(T a, T b, c T &m)
{
    a %= m;
    T res = 1;
    while (b > 0)
    {
        if (b & 1)
        {
            res = res * a % m;
        }
        a = a * a % m;
        b >>= 1;
    }
    return res % m;
}
} // namespace _f

namespace io
{
template <typename T>
inline T read()
{
    r T res = 0, neg = 1;
    char g = getchar();
    for (; !isdigit(g); g = getchar())
    {
        if (g == '-')
        {
            neg = -1;
        }
    }
    for (; isdigit(g); g = getchar())
    {
        res = res * 10 + g - '0';
    }
    return res * neg;
}
template <typename T>
inline void read(T &t)
{
    t = read<T>();
}
template <typename T>
inline void readln(c T first, c T last)
{
    for (r T it = first; it != last; it++)
    {
        read(*it);
    }
}

template <typename T>
inline void _write(T x)
{
    if (x < 0)
    {
        putchar('-');
        x = -x;
    }
    if (x > 9)
    {
        _write(x / 10);
    }
    putchar(x % 10 + '0');
}
template <typename T>
inline void write(c T &x, c char &sep = ' ')
{
    _write(x);
    putchar(sep);
}
template <typename T>
inline void writeln(c T &x)
{
    write(x, '\n');
}
template <typename T>
inline void writeln(c T first, c T last, c char &sep = ' ', c char &ends = '\n')
{
    for (r T it = first; it != last; it++)
    {
        write(*it, sep);
    }
    putchar(ends);
}

#if __cplusplus >= 201103L
template <typename T, typename... Args>
void read(T &x, Args &... args)
{
    read(x);
    read(args...);
}
#endif
} // namespace io
#undef c
#undef r

int T;
int n, m;
bool A[65][65];

inline bool check_x(int x)
{
    for (int i = 1; i <= m; i++)
    {
        if (!A[x][i])
        {
            return 0;
        }
    }
    return 1;
}
inline bool check_y(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (!A[i][x])
        {
            return 0;
        }
    }
    return 1;
}

template <typename T>
inline void chkmin(T &x, T y)
{
    if (x > y)
    {
        x = y;
    }
}

int main()
{
    io::read(T);
    while (T--)
    {
        io::read(n, m);

        char c = getchar();
        bool flg = 1;

        for (int i = 1; i <= n; i++)
        {
            while (!isalpha(c))
            {
                c = getchar();
            }
            for (int j = 1; j <= m; j++)
            {
                A[i][j] = (c == 'A');
                flg &= A[i][j];
                c = getchar();
            }
        }

        int ans = _c::max::i;

        if (flg)
        {
            ans = 0;
        }

        if (check_x(1) || check_x(n) || check_y(1) || check_y(m))
        {
            chkmin(ans, 1);
        }

        for (int i = 1; i <= n; i++)
        {
            if (check_x(i))
            {
                chkmin(ans, 2);
            }
        }

        for (int i = 1; i <= m; i++)
        {
            if (check_y(i))
            {
                chkmin(ans, 2);
            }
        }

        if (A[1][1] || A[1][m] || A[n][1] || A[n][m])
        {
            chkmin(ans, 2);
        }

        for (int i = 1; i <= n; i++)
        {
            if (A[i][1] || A[i][m])
            {
                chkmin(ans, 3);
            }
        }

        for (int i = 1; i <= m; i++)
        {
            if (A[1][i] || A[n][i])
            {
                chkmin(ans, 3);
            }
        }

        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= m; j++)
            {
                if (A[i][j])
                {
                    chkmin(ans, 4);
                }
            }
        }

        if (ans > 4)
        {
            puts("MORTAL");
        }
        else
        {
            io::writeln(ans);
        }
    }
}
