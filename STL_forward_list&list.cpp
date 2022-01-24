#include <iostream>
#include <algorithm>
#include <foward_list> 
#include <list> 

using namespace std;

int main()
{
	
	//----------------------------------------foward list (single linkled list)-------------------------------------------
    
	foward_list<int> fwd_ist = { 1, 2, 3 }; // 한방향으로만 이동이 가능한 single linkled list

	fwd_list.push_front(0) ; // 연결 리스트는 마지막 원소에 접근할 수 없으므로 맨 앞에 새로운 원소를 삽입한다.

	auto it = fwd_list.begin();
	fwd_list.insert_after(it, 5) ; // it으로 받은 맨 처음 원소 뒤에 5 추가
	                               // 특정 위치의 원소 삽입은 대해당 위치 앞에 원소의 next pointer를 수정해야 되므로 after추가 형식

 	fwd_list.pop_front() ; // 맨 앞에 원소를 삭제
 	
 	auto it = fwd_list.begin();

	fwd_list.erase_after(it) ; // it으로 받은 맨 처음 원소 다음을 삭제
	fwd_list.erase_after(it, fwd_list.end()) ; // 맨앞 원소 다음 부터 맨 마지막 원소까지 삭제
	
	foward_list<int> list12 = { 23,0,1,-3,34,32 };
	list12.sort();     	      // { -3,0,1,23,32,34 }의 오름차순으로 정렬됨 (사용자 정의 타입 원소를 사용하는 경우에는 < 연산자가 정의되어 있다)
	list12.sort(greater<int>()); // { 34,32,23,1,0,-3 }의 내림차순으로으로 정렬됨 (표준으로 제공되는 비교함수 객체 greater에 따라서 > 연산자에 대한 래퍼)
	
	
	foward_list<int> list3 = { 0,1,0,1,-1,10,5,5,10,0 };
	list3.sort();    // { -1,0,0,0,1,1,5,5,10,10 }
	list3.unique();  // { -1,0,1,5,10 } // 인접한 원소에 대해 판단하여 뒤의 원소를 제거
	
	list3.unique([](int a, int b) {return (b-a) < 2; }); // { -1,1,5,10 } 리스트의 특정 원소가 앞 원소보다 2 이상 크지 않으면 삭제
	
	
	//---------------------------------------- list (double linkled list)-------------------------------------------
	
	// 임의의 위치에 있는 원소를 확인/ 변경 O(N)
	// 임의의 위치에 있는 원소를 추가/ 제거 O(1)  
	// -> 임의의 위치에서 원소를 추가하거나 임의 위치의 원소를 제거하는 연산을 많이 해야 할 경우에는 연결 리스트의 사용을 고려
	
	list<int> list = {1,2,3,4,5};

	list.push_front(6); // {6,1,2,3,4,5}
	list.push_back(6);  // {6,1,2,3,4,5,6} 양방향에 대한 접근이 가능

	list.pop_front(); // {1,2,3,4,5,6}
	list.pop_back(); // {1,2,3,4,5} 양방향에 대한 접근이 가능
	
	// insert : 매개변수로 받은 iterator 위치의 앞에 원소를 삽입. O(1)
	// erase : 매개변수로 받은 iterator 위치의 원소를 삭제 후 원래 위치의 다음 원소의 iterator를 반환. O(1)

	//-------------------------------------list.insert(100); 반복자에 대한 지정이 없으므로 오류 발생
	list.insert(next(list.begin()),100);  // {1,100,2,3,4,5} 첫번째 원소 오른쪽에 100 추가
	list.insert(list.begin(),100);   // {100,1,100,2,3,4,5} 첫번째 원소 자리에 100 추가
	
	//--------------------------------------list.insert(list.begin()+3,6); list의 경우 이렇게 하면 오류 발생
    	auto element = next(list.begin(),4); // list의 인덱스 참조는 next함수를 사용하여만 가능 (하나하나 다 접근해서 찾아가야 된다) 
					    // vector의 경우 next 없이 사용 가능 auto element = v1.begin()+4; 
					    // *element는 3
	

	//list = {100,1,100,2,3,4,5}   -------------------------------------------iterator 사용
	auto begin = list.begin(); // 100
	auto it = next(list.begin()); // *it == 1
    	auto it8 = next(list.begin(),-1); // *it8 == 5
	
	auto end = list.end(); // 5
	auto it3 = next(list.end()); // *it3 == 100
	auto it4 = next(list.end(),-1); // *it4 == 5 , end는 list의 마지막 원소의 다음 칸을 가리키는 iterator를 반환.
	auto it5 = next(list.end(),-2); // *it5 == 4
	
	// reverse_iterator 타입의 rbegin(), rend() 도 존재한다
	
	auto it2 = list.insert(it, 10); // { 100,10,1,100,2,3,4,5 } it인 1자리에 10 추가하여 그자리의 it2를 받음 (*it2 == 10, *it == 1)

	it = prev(it); // *it == 10
	it = list.erase(it); // *it == 1, (it가 가르키던 10을 지우고 그자리에 오는 1을 it로 업데이트하여 받음)
	// 삭제의 경우, it는 무효화(invalidated)되기 때문에 *it, it++등으로 사용하면 UB를 발생시키며 일반적으로 it = L.erase(it)으로 사용
	
        cout<< *element<<"\n\n"; 
	// 3 출력
	// list는 vector와 다르게 삽입과 삭제의 동작에서 원소를 실제로 이동할 필요가 없다
	// 반복자의 무효화가 삽입에서 발생하지 않는다 (가리키던 "원소가 삭제되지 않는 이상" 나머지의 원소에 대해서는 그대로 사용이 가능하다)
       	
	
	// --------------------------- Ranged-based for loops를 사용한 출력의 예시 -------------------------------------
	
        for(auto element: list)
	    cout<< element<<" ";        // {100,1,100,2,3,4,5} 
	
	list<int> L = { 3, 1, 2 }; // ------------------------list는 random access iterator가 없기 때문에 std::sort 대신 L.sort()를 사용
	L.sort();
	for (auto& i : L) 
		cout << i << ' '<< '\n'; // 1 2 3
	L.sort(greater<>{});
	for (auto& i : L) 
		cout << i << ' '<< '\n'; // 3 2 1

	return 0;
}
