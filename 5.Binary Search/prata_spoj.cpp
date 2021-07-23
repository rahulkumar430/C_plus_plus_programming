#include<bits/stdc++.h>
using namespace std;

bool isPossible(int p, int l, int r[], int min_time) {
	int prataMade = 0;
	for (int i = 0; i < l ; i++) {
		int t = r[i];
		int j = 1;
		int time_remaining = min_time;
		//cout << t << " " << j << " " << time_remaining << endl;
		while (time_remaining - t >= 0) {
			prataMade++;
			j++;
			time_remaining = time_remaining - t;
			//cout << prataMade << " " << j << " " << t << " " <<time_remaining << endl;
			t = r[i] * j;
		}
	}
	if (prataMade >= p) {
		//cout<<"possible at "<<min_time<<endl;
		return true;
	}
	else {
		//cout<<"not possible at "<<min_time<<endl;
		return false;
	}
}

int pratamakingtime(int p, int l, int r[]) {
	int s = 0;
	int e = r[0] * (p * (p + 1) / 2);

	int ans = INT_MAX;
	while (s <= e) {
		int mid = (s + e) / 2;
		if (isPossible(p, l, r, mid)) {
			ans = min(mid, ans);
			e = mid - 1;
		}
		else {
			s = mid + 1;
		}
	}
	return ans;
}

int main() {
	int tc;
	cin >> tc;

	while (tc--) {
		int p, l;
		cin >> p >> l;
		int r[10005] = {0};
		for (int i = 0; i < l; i++)
		{
			cin >> r[i];
		}
		//sort(r,r+l);
		cout << pratamakingtime(p, l, r) << endl;
	}
	return 0;
}