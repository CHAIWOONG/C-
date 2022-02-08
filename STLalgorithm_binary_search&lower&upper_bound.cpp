#include <bits/stdc++.h>
using namespace std;

int a[100005];
int n;

int binarysearch(int target){
        int st = 0;
        int en = n-1;

        while(st <= en){
          int mid = (st+en)/2;

          if(a[mid] < target)
            st = mid+1;
          else if(a[mid] > target)
            en = mid-1;
          else
            return 1;
        }
        return 0; // st > en일 경우 while문을 탈출
}

int main(void) {
  
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a, a+n);

        int m;
        cin >> m;

        while(m--){
        int t;
        cin >> t;
        cout << BinarySearch(t) << '\n';
        }
  
        // --------------------------------------------------------------------
        cin >> n;

        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a,a+n);

        int m;
        cin >> m;

        while(m--){
        int t;
        cin >> t;
        cout << binary_search(a, a+n, t) << '\n';
        }

        const int n = 5;
        vector<int> v{ 1, 2, 3, 3, 5 };
        cout << binary_search(v.begin(), v.end(), 3) << '\n'; // 1
        cout << binary_search(v.begin(), v.end(), 4) << '\n'; // 0

    
        // --------------------------------------------------------------------
    
        const int n = 5;
        vector<int> v{ 1, 2, 3, 3, 4 };
        auto lo = lower_bound(v.begin(), v.end(), 3);
        auto hi = upper_bound(v.begin(), v.end(), 3);
        cout << lo - v.begin() << '\n'; // 2
        cout << hi - v.begin() << '\n'; // 4
        
        return 0;
}
