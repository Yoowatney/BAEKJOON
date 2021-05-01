#include <bits/stdc++.h>

using namespace std;

int main()
{
	int base, power, mod;
	int ans = 1;

	cin >> base >> power >> mod;

	ans = pow(base, power);
	ans = ans % 12;
//	for (int i = 0; i < pow; i++)
//	{
//		ans *= base;
//		ans = ans % mod;
//	}
	cout << ans;
}
