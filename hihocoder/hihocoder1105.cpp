#include<iostream>
#include<vector>
using namespace std;
void heapInsert(vector<int> &heap, int i);
int heapExtractMaxmum(vector<int> &heap);
int main()
{
	vector<int> heap;
	int m;
	char ch;
	int w;
	heap.push_back(0);
	cin >> m;
	while (m--)
	{
		cin>>ch;
		if (ch == 'A')
		{
			cin >> w;
			heapInsert(heap, w);
		}
		else if (ch == 'T')
		{
			cout << heapExtractMaxmum(heap) << endl;
		}

	}
	return 0;

}

void heapInsert(vector<int> &heap, int i)
{
	heap.push_back(i);
	int length = heap.size()-1;
	while (length > 1 && heap[length] > heap[length / 2])
	{
		int temp = heap[length];
		heap[length] = heap[length / 2];
		heap[length / 2] = temp;
		length = length / 2;
	}
}

int heapExtractMaxmum(vector<int> &heap)
{
	int length = heap.size() - 1;
	int maxmum = heap[1];
	heap[1] = heap[length];
	int index = 1;
	int largest;
	while (index * 2 <= length)
	{
		largest = index;
		if (index * 2 < length && heap[largest] < heap[index * 2])
			largest = index * 2;
		if (index * 2 + 1 < length && heap[largest] < heap[index * 2 + 1])
			largest = index * 2 + 1;
		if (largest == index)
			break;
		else
		{
			int temp = heap[largest];
			heap[largest] = heap[index];
			heap[index] = temp;
			index = largest;
		}
	}
	heap.pop_back();
	return maxmum;
}
