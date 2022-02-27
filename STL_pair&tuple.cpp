#include <iostream>
#include <algorithm>
#include <foward_list> 
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;
using pii = pair<int, int>; // 자주 사용하는 조합은 using을 이용해 별칭을 만듦
using tii = tuple<int, int, int>;

int main()
{
	// ----------------------------------------------------------------pair------------------------------------------------------------------------
	pii a; // a = { 0, 0 }
	pii b(1, 2); // b = { 1, 2 };
	pair<string, double> c{ "HI", 3.14 }; // c = { "HI", 3.14 }

	cout << a.first << ' ' << b.second << '\n';
	cout << c.first << ' ' << c.second << '\n';

	vector<pii> v;
	v.push_back(a);
	v.push_back({ 3, 4 }); //  직접 삽입
	v.push_back(make_pair(5, 6)); // make_pair() 함수 사용
	
	// 정렬 기준은 first를 먼저 비교하고, first가 같다면 second를 비교
	pii a1 = { 4, 2 };
	pii b1 = { 1, 3 };
	cout << (a1 < b1) << '\n'; // 0

	// 구조적 바인딩(structured binding)을 이용하여 접근이 가능
	// 값의 수정이 필요하다면 auto&와 같이 reference로 받아옴
	// 값의 얕은 복사가 필요하지만 수정은 필요없다면 const auto&와 같이 const reference로 값
	
	for (const auto& [a, b] : v) cout << a << ' ' << b << '\n';
	
	// ----------------------------------------------------------------tuple------------------------------------------------------------------------
	tii a; // a = { 0, 0, 0 }
	tii b(1, 2, 3); // b = { 1, 2, 3 }
	tuple<int, double, string> c = { 123, 3.14, "HI" }; // c = { 123, 3.14, "HI" }
	
	// pair의 first, second같은게 없어서 0, 1, 2, ...번째 값에 접근할 때 get<i>(a)와 같이 사용
	cout << get<0>(a) << ' ' << get<1>(b) << ' ' << get<2>(c) << '\n'; // 0 2 HI

	vector<tii> v;
	v.push_back(a);
	v.push_back({ 1, 2, 3 });
	v.push_back(make_tuple(4, 5, 6));
	
	// 구조적 바인딩(structured binding)을 이용하여 접근이 가능
	for (const auto& [a, b, c] : v) cout << a << ' ' << b << ' ' << c << '\n';
	
	return 0;
}
