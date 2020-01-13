#include <iostream>

using namespace std;

int result[100]; //�ᱣ�� ����
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
	if(check < length) // �ڽ��� length�� �ʰ����� �ʴ��� �˻�.
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
	int temp, index = 0;

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
		
		result[index++] = temp;

		heapify(heap, i, 0);
	}

}