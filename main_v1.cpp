// lưu dưới dạng string

#include <bits/stdc++.h>
using namespace std;
struct BigInt
{
    int sign; // 1 la so duong, -1 la so am, 0 la so 0
    int base;
    string data;
    void Read()
    {
        cin >> data;
        if (data[0] == '-')
        {
            sign = -1;
            data = data.substr(1, data.size() - 1);
        }
        else
        {
            sign = 1;
        }
    }
};
BigInt toBinary(BigInt number)
{
    BigInt res;
    res.sign = number.sign;
    while (number.data != "0")
    {
        int lastDigit = number.data.back() - '0';
        res.data += char(lastDigit % 2 + '0');
        number = number / 2;
    }
    reverse(res.data.begin(), res.data.end());
    return res;
}
BigInt toDecimal(BigInt number)
{
    BigInt two, Pow2, res;
    two.data = "2";
    Pow2.data = "1";
    for (int i = number.data.size() - 1; i >= 0; i--)
    {
        if (number.data[i] == '1')
        {
            res = res + Pow2;
        }
        Pow2 = Pow2 * two;
    }
    return res;
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    BigInt x;
    x.Read();
    cout << x.data << endl;
    BigInt res = x / 2;
    //cout << res.data << endl;
    //cout << toBinary(x).data << endl;
    BigInt a, b;
    a.sign = b.sign = 1;
    a.data = "22";
    b.data = "3";
    BigInt c = a - b;
    cout << c.data << endl;
    cout << toDecimal(toBinary(x)).data << endl;
}