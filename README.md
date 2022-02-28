# Cpp
___

- std::priority_queue
```c++

#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

template<typename T>
struct _less {
	inline bool operator() (const T& lhs, const T& rhs) const {
		return lhs < rhs;
	}
};

template<typename T, typename f = _less<T>>
class Priority_queue {
public:
	/* constructor */
	Priority_queue() { _arr.push_back(T()); }

	/* methods */
	void push(const T& val) {
		_arr.push_back(val);
		size_t child = _arr.size() - 1;
		size_t parent = child / 2;
		while (child > 1 && cmp(_arr[parent], _arr[child])) {
			swap(_arr[parent], _arr[child]);
			child = parent;
			parent = child / 2;
		}
	}
	void pop() {
		assert(!empty());
		swap(_arr[1], _arr.back());
		_arr.pop_back();
		size_t parent = 1;
		size_t child = parent * 2;
		if (child + 1 < _arr.size() && cmp(_arr[child], _arr[child + 1])) child++;
		while (child < _arr.size() && cmp(_arr[parent], _arr[child])) {
			swap(_arr[parent], _arr[child]);
			parent = child;
			child = parent * 2;
			if (child + 1 < _arr.size() && cmp(_arr[child], _arr[child + 1])) child++;
		}
	}
	inline T& top() { assert(!empty()); return _arr[1]; }
	inline size_t size() { return _arr.size() - 1; }
	inline bool empty() { return _arr.size() <= 1; }

private:
	vector<T> _arr;
	f cmp;
};

//BOJ 1927
int main() {
	fastio;
	int n; cin >> n;
	Priority_queue<int, greater<int>> PQ;
	while (n--) {
		int t; cin >> t;
		if (!t) {
			cout << (PQ.empty() ? 0 : PQ.top()) << '\n';
			if (!PQ.empty()) PQ.pop();
		}
		else PQ.push(t);
	}
}
