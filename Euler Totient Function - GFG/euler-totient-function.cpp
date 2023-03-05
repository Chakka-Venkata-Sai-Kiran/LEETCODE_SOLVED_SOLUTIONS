//{ Driver Code Starts
#include<bits/stdc++.h> 
using namespace std;

// } Driver Code Ends
class Solution{
public:
    // function to find totient of n
    bool isprime(long long n){
        if(n == 2 || n == 3)
            return true;
        if(n % 2 == 0 || n % 3 == 0)
            return false;
        for(int i = 5; i * i <= n; i += 6)
            if(n % i == 0 || n % (i + 2) == 0)
                return false;
        return true;
    }
    long long ETF(long long n){
        // code here
        if(isprime(n))
            return n - 1;
        long long ans = 0;
        unordered_map<long long,int> fact;
        long long N = n;
        for(int i = 2; i * i <= n; i++)
            while(n % i == 0){
                fact[i]++;
                n /= i;
            }
        if( n > 1) fact[n]++;
        vector<int> temp;
        for(auto it:fact)
            temp.push_back(it.first);
        sort(temp.begin(),temp.end());
        for(long long i = 1; i < N; i++){
            bool flag = true;
            for(auto it:temp)
                if(i % it == 0){
                    flag = false;
                    break;
                }
            if(flag)
                ans++;
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        long long N;
        cin>>N;
        Solution ob;
        cout << ob.ETF(N) << endl;
    }
    return 0; 
}
// } Driver Code Ends