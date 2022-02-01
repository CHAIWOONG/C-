#include <iostream>
#include <algorithm>
#include <foward_list> 
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

int main()
{	
	// ---------------------------------------------------------------- priority queue (heap) ----------------------------------------------------------------
	
	vector<int> v = { 3, 1, 4, 1, 5, 9, 2 };
	int w[5] = { 1, 2, 3, 4, 5 };
	string s = "jinhan814";

	sort(v.begin(), v.end());
	sort(w, w + 5, greater<>{});
	sort(s.begin(), s.end());

	for (auto& i : v) cout << i << ' '; cout << '\n'; // 1 1 2 3 4 5 9
	for (auto& i : w) cout << i << ' '; cout << '\n'; // 5 4 3 2 1
	cout << s << '\n'; // 148ahijnn
	
	return 0;
	
}
