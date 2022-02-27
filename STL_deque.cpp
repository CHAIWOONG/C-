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
<<<<<<< HEAD

    // stack은 임의 위치의 접근, 수정을 제공하지 않으며, 마지막 위치의 접근, 삽입, 삭제에만 특화된 자료형
    // 원소들을 순서대로 집어넣거나 가장 최근에 들어온 원소를 확인할 때 주로 사용

    deque<int> dq = { 1,2,3,4,5 };

    dq.push_front(0); //{0,1,2,3,4,5}
    dq.push_back(6); //{0,1,2,3,4,5,6}

    dq.insert(dq.begin() + 2, 10); //{0,1,10,2,3,4,5,6}

    dq.pop_back(); //{0,1,10,2,3,4,5}
    dq.pop_front(); //{1,10,2,3,4,5}

    dq.erase(dq.begin() + 1); //{1,2,3,4,5}
    dq.erase(dq.begin() + 3, dq.end()); //{1,2,3}


    cout << dq[1] << "\n";

    return 0;
=======
	// 벡터와 비슷하지만 앞,뒤쪽으로 모두 확장할 수 있다 (double ended queue라는 느낌보다는 vector랑 비슷)
	// 단일 메모리 청크가 아닌 여러개의 메로리 청크를 사용한다

	deque<int> dq = { 1,2,3,4,5 };

	// "시작 위치와 마지막 위치"의 삽입, 삭제를 O(1)에 처리
	// 일반적으로 연속된 자료에서 front(), back() 위치의 삽입, 삭제가 여러 번 일어날 때 사용
	// insert, erase의 시간복잡도는 O(n)

	dq.push_front(0); //{0,1,2,3,4,5}
	dq.push_back(6); //{0,1,2,3,4,5,6}

	dq.insert(dq.begin() + 2, 10); //{0,1,10,2,3,4,5,6} 

	dq.pop_back(); //{0,1,10,2,3,4,5}
	dq.pop_front(); //{1,10,2,3,4,5}

	dq.erase(dq.begin() + 1); //{1,2,3,4,5}
	dq.erase(dq.begin() + 3, dq.end()); //{1,2,3}

	// ------------------------------------------ 원소의 접근--------------------------------------------
	deque<int> dq = { 1,2,3,4,5 };

	cout << dq[1] << "\n";           // 2 덱은 vector와 마찬가지로 [] operator를 통한 원소의 접근이 가능
	cout << dq.front() << "\n";      // 1 dq[0]을 reference로 반환. O(1)
	cout << dq.back() << "\n";c      // 5 dq[n - 1]을 reference로 반환. O(1)

	// begin : deque의 첫 번째 원소를 가리키는 iterator를 반환.
	//  end : deque의 마지막 원소의 "다음 칸" 을 가리키는 iterator를 반환.
	for (auto it = dq.begin(); it != dq.end(); it++) cout << *it << ' '; cout << '\n'; // 1 2 3 4 5
	for (auto it = dq.rbegin(); it != dq.rend(); it++) cout << *it << ' '; cout << '\n'; // 2 1 0

	// 연속된 메모리 상에 존재하지 않기 때문에 cache hit rate가 떨어져 vector에 비해 느림
	// 연속된 메모리 상에 존재하지 않기 때문에 원소들을 가리키는 포인터 간의 연산이 불가능 (단, iterator 간의 연산은 가능하다)
	return 0;
>>>>>>> acc4ae9573e9f993020e6736e61f2b4939910a39

}
