#include<bits/stdc++.h>
using namespace std;

int extendedGCD(int a, int b, int& x, int& y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}

int modInverse(int a, int m) {
    int x, y;
    int gcd = extendedGCD(a, m, x, y);
    if (gcd != 1) {
        cout << "Modular inverse does not exist.\n";
        return -1; 
    } else {
        return (x % m + m) % m;
    }
}

long long binaryExponentiation(long long  a, long long b,long long MOD) {
    if(b==0)return 1;
    if(b%2){
        return (a*binaryExponentiation(a,b-1,MOD))%MOD;     
    }
    else {
        long long x = binaryExponentiation(a,b/2,MOD)%MOD;
        return (x*x)%MOD;
    }
}

int main()
{
    cout << "CHOOSE ONE :\n(1) GENERATE KEY \n(2) PROVIDE KEYS\nOPTION = ";
    int choice;
    cin >> choice;
    long long n, e, d;
    if(choice == 1) {
        long long p, q;
        p = 3,q = 41;
        cout << "\nENTER TWO PRIME NUMBERS p, q:\n\tp = ";
        cin >> p;
        cout << "\tq = ";
        cin >> q;
        n = p*q;
        long long qn = (p-1)*(q-1);
        e = qn-1;
        d = modInverse(e,qn);
        cout << "\nPROVIDE PUBLIC KEY {" << e <<", "<< n <<"}\n";
        cout << "PROVIDE PRIVATE KEY {" << d <<", "<< n <<"}\n\n";
    } 
    else {
        cout << "\nPROVIDE PRIVATE KEY {e, n}:\n\td = ";
        cin >> d;
        cout << "\nPROVIDE PUBLIC KEY {d, n}:\n\te = ";
        cin >> e;
        cout << "\nPROVIDE n:\n\t n = ";
        cin >> n;
        cout << '\n';
    }

    string v;
    cout << "ENTER THE MESSAGE: ";
    cin >> v;
    string encrypt = "";
    for(int i=0; i<v.size(); i++){
        long long x = v[i];
        long long y = binaryExponentiation(x,e,n);
        encrypt.push_back(char(y));
    }
    
    cout << "\nENCRYPTED TEXT: " << encrypt << endl;
    string decrypt = "";
    
    for(long long i=0;i<encrypt.size();i++){
        long long x = encrypt[i];
        long long y = binaryExponentiation(x,d,n);
        decrypt.push_back(y);
    }
    cout << "DECRYPTED TEXT: " << decrypt << endl;

}