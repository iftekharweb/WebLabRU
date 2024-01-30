#include <bits/stdc++.h>

using namespace std;

int main (){
    cout <<"enter a text"<<endl;
    string s,stp;
    do {
        getline(cin,s);
        stp+=s+"\n";
    } while(s.length()>0);

    cout <<"enter a key: ";
    int key ;
    cin >>key;
    vector <char> enp,dep;
    for (int i=0;i<stp.size();i++){
        if((stp[i]>='a' && stp[i]<='z')){
           int ct=(((int(stp[i])-'a')+key)%26);
           enp.push_back(ct+'a');
        }
        else if ((stp[i]>='A' && stp[i]<='Z')){
            int ct=(((int(stp[i])-'A')+key)%26);
            enp.push_back(ct+'A');
        }
        else if (stp[i]==' ') {
            enp.push_back(' ');
        }
        else {
            enp.push_back('\n');
        }
    }
    cout<<"Cipertext: "<<endl;
    for (int i=0;i<enp.size();i++){
        cout <<enp[i];
    }
    for (int i=0;i<enp.size();i++){
        if((enp[i]>='a' && enp[i]<='z')){
           int ct=(abs((int(enp[i])-'a')-key+26)%26);
           dep.push_back(ct+'a');
        }
        else if ((enp[i]>='A' && enp[i]<='Z')){
            int ct=(abs((int(enp[i])-'A')-key+26)%26);
            dep.push_back(ct+'A');
        }
        else if (enp[i]==' ') {
            dep.push_back(' ');
        }
        else {
            dep.push_back('\n');
        }
    }
    cout<<"Decripted plain text: "<<endl;
    for(int i=0;i<dep.size();i++){
        cout<<dep[i];
    }

   // cout <<stp;
    //cout<<endl<<stp.size();
}