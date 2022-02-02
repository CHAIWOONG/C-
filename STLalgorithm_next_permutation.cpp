#include <iostream>
#include <algorithm>
#include <foward_list> 
#include <list>
#include <deque>
#include <stack>
#include <queue>

using namespace std;

// -------------------------------------------------------------------- permutation의 구현 --------------------------------------------------------------------------
// (1) v[i - 1] < v[i]인 i의 최댓값을 찾음. 만약 i가 없다면 0을 반환
// (2) v[i - 1] < v[j]인 j의 최댓값을 찾음. 이러한 j는 [i, en) 범위에 항상 존재함.
// (3) swap(v[i - 1], v[j])
// (4) reverse(v[i] ~ v.back())

template<typename It>
bool NextPermutation(It st, It en) {
	for (It i = en - 1, j = en; i > st; i--) {
		if (*(i - 1) >= *i) continue;
		while (*--j <= *(i - 1));
		swap(*(i - 1), *j);
		reverse(i, en);
		return 1;
	}
	reverse(st, en);
	return 0;
}

template<typename It>
bool PrevPermutation(It st, It en) {
	for (It i = en - 1, j = en; i > st; i--) {
		if (*(i - 1) <= *i) continue;
		while (*--j >= *(i - 1));
		swap(*(i - 1), *j);
		reverse(i, en);
		return 1;
	}
	reverse(st, en);
	return 0;
}

int main()
{	
	// -------------------------------------------------------------------- permutation --------------------------------------------------------------------------
	// std::next_permutation(st, en)
  	// [st, en) 범위의 값을 en - st칸짜리 순열로 볼 때 현재 순열의 바로 다음 순서의 순열로 [st, en) 범위를 채워주는 함수
	// 반환값이 bool로 다음 순열이 존재했다면 1을, 아니라면 0을 반환
	
	// 보통 단순 순열, 조합을 필요로 하면서 효율성을 고려하지 않아도 되는 문제라면 next_permutation을 사용
	// 중복 순열, 중복 조합 등을 필요로 하거나 시간 최적화가 필요한 문제는 백트래킹으로 처리합니다.
  
  	vector<int> v{ 1, 2, 3, 4 };
	do {
		for (auto& i : v) cout << i << ' '; cout << '\n';
	} while (next_permutation(v.begin(), v.end()));
	
	// combination은 순서에 상관없이 수를 선택하는 것을 의미, 선택하는 수의 개수 k가 고정일 때(=nCk)
	// P = { 1, 2, 3, 4 }, k = 3일 때, (1, 2, 3), (1, 2, 4), (1, 3, 4), (2, 3, 4) 이렇게 4개의 조합이 가능
	// 이에 따라서 v = { 0, 1, 1, 1 }과 같이 뒤쪽 k개의 원소를 1로 채운 순열을 만들어서 next_permutation을 사용한다
	// 즉, v에 대한 permutation을 순회하며 v[i] = 1인 P[i]만 골라서 조합을 만들어주면 됩니다.
	
	vector<int> P{ 1, 2, 3, 4 };
	vector<int> v{ 1, 1, 1 ,0 };
	do {
		for (int i = 0; i < 4; i++) if (v[i]) cout << P[i] << ' ';
		cout << '\n';
	} while (prev_permutation(v.begin(), v.end()));
	
	return 0;
	
}
