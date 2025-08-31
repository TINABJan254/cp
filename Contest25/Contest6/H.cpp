#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define ll long long
#define fi first
#define se second
#define sz size()
#define pb push_back
#define vi vector<int>
#define vvi vector<vector<int>>
#define vll vector<long long>
#define vvl vector<vector<long long>>
#define faster() ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);
#define pii pair<int, int>
#define pll pair<ll, ll>

const int MOD = 1e9 + 7;
const int N = 1e6 + 5;

bool cmp(pii x, pii y) {
    return x.fi < y.fi;
}

bool check(int d, vector<pii> v) {
    int miny = INT_MAX;
    int maxy = INT_MIN;

    int k = 0;

    for (int i = 0; i < v.sz; i++) {
        while (k < i && v[i].fi - v[k].fi >= d) {
            miny = min(miny, v[k].se);
            maxy = max(maxy, v[k].se);
            ++k;
        }

        if (k > 0) {
            if (v[i].se - miny >= d || maxy - v[i].se >= d)
                return true;
        }
    }

    return false;
}

void solve(){
    int n; cin >> n;
    vector<pii> v; 
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        v.pb({x, y});
    }

    stable_sort(v.begin(), v.end(), cmp);

    int low = 0, high = 1000000000;
    while (low < high) {
        int mid = (low + high + 1)/2;
        if (check(mid, v))
            low = mid;
        else 
            high = mid - 1;
    }

    cout << low;

}   

void iof(){
    #ifndef ONLINE_JUDGE
        freopen("../build/inputf.txt", "r", stdin);
        // freopen("outputf.txt", "w", stdout);
    #endif
}

int main(){
    iof();
    faster();
    int TC = 1; 
    // cin >> TC;
    while (TC--){
      solve();
    }
    return 0;
}

/*
    
*/