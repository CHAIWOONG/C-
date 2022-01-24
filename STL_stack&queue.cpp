#include <iostream>
#include <algorithm>
#include <foward_list> 
#include <list>
#include <deque>

using namespace std;

int main()
{
    
	// 벡터와 비슷하지만 앞,뒤쪽으로 모두 확장할 수 있다
    	deque<int> dq = {1,2,3,4,5};
    
   	dq.push_front(0); //{0,1,2,3,4,5}
    	dq.push_back(6); //{0,1,2,3,4,5,6}
    
    	dq.insert(dq.begin()+2, 10); //{0,1,10,2,3,4,5,6}
    
    	dq.pop_back(); //{0,1,10,2,3,4,5}
    	dq.pop_front(); //{1,10,2,3,4,5}
    
    	dq.erase(dq.begin()+1); //{1,2,3,4,5}
    	dq.erase(dq.begin()+3, dq.end()); //{1,2,3}
    
    
    	cout<<dq[1]<<"\n";
   
   	return 0;
	
}
