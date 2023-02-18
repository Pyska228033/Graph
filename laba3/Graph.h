#ifndef GRAPH_H
#define GRAPH_H

#include "Edge.h"
#include <queue>
#include <stack>

using namespace std;

template <class T>
class Graph
{
private:

	vector<vector<T> > Matrix;
	vector<T> names;
	int size;

public:
	Graph();
	Graph(vector<Edge<T>> edges, int n);
	void Insert(Edge<T>& edge);
	void Delet(T key);
	void BFS(T start, T end);
	void DFS(T start);
	void printGraph();
};

template < class T>
Graph<T>::Graph()
{

}

template<class T>
Graph<T>::Graph(vector<Edge<T>>edges, int n)
{
	Matrix.resize(n);
	this->size = n;
	names.resize(size);

	for (Edge<T> edge : edges)
	{

		names[edge.first] = edge.first;
		for(int i = 0; i < size; i++)
			if(names[i] != edge.second )
				names[edge.second] = edge.second;

		if (Matrix[edge.first].size() != 0)
		for (T v : Matrix[edge.first])
		{
			if (v -= edge.second)
			{
				//Matrix[edge.first].push_back(edge.second);
				break;
			}
		}
		else Matrix[edge.first].push_back(edge.second);

		if (Matrix[edge.second].size() != 0)
		for (T v : Matrix[edge.second])
		{
			if (v == edge.first )
			{
				//Matrix[edge.second].push_back(edge.first);
				break;
			}
		}
			else Matrix[edge.second].push_back(edge.first);
	}
}

template<class T>
void Graph<T>::Insert(Edge<T>& edge)
{
	Matrix.resize(size+1);
	size++;
	names.resize(size);
	names[edge.first] = edge.first;

		for(int i = 0; i < size; i++)
			if(names[i] != edge.second )
				names[edge.second] = edge.second;

		if (Matrix[edge.first].size() > 0)
			for (T v : Matrix[edge.first])
			{
				if (v != edge.second)
				{
					Matrix[edge.first].push_back(edge.second);
					break;
				}
			}
		else Matrix[edge.first].push_back(edge.second);

		if (Matrix[edge.second].size() > 0)
			for (T v : Matrix[edge.second])
			{
				if (v != edge.first && edge.second != NULL)
				{
					Matrix[edge.second].push_back(edge.first);
					break;
				}
			}

		else if (edge.second != NULL)
			Matrix[edge.second].push_back(edge.first);
	
	
}

template <class T>
void Graph<T>::Delet(T key)
{
	for (T i : Matrix[key])
	{
		int n = 0;
		for (T j : Matrix[i])
		{
			n++;
			if (j == key)
			{
				Matrix[i].erase(Matrix[i].begin() + n - 1);
			}
		}
	}

	for (int i = key; i < size - 1; i++)
	{
		Matrix[i] = Matrix[i + 1];
	}

	//vector<T>().swap(Matrix[key]);
	names.erase(names.begin() + key);
	size--;
}

template < class T>
void Graph<T>::BFS(T start, T end)
{
	if (start == 0) 
	{
		cout << "ERROR";
		return;
	}
	queue<T> spis;
	vector<pair<bool,int>> discovered(size);
	
	discovered[start].first = true;
	spis.push(start);

	int k = 0;
	while (!spis.empty())
	{
		T i = spis.front();
		cout << i << " ";
		spis.pop();

		for (T index : Matrix[i])
		{
			if (discovered[index].first != true && index != end)
			{
				discovered[index].first = true;
				discovered[index].second = k;
				spis.push(index);
			}
			else if (index == end)
			{
				discovered[index].first = true;
				discovered[index].second = k;
				while (!spis.empty())
					spis.pop();
				break;
			}
		}
		k++;
	}

	if (discovered[end].first != true)
		cout << "Way not found"<< endl;
	else
	{
		stack<T> Way;
		cout << "Way: ";
		discovered[end].first = false;
		T index = end;
		while (index != start && index != 0)
		{
			vector<pair<T, int>> razm;

			for (int j = 0; j < Matrix[index].size(); j++)
			{
				T i = Matrix[index][j];

				if (discovered[i].first == true)
				{
					pair<T, int> a;
					discovered[i].first = false;
					a.first = i;
					a.second = discovered[i].second;

					razm.push_back(a);
					if (a.first == start)
						break;
				}
			}

			pair<T, int> a;
			if(razm.size() > 0)
				a = razm.front();
			if(razm.size() > 1)
				for (int j = 0; j < razm.size() - 1; j++)
				{	
					if (razm[j].second <= razm[j + 1].second)
						a = razm[j];
					else a = razm[j + 1];
				}

			Way.push(a.first);
			index = a.first;

		}
		while (!Way.empty())
		{
			cout << Way.top() << " -> ";
			Way.pop();
		}
		cout << end;

	}
	cout << endl;
}

template <class T>
void Graph<T>::DFS(T start)
{
	vector<bool> discovered(size);
	stack<T> spis;

	discovered[start] = true;
	spis.push(start);

	while (!spis.empty())
	{
		T i = spis.top();
		cout << i << " ";
		spis.pop();

		for (T index : Matrix[i])
		{
			if (discovered[index] != true)
			{
				discovered[index] = true;
				spis.push(index);
			}
		}
	}
	cout << endl;

}

template<class T>
void Graph<T>::printGraph()
{
	for (int i = 0; i < this->size; i++)
	{
		if(names[i] != NULL)
		cout << names[i] << "-->";

		for (T v : Matrix[i]) 
		{
			if(v!=NULL)
			cout << v << " ";
		}
		cout << endl;
	}
}

#endif // !GRAPH_H

