#include<stdio.h>
#include<iostream>
#include<vector>


using namespace std;


int color[100]; //0 : white , 1 : gray , 2 : black
vector<int> adj[100];
bool check[100];
int cross = 0;
int result[100];
int cnt = 0;

void DFS(int n)
{
	check[n] = true;
	color[n] = 1;
	
	result[cnt++] = n;

	for (int i = 0; i < adj[n].size(); i++)
	{
		int a = adj[n][i];
		if (color[a] == 0) { // 흰색
			cout << "(" << n << "," << a << ") " << "tree edge" << endl;
			DFS(a);
		}
		else if (color[a] == 1) // 회색
		{
			cout << "(" << n << "," << a << ") " << "back edge" << endl;
		}
		else if (color[a] == 2 &&  cross == 0) // 검은색
		{
			cout << "(" << n << "," << a << ") " << "forward edge" << endl;
		}
		else if (color[a] == 2 && cross != 0) // 반대쪽에서 넘어왔을 때
		{
			cout << "(" << n << "," << a << ") " << "cross edge" << endl;

		}
	}

	color[n] = 2;
	
	
}


int main()
{
	int n=0; // 노드의 갯수
	int e;
	char a;
	
	for (int i = 0; i < 100; i++)
	{
		check[i] = false;
		color[i] = 0;
	}
	FILE* file = fopen("input3-1.txt", "r");
	fscanf(file, "%d\n", &n);
	

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			fscanf(file, "%d", &e);
			if (e == 1)
			{
				adj[i].push_back(j);
			}
			if (feof(file))
			{
				break;
			}

		}
	
	}
	DFS(1);

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			cross++;
			DFS(i);
		}
	}
	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}

	fclose(file);
}