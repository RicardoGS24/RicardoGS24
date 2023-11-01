#include <iostream>
using namespace std;

// Vertice
#include "GraphM.h"
// Arco

int main()
{
    // Declarar los verticies
    vector<int> listVertices = {0,1,2,3,4,5,6,7};

    // Definir los arcos
    vector<Edge<int>> listArcos;
    
    for(int i=0;i<listVertices.size();i++){
        Edge<int> Edge1(i,i+1);
        Edge<int> Edge2(i+1,i);
        listArcos.push_back(Edge1);
        listArcos.push_back(Edge2);
    }

    // Actualizar las matrices
    GraphM<int> Matriz(listVertices,listArcos);
    Matriz.print();
    
    return 0;
}
