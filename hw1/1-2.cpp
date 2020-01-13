#include <iostream>
#include<fstream>
#include<string>
#include <cstring>


using namespace std;


void heapify(int heap[], int length, int i);
void heapSort(int heap[], int length);


int main() {
	int result[100][100]; //���� ����¿��� ���� ������ ���߹迭�� ���·� ����
	for (int i = 0; i < 100; i++) { //-1�� �ʱ�ȭ
		for (int j = 0; j < 100; j++) {
			result[i][j] = -1;
		}
	}
	int heap[100]; //����� �迭

	FILE* file = fopen("input1-2.txt", "r");


	int k; char s; //k���� �迭�� ������, s���� " " �� \n�� �Ľ��ϱ� ���� ����
	int value; //�� ����
	int max_index = 0; //�迭�߿��� ���� ���̰� �� �迭�� ���̸� ����

	fscanf(file, "%d%c ", &k,&s); //k�� ����
	
	int index[100] = { 0 };
	
	/*	i�� �迭�� ������ŭ ����,
		j�°����� ���������� �ݺ�. (1�پ� ����)*/
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
	

	
	int index2 = 0; //���� ���� heap�� �ε����� ����
	

	for (int i = 0; i < max_index; i++) { //���� ���̰� �� �迭���� �� �˻�
		for (int j = 0; j < k; j++)
		{

			if (result[j][i] == -1) { //-1�϶��� �ѱ��. �̸� ���� �˻縦 ���ص� �Ǵ�(max_index���� ���� �迭��)�迭���� �˻������ʴ´�.
				continue;
			}
			else {
				
				heap[index2++] = result[j][i];

			}
		}
		heapSort(heap, index2 ); //������� �迭�� Heapsort
	}
	
	for (int i = 0; i < index2; i++) {
		cout << heap[i] << " ";
	}
}


/*	heapify �Լ�
	ppt�� �����ڵ带 �����Ͽ� �ۼ�
	index�� �迭 0���� �����ϴ°����� ���������Ƿ� left �� right�� 1���� ���������� ���� +1�� �� �����ݴϴ�.
	max���� �˻��ؾ��� �θ� ���ϴ�.
	��������� �����߽��ϴ�*/

void heapify(int heap[], int length, int i)
{
	int max = i; int check;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	int temp;

	check = left;
	if (check < length) // �ڽ��� length�� �ʰ����� �ʴ��� �˻�.
	{
		if (heap[left] > heap[max])
			max = left;
	}

	check = right;
	if (check < length)
	{
		if (heap[right] > heap[max])
			max = right; //������ Ŭ�� ������, �������� Ŭ�� �������� �θ� max���� ����.
	}



	/*	max�� ���� ����Ǿ����� �θ�� �ڽ��� �ٲ�����ϹǷ�
		�ڸ��� �ٲ�����, ���ȣ��(�ڸ��� �ٲ�����Ƿ�
		�ٲ� ��带 ������� heapify*/
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

	/*	���� �� �ڽ��� �θ���� �˻�(n�� �θ�� n/2) �ٸ� -1��, �ε����� 0���ͱ� ������
		-1�� ���ش�. */
	for (int i = length / 2 - 1; i >= 0; i--)
		heapify(heap, length, i);

	/*���� ���� ���� ���� �Ŀ�, �ٽ��ѹ� heap�� �����Ѵ�.
	���� ���� result�� �ϳ��� �־��ش�.
	heap�� �����ϸ� heap[0]�� �׻� ���� ū���̹Ƿ� ������������ ������ �����ϴ�.
	�ݸ� array�� heapsort�� ���� ������������ ���ĵȴ�.
	�� ������ swap �������� ������ ���� max�� ����ǰ�,
	heapify�� i�� --�ǹǷ� Ʈ���� ���Ҹ� �ϳ� �����ٰ� (�ִ��� �����ߴٰ�) �����ϰ� ������
	���ҵ��� heap���� ���� �� �ִ�.*/

	for (int i = length - 1; i >= 0; i--)
	{
		temp = heap[0];
		heap[0] = heap[i];
		heap[i] = temp;


		heapify(heap, i, 0);
	}

}