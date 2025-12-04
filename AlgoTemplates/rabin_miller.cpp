#include<bits/stdc++.h>
#define int long long
using namespace std;
 
int mulmod(int a, int b, int mod){
    int res = 0;
    a %= mod;
    
    while(b > 0){
        if(b & 1) res = (res + a) % mod;
        a = (a << 1) % mod;
        b >>= 1;
    }
    return res;
}
 
int powmod(int a, int b, int mod){
    int res = 1 % mod;
    a %= mod;
    
    while(b > 0){
        if(b & 1) res = mulmod(res, a, mod);
        a = mulmod(a, a, mod);
        b >>= 1;
    }
    return res;
}
 
bool check(int a, int m, int d, int n){
    int x = powmod(a, m, n);
    if(x == 1 || x == n - 1) return true;
    
    int prev = x;
    while(d--){
        x = mulmod(x, x, n);
        if(x == 1 && prev != 1 && prev != n - 1) return false;
        
        prev = x;
    }
    return x == 1;
}
 
bool rabin_miller(int n){
    if(n < 2) return false;
    else if(n == 2) return true;
    else if(n % 2 == 0) return false;
    
    int d = 0, m = n - 1;
    while(m % 2 == 0){
        m /= 2;
        ++d;
    }
    
    vector<int> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for(int a: bases){
        if(a >= n) break;
        if(!check(a, m, d, n)) return false;
    }
    
    return true;
}
 
signed main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
    int t;
    cin >> t;
    
    while(t--){
        int n;
        cin >> n;
        
        cout << (rabin_miller(n) ? "YES\n" : "NO\n");
    }
 
    return 0;
} 