#include <iostream>
#include <vector>
#include <algorithm>

enum class city : int
{
	MOSCOW,
	LONDON,
	SEOUL,
	SEATTLE,
	DUBAI,
	SYDNEY
};

std::ostream& operator<<(std::ostream& os, const city c)
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
	std::vector<std::vector<std::pair<int, int>>> data; //-----------------vector< vector<pair<int,int> >의 형태를 통해 adjacency list 구현

	graph(int n) // -------------------생성자, 비어있는 형태로 초기화 (-1의 초기값 할당 필요 없음)
	{
		data = std::vector<std::vector<std::pair<int, int>>>(n, std::vector<std::pair<int, int>>()); 
	}

	void addEdge(const city c1, const city c2, int dis) // --------------------------------------edge의 추가 함수
	{
		std::cout << "에지 추가: " << c1 << "-" << c2 << "=" << dis << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		data[n1].push_back({n2, dis}); 
		data[n2].push_back({n1, dis});  // ---------------- pair를 통해 인접 도시 노드의 이름과 edge의 cost를 인자로 받아 각각 push_back 
	}

	void removeEdge(const city c1, const city c2) // --------------------------------------edge의 삭제 함수
	{
		std::cout << "에지 삭제: " << c1 << "-" << c2 << std::endl;

		auto n1 = static_cast<int>(c1);
		auto n2 = static_cast<int>(c2);
		std::remove_if(data[n1].begin(), data[n1].end(), [n2](const auto& pair) {
			return pair.first == n2;
			});
		std::remove_if(data[n2].begin(), data[n2].end(), [n1](const auto& pair) {
			return pair.first == n1;
			});   // ---------------- pair를 통해 인접 도시 노드의 이름과 edge의 cost를 인자로 받아 각각 push_back 
	}
};

int main()
{
	graph g(6);
	g.addEdge(city::LONDON, city::MOSCOW, 2500);  // 인자는 node1, node2, cost
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
