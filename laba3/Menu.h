#ifndef MENU_H
#define MENU_H
#include "Graph.h"
#include <chrono>

using namespace std;

template <class T>
void Menu()
{
	cout << "Menu:" << endl;
	int indicator = 0;
	int n;
	Graph<T> graph = Graph<T>();

	while (indicator != 7)
	{
		cout << "1.Enter edges:" << endl << "2.Print graph" << endl << "3.Insert edge" << endl << "4.Delet"
			<< endl << "5.Find a way" << endl << "6.DFS" << endl<<"7.End"<<endl;
		
		cin >> indicator;

		if (indicator == 1)
		{
			cout << "How many edge:";
			
			cin >> n;

			cout << "1. Random" << endl << "2.Ñonsole" << endl;
			int indicator1;
			cin >> indicator1;

			T* arr = new T[n];
			srand(time(0));
			for (int i = 0; i < n; i++)
			{
				arr[i] = 1 + rand() % (n+1);
			}

				if (indicator1 == 1)
				{
					vector<Edge<T>> edges(n);

					for (int i = 0; i < n; i++)
					{
						Edge<T> edge;
						edge.first = arr[0 + rand() % n];
						edge.second = arr[0 + rand() % n];

						edges.push_back(edge);
					}
					graph = Graph<T>(edges, n+2);
				}

				if (indicator1 == 2)
				{
					vector<Edge<T>> edges(n+1);
					for (int i = 0; i < n; i++)
					{
						Edge<T> edge;
						cout << "Enter point: ";
						cin >> edge.first;
						cout << "Connected with: ";
						cin >> edge.second;

						edges.push_back(edge);
					}
					graph = Graph<T>(edges, n+2);
				}
		}

		if (indicator == 2)
		{
			graph.printGraph();
		}

		if (indicator == 3)
		{
			Edge<T> edge;
			cout << "Enter point: ";
			cin >> edge.first;
			cout << "Connected with: ";
			cin >> edge.second;
			graph.Insert(edge);
		}

		if (indicator == 4)
		{
			T key;
			cout << "Enter point: ";
			cin >> key;
			graph.Delet(key);
		}

		if (indicator == 5)
		{
			T start;
			cout << "Enter start: ";
			cin >> start;
			T end;
			cout << "Enter end: ";
			cin >> end;

			graph.BFS(start, end);
		}
		if (indicator == 6)
		{
			cout << "Enter start: ";
			T start;
			cin >> start;
			graph.DFS(start);
		}


	}
}

#endif // !MENU_H
