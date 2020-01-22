#include <bits/stdc++.h>
//For ordered_set
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define MOD 1000000007
#define test int t; cin>>t; while(t--)
#define init(arr,val) memset(arr,val,sizeof(arr))
#define loop(i,a,b) for(int i=a;i<b;i++)
#define loopr(i,a,b) for(int i=a;i>=b;i--)
#define loops(i,a,b,step) for(int i=a;i<b;i+=step)
#define looprs(i,a,b,step) for(int i=a;i>=b;i-=step)
#define ull unsigned long long int
#define ll long long int
#define P pair
#define PLL pair<long long, long long>
#define PII pair<int, int>
#define PUU pair<unsigned long long int, unsigned long long int>
#define L list
#define V vector
#define D deque
#define ST set
#define MS multiset
#define M map
#define UM unordered_map
#define mp make_pair
#define pb push_back
#define pf push_front
#define MM multimap
#define F first
#define S second
#define IT iterator
#define RIT reverse_iterator
#define FAST ios_base::sync_with_stdio(false);cin.tie();cout.tie();
#define FILE_READ_IN freopen("input.txt","r",stdin);
#define FILE_READ_OUT freopen("output.txt","w",stdout);
#define all(a) a.begin(),a.end()
#define ld long double
using namespace std;
// For ordered_set
using namespace __gnu_pbds;
template <typename T>
using ord_set = tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
const ll N = 1e5+10;
const ll inf = 1e9;
const double pi = acos(-1);
int parent[N];
set<int> g;
V<PII> adj[N];
int mx = 0;
int fp(int x){
    if(x == parent[x])return x;
    parent[x] = fp(parent[x]);
    return parent[x];
}
void un(int a, int b){
    parent[fp(a)]=fp(b);
}

void dfs(int s, int p=-1, int mx1 = 0){
    for(auto i: adj[s]){
        if(i.F == p)continue;
        mx1=max(mx1,i.S);
        if(g.find(i.F) != g.end())mx=max(mx,mx1);
        dfs(i.F,s,mx1);
    }
}

int main(){
    FAST
    loop(i,0,N)parent[i]=i;
    int n,m,k;
    cin >> n >> m >> k;
    V<P<int,PII>> a;
    loop(i,0,k){
        int o;
        cin  >> o;
        g.insert(o);
    }
    while(m--){
        int u,v,w;
        cin >> u >> v >> w;
        a.pb({w,{u,v}});
    }
    sort(all(a));
    for(auto i: a){
        if(fp(i.S.S) == fp(i.S.F))continue;
        un(i.S.F,i.S.S);
        adj[i.S.F].pb({i.S.S,i.F});
        adj[i.S.S].pb({i.S.F,i.F});
    }
    if(g.size())dfs(*g.begin());
    loop(i,0,k)cout << mx << " ";
   return 0;
}