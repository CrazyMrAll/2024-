#include <cstdio>
#include <algorithm>
#include <cstring>
typedef long long ll;

ll read() {
	ll ans = 0;
	char last = ' ', ch = getchar();
	while (ch < '0' || ch > '9') last = ch, ch = getchar();
	while (ch >= '0' && ch <= '9') ans = ans * 10 + ch - '0', ch = getchar();
	if (last == '-') ans = -ans;
	return ans;
}

int month[15] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
bool isLeapYear(int x) {
	return ((x % 4 == 0) && (x % 100 != 0)) || (x % 400 == 0);
}
int ans, year1, year2, mon1, mon2, day1, day2;
int main() {
	year1 = read(), mon1 = read(), day1 = read();
	year2 = read(), mon2 = read(), day2 = read();
	if (year1 != year2) {
		for (int i = year1 + 1; i < year2; ++i) {
			ans += 365 + isLeapYear(i); 
		}
		for (int m = mon1 + 1; m <= 12; ++m) {
			ans += month[m];
			if (m == 2) ans += isLeapYear(year1);
		}
		ans += month[mon1] - day1;
		for (int m = 1; m < mon2; ++m) {
			ans += month[m];
			if (m == 2) ans += isLeapYear(year2);
		}
		ans += day2;
	} else {
		for (int m = 1; m < mon1; ++m) {
			ans -= month[m];
			if (m == 2) ans -= isLeapYear(year1);
		}
		ans -= day1;
		for (int m = 1; m < mon2; ++m) {
			ans += month[m];
			if (m == 2) ans += isLeapYear(year2);
		}
		ans += day2;
	}
	printf("%d days\n", ans);
	return 0;
}