#include <bits/stdc++.h>
using namespace std;

bool check_prime(long long n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

long long gcd(long long a, long long b)
{
    long long temp;

    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }

    return a;
}

long long public_key(long long p, long long q)
{
    long long fie = (p - 1) * (q - 1);

    for (int i = 2; i < fie; i++)
    {
        long long e = i;

        if (e < fie && gcd(e, fie) == 1 && e != p && e != q)
        {
            return e;
        }
    }
}

long long private_key(long long e, long long p, long long q)
{
    long long d;

    long long fie = (p - 1) * (q - 1);

    for (int i = 1; i < INT16_MAX; i++)
    {
        d = i;
        long long temp = (e * d) % fie;

        if (temp == 1 && d < fie)
        {
            return d;
        }
    }
}

long long encrypt(long long e, long long m, long long n)
{
    return (long long)pow(m, e) % n;
}

long long decrypt(long long d, long long c, long long n)
{
    return (long long)pow(c, d) % n;
}

int main()
{
    long long p, q, n, m, e;

    cout << "enter value of p and q:" << endl;
    cin >> p >> q;

    cout << "enter msg :" << endl;
    cin >> m;

    if (check_prime(p) == 0 || check_prime(q) == 0)
    {
        cout << "enter prime numbers:" << endl;
    }

    else
    {
        n = p * q;
        e = public_key(p, q);

        cout << "public key is :" << public_key(p, q) << "," << n << endl
             << endl;
        cout << "e:" << e << endl;

        cout << "Private key is :" << private_key(e, p, q) << "," << n << endl
             << endl;

        long long d = private_key(e, p, q);

        cout << "encrypted msg is" << encrypt(e, m, n) << endl;
        long long c = encrypt(e, m, n);

        cout << "decrypted msg is" << decrypt(d, c, n) << endl;
    }

    return 0;
}