#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <tuple>
#include <string>
#include <algorithm>

using namespace std;

using ll = long long;
using vb = vector<bool>;
using vvb = vector<vb>;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pii = pair<int, int>;
using vii = vector<pii>;
using pll = pair<ll, ll>;
using vll = vector<pll>;

int n, l;
vvi field;
ll ans;

bool checkRow(int r) {
	{ // all equal
		const auto& z = field[r][0];

		auto isEq = bool{ true };
		for (auto i = 1; i < n; ++i) {
			if (z != field[r][i]) {
				isEq = false;
				break;
			}
		}

		if (isEq) {
			return true;
		}
	}

	{ // put slope
		auto isPut = vb(n, false);
		for (auto i = 0; i < n - 1; ++i) {
			if (1 < abs(field[r][i] - field[r][i + 1])) {
				return false;
			}

			if (field[r][i] - 1 == field[r][i + 1]) {
				auto ct = ll{ 0 };
				for (auto k = i + 1; k < n && !isPut[k]; ++k) {
					if (field[r][k] == field[r][i + 1]) {
						++ct;
					}
					else {
						break;
					}
				}

				if (l <= ct) {
					isPut[i + l] = true;
				}
				else {
					return false;
				}

				continue;
			}

			if (field[r][i] + 1 == field[r][i + 1]) {
				auto ct = ll{ 0 };
				for (auto k = i; 0 <= k && !isPut[k]; --k) {
					if (field[r][k] == field[r][i]) {
						++ct;
					}
					else {
						break;
					}
				}

				if (ct < l) {
					return false;
				}
			}
		}
	}

	return true;
}

bool checkCol(int c) {
	{ // all equal
		const auto& z = field[0][c];

		auto isEq = bool{ true };
		for (auto i = 1; i < n; ++i) {
			if (z != field[i][c]) {
				isEq = false;
				break;
			}
		}

		if (isEq) {
			return true;
		}
	}

	{ // put slope
		auto isPut = vb(n, false);
		for (auto i = 0; i < n - 1; ++i) {
			if (1 < abs(field[i][c] - field[i + 1][c])) {
				return false;
			}

			if (field[i][c] - 1 == field[i + 1][c]) {
				auto ct = ll{ 0 };
				for (auto k = i + 1; k < n && !isPut[k]; ++k) {
					if (field[k][c] == field[i + 1][c]) {
						++ct;
					}
					else {
						break;
					}
				}

				if (l <= ct) {
					isPut[i + l] = true;
				}
				else {
					return false;
				}

				continue;
			}

			if (field[i][c] + 1 == field[i + 1][c]) {
				auto ct = ll{ 0 };
				for (auto k = i; 0 <= k && !isPut[k]; --k) {
					if (field[k][c] == field[i][c]) {
						++ct;
					}
					else {
						break;
					}
				}

				if (ct < l) {
					return false;
				}
			}
		}
	}

	return true;
}

int main() {
	ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	cin >> n >> l;
	field = vvi(n, vi(n));

	for (auto&& rows : field) {
		for (auto&& x : rows) {
			cin >> x;
		}
	}

	ans = 0;

	for (auto r = 0; r < n; ++r) {
		if (checkRow(r)) {
			++ans;
		}
	}

	for (auto c = 0; c < n; ++c) {
		if (checkCol(c)) {
			++ans;
		}
	}

	cout << ans;

	return 0;
}