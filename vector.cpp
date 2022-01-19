#include <iostream>
#include <algorithm>
#include <vector> 

int main()
{
	vector<int> v1;                       // int타입 벡터 생성
	vector<int> v2 = { 1, 2, 3};          // int형 백터 생성 후 1, 2, 3 으로 초기화
	vector<int> v3[10];                   // int타입 벡터 배열(크기 : 10) 생성
	vector<int> v4[] = {{ 1, 2}, {3, 4}}; // int형 백터 배열 생성(행은 가변이지만 열은 고정)
	
	vector<vector<int>> v5;               // 2차원 백터 생성(행과 열 모두 가변)
	vector<int> v6(5);                    // 5개의 원소를 0으로 초기화
	vector<int> v7(5, 3);                 // 5개의 원소를 3으로 초기화
	vector<int> v8(v1);                   // 벡터 v를 복사하여 벡터v2 생성(복사 생성자)

	v.push_back(10);  // 마지막 위치에 숫자 10 추가

	vector<int>::iterator it = v.begin();
	it = v.insert(it, 2); //맨앞에 2를 삽입
	it = v.insert(it, 2, 3); // 맨앞에 3을 2개 삽입
	it = v.insert(it+2, 2, 4); // 2번째부터 4를 2개 삽입

	v.pop_back();                        // 마지막에 넣은 값 제거
	v.erase(vec.begin()+10);             // index 10의 값을 제거
	v.erase(vec.begin(), vec.begin()+5);  // index 0~5의 값을 제거
	v.clear();                           //모든 값 제거

	v.size();   //vector의 원소 갯수
	v.capacity; //vector의 물리적 크기

	 v.at(i) //vector의 i번째 요소 접근 at은 범위를 검사하여 범위 밖의 요소에 접근 시 예외처리를 발생 (std::out_of_range)
	 v[i]  ///vector의 i번째 요소 접근
		 
		 
	// 2차원 벡터에 대한 요소 입력의 예시		 
	int N;
        cin>>N;

        vector<vector<int>> v(N, vector<int>(2,0)); // 2차원 백터(N*2) 생성(행은 N개 열은 0으로 2개)

        for(int i = 0; i < N; i++){
	   cin>>v[i][1];
	   cin>>v[i][0];
        }
        sort(v.begin(),v.end());

        for(int i = 0; i < v.size(); i++){
	     cout<<v[i][1]<<" "<<v[i][0]<<'\n';
        }
}


