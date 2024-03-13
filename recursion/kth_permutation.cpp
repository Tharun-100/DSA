class Solution {
public:
    string getPermutation(int n, int k){
        // we have to find the 
        vector<int> a;
        string b="";
        k=k-1;
        int fact=1;
        for(int i=1;i<n;i++){
            fact*=i;// this one will go until: 
            a.push_back(i);
        }
        a.push_back(n);
        
        int x=n;
        while(x!=0){
            // the number which want at that position is k/fact index of the array a;
            // add the string 
            b=b+to_string(a[k/fact]);
            // then erase the number in the array:
            a.erase(a.begin()+(k/fact));
            //check whether a is null or not? if yes then break the loop
            if((a.size()==NULL))break;
            
            // update the factorial and the k;
            k=(k%fact);
            fact=fact/(a.size());
        }
        
        return b;
    }
};
