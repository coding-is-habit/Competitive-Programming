#include<bits/stdc++.h>
#define ll long long int 
#define mp make_pair
#define pb emplace_back
#define loop(a,b,c) for(int a = b; a < c; ++a)
#define P pair
#define PII pair<int,int>
#define PLL pair<ll,ll>
#ifdef LOCAL
#define debug(x) cout << #x << " = " << x << " ";
#define debugn(x) cout << #x << " = " << x << "\n";
#endif
#ifndef LOCAL
#define debug(x) 42;
#define debugn(x) 42;
#endif
#define V vector
#define all(a) a.begin(), a.end()
#define MAX(a) *max_element(all(a));
#define MIN(a) *min_element(all(a));
#define SUM(a) *accumulate(all(a),0LL);
#define C continue
#define R return 
using namespace std;

int solve(){
    int n;
    cin >> n;
    V<int> arr(n);
    loop(i,0,n)cin >> arr[i];
    int ans = 0;
    int mn = 1;
    sort(all(arr));
    loop(i,0,n){
        if(arr[i] < mn)ans+=mn-arr[i];
        mn = max(arr[i],mn)+1;
    }
    cout << ans << "\n";
    R 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t = 1;
    // cin >> t;
    while(t--)solve();
    return 0;
}