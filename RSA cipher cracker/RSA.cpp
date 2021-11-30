#include <bits/stdc++.h>
using namespace std;

int gcd(int x, int y)
{
    if (x == 0)
        return y;
    return gcd(y % x, x);
}

int EulerTotient(int x)
{
    int r = 1;
    for (int i = 2; i < x; i++)
        if (gcd(i, x) == 1)
            r++;
    return r;
}
 

int main()
{
    cout << "Input n | n < 65536" << endl;
    int n;
    cin >> n;
    
    cout << "Input e (The public encryption key)" << endl;
    int e;
    cin >> e;
    
    cout << "Input the cipher encrypted text" << endl;
    string cipher;
    cin >> cipher;

    int phi = EulerTotient(n);
    int k = 11;
    int d = (1 + (k*phi))/e;
    
    //Assuming that the RSA algorithm used for encrypting this cipher text encodes the non-numerical text 
    //into their corresponding ASCII number and perform the operation C = P^e mod n on this ASCII value
    string plain = "";
    for (int i = 0; i < cipher.length(); i++) {
        if(cipher.at(i) != ' '){
            int c = (int) cipher.at(i);
            double p = fmod(pow(c,d), n);
            plain.push_back((char)p);
        }
        else
            plain.push_back(' ');
    }

    cout << "The value of d (The private decryption key) is = " << d << endl;
    cout << "The plain decrypted text is: " << plain << endl;

    return 0;
}
