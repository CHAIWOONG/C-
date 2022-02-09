#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int binarysearch(int target){
        int st = 0;
        int en = n-1;

        while(st <= en){
          int mid = (st+en)/2;

          if(a[mid] < target)  // 타겟 보다 mid 가 작으면 start의 index를 재설정
            st = mid+1;
          else if(a[mid] > target) // 타겟 보다 mid 가 크면 end의 index를 재설정
            en = mid-1;
          else                     // 타겟과 mid 가 같으면 발견 한 것이므로 true를 return 
            return 1;
        }
        return 0; // st > en일 경우 while문을 탈출
}

int main(void) {
        
        // 이분탐색은 정렬되어 있는 배열에서 특정 데이터를 찾기 위해 모든 데이터를 순차적으로 확인하는 대신 탐색 범위를 절반으로 줄여가며 찾는 탐색 방법
        
        // ------------------------------------------------------------------  binary_search 구현 --------------------------------------------------------------------------

        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);   // ******** 이분 탐색 전에, 먼저 정렬을 실시한 다음 사용해야 런타임 오류가 발생하지 않는다.

        int m;
        cin >> m;

        while(m--){
                int t;
                cin >> t;
                cout << BinarySearch(t) << '\n';        // 직접 구현한 binary search 함수를 사용 
        }
  
        // -------------------------------------------------------------------- STL binary_search() --------------------------------------------------------------------------------
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n);   // ******** 이분 탐색 전에, 먼저 정렬을 실시한 다음 사용해야 런타임 오류가 발생하지 않는다.

        int m;
        cin >> m;

        while(m--){
                int t;
                cin >> t;
                cout << binary_search(a, a+n, t) << '\n';
        }

        const int n = 5;
        vector<int> v{ 1, 2, 3, 3, 5 };
        cout << binary_search(v.begin(), v.end(), 3) << '\n';   // 1  ( 이분 탐색으로 확인하여 해당 값이 존재하면 1 )  
        cout << binary_search(v.begin(), v.end(), 4) << '\n';   // 0  ( 이분 탐색으로 확인하여 해당 값이 존재하지 않으면 0 )

    
        // ------------------------------------------------------ STL upper_bound() & lower_bound() --------------------------------------------------------------------------
        // lower_bound, upper_bound는 정렬된 배열에서 특정 값의 위치, 개수 등을 O(logn)에 구하는데 사용할 수 있는 STL 함수
        
        const int n = 5;
        vector<int> v{ 1, 2, 3, 3, 4 };
        auto lo = lower_bound(v.begin(), v.end(), 3);  // lower_bound(v, v + n, x) := v[i - 1] < x <= v[i]인 i를 반환 (v[i] >= x인 i의 최솟값과 동치)
        auto hi = upper_bound(v.begin(), v.end(), 3);  // upper_bound(v, v + n, x) := v[i - 1] <= x < v[i]인 i를 반환 (v[i] > x인 i의 최솟값과 동치)
        cout << lo - v.begin() << '\n'; // 2 (3이 처음 나오는 index를 iterator로 반환)
        cout << hi - v.begin() << '\n'; // 4 (3이 처음으로 나오지 않는 index를 iterator로 반환)
        
        auto lo1 = lower_bound(v.begin(), v.end(), 3);
	auto hi1 = upper_bound(v.begin(), v.end(), 3);
        cout << hi1 - lo1 << '\n'; // 2 ----------------------------([3, 3] 범위의 수의 개수) = O(logn)에 배열 내 3이 나오는 개수를 찾아낼 수 있다 (BOJ_10816)
        
        auto lo2 = lower_bound(v.begin(), v.end(), 2);
	auto hi2 = upper_bound(v.begin(), v.end(), 3);
	cout << hi2 - lo2 << '\n'; // 3 ([2, 3] 범위의 수의 개수) ------ [l, r] 범위의 수의 개수도 O(logn)에 구할 수 있다
        // upper_bound는 마지막 3의 다음 칸을, lower_bound는 처음으로 등장하는 2를 반환
        
        // ------------------------------------------------------------------ STL equal_range --------------------------------------------------------------------------------
        
        vector<int> v{ 1, 2, 3, 3, 4 };
	auto [lo, hi] = equal_range(v.begin(), v.end(), 3);  // equal_range(v, v + n, x)는 lower_bound(v, v + n, x), upper_bound(v, v + n, x)를 pair로 반환
	cout << hi - lo << '\n'; // 2
        
        // ------------------------------------------------------------------ STL unique --------------------------------------------------------------------------------

        int n;
        int x[1000005];
        vector<int> uni; // unique

        cin >> n;
        for(int i = 0; i < n; i++){
                cin >> x[i];
                uni.push_back(x[i]);   // 1,2,2,3,3,4,4,4,4,5,5
        }
        sort(uni.begin(), uni.end());
        uni.erase(unique(uni.begin(), uni.end()), uni.end()); // 1,2,3,4,5
        
        // 중복이 제거된 원소들을 앞으로 모아준 후 뒤쪽에는 쓰레기 값들이 들어가게 되는데, 그런 다음 쓰레기 값이 시작되는 구간을 return
        // vector의 erase를 이용해서 뒤쪽을 날리면 중복이 제거된 배열을 얻을 수 있다
        
        for(int i = 0; i < n; i++) 
                cout << lower_bound(uni.begin(), uni.end(), x[i]) - uni.begin() << ' '; // (BOJ_18870)
        
        return 0;
}
