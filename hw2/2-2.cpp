#include <iostream>
#include <fstream>
#include <limits.h>
using namespace std;


void bottom_up_cutrod(int* r, int* s, int* p,int n) {
	int q;

	for (int i = 0; i < n; i++)
	{
		r[i] = 0;
		s[i] = 0;
	}


	for (int j = 1; j <= n; j++)
	{
		q = INT_MIN;

		for (int i = 1; i <= j ;i++)
		{
			if (q < p[i] + r[j - i])
			{
				q = p[i] + r[j - i];
				s[j] = i;
			}
			
		}
		r[j] = q;
	}


}





int main() {
	int n; // Rod 의 길이
	int i = 1;
	int* p = new int[101];
	p[0] = NULL;
	FILE* file = fopen("input2-2.txt", "r");

	if (file == NULL) {
		return 0;
	}

	fscanf(file, "%d\n", &n);
	int* r = new int[n];
	int* s = new int[n];
	

	while (!feof(file)) { // 배열에 값 저장
		fscanf(file, "%d ", &p[i]);
		i++;
	}

	bottom_up_cutrod(r, s, p, n);
	cout << r[n] << endl;
	
	while (n > 0)
	{
		cout << s[n] << " " ;
		n = n - s[n];
	}

	fclose(file);
	p = NULL; r = NULL; s = NULL;
	delete[] p;
	delete[] r;
	delete[] s;

	return 0;

}