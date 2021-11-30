#include <bits/stdc++.h>
using namespace std;

struct point
{
    int x;
    int y;
};

int inv(int a, int m)
{
    for (int x = 1; x < m; x++)
        if (((a%m) * (x%m)) % m == 1)
            return x;
}

point publickey(point g, int pr, int p){
    point r = g;
    for(int i = 0; i < pr-1; i++){
        //r+g
        int s = ((r.y-g.y) * inv(r.x-g.x,p))%p;
        r.x = ((int)pow(s,2) - (r.x-g.x))%p;
        r.y = (s*(r.x-g.x) - r.y)%p;
    }
    return r;
}

int main()
{
    /*cout << "Input a" << endl;
    int a;
    cin >> a;
    
    cout << "Input b" << endl;
    int b;
    cin >> b;
    */
    
    cout << "Input p (The field)" << endl;
    int p;
    cin >> p;

    cout << "Input the private key" << endl;
    int pr;
    cin >> pr;

    cout << "Input the the x-coordinate of the genrator point" << endl;
    int gx;
    cin >> gx;

    cout << "Input the the y-coordinate of the genrator point" << endl;
    int gy;
    cin >> gy;

    point g;
    g.x=gx;
    g.y=gy;

    point pu = publickey(g,pr,p);

    cout << "The public key is = (" << pu.x << "," << pu.y << ")" << endl;

    return 0;
}
