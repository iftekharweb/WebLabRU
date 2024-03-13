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

int main() {

    string key = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string value = "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";

    cout << "Enter The Text: \n";

    string fullParagraph = "";
    ParagraphInput(fullParagraph);

    map<char,char> forEncrypt, forDecrypt;
    for(int i=0; i<key.size(); i++) {
        forEncrypt[key[i]] = value[i];
        forDecrypt[value[i]] = key[i];
    }

    string Encrypt = "", Decrypt = "";
    for(auto x:fullParagraph) { 
        if(x != ' ' && x != '\n') {
            Encrypt += forEncrypt[x];
        } else {
            Encrypt += x;
        }
    }
    cout << "Encrypted Message:\n" << Encrypt << endl;

    for(auto x:Encrypt) {
        if(x != ' ' && x != '\n') {
            Decrypt += forDecrypt[x];
        } else {
            Decrypt += x;
        }
    }
    cout  << "Decrypted Message:\n" << Decrypt << endl;

    return 0;
}