#include <iostream>

using namespace std;

int result[100]; //결괏값 저장
void heapify(int heap[], int length, int i);
void heapSort(int heap[], int length);


int main() {
	int input;
	int length = 0;
	int array[100];

	cout << "Input numbers to sort" << endl;

	/*insert the number
	If the number less than 0 or more than 1000, finish main.
	If the number is -1, break.
	insert the number into array, which is not sorted*/

	for (int i = 0; i < 100; i++) {
		cin >> input;
		if (input == -1) {
			break;
		}
		else if (input < -1 || input > 1000) {
			cout << "Wrong Input" << endl;
			return 0;
		}

		
		array[i] = input;
		length++;
		
	}

	heapSort(array, length);

	cout << "Result" << endl;
	for (int i = 0; i <length ; i++) {
		cout << result[i] << " ";
	}

	return 0;
}


/*	heapify 함수
	ppt의 수도코드를 참고하여 작성
	index가 배열 0부터 시작하는것으로 설정했으므로 left 와 right는 1부터 했을때보다 각각 +1을 더 더해줍니다.
	max에는 검사해야할 부모가 들어갑니다.
	재귀적으로 구현했습니다*/

void heapify(int heap[], int length, int i)
{
	int max = i; int check;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp;

	check = left;
	if(check < length) // 자식이 length를 초과하지 않는지 검사.
	{
		if (heap[left] > heap[max]) 
			max = left;
	}

	check = right;
	if (check < length)
	{
		if (heap[right] > heap[max])
			max = right; //왼쪽이 클땐 왼쪽을, 오른쪽이 클땐 오른쪽을 부모에 max값에 넣음.
	}
	


	/*	max의 값이 변경되었을땐 부모와 자식을 바꿔줘야하므로
		자리를 바꿔준후, 재귀호출(자리가 바뀌었으므로
		바뀐 노드를 대상으로 heapify*/
	if (max != i)
	{
		temp = heap[i];
		heap[i] = heap[max];
		heap[max] = temp;

		heapify(heap, length, max);
	}
}


void heapSort(int heap[], int length)
{
	int temp, index = 0;

	/*	제일 밑 자식의 부모부터 검사(n의 부모는 n/2) 다만 -1은, 인덱스가 0부터기 때문에
		-1을 해준다. */
	for (int i = length / 2 - 1; i >= 0; i--)
		heapify(heap, length, i);

	/*제일 끝의 값을 빼준 후에, 다시한번 heap을 구축한다.
	끝의 값을 result에 하나씩 넣어준다.
	heap을 구축하면 heap[0]은 항상 제일 큰값이므로 내림차순으로 정렬이 가능하다.
	반면 array는 heapsort로 인해 오름차순으로 정렬된다.
	그 이유는 swap 과정에서 끝에서 부터 max가 저장되고,
	heapify는 i가 --되므로 트리의 원소를 하나 빼었다고 (최댓값을 제외했다고) 가정하고 나머지
	원소들을 heap으로 만들 수 있다.*/

	for (int i = length - 1; i >= 0; i--)
	{
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;
		
		result[index++] = temp;

		heapify(heap, i, 0);
	}

}