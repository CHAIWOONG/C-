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
	// ------------------------------------------------------------------------- stack ------------------------------------------------------------------------
	
	// stack은 임의 위치의 접근, 수정을 제공하지 않으며, 마지막 위치의 접근, 삽입, 삭제에만 특화된 자료형
	// std::deque를 기본 컨테이너로 사용
	// 원소들을 순서대로 집어넣거나 가장 최근에 들어온 원소를 확인할 때 주로 사용
	// stack 대신 vector를 사용해도 성능 차이는 거의 없으며 기능을 더 다양하게 사용할 수 있기 때문에 결론은 개인 취향에 맞게 이용하면 되지만, 직관적 의미 차이 발생 가능
	stack<int> s;

	stack<int, vector<int>> stk1; 
	stack<int, list<int>> stk2;
	
	// 모든 연산(원소 확인, 추가, 제거)의 시간복잡도는 O(1)
	for (int i = 1; i <= 5; i++) s.push(i);             // s = [1, 2, 3, 4, 5(top)]
	while (!s.empty()) {
		cout << s.size() << ' ' << s.top() << '\n'; 
		s.pop(); }  				   // pop의 반환값은 void이며 마지막 원소가 아님
	
	// --------------------------------------------------------------------------- queue -------------------------------------------------------------------
	
	// std::deque를 기본 로 사용
	queue<int> q;
	
	// 모든 연산(원소 확인, 추가, 제거)의 시간복잡도는 O(1)
	for (int i = 1; i <= 5; i++) q.push(i); 	  // q = [1(front), 2, 3, 4, 5(back)]
	while (!q.empty()) {
		cout << q.size() << ' ' << q.front() << '\n';   // front : 가장 먼저 들어온 원소를 reference로 반환. O(1)
		q.pop();					// back : 가장 마지막에 넣은 원소를 reference로 반환. O(1) (잘 사용하진 않음)
								// pop : 반환값은 void이며 front()가 아님
	}
	// [] 연산자나 iterator가 없기 때문에 front(), back() 이외의 원소에는 접근할 수 없다
	// 큐가 비어있는데 front나 back이나 pop을 호출하면 런타임에러가 발생
	
	
	return 0;
	
}
