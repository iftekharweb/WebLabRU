#include <bits/stdc++.h>
using namespace std;

void ParagraphInput(string &fullParagraph) {
    string line;
    do {
        getline(cin, line);
        fullParagraph += line;
        fullParagraph += "\n";
    } while (line.size());
} 

void Decrypting(string &Encrypt, string &Decrypt, int key) {
    for(auto x:Encrypt) {
        if(x != ' ' && x != '\n') {
            int val;
            char ch;
            if(x>='a') {
                val = (abs((int)x-'a')-key+26)%26;
                ch = val+'a';
            } else {
                val = (abs((int)x-'A')-key+26)%26;
                ch = val+'A';
            }
            Decrypt += ch;
        } else {
            Decrypt += x;
        }
    }
    return;
}

int main() 
{
    cout << "Enter The Text: \n";

    string fullParagraph = "";
    ParagraphInput(fullParagraph);

    cout << "Enter A Key: \n";
    int key;
    cin >> key;

    string Encrypt = "", Decrypt = "";
    for(auto x:fullParagraph) {
        if(x != ' ' && x != '\n') {
            int val;
            char ch;
            if(x>='a') {
                val = (x-'a'+key)%26;
                ch = val+'a';
            } else {
                val = (x-'A'+key)%26;
                ch = val+'A';
            }
            Encrypt += ch;
        } else {
            Encrypt += x;
        }
    }
    cout << "Encrypted Message:\n" << Encrypt << endl;

    Decrypting(Encrypt,Decrypt,key);
    cout  << "Decrypted Message:\n" << Decrypt << endl;

    for(int i=0; i<26; i++) {
        Decrypt = "";
        Decrypting(Encrypt,Decrypt,i);
        if(fullParagraph == Decrypt) {
            cout << "Used Key is " << i << endl;
            break;
        }
    }
    
    return 0;
}