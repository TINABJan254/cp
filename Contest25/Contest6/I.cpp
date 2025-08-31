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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];

    vector<ll> pre(n + 1, 0);
    vector<ll> s(n + 1, 0);
    pre[0] = 0;
    s[0] = 0;
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + a[i - 1];
        s[i] = pre[i] - i;
    }

    ll ans = 0;
    map<ll, ll> mp;
    mp[(s[0] % k + k) % k]++;
    for (int j = 1; j <= n; j++) {
        ll smod = (s[j] % k + k) % k;
        if (j - k >= 0) {
            mp[(s[j - k] % k + k) % k]--;
        }
        ans += mp[smod];
        mp[smod]++;
    }

    cout << ans << endl;
}

void iof() {
#ifndef ONLINE_JUDGE
    freopen("../build/inputf.txt", "r", stdin);
    // freopen("outputf.txt", "w", stdout);
#endif
}

int main() {
    iof();
    faster();
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        solve();
    }
    return 0;
}