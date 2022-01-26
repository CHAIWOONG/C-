#include <iostream>
#include <queue>
#include <vector>

// 최대힙과 최소힙을 두개 구성하여 새로운 데이터가 기존 데이터의 중앙값보다 작으면 최대힙에 저장, 크면 최소힙에 저장하여
// 데이터의 정렬시 가운데에 위치한 값(중앙값)을 출력, 데이터가 짝수일 경우 가운데 위치한 두 데이터의 산술평균 반환
// minheap의 데이터가 k,k+1 maxheap의 데이터가 k,k가 되도록 유지

struct median
{
	std::priority_queue<int> maxHeap;  // maxHeap
	std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; //비교함수 객체 greater에 따라서 > 연산자에 대한 래퍼 사용으로 minHeap

	void insert(int data) // 새로 들어온 데이터를 저장
	{
		if (maxHeap.size() == 0) // 비어있는 경우
		{
		  maxHeap.push(data);
		  return;
		}

		if (maxHeap.size() == minHeap.size()) 
		{
		  if (data <= get()) // 새로운 데이터가 기존 데이터의 중앙값보다 작으면 최대힙에 저장
		    maxHeap.push(data);
		  else              // 새로운 데이터가 기존 데이터의 중앙값보다 크면 최소힙에 저장
		    minHeap.push(data);
		  return;
		}

		if (maxHeap.size() < minHeap.size()) 
		{
		  if (data > get()) // 새로운 데이터가 기존 데이터의 중앙값보다 크면 최소힙에 저장
		  { 
		    maxHeap.push(minHeap.top()); // heap의 개수를 맞춰주기 위함
		    minHeap.pop();
		    minHeap.push(data);
		  }
		  else              // 새로운 데이터가 기존 데이터의 중앙값보다 작으면 최대힙에 저장
		    maxHeap.push(data);
		  return;
		}

		if (data < get()) // 새로운 데이터가 기존 데이터의 중앙값보다 작으면 최대힙에 저장
		{
		  minHeap.push(maxHeap.top());
		  maxHeap.pop();
		  maxHeap.push(data);
		}
		else              // 새로운 데이터가 기존 데이터의 중앙값보다 크면 최소힙에 저장
		  minHeap.push(data);

	} // ----------------------------------insert()

	double get() // 저장된 기존 데이터에서 중앙값을 구하여 반환
	{
		if (maxHeap.size() == minHeap.size()) // 데이터의 개수가 짝수
		  return (maxHeap.top() + minHeap.top()) / 2.0;

		if (maxHeap.size() < minHeap.size()) // 데이터의 개수가 홀수
		  return minHeap.top();

		return maxHeap.top(); // 데이터가 1개만 있는 경우  
    
	} // ----------------------------------get()
};

int main()
{
	median med;

	med.insert(1);
	std::cout << "1 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(5);
	std::cout << "5 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(2);
	std::cout << "2 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(10);
	std::cout << "10 삽입 후 중앙값: " << med.get() << std::endl;

	med.insert(40);
	std::cout << "40 삽입 후 중앙값: " << med.get() << std::endl;
}


