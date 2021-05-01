#include <bits/stdc++.h>

using namespace std;

int main()
{
	vector < vector<char> > vec2d;
	vector <char> vec1;
	vector <char> vec2;
	vector <string> sv;
	string name;

	int n;

	cout << "이름 입력\n";
	for (int i = 0; i < 2; i++)
	{
		cout << i + 1 << ">>";
		getline(cin, name);
		sv.push_back(name);
	}
	for (auto e : sv)
	{
		cout << e << '\n';
	}
//
//	vec1.push_back('a');
//	vec1.push_back('b');
//	vec2.push_back('c');
//	vec2d.push_back(vec1);
//	vec2d.push_back(vec2);
//	cout << "vec2d.size(): " << vec2d.size() << '\n';
//	for (auto e : vec2d)
//	{
//		for (int i = 0; i != e.size(); i++)
//			cout << e[i];
//		cout << '\n';
//	}
}
