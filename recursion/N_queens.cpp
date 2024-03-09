// Online C++ compiler to run C++ program online
#include <bits/stdc++.h>
using namespace std;
int Chess_Q(vector<vector<int>> &a,vector<vector<int>> b, int row){
    // what is the base condition:
    if(row>=b.size()){
        return 1;
    }
    int count=0;
    for(int i=0;i<b[row].size();i++){
        
        int sum=0;
        for(int j=0;j<a.size();j++){
            if((row+1)==a[j][0] || (i+1)==a[j][1] || (((row+1)/float(i+1))==(a[j][0]/float(a[j][1]))))sum=1;
        }
        // it should not be the diagonal and it should not be the array:
        if(sum==0){
            a.push_back({row+1,i+1});
            count+=Chess_Q(a,b,row+1);// next index
            a.pop_back();
        }
        
    }
    return count;
    
}
void print(vector<vector<int>> a){
    cout<<"The elements inside the container is!"<<endl;
    for(int i=0;i<a.size();i++){
        for(int j=0;j<a[i].size();j++){
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int main() {
    vector<vector<int>> b(8,vector<int>(8,0));
    vector<vector<int>> a;
    
    print(b);
    int count=Chess_Q(a,b,0);
    cout<<"\nThe number of possible combinations of queens are:"<<count<<endl;
    
    
    return 0;
}
