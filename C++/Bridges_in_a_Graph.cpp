//--------------------------------Optimizations---------------------------------//

#pragma comment(linker, "/stack:200000000")
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,avx,avx2")

//------------------------------------------------------------------------------//

//----------------------------Headers and Namespaces----------------------------//

#include<bits/stdc++.h>
#include <ext/pb_ds/detail/standard_policies.hpp>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;

//------------------------------------------------------------------------------//

//----------------------------------Defines-------------------------------------//

#define fastIO              ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
#define int                 long long
#define ll                  long long
#define float               long double
#define vi                  vector<int>
#define pii                 pair<int,int>
#define vpii                vector< pair<int,int> >

#define all(v)              v.begin(),v.end()
#define sz(x)               (int)x.size()
#define minv(a)             *min_element(all(a))
#define maxv(a)             *max_element(all(a))
#define sumv(a)             accumulate(all(a),0LL)

#define pb                  emplace_back
#define mp                  make_pair
#define F                   first
#define S                   second

#define mod                 1000000007
#define endl                "\n"

#define gcd(a,b)            __gcd(a,b)
#define lcm(a,b)            (a/(__gcd(a,b)))*b

#define setbits(x)          __builtin_popcountll(x)
#define leadzero(x)         __builtin_clzll(x)
#define trailzero(x)        __builtin_ctzll(x)

#define ordered_set         tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update>

//------------------------------------------------------------------------------//

//-------------------------------Debgugger--------------------------------------//

#ifndef ONLINE_JUDGE
#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1) {cout << name << " : " << arg1 << endl;}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args) {
    const char* comma = strchr(names + 1, ',');
    cout.write(names, comma - names) << " : " << arg1 << "  ";
    __f(comma + 1, args...);
}
#else
#define dbg(...) 50
#endif

//------------------------------------------------------------------------------//





//------------------------Highly Sophisticated Code Starts----------------------//

// Bridges in a graph are those edges on whose removal, the graph is broken domw into two or more components.

// Time Complexity : O(N + E)
// Space Complexity : O(N + N)
// Auxilary Sapce Complexity : O(N) for dfs call

const int N = 1e5 + 5;
vector<int>adj[N];
vector<bool>vis(N, false);
vector<int>tin(N, -1);  // time of insertion or entry time for node
vector<int>low(N, -1);  // lowest time of insertion (of a node) among all it's adjacent nodes (except the parent)
int timer = 0;
vector<pair<int,int>>bridges;

void dfs(int node, int parent)
{
    vis[node] = true;
    
    tin[node] = low[node] = timer++;
    
    for(auto i : adj[node]) // traversing the adjacent nodes of current node
    {
        if(i == parent)
            continue;
            
        if(!vis[i])
        {
            dfs(i, node);
            
            low[node] = min(low[node], low[i]);
            
            if(low[i] > tin[node])
            {
                bridges.push_back({node, i});
            }

        }
        else    // It means edge between them cannot be a bridge, because, this node has already been visited before.
        {
            low[node] = min(low[node], tin[i]);
        }

    }

}



void solve()
{

    int n, m;
    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;

        adj[u].push_back(v);
        adj[v].push_back(u);

    }    

    for(int i = 1; i <= n; i++)
    {
        if(!vis[i])
            dfs(i, -1);
    }

    cout << "Bridges in the given graph are : \n";
    for(auto i : bridges)
        cout << i.F << " -- " << i.S << endl;



}

int32_t main()
{

    fastIO
    cout << setprecision(15) << fixed;

    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<": \n";
        solve();
    }

    return 0;

}
