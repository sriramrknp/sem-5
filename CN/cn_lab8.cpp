// CS20B1107, SRIRAM REDDY CHEERLA

#include <bits/stdc++.h>
using namespace std;

// defining the number of vertices
#define numOfVertices 4
#define INF 999

void printMat(int mat[][numOfVertices]);

// Implementing floyd warshall algorithm
void floydWarshall(int graph[][numOfVertices])
{
    int mat[numOfVertices][numOfVertices], i, j, k;

    for (i = 0; i < numOfVertices; i++)
        for (j = 0; j < numOfVertices; j++)
            mat[i][j] = graph[i][j];

    // Adding vertices individually
    for (k = 0; k < numOfVertices; k++)
    {
        cout << "Level " << k << '\n';
        for (i = 0; i < numOfVertices; i++)
        {
            for (j = 0; j < numOfVertices; j++)
            {
                if (mat[i][k] + mat[k][j] < mat[i][j])
                    mat[i][j] = mat[i][k] + mat[k][j];
            }
            printMat(mat);
            cout << '\n';
        }
    }
    printMat(mat);
}

void printMat(int mat[][numOfVertices])
{
    for (int i = 0; i < numOfVertices; i++)
    {
        for (int j = 0; j < numOfVertices; j++)
        {
            if (mat[i][j] == INF)
                printf("%4s ", "INF");
                // cout << INF;
            else
                printf("%4d ", mat[i][j]);
                // cout << mat[i][j];
        }
        printf("\n");
    }
}

int main()
{
    int graph[numOfVertices][numOfVertices];
    cout << "Enter the vertices edges from each node\n";
    // 0 2 0 1
    // 2 0 3 7
    // 0 3 0 11
    // 1 7 11 0
    for (int i = 0; i < numOfVertices;i++)
    {
        cout << "Enter for node "<<i+1<<'\n';
        for (int j = 0; j < numOfVertices; j++)
        {
            int n;
            cin >> n;
            if(n == 0 && i!=j)
                graph[i][j] = INF;
            else
                graph[i][j] = n;
        }
    }
    floydWarshall(graph);
}