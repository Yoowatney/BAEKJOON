#include <bits/stdc++.h>
 
using namespace std;
 
int N;
int alpha[26];
vector <string> V;
 
bool cmp(int A, int B)
{
    if (A > B)
		return (true);
    return (false);
}
 
void input()
{
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        string s;
		cin >> s;
        V.push_back(s);
    }
}
 
void solution()
{
    for (int i = 0; i < N; i++)
    {
        string S = V[i];
        int len = S.length();
        int pow = 1;
 
        for (int j = len - 1; j >= 0; j--)
        {
            int tmp = S[j] - 'A';
            alpha[tmp] = alpha[tmp] + pow;
            pow = pow * 10;
        }
    }
    sort(alpha, alpha + 26, cmp);
//	for (int i = 0; i < 15; i++)
//	{
//		cout << alpha[i] << ' ';
//	}
//	return ;
    int ans = 0;
	int i = 0;
	for (int num = 9; num >= 0; num--)
	{
		ans = ans + (alpha[i] * num);
		i++;
	}
	cout << ans << '\n';

//		int num = 9;
//		ans = 0;
//    for (int i = 0; i < 26; i++)
//    {
//        if (alpha[i] == 0)
//			break;
//        ans = ans + (alpha[i] * num);
//        num--;
//    }
//    cout << ans << '\n';
}
 
void solve()
{
    input();
    solution();
}
 
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
 
    solve();
}
