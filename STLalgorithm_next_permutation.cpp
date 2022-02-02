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
	// -------------------------------------------------------------------- permutation --------------------------------------------------------------------------
	// std::next_permutation(st, en)
  // [st, en) 범위의 값을 en - st칸짜리 순열로 볼 때 현재 순열의 바로 다음 순서의 순열로 [st, en) 범위를 채워주는 함수
  
  vector<int> v{ 1, 2, 3, 4 };
	do {
		for (auto& i : v) cout << i << ' '; cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
	
	return 0;
	
}
