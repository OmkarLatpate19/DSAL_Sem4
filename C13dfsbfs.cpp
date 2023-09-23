#include <iostream>
#include <stack>
#include <queue>
#include <vector>
#define MAX 10
using namespace std;

int v;
int adj_mat[MAX][MAX] = {0};
vector<vector<int>> adj_list = {{}};

void dfs(int mat[MAX][MAX])
{

	bool visited[MAX] = {false};
	stack<int> s;
	s.push(0);

	while (!s.empty())
	{

		int t = s.top();
		if (visited[t] == false)
		{
			cout << t << "  ";
		}
		visited[t] = true;
		bool flag = false;
		for (int i = 0; i < v; i++)
		{
			if (mat[t][i] == 1 && visited[i] == false)
			{
				s.push(i);
				flag = true;
				break;
			}
		}

		if (!flag)
		{
			s.pop();
		}
	}
}

void bfs()
{

	bool visited[MAX] = {false};
	queue<int> q;
	q.push(0);
	visited[0] = true;

	while (!q.empty())
	{

		int t = q.front();
		cout << t << "  ";
		q.pop();

		for (int i = 0; i < adj_list[t].size(); i++)
		{
			if (visited[adj_list[t][i]] == false)
			{
				visited[adj_list[t][i]] = true;
				q.push(adj_list[t][i]);
			}
		}
	}
}

int main()
{

	int e, i, j;
	cout << "Enter number of vertices :";
	cin >> v;
	for (int i = 0; i < v; i++)
	{
		adj_list.push_back({});
	}
	cout << "Enter number of edges :";
	cin >> e;
	for (int c = 0; c < e; c++)
	{
		cout << "Enter end vertices of edges  " << c + 1 << endl;
		cout << "Enter first vertex :";
		cin >> i;
		cout << "Enter second vertex :";
		cin >> j;
		adj_mat[i][j] = 1;
		adj_mat[j][i] = 1;
		adj_list[i].push_back(j);
		adj_list[j].push_back(i);
	}

	cout << "\n------:Adjacency Matrix:------" << endl;
	for (int i = 0; i < v; i++)
	{
		for (int j = 0; j < v; j++)
		{
			cout << adj_mat[i][j] << " ";
		}
		cout << endl;
	}

	cout << "\n------:Adjacency List:------" << endl;
	for (int i = 0; i < v; i++)
	{
		cout << i << "->";
		for (int j = 0; j < adj_list[i].size(); j++)
		{
			cout << adj_list[i][j] <<"  ";
		}
		cout << endl;
	}

	cout << "\n------: DFS Order :------" << endl;
	dfs(adj_mat);
	cout << "\n------: BFS Order :------" << endl;
	bfs();

	return 0;
}