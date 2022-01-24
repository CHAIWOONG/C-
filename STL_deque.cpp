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

}
