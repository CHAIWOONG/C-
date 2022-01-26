#include <iostream>
#include <vector>

enum class city : int // --------------------------------도시 이름의 int 기반 저장
{
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c) // enum 클래스의 operator<< 정의
{
	switch (c)
	{
	case city::LONDON:
		os << "런던";
		return os;
	case city::MOSCOW:
		os << "모스크바";
		return os;
	case city::SEOUL:
		os << "서울";
		return os;
	case city::SEATTLE:
		os << "시애틀";
		return os;
	case city::DUBAI:
		os << "두바이";
		return os;
	case city::SYDNEY:
		os << "시드니";
		return os;
	default:
		return os;
	}
}

struct graph // -------------------------------------그래프의 구조체 형태의 저장
{
	std::vector<std::vector<int>> data; //------------------[]*[] 행렬의 형태

	graph(int n) // graph 생성자 추가
	{
		data.reserve(n); 			// data 구조체의 ~~
		std::vector<int> row(n); 		// 행 백터의 선언
		std::fill(row.begin(), row.end(), -1);  // fill 함수를 통해 행 백터를 -1의 초기 값으로 선언 (비어있는 상태의 표시)

		for (int i = 0; i < n; i++)
		{
			data.push_back(row);            // data 구조체 그래프에 각 열(columnn) 마다 행 백터 넣어둠 (data는 vector<vector<int>> 타입)
		}
	}

	void addEdge(const city c1, const city c2, int dis)  //------------------에지를 추가하는 함수
	{
		std::cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << std::endl;

		auto n1 = static_cast<int>(c1);  //------------------ int 형변환
		auto n2 = static_cast<int>(c2);  //------------------ int 형변환
		data[n1][n2] = dis;
		data[n2][n1] = dis; // ----------------------------도시 사이의 거리를 의미하는 edge의 cost를 인자로 받아 각각 서로 할당 (양방향 graph) 
	}

	void removeEdge(const city c1, const city c2) //--------------------------에지를 삭제하는 함수
	{
		std::cout << "에지 삭제: " << c1 << "-" << c2 << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1][n2] = -1;
		data[n2][n1] = -1; // ----------------------------도시 사이의 거리의 삭제는 cost의 -1로 초기화를 통해 구현
	}
};

int main()
{
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);
	g.addEdge(city::LONDON, city::SEOUL, 9000);
	g.addEdge(city::LONDON, city::DUBAI, 5500);
	g.addEdge(city::SEOUL, city::MOSCOW, 6600);
	g.addEdge(city::SEOUL, city::SEATTLE, 8000);
	g.addEdge(city::SEOUL, city::DUBAI, 7000);
	g.addEdge(city::SEOUL, city::SYDNEY, 8000);
	g.addEdge(city::SEATTLE, city::MOSCOW, 8400);
	g.addEdge(city::SEATTLE, city::SYDNEY, 12000);
	g.addEdge(city::DUBAI, city::SYDNEY, 1200);

	g.addEdge(city::SEATTLE, city::LONDON, 8000);
	g.removeEdge(city::SEATTLE, city::LONDON);

	return 0;
}
