#include <bits/stdc++.h>
using namespace std;
 
void fastio() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
}
 
void open(string filename) {
    fastio();
    freopen((filename + ".in").c_str(), "r", stdin);
    freopen((filename + ".out").c_str(), "w", stdout);
}
 
typedef long long ll;
#define vll vector<ll>
#define vint vector<int>
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pb push_back
#define mp make_pair
#define sz() size()
#define rsz resize
#define se second
#define fi first
#define cont continue

ll MOD = 1000000007;

int main() {
    // open("problem");
    fastio();
    int tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
// Comment or uncomment the open("problem") and cin >> t lines, they are for file input and test cases, respectively. 
