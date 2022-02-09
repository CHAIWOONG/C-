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
    
        const int n = 5;
        vector<int> v{ 1, 2, 3, 3, 4 };
        auto lo = lower_bound(v.begin(), v.end(), 3);
        auto hi = upper_bound(v.begin(), v.end(), 3);
        cout << lo - v.begin() << '\n'; // 2
        cout << hi - v.begin() << '\n'; // 4
        
        // ------------------------------------------------------------------ STL unique --------------------------------------------------------------------------------

        
        return 0;
}
