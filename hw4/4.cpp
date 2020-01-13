#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

//�ִ� ����� ���� ���� �� ���� ��� ����
const int MAX_N = 5000;
const int INF = 1000000000;

using namespace std;

//pair�� ���� �ִܰ��cost �ڴ� �������
typedef pair<int, int> p;

//�켱����ť�� ���ڴ� pair p
priority_queue<p> pq;

//��������� ���ø� ���ڶ��� p�� ����(�ٸ� �׷����� �޸� cost�� ���ǵǾ��ֱ� ����)
vector<p> adj[MAX_N-1];

vector<int> Dijk(int first, int v)
{
	//��� ��ο� ���� �ִܰŸ��� �������� �������ش�.
	vector<int> dist(v, INF);
	//�ڽſ� ���� cost = 0
	dist[first] = 0;
	
	//���� ó�� ������ ��θ� �־��ش�.
	pq.push(p(0, first));

	//pq�� empty�� �ƴ� ����
	while (!pq.empty())
	{
		//pair�� ù���� cost, ���� ���� �� ���� ���� ������ ����
		int weight = -pq.top().first;
		int bef = pq.top().second;
		//������ �� �� ���� ���ش�.
		pq.pop();

		//�� �� ����� ���� cost���� ������ update���� �ʴ´�.
		if (dist[bef] < weight)
			continue;

		//�׷��� ���� ��쿡 relax�� ���ش�. (update)
		for (int i = 0; i < adj[bef].size(); i++)
		{
			int aft = adj[bef][i].first;
			//������Ʈ �� dist�� dist[aft]�� �����ϱ� ����
			int dist_bef_aft = weight + adj[bef][i].second; 
			if (dist_bef_aft < dist[aft])
			{
				dist[aft] = dist_bef_aft;
				pq.push(p(-dist_bef_aft, aft));
			}
		}
	}

	return dist;
}



int main()
{
	int n = 0; // ����� ����
	int e;

	FILE* file = fopen("input4.txt", "r");
	fscanf(file, "%d\n", &n);

	if (n < 1 || n >= MAX_N) { // ��� 1���̻� 5000���̸�
		exit(-1);
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(file, "%d ", &e);
			if (e >= 1 && e < 100) //weight �� ����
			{
				adj[i].push_back(p(j,e));
			}
			if (feof(file))
			{
				break;
			}

		}

	}

	vector<int> dist = Dijk(0, n);

	for (int i = 0; i < n; i++) {
		cout << dist[i] << " ";
	}
	fclose(file);
}

