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
	// --------------------------------------------------------------------sort()--------------------------------------------------------------------------
	// 기본은 오름차순 정렬
	// sort(st, en, cmp = less<>{})의 인자로 구현
	// list, stack, queue와 같이 v.begin() + i 등의 연산이 불가능한 container는 std::sort를 사용할 수 없다
	
	vector<int> v = { 3, 1, 4, 1, 5, 9, 2 };
	int w[5] = { 1, 2, 3, 4, 5 };
	string s = "hello";

	sort(v.begin(), v.end());
	//sort(v.rbegin(), v.rend()); // reverse iterator를 사용하여 ++해도 감소하므로 내림 차순으로 정렬
	sort(w, w + 5, greater<>{}); // a > b를 리턴하는 greater<> functor를 이용하여 내림 차순으로 정렬
	sort(s.begin(), s.end());

	for (auto& i : v) cout << i << ' '; cout << '\n'; // 1 1 2 3 4 5 9
	for (auto& i : w) cout << i << ' '; cout << '\n'; // 5 4 3 2 1
	cout << s << '\n'; // ehllo
	
	
	// stable_sort
	
	// partial_sort
	
	// nth_element
	
	return 0;
	
}
