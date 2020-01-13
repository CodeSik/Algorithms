#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>

//최대 노드의 값과 나올 수 없는 경로 설정
const int MAX_N = 5000;
const int INF = 1000000000;

using namespace std;

//pair의 앞은 최단경로cost 뒤는 이전노드
typedef pair<int, int> p;

//우선순위큐의 인자는 pair p
priority_queue<p> pq;

//인접행렬의 템플릿 인자또한 p로 설정(다른 그래프와 달리 cost가 정의되어있기 때문)
vector<p> adj[MAX_N-1];

vector<int> Dijk(int first, int v)
{
	//모든 경로에 대한 최단거리를 무한으로 설정해준다.
	vector<int> dist(v, INF);
	//자신에 대한 cost = 0
	dist[first] = 0;
	
	//제일 처음 지나간 경로를 넣어준다.
	pq.push(p(0, first));

	//pq가 empty가 아닐 동안
	while (!pq.empty())
	{
		//pair의 첫값은 cost, 뒤의 값은 전 노드로 각각 변수에 저장
		int weight = -pq.top().first;
		int bef = pq.top().second;
		//저장한 후 그 값을 빼준다.
		pq.pop();

		//그 전 경로의 값이 cost보다 작으면 update하지 않는다.
		if (dist[bef] < weight)
			continue;

		//그렇지 않은 경우에 relax를 해준다. (update)
		for (int i = 0; i < adj[bef].size(); i++)
		{
			int aft = adj[bef][i].first;
			//업데이트 한 dist를 dist[aft]에 저장하기 위함
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
	int n = 0; // 노드의 갯수
	int e;

	FILE* file = fopen("input4.txt", "r");
	fscanf(file, "%d\n", &n);

	if (n < 1 || n >= MAX_N) { // 노드 1개이상 5000개미만
		exit(-1);
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			fscanf(file, "%d ", &e);
			if (e >= 1 && e < 100) //weight 값 조건
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

