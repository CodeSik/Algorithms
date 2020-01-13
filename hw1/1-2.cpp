#include <iostream>
#include<fstream>
#include<string>
#include <cstring>


using namespace std;


void heapify(int heap[], int length, int i);
void heapSort(int heap[], int length);


int main() {
	int result[100][100]; //파일 입출력에서 받은 값들을 이중배열의 형태로 저장
	for (int i = 0; i < 100; i++) { //-1로 초기화
		for (int j = 0; j < 100; j++) {
			result[i][j] = -1;
		}
	}
	int heap[100]; //출력할 배열

	FILE* file = fopen("input1-2.txt", "r");


	int k; char s; //k에는 배열의 갯수를, s에는 " " 과 \n을 파싱하기 위해 생성
	int value; //들어갈 값들
	int max_index = 0; //배열중에서 가장 길이가 긴 배열의 길이를 저장

	fscanf(file, "%d%c ", &k,&s); //k를 저장
	
	int index[100] = { 0 };
	
	/*	i는 배열의 갯수만큼 돌고,
		j는개행을 받을때까지 반복. (1줄씩 받음)*/
	for (int i = 0; i < k; i++)
	{
		fscanf(file, "%d%c", &value, &s);
		result[i][0] = value;
		index[i]++;

		for (int j = 1; s != '\n'; j++) {
			fscanf(file, "%d%c", &value, &s);
			result[i][j] = value;
			index[i]++;
		}
		
	}
	max_index = index[0];
	for (int i = 1; i < k; i++) {
		
		if (index[i] > max_index)
			max_index = index[i];

	}
	

	
	int index2 = 0; //새로 만들 heap의 인덱스를 저장
	

	for (int i = 0; i < max_index; i++) { //제일 길이가 긴 배열까지 다 검사
		for (int j = 0; j < k; j++)
		{

			if (result[j][i] == -1) { //-1일때는 넘긴다. 이를 통해 검사를 안해도 되는(max_index보다 작은 배열들)배열들은 검사하지않는다.
				continue;
			}
			else {
				
				heap[index2++] = result[j][i];

			}
		}
		heapSort(heap, index2 ); //만들어진 배열을 Heapsort
	}
	
	for (int i = 0; i < index2; i++) {
		cout << heap[i] << " ";
	}
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
	if (check < length) // 자식이 length를 초과하지 않는지 검사.
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
	int temp;

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


		heapify(heap, i, 0);
	}

}