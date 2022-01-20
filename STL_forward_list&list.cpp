#include <iostream>
#include <algorithm>
#include <foward_list> 

using namespace std;

int main()
{
    
	foward_list<int> fwd_ist = { 1, 2, 3 }; // 한방향으로만 이동이 가능한 single linkled list
	

	fwd_list.push_front(0) ; // 연결 리스트는 마지막 원소에 접근할 수 없으므로 맨 앞에 새로운 원소를 삽입한다.
	

	auto it = fwd_list.begin();

	fwd_list.insert_after(it, 5) ; // it으로 받은 맨 처음 원소 뒤에 5 추가
	                               // 특정 위치의 원소 삽입은 대해당 위치 앞에 원소의 next pointer를 수정해야 되므로 after추가 형식
	
	
 	fwd_list.pop_front() ; // 맨 앞에 원소를 삭제
 	
 	auto it = fwd_list.begin();

	fwd_list.erase_after(i) ; // it으로 받은 맨 처음 원소 다음을 삭제
	fwd_list.erase_after(it, fwd_list.end()) ; // 맨앞 원소 다음 부터 맨 마지막 원소까지 삭제

	
	
	
}
