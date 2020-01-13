#include <iostream>
#include <cstdlib>
#include <fstream>
#include <ctime>


using namespace std;

int length = 0;



void swap(int* a, int* b) { 
	int temp = *a; 
	*a = *b; 
	*b = temp;
}

int partition(int* arr, int p, int r)
{

	int x = arr[r];
	
	int i = p - 1, j;
	
	for (j = p; j < r ; j++) {
		if (arr[j] <= x) {
			i = i + 1;

			swap(&arr[i], &arr[j]);
	
		}
	}
	swap(&arr[i+1], &arr[j]);

	return i + 1;
}

int randomized(int* arr, int p, int r) {
	int a = rand() % (r-p+1) +p;
	int b = rand() % (r - p + 1) + p;
	int c = rand() % (r - p + 1) + p;
	int midindex;

	if (arr[a] >= arr[b])
		if (arr[b] >= arr[c])
			midindex = b;
		else if (arr[a] <= arr[c])
			midindex = a;
		else
			midindex = c;
	else if (arr[a] > arr[c])
		midindex = a;
	else if (arr[b] > arr[c])
		midindex = c;
	else
		midindex = b;

	swap(&arr[r], &arr[midindex]);
	
	return partition(arr, p, r);
}

void quick_sort(int* arr, int p, int r) {
	if( p < r ){
		int q = randomized(arr, p, r);
		quick_sort(arr, p, q - 1);
		quick_sort(arr, q+1, r);
	}
}

void insertion_sort(int* arr, int n) {
	int i, j, key;

	for (i = 1; i < n; i++)
	{
		key = arr[i];

		for (j = i - 1; j >= 0; j--)
		{
			if (arr[j] > key)
			{
				arr[j + 1] = arr[j];
			}
			else
			{
				break;
			}

		}
		arr[j + 1] = key;
	}
}



int main() {
	srand((unsigned)time(NULL)); // �Ź� ���ο� random value �� �ޱ����� ����

	FILE* file = fopen("input2-1.txt", "r");
	FILE* outfile = fopen("output2-1.txt", "w");

	int* arr = new int[200000]; // �� 20������ array �����Ҵ�

	if (file == NULL) {
		return 0;
	}

	while (!feof(file)) { // �迭�� �� ����
		fscanf(file, "%d ", &arr[length]);

		if (arr[length] < 0 || arr[length] > 10000) { //0 �̻� 10000�̸��� ���� ������ �ϴ� ����
			return 0;
		}

		length++;
	}

	
	if (3 <= length && length <= 10) { // ���Ұ� 3�̻� 10�����϶� insertion sort
		clock_t start, end;
		float delay;
		start = clock();
		insertion_sort(arr, length); // �ð��� �� �Լ�
		end = clock();
		delay = (float)(end - start) / CLOCKS_PER_SEC;

		for (int i = 0; i < length; i++)
		{
			fprintf(outfile, "%d ", arr[i]);
		}
		fprintf(outfile, "%s", "\n");
		fprintf(outfile, "%.3f s", delay);
		
		
	}
	else if (length < 3 || length > 200000) { //������ ���� ������ ��� �� ���α׷� ����
		return 0;
	}
	else
	{
		clock_t start, end;
		float delay;
		start = clock();
		quick_sort(arr, 0, length - 1); // �ð��� �� �Լ�
		end = clock();
		delay = (float)(end - start) / CLOCKS_PER_SEC; // �������� ����Ʈ�� ������.

		for (int i = 0; i < length; i++)
		{
			
			fprintf(outfile, "%d ", arr[i]);
		}

		fprintf(outfile, "%s", "\n");
		fprintf(outfile, "%.3f s", delay);
		
	}


	fclose(file);
	fclose(outfile);

	arr = NULL;
	delete[] arr;

	
}