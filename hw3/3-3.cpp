#include<stdio.h>
#include<iostream>
#include<vector>
#include <stack>

using namespace std;


int color[100]; //0 : white , 1 : gray , 2 : black
vector<int> adj[100];
bool check[100];
int cross = 0;
int result[100];
int cnt = 0;

int DFS(int n)
{
	check[n] = true;
	color[n] = 1;
	int dag = 1;
	

	for (int i = 0; i < adj[n].size(); i++)
	{
		int a = adj[n][i];
		if (color[a] == 0) { // 흰색
			DFS(a);
		}
		else if (color[a] == 1) // 회색
		{
			dag = 0; //back edge가 발생하면 dag가 아니므로 0으로 바꿔줌.
		}
		
	}

	color[n] = 2;
	result[cnt++] = n;
	return dag;
}


int main()
{
	int n = 0; // 노드의 갯수
	int e;
	char a;
	int re_dfs = 0;
	for (int i = 0; i < 100; i++)
	{
		check[i] = false;
		color[i] = 0;
	}
	FILE* file = fopen("input3-3.txt", "r");
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
	if (DFS(1))
	{
		cout << 1 << endl;
	}

	for (int i = 1; i <= n; i++)
	{
		if (check[i] == false)
		{
			cross++;
			DFS(i);
		}
	}
	for (int i = n-1 ; i >= 0; i--)
	{
		cout << result[i] << ' ';
	}

	fclose(file);
}