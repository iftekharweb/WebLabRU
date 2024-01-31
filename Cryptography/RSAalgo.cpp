#include <bits/stdc++.h>
using namespace std;

/*

KEY GENERATION:

Message number = M
select p,q where p,q are both primes and p!=q
calculate n = p*q
calculate @(n) = (p-1)(q-1)
select integer e where gcd(@(n),e) = 1 and 1<e<@(n)
calculate d where d = e^(-1) mod @(n)
public key PU = {e,n}
private key PR = {d,n}

ENCRYPTION:
plaintext M<n
Cipher text C = M^e mod n


DECRYPTION:
Cipher text C
plain text M = C^d  mod n

*/

bool isPrime(long long n) {
    for(long long i = 2; i*i<=n; i++) {
        if(n%i == 0) return true;
    }
    return false;
}

long long modInverse(long long A, long long M) {
    long long m0 = M;
    long long y = 0, x = 1;
    if (M == 1) return 0;
    while (A > 1) {
        long long q = A / M;
        long long t = M;
        M = A % M, A = t;
        t = y;
        y = x - q * y;
        x = t;
    }
    if (x < 0) x += m0;
    return x;
}
long long POW(long long a, long long b) {
    long long res = 1; 
    while(b){ 
        if(b%2) res = (res*a); 
        a = (a*a); 
        b /= 2;
    } 
    return res;
}

long long Decryption(pair<long long,long long> PR, long long C) {
    long long M;
    M = POW(C,PR.first) % PR.second;
    return M;
}

long long Encryption(pair<long long,long long> PU) {
    long long M, C;
    cout << "Enter The Number: ";
    cin >> M;
    C = POW(M,PU.first) % PU.second;
    return C;

}

void KeyGeneration() {
    long long p , q, n, T, e = -1;
    cout << "Enter Two Prime Numbers p and q:\n";
    cin >> p >> q;
    n = p*q;
    if(isPrime(p) || isPrime(q)) {
        cout << "p and/or q is not a prime. So, encription is not possible.";
    } else {
        T = (p-1)*(q-1);
        for(long long i=2; i<T; i++) {
            if(__gcd(T,i) == 1) {
                e = i;
                break;
            }
        }
        long long d = modInverse(e,T);
        pair<long long,long long> PU = {e,n}, PR = {d,n};

        cout << T << " " << e << " " << d << " " << n << endl;

        // Encryption & decryption
        long long C = Encryption(PU);
        cout << C << endl;
        long long M = Decryption(PR, C);
        cout << M << endl;
    }
}

int main() 
{
        cout << "SELECT ONE OPTION:(1) KEY GENERATION (2) KEYS WILL BE GIVEN\n";
        cout << "Enter option number: ";
        int option;
        cin >> option;

        if(option == 1) {
            KeyGeneration();
        } else {

        }

        return 0;
}