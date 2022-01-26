#include <iostream>
#include <algorithm>
#include <set>
#include <map>


using namespace std;

int main()
{	
	// ------------------------------------------------------------------------- set ------------------------------------------------------------------------
	
	// set, map은 자가 균형 이진 탐색 트리(BBST, self-balancing binary search tree)로 구현되어있는 자료구조로 대소관계가 정의된 자료형의 삽입, 삭제, 검색을 O(logn)에 처리할 수 있다
	// set, map은 1)원소의 삽입, 삭제가 빈번하게 일어나면서 2)원소의 정렬 상태를 유지해야 하고, 3)특정 원소를 검색하거나 수정할 필요가 있을 때 주로 사용됩니다. 
	// set과 map의 차이점은 set은 컨테이너 내부의 원소들을 저장만 하고, 
  // map은 원소(key)와 원소에 대응되는 value를 같이 저장한다는 것이 있습니다. 
  // set은 보통 vector처럼 원소만 저장할 때, 
  // map은 (key, val) pair를 순서대로 저장하면서 M[key] = val와 같이 key로 val을 접근할 때 사용합니다.
  
  // set, map은 같은 원소가 중복될 수 없습니다. 
	
	return 0;
	
}
