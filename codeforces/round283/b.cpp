#include<bits/stdc++.h>
#define ll long long int
#define loop(a,b,c) for(int a = b; a < c; ++a);
#define loopr(a,b,c) for(int a = b; a >= c; --a);
#define P pair;
#define PII pair<int,int>
#define PLL pair<long long, long long>
#define V vector
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define pb emplace_back
#define mp make_pair
#define fast ios_base::sync_with_stdio(false);cout.tie(0);cin.tie(0);
#define ld long double
#define mod 1000000007
#ifndef LOCAL
#define deb(x) 45;
#endif 
#ifdef LOCAL
#define deb(x) cout << #x << " = " <<  x << "\n";
#endif 
using namespace std;
const int N = 1e5+10;


ll power(ll a, ll n){
    if(a >= mod)a%=mod;
    if(n == 0)return 1;
    if(n == 1)return a;
    ll p = power(a,n>>1);
    if(p >= mod)p%=mod;
    if(n&1)p*=a;
    if(p >= mod)p%=mod;
    return p;
}


int solve(){
    int n;
    cin >> n;
    string a;
    cin >> a;
    string ans = a;
    for(int i = 0; i < 2*n; ++i){
        int s = 10-(a[0]-'0');
        for(char &j: a)j = char((j-'0'+s)%10+'0');
        ans = min(a,ans);
        char j = a[n-1];
        a.pop_back();
        a = j+a;
    }
    cout << ans;
    return 0;
}

int main(){
    fast
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}