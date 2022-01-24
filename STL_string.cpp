#include <iostream>
#include <algorithm>
#include <foward_list> 
#include <list>
#include <deque>
#include <string>

using namespace std;

int main()
{
    
    
	// 벡터와 비슷한 방식으로 동적 할당을 이용해 구현이 되어있다.
	string s;
	string s(cnt, c); // 단, cnt는 정수, c는 char , c가 cnt개 있는 문자열 생성
	string s("Hello World!"); 
	string s = "Hello World!" // 리터럴 또는 const char*
	string s(v.begin(), v.end());


	string s(5, 'a'); // s = "aaaaa"
	string t = "Hello World!";


	s.pop_back(); // s = "aaaa"
	s.push_back('b'); // s = "aaaab" = char 한개만 문자열 끝에 추가 
	// (operator +=도 가능)

	//임의의 위치에 문자, string을 삽입  O(n)
	s.insert(s.begin() + 1, 'c'); // insert 'c' at s[1], s = "acaaab"
	s.insert(s.begin() + 3, 2, 'd'); // insert "dd" at s[3], s = "acaddaab";
	s.insert(s.begin(), t.begin(), t.begin() + 5); // insert [t[0], t[5]) at s[0], s = "Helloaa"

	//임의의 위치에 문자를 삭제 O(n)
	s.erase(s.begin() + 1); // erase s[1], s = "aaddaab"
	s.erase(s.begin() + 2, s.end()); // erase [s[2], s.end()), s = "aa"
    
	cout << "s.size() : " << s.size() << '\n'; // 7 string의 크기를 size_t로 반환 (s.length()와 같다)
	cout << "s.empty() : " << s.empty() << '\n' << '\n'; // 0 비어있는지의 여부를 bool 자료형으로 반환
	
	s.resize(4); // s = "Hell" (string의 크기를 변경)
	s.resize(3, 'a'); // s = "aaa" (string의 크기를 변경)
	s.clear(); // s = "" (string의 모든 문자를 삭제)
	
	
	string s1 = "ABCDE123";

	cout << s1.length() << endl;        //output : 8
	cout << s1.size() << endl;        //output : 8
	cout << s1.capacity() << endl;    //output : 15 string의 capacity를 15로 맞춰준 상황

	s1.reserve(100);  // capacity의 크기를 늘렸을 때,
	cout << s1.size() << endl;        //output : 8 실제 string의 길이는 여전
	cout << s1.capacity() << endl;    //output : 111 설정한 크기봐 capacity가 여유있는 메모리 공간을 가짐

	s.shrink_to_fit(); // 잉여 capacity 공간을 조절함
	cout << s.capacity() << endl;    //output : 15 capacity의 크기가 복귀


	//---------------------------------------------------------------

	cout << "t.substr(0, 5) : " << t.substr(0, 5) << '\n'; // "Hello"
	cout << "t.substr(6) : " << t.substr(6) << '\n'; // "World!"
	//substr(a,b) =  s[a]에서부터 b개의 원소를 이어붙인 문자열을 반환
	// a가 s.size()보다 크거나 같은 경우에는 런타임 에러가 발생할 수 있으므로 존재하는 인덱스로 잡아줘야 한다
	// b는 충분히 큰 값이 들어가기  때문에 생략하면 s.back()까지의 문자열을 반환한다
	
	cout << "t.find(\'!\') : " << t.find('!') << '\n'; // 11 (t[11] == '!')
	cout << "t.find(\'?\') : " << t.find('?') << ' ' << string::npos << ' ' << typeid(string::npos).name() << '\n'; // 4294967295 == (unsigned int)(-1)
	//find : s에서 문자 또는 문자열의 존재 여부를 찾은 뒤, 존재한다면 시작 인덱스(size_t)를, 아니라면 npos를 반환.
	
	cout << "s + t : " << s + t << '\n' << '\n'; // s + t == "aaaHello World!"

	for (auto it = t.begin(); it != t.end(); it++) cout << *it; cout << '\n'; // "Hello World!"
	for (auto it = t.rbegin(); it != t.rend(); it++) cout << *it; cout << '\n'; // "!dlroW olleH"
	cout << "t.front() : " << t.front() << '\n'; // 'H'
	cout << "t.back() : " << t.back() << '\n'; // '!'
	
	
	// -----------------------(string -> int)--------------------
	
	//mixed string
	string str1 = "33BlockDMask";

	//test1
	//원형 = int stoi(const string& str, size_t* idx =0, int base = 10);


	int num1 = stoi(str1);   // stoi, stof, stol, stod, stoll
	cout << "test1. stoi(str1);" << endl;
	cout << " - str1 : " << str1 << endl; // 33BlockDMask
	cout << " - num1 : " << num1 << endl; // 33 (string to int)
	cout << endl;

	//test2
	size_t sz;
	int num2 = stoi(str1, &sz); // 두번째 인자 size_t* 타입의 idx 매개변수
	cout << "test2. stoi(str1, &sz);" << endl;
	cout << " - str1 : " << str1 << endl; // 33BlockDMask
	cout << " - num2 : " << num2 << endl; // 33

	cout << " - sz : " << sz << endl; // 2  (숫자가 아닌 게 처음 나오는 index)
	cout << " - str1[sz] : " << str1[sz] << endl; // B
	cout << " - str1.substr(sz) : " << str1.substr(sz) << endl; // BlockDMask

	cout << endl;
	//test3
	string str2 = "";
	cout << "test3. stoi(str2, nullptr, base);" << endl;
	// 세번째 인자 stoi만 존재 int base = 10 (10진수를 기본으로 계산)

	//string binary -> int
	str2 = "1110";
	cout << " - stoi(1110, nullptr, 2) : " << stoi(str2, nullptr, 2) << endl;
	// 두번째 인자를 사용하지 않으므로 nullptr로 작성
	// string 안에있는 숫자를 2진수로 생각하여 정수로 출력

	//string oct -> int
	str2 = "014";
	cout << " - stoi(014 , nullptr, 8) : " << stoi(str2, nullptr, 8) << endl;

	//string hex -> int
	str2 = "0x14";
	cout << " - stoi(0x14, nullptr, 16) : " << stoi(str2, nullptr, 16) << endl;

	// -----------------------------int -> string---------------------
	int num1 = 10;
	float num2 = 22.1f;

	//to_string(int) -> int.
	string str1 = to_string(num1);
	cout << "to_string(num1) : " << str1 << endl;  // 10
	cout << "to_string(num2) : " << to_string(num2) << endl; // 22.1000000



	//----------------------------------추가적 함수----------------
	toupper(s[i]); // 소문자를 대문자로 변환
	tolower(s[i]); // 대문자를 소문자로 변환

	isupper(s[i]); // 대문자 판별 (대문자가 아니라면 0이 반환)
	islower(s[i]); // 소문자 판별

	isspace(s[i]); // 문자가 공백인지 판별
	isdigit(s[i]); // 문자가 숫자인지 판별
	isalpha(s[i]); // 문자가 알파벳인지 판별

	return 0;
   
}
