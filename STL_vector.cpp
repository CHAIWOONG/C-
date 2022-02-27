#include <iostream>
#include <algorithm>
#include <vector> 

int main()
{
	// 주로 array를 사용하고, 그래프의 adjacency list를 구현할 때에 주로 vector를 사용하는 일이 많다.

	vector<int> v1;                       // int타입 벡터 생성
	vector<int> v2 = { 1, 2, 3};          // int형 백터 생성 후 1, 2, 3 으로 초기화
	vector<int> v3[10];                   // int타입 벡터 배열(크기 : 10) 생성
	vector<int> v4[] = {{ 1, 2}, {3, 4}}; // int형 백터 배열 생성(행은 가변이지만 열은 고정)
	
	vector<vector<int>> v5;               // 2차원 백터 생성(행과 열 모두 가변)
	vector<int> v6(5);                    // 5개의 원소를 0으로 초기화
	vector<int> v7(5, 3);                 // 5개의 원소를 3으로 초기화
	vector<int> v8(v1);                   // 벡터 v를 복사하여 벡터v2 생성(복사 생성자)
	vector<int> vec7=vector<int>(vec1.begin()+2, vec1.end());  //vec7은 vec1의 2번째 원소부터 마지막 원소까지 복사하여 생성
	
	
	
	// ---------------------------------------------- 벡터 요소 추가, 참조 및 삭제-----------------------------------------------------------
	
	v1.push_back(10);  // 마지막 위치에 숫자 10 추가 (평균 시간 복잡도는 O(1)에 가깝다)

	v1.insert(v.begin(),0);  // 벡터의 맨 앞에 0 추가 (insert는 지정 반복자의 위치 다음의 모든 원소를 이동시킴 시간복잡도 O(n))
	v1.insert(find(v1.begin(), v1.end(), 1), 4); // 벡터에서 1을 찾아서 그 앞에 4를 추가
	
	
	auto element = v1.begin()+4; // 반복자  -----------------------------iterator 사용 (반복자가 무효화가 존재함)
	cout<< *element<<"\n\n";           // element 변수는 v1의 첫번째 값에서 4만큼 떨어진 자리의 주소값을 가진다
	// 벡터는 새로운 메모리 공간을 할당하고 기존의 원소를 새로운 메모리 공간에 복사한다.
	// 반복자의 무효화가 발생한다. (list는 삽입에서 무효화가 발생하지 않는다)
	
	vector<int>::iterator it = v.begin(); // 반복자 타입의 it 변수 생성
	it = v.insert(it, 2); //맨앞에 2를 삽입 (평균 시간 복잡도는 O(n)에 가깝다)
	it = v.insert(it, 2, 3); // 맨앞에 3을 2개 삽입
	it = v.insert(it+2, 2, 4); // 2번째부터 4를 2개 삽입

	v.pop_back();                        // 마지막에 넣은 값 제거 (시간 복잡도는 O(1))
	
	vec1.erase(vec1.begin(), vec1.end());//모든 원소 삭제 (시간 복잡도는 O(n)에 가깝다)
	v.erase(vec.begin()+10);             // index 10의 값을 제거
	v.erase(vec.begin(), vec.begin()+5);  // index 0~5의 값을 제거
	v.clear();                           //모든 값 제거

	v.size();   //vector의 원소 갯수
	v.capacity; //vector의 물리적 크기

	v.at(i) //vector의 i번째 요소 접근 at은 범위를 검사하여 범위 밖의 요소에 접근 시 예외처리를 발생 (std::out_of_range)
	v[i]  ///vector의 i번째 요소 접근
	
		
	// ---------------------------------------------------------------- 벡터의 비교 연산자 -----------------------------------------------------------
		
	// ******* 두 vector 사이에 연산자  ==, !=, <, >, <=, >= 를 사용할 수 있다
	vector<int> v1 = { 1, 2, 3};                        
	vector<int> v2 = { 1, 2, 3};  
	
	if(v1==v2) cout<<"true"; //  {1,2,3} = {1,2,3} 이므로 true 
		 
	// -----------------------------------------------2차원 벡터에 대한 요소 입력의 예시----------------------------------------------------------	 
	int N;
        cin>>N;

        vector<vector<int>> v(N, vector<int>(2,0)); // 2차원 백터(N*2) 생성(행은 N개 열은 0으로 2개)

        for(int i = 0; i < N; i++){
	   cin>>v[i][1];
	   cin>>v[i][0];
        }
        sort(v.begin(),v.end());

        for(int i = 0; i < v.size(); i++){         // vector의 size() 함수의 경우, unsigned int 혹은 unsigned long long을 반환
	     cout<<v[i][1]<<" "<<v[i][0]<<'\n';    // 이에 따라서 i<=v.size()-1과 같이 구현하게 되면 unsigned int overflow가 발생하게 되므로 런타임 오류가 발생한다
        }
	
	
	// ---------------------------------------------- Ranged-based for loops를 사용한 출력의 예시 --------------------------------------------------------------
	
	vector<int> v2 = { 1, 2, 3};  
	
	for(auto number : v2)                     // elemen declaration의 부분이 배열요소와 같은 타입이어야 하므로 auto 키워드를 통해 c++ 추론하도록 한다
		cout<< number <<"\n";		  // 참조자로 선언하지 않고 받고 있으므로 일일이 복사한 값이 number로 들어가게 된다
	
	for(auto& number : v2)                    // 요소를 일일히 복사하는 것은 비용이 많이 들 수 있으므로 참조를 사용할 수 있다.
		cout<< number <<"\n";		  // &로 선언하여 받고 있으므로 원본의 주소가 number로 들어가게 되어 원본을 받게 된다
	
	for(const auto& number : v2)              // 요소의 사용은 읽기로만 이뤄지므로 const 참조를 사용할 수 있다
		cout<< number <<"\n";
 	
}


