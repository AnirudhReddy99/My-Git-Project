#include <iostream> 
#include <limits.h> 
#include <list> 
#include <queue>

using namespace std; 

#define Vertex 9 

int minDistance(int distance[], bool sptSet[]) 
{ 
	int min = INT_MAX, min_index; 

	for (int v = 0; v < Vertex; v++) 
		if (sptSet[v] == false && distance[v] <= min) 
			min = distance[v], min_index = v; 

	return min_index; 
} 

void printSolution(int distance[], int n) 
{ 
	printf("Vertex Distance from Source\n"); 
	for (int i = 0; i < Vertex; i++) 
		printf("%d tt %d\n", i, distance[i]); 
} 


void dijkstra(int graph[Vertex][Vertex], int src) 
{ 
	int distance[Vertex]; 

	bool sptSet[Vertex]; 

	for (int i = 0; i < Vertex; i++) 
		distance[i] = INT_MAX, sptSet[i] = false; 

	distance[src] = 0; 

	for (int count = 0; count < Vertex - 1; count++) { 
		int u = minDistance(distance, sptSet); 

		sptSet[u] = true; 

		for (int v = 0; v < Vertex; v++) 
			if (!sptSet[v] && graph[u][v] && distance[u] != INT_MAX 
				&& distance[u] + graph[u][v] < distance[v]) 
				distance[v] = distance[u] + graph[u][v]; 
	} 

	printSolution(distance, Vertex); 
} 

int main() 
{ 
	int graph[Vertex][Vertex] = { { 0, 4, 0, 0, 0, 0,  8, 0 }, 
						{ 4, 0, 8, 0, 0, 0,  11, 0 }, 
						{ 0, 8, 0, 7, 0, 4,  0, 2 }, 
						{ 0, 0, 7, 0, 9, 14, 0,  0 }, 
						{ 0, 0, 0, 9, 0, 10, 0,  0 }, 
						{ 0, 0, 4, 14, 10, 0, 2, 0 }, 
						{ 0, 0, 0, 0, 0, 2, 1, 6 }, 
						{ 8, 11, 0, 0, 0, 0, 1, 7 }, 
						{ 0, 0, 2, 0, 0, 0, 6, 7 } }; 

	dijkstra(graph, 0); 

	return 0; 
}
