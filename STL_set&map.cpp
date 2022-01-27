#include <iostream>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

int main()
{	
	// set, map은 자가 균형 이진 탐색 트리(BBST, self-balancing binary search tree)로 구현되어있는 자료구조로 대소관계가 정의된 자료형의 삽입, 삭제, 검색을 O(logn)에 처리 가능
	// set, map은 1)원소의 삽입, 삭제가 빈번하게 일어나면서 2)원소의 정렬 상태를 유지해야 하고, 3)특정 원소를 검색하거나 수정할 필요가 있을 때 주로 사용 
	// set, map은 같은 원소가 중복될 수 없음  (중복된 원소를 사용하고 싶다면 multiset, multimap을 이용)
	// set<int> S = { 1, 1, 2, 3 }으로 선언하면 S = { 1, 2, 3 }
	// map은 같은 key값을 갖는 여러 { key, val }쌍이 존재할 수 없다
	
	// set은 컨테이너 내부의 원소들을 저장 
	// map은 (key, val) pair를 순서대로 저장하여 M[key] = val와 같이 key로 val을 접근할 때 사용
	
	
	// ------------------------------------------------------------------------- set & map------------------------------------------------------------------------
	set<int> S; // 비어있는 set을 생성
	set<int> S(v.begin(), v.end()); // 다른 컨테이너에서 시작 iterator와 끝 iterator를 받아와서 [st, en) 범위의 원소를 갖는 set을 생성
	set<int, Compare> S(cmp); // 비교 자료형을 템플릿에 넣어준 뒤 비교 함수 객체를 매개변수로 넣어줘서 set의 정렬 기준으로 이용 (단, cmp의 자료형은 Compare)
	set<int> S{ 1, 2, 3 }; // 또는 set<int> S = { 1, 2, 3 };
	
	map<string, int> M;
	map<string, int> M(v.begin(), v.end()); // 단, v의 원소의 자료형은 pair<string, int>
	map<string, int, Compare> M(cmp); // 단, cmp의 자료형은 Compare, Compare는 greater<string>
	
	//set, map은 priority_queue와 달리 템플릿 인자에 Container 부분이 없어서 그냥 비교 자료형만 넣으면 된다
	
// 	template<typename T>
// 	struct Cmp {
// 		bool operator() (const T& a, const T& b) const {
// 			if (abs(a) != abs(b)) return abs(a) < abs(b);
// 			return a > b;
// 		}
// 	};
	
	set<int, greater<int>> S1 = { 1, 2, 3, 4 }; // descending order
	for (auto& i : S1) cout << i << ' '; cout << '\n'; // 4 3 2 1

	set<int, Cmp<int>> S2 = { 3, -1, -4, 1, 5, 1 }; // custom compare function
	for (auto& i : S2) cout << i << ' '; cout << '\n'; // 1, -1, 3, -4, 5

	// ------------------------------------------------------------------------- set 멤버함수------------------------------------------------------------------------
	
	set<int> S = { 1, 2 }; // initializer_list
	
	// insert(val) : val을 삽입, val을 가리키는 iterator와 val의 삽입 여부(bool)를 pair로 반환 ( O(logn) )
	auto [it1, flag1] = S.insert(2); // S = { 1, 2 }, *it1 == 2, flag1 == 0
	auto [it2, flag2] = S.insert(3); // S = { 1, 2, 3 }, *it2 == 3, flag2 == 1
	
	// erase(it) : 매개변수로 받은 iterator 위치의 원소를 삭제, 원래 위치의 다음 원소의 iterator를 반환. O(logn)
	it1 = S.erase(it1); // S = { 1, 3 }, *it1 == 3
	
	//erase(val) : 컨테이너 내의 매개변수로 받은 val을 모두 삭제, 삭제한 원소의 개수를 반환. O(logn)
	auto cnt = S.erase(3); // S = { 1 }, cnt == 1
	
	cout << "S.size() : " << S.size() << '\n'; // 1  (크기를 size_t 자료형으로 반환)
	cout << "S.empty() : " << S.empty() << '\n'; // 0 (비어있는지 여부를 bool 자료형으로 반환)
	S.clear(); // 모든 원소를 삭제

	for (auto& i : { 3, 1, 4, 1, 5 }) S.insert(i); // S = { 1, 3, 4, 5 }
	for (auto& i : S) cout << i << ' '; cout << '\n'; // 1 3 4 5
	
	// count : set, map 내부의 val의 개수를 반환 (multiset, multimap이 아니라면 있으면 1, 없으면 0) O(logn)
	if (S.count(2)) cout << "found 2" << '\n'; // x
	if (S.count(3)) cout << "found 3" << '\n'; // o

	auto lo = S.lower_bound(3); // *lo == 3, *prev(lo) < 3 <= *lo (lower_bound를 반환 O(logn))
	auto hi = S.upper_bound(3); // *lo == 4, *prev(lo) <= 3 < *lo (upper_bound를 반환. O(logn))
	
	
	
	// ------------------------------------------------------------------------- map 멤버함수------------------------------------------------------------------------
	
	map<string, int> M;
	
	M["abc"] = 3; // == M.insert({ "abc", 3 })
	cout << M["abc"] << '\n'; // 3
	M["abc"] = 4;
	cout << M["abc"] << '\n'; // 4
	
	// erase(it) : 매개변수로 받은 iterator 위치의 원소를 삭제, 원래 위치의 다음 원소의 iterator를 반환. O(logn)
	auto it = M.erase("abc"); // M = { }, it == M.end()

	//erase(val) : 컨테이너 내의 매개변수로 받은 val을 모두 삭제, 삭제한 원소의 개수를 반환. O(logn)
	M["hi"] = 123; // M = { { "hi", 123 } }
	auto cnt = M.erase("hi"); // M = { }, cnt == 1

	cout << "M.size() : " << M.size() << '\n'; // 0
	cout << "M.empty() : " << M.empty() << '\n'; // 1
	M.clear();

	vector<string> s{ "ab", "cde", "fghi" };
	vector<int> v{ 3, 1, 4 };
	for (int i = 0; i < 3; i++) M[s[i]] = v[i];
	for (auto& [a, b] : M) cout << '(' << a << ',' << b << ')' << ' '; cout << '\n'; // (ab,3) (cde,1) (fghi,4)

	// count : set, map 내부의 val의 개수를 반환 (multiset, multimap이 아니라면 있으면 1, 없으면 0) O(logn)
	if (M.count("abc")) cout << "found abc" << '\n'; // x
	if (M.count("cde")) cout << "found cde" << '\n'; // o
	
	map<int, int> M;
	cout << M.count(3) << '\n'; // 0
	M[3];
	cout << M.count(3) << '\n'; // 1
	
	return 0;
	
}
