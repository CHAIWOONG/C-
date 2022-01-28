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
	
	// vector, stack, queue, deque가 연속된 위치에 일렬로 데이터를 세워둔 것과 달리 priority_queue는 이진 트리 구조를 갖는 heap을 이용해서 데이터를 저장
	// complete binary tree (완전 이진 트리)
	// 1) 원소를 추가하는 연산이 있으면서  (O(logn)의 시간 복잡도)
	// 2) 우선순위 큐 내의 원소 중 "최댓값(또는 최솟값)"을 빠르게 구해야 하고 (O(1)의 시간 복잡도)
	// 3) 해당 원소를 삭제하는 연산이 있는 경우 주로 사용  (원소의 제거는 "최소/ 최대 원소"에 대해서만 가능) (O(logn)의 시간 복잡도)
	// 이때 최댓값, 최솟값 중 하나만을 구할 수 있으며(기본적으로는 Max heap) 이외의 값들은 정렬되어있지 않고, 접근할 수도 없다
	// ------->  최댓값(최솟값) 중 하나만을 관리할 때 유용 
	// std::vector를 기본 컨테이너로 사용
	// 트리의 데이터를 배열을 이용하여 저장하게 되므로 다른 노드를 가리키는 포인터를 저장할 필요가 없어서 메모리 사용에서 효율적
	// 부모의 노드에서 자식의 노드로 인덱스 계산을 통하여 이동 가능 (부모 : i(1 부터) ------ 자식 : 2*i or 2*i+1) (자식 : i ---------- 부모(i/2))
	
	// 기본형: priority_queue<T, vector<T>, less<T>>
	template <typename T>
	priority_queue<T> pq;
	priority_queue<T> pq(v.begin(), v.end()); 
	priority_queue<T, vector<T>, Cmp> pq(cmp); 
	priority_queue<T, vector<T>, Cmp> pq(v.begin(), v.end(), cmp);
	// priority_queue의 템플릿 인자는 <자료형, 컨테이너(default값인 vector를 이용), 비교 자료형(Compare = less<T>)>
	// 단, cmp의 자료형은 Cmp.
	// 비교 자료형(cmp)을 템플릿에 넣어준 뒤 선언된 비교 연산자를 매개변수로 넣어줘서 "우선순위 큐의 비교함수"로 이용
	// 이때 Cmp가 ()연산자가 정의된 구조체(= Functor)라면 알아서 자료형에 정의된 ()연산자를 이용해서 매개변수를 생략해도 되지만, 
	// 람다식(또는 전역함수)이라면 타입만으로 ()연산자를 알아서 정의할 수 없기 때문에 매개변수로 객체를 넣어줘야 한다
	
	// ------------------------------------------------------------------max_heap---------------------------------------------------------------------
	priority_queue<int> pq1; // max_heap  (Compare =less<T>에서 자료형의 < 연산자를 기준으로 가장 큰 값이 pq.top()에 위치)
	for (auto& i : { 3, 1, 4, 1, 5 }) pq1.push(i);// pq1 = [5(top), ...]
	while (!pq1.empty()) {
		cout << pq1.size() << ' ' << pq1.top() << '\n';  // top: 최댓값을 반환 (O(1)) (const T& 자료형으로 반환. 따라서 얕은 복사가 일어나며 수정은 불가능)
		pq1.pop(); }
	cout << '\n';
	
	// ------------------------------------------------------------------min_heap---------------------------------------------------------------------
	priority_queue<int, vector<int>, greater<int>> pq2; // min_heap (비교 자료형에 표준으로 제공되는 비교함수 객체 greater에 따라서 > 연산자에 대한 래퍼 제공)
	for (auto& i : { 3, 1, 4, 1, 5 }) pq2.push(i); // pq2 = [1(top), ...]
	while (!pq2.empty()) {
		cout << pq2.size() << ' ' << pq2.top() << '\n';
		pq2.pop(); }
	//top(), pop()을 빈 PQ에서 호출하는 것은 UB이며 일반적으로 런타임 에러를 발생
	
	// ----------------------------------------------------pair 를 사용한 priority queue (MaxHeap, MinHeap) -------------------------------------------------------------
	priority_queue<pair<int,int>> temp; // ---------------------------------------------------// ******pair를 사용한 maxHeap의 정의 
	temp.push(make_pair(3,100));
	temp.push(make_pair(-2,140));
	temp.push(make_pair(3,50));
	temp.push(make_pair(49,12));
	temp.push(make_pair(300,-20));
	int sz = temp.size();
	for(int i=0;i<sz;i++){
		cout << temp.top().first << ',' << temp.top().second << '\n';
		temp.pop();
	}
	// pair의 first에 대해서 비교한 후 같은 것에 대해 second에 대해서 비교함
	// (300,-20) (49,12) (3,100) (3,50) (-2,140)
	
	priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq; // -----------------******pair를 사용한 minHeap의 정의
	
	//------------------------------------------------- 비교함수를 직접 만들어 줘야하는 경우
	// pair 예제에서 첫 번째 값은 큰 순, 두 번째 값은 작은 순으로 정렬하고 싶은 경우
	
	struct cmp {
          bool operator()(pair<int, int>&a, pair<int, int>&b) { //연산자 오버로딩
              if (a.first == b.first) {
                  return a.second > b.second;
              }
              else {
                  return a.first < b.first;
              }
          }
      };

	priority_queue<pair<int,int>,vector<pair<int,int>>, cmp> pq;
	pq.push({ 1,2 });
	pq.push({ 2,2 });
	pq.push({ 2,3 });
	pq.push({ 2,1 });
	pq.push({ 1,1 });

	while (!pq.empty())
	{
		cout << pq.top().first << pq.top().second << '\n';
		pq.pop();
	}
	
	// 구조체를 pq에 저장하는 경우
	
	struct Info
	{
		int x, y;
	};

	struct cmp {
		bool operator()(Info &a, Info &b) {
			if (a.x == b.x) {
				return a.y < b.y;
			}
			return a.x > b.x;
		}
	};
	
	priority_queue<Info,vector<Info>, cmp > pq;
	pq.push({ 1,2 });
	pq.push({ 2,2 });
	pq.push({ 2,3 });
	pq.push({ 2,1 });
	pq.push({ 1,1 });

	while (!pq.empty())
	{
		cout << pq.top().x << pq.top().y << '\n';
		pq.pop();
	}
	
	return 0;
	
}
