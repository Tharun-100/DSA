// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;

void binarystring(int i,int n,string s,vector<string> &a){
    if(i>=n){
        a.push_back(s);
        return;
    }
    binarystring(i+1,n,s,a);
    if(s[i-1]!='1'){
        s[i]='1';
        binarystring(i+1,n,s,a);
    }
    return;
}
vector<string> generateString(int N,string s) {
    // Write your code here.
    vector<string> a;
    binarystring(0,N,s,a);
    return a;
 
}
void print(string s){
    cout<<"Elements in the string are!"<<endl;
    for(int i=0;i<s.length();i++){
        cout<<s[i];
    }
    cout<<endl;
}
void printa(vector<string> a){
    cout<<"Elements in the vector of strings are!"<<endl;
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int main() {
    // Write C++ code here
    std::cout << "Hello world!"<<endl;
     char x='0';
     int N=4;
     string s(N,x);
     print(s);
     vector<string> a=generateString(N,s);
     printa(a);
     

    return 0;
}
