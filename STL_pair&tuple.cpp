#include <iostream>
#include <algorithm>
#include <foward_list> 
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;
using pii = pair<int, int>;
using tii = tuple<int, int, int>;

int main()
{
	pii a; // a = { 0, 0 }
	pii b(1, 2); // b = { 1, 2 };
	pair<string, double> c{ "HI", 3.14 }; // c = { "HI", 3.14 }

	cout << a.first << ' ' << b.second << '\n';
	cout << c.first << ' ' << c.second << '\n';

	vector<pii> v;
	v.push_back(a);
	v.push_back({ 3, 4 });
	v.push_back(make_pair(5, 6));

	for (const auto& [a, b] : v) cout << a << ' ' << b << '\n';
	return 0;

}
