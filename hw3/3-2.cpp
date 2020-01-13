#include<stdio.h>
#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int n = 0; // ����� ����
bool visit[100];
vector<int> adj[100];
int result[100];
int component[100];
int cnt = 0;

void DFS(int k)
{
	visit[k] = true;
	result[cnt++] = k;
	for (int i = 0; i < adj[k].size(); i++)
	{
		int a = adj[k][i];
		if (visit[a] == false) {
			DFS(a);
		}
	}

}


int DFS_ALL()
{
	int cmp = 0;
	int component_count =0;
	for (int i = 0; i < 100; i++)
	{
		visit[i] = false;
	}

	for (int i = 1; i <= n; i++)
	{
		if (visit[i] == false)
		{
			DFS(i);
			cmp++;

			for (component_count; component_count < cnt; component_count++)
			{
				component[result[component_count]] = cmp; // �� ����� component ��ȣ �����ϴ� �ڵ�
				//DFS ��� Array�� �ִ� ����� index�� ��Ÿ���� component array�� �� ����� component���� ����
			}

		}
	}

	return cmp;
}



int main()
{
	int e;
	char a;
	
	for (int i = 0; i < 100; i++)
	{
		visit[i] = false;
	}
	FILE* file = fopen("input3-2.txt", "r");
	fscanf(file, "%d\n", &n);


	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			fscanf(file, "%d", &e);
			if (e == 1)
			{
				adj[i].push_back(j);
				adj[j].push_back(i);
			}
			if (feof(file))
			{
				break;
			}

		}

	}
	int cmp = DFS_ALL();

	for (int i = 0; i < n; i++)
	{
		cout << result[i] << ' ';
	}
	
	cout << endl;

	for (int i = 1; i <= n; i++)
	{
		cout << i << ':' << component[i] << endl;
	}

	
	fclose(file);
}