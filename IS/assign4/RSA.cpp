#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b)
{
    int temp;
    while (b != 0)
    {
        temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}
int checkprime(int n)
{
    if (n <= 1)
    {
        return false;
    }

    for (int i = 2; i < n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }

    return true;
}

int public_key(int p, int q)
{
    int fie = (p - 1) * (q - 1);

    for (int i = 2; i < INT16_MAX; i++)
    {
        int e = i;

        if (e < fie && gcd(e, fie) == 1 && e != p && e != q)
        {
            return e;
        }
    }
}

int private_key(int e, int p, int q)
{
    int d;
    int fie = (p - 1) * (q - 1);

    for (int i = 1; i < INT16_MAX; i++)
    {

        d = i;
        int temp = (e * d) % fie;
        if (temp == 1)
        {
            return d;
        }
    }
}

int encryption(int e, int n, int m)
{
    int c;

    int power = pow(m, e);

    c = power % n;

    return c;
}

int decryption(int d, int n, int c)
{
    return fmod(pow(c, d), n);
}

int main()
{

    int p, q, n, e, m;

    int pk;

    cout << "Enter values of p and q:" << endl;
    cin >> p >> q;

    cout << "Enter massage:" << endl;
    cin >> m;

    if (checkprime(p) == 0 && checkprime(q) == 0)
    {
        cout << "Enter the prime numbers" << endl;
    }

    else
    {
        n = p * q;
        e = public_key(p, q);

        cout << "public key is :" << public_key(p, q) << "," << n << endl
             << endl;

        cout << "Private key is :" << private_key(e, p, q) << "," << n << endl
             << endl;

        int d = private_key(e, p, q);

        cout << "Encrpyted msg is:" << encryption(e, n, m) << endl
             << endl;

        int c = encryption(e, n, m);

        cout << "plaintext  msg is:" << decryption(d, n, c) << endl;
    }
    return 0;
}