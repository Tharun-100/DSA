#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    // int countpath(int i,int j, int m,int n){
    //     if(i==m-1 && j==n-1)return 1;
    //     if(i>=m || j>=n)return 0;
    //     int count=0;
    //     count+=countpath(i+1,j,m,n);
    //     count+=countpath(i,j+1,m,n);
    //     return count;
        
    // }// this is bruteforce technique:
    int uniquePaths(int m, int n) {
        // return countpath(0,0,m,n);
        // optimal solution:
        int N = n + m - 2;
        int r = m - 1; 
        double res = 1;
        
        for (int i = 1; i <= r; i++)res = res * (N - r + i) / i;
        return (int)res;
    }
};

int main(){
    
    int m=4,n=5;
    // a=class solution();
    class Solution a;
    cout<<a.uniquePaths(m,n)<<endl;
}
