#include <bits/stdc++.h>
using namespace std;
#define ll long long
bool possible(ll n, ll m, ll x, ll y, ll ans)
{
	if ((ans * x) <= m + (n - ans)*y)
		return true;
	else return false;
}
ll binary_search(ll n, ll m, ll x, ll y)
{	ll ans = 0, s = 0, e = n; // Corrected
	while (s <= e)
	{
		ll mid = (s + e) / 2;
		if (possible(n, m, x, y, mid)) {
			ans = max(mid, ans);
			s = mid + 1;
		}
		else
			e = mid - 1;
	}
	return ans;
}

int main() {

	ll int n, m, x, y;
	cin >> n >> m >> x >> y;

	cout << binary_search(n, m, x, y);
	return 0;
}