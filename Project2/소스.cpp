#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;


long long h[100001];

long long solve(int left, int right) {
	if (left == right)return h[left];
	int mid = (left + right) / 2;
	long long ret = max(solve(left, mid), solve(mid + 1, right));
	int lo = mid, hi = mid + 1;
	long long height = min(h[lo], h[hi]);
	ret = max(ret, height * 2);
	while (left < lo || hi < right) {
		if (hi < right && (lo == left || h[lo - 1] < h[hi + 1])) { 
			hi++;
			height = min(height, h[hi]);
		}
		else {
			lo--;
			height = min(h[lo],height);
		}
		ret = max(ret, (hi - lo + 1)* height);
	}
	return ret;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	while (true) {
		long long n;
		cin >> n;
		if (n == 0)break;
		memset(h, 0, sizeof(h));
		for (int i = 0; i < n; i++) {
			long long tmp;
			cin >> tmp;
			h[i] = tmp;
		}
		cout << solve(0, n - 1) << '\n';
	}
}