#include <iostream>
using namespace std;

// Vertice
#include "GraphM.h"
#include "Graph.h"
// Arco

void menuMatrixGraph(GraphM<int>& grafoM){

    int choice;

    do {
        cout << "\n\n---------- Menú de Operaciones - Matriz de Ayacencias ----------\n";
        cout << "1. Agregar vértice\n";
        cout << "2. Agregar arista\n";
        cout << "3. Eliminar vértice\n";
        cout << "4. Eliminar arista\n";
        cout << "5. Imprimir grafo\n";
        cout << "6. Salir\n";
        cout << "Ingrese su elección (1-6): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int vertex;
                cout << "Ingrese el vértice a agregar: ";
                cin >> vertex;
                grafoM.addVertex(vertex);
                break;
            }
            case 2: {
                int source, destination, weight;
                cout << "Ingrese el vértice de origen: ";
                cin >> source;
                cout << "Ingrese el vértice de destino: ";
                cin >> destination;
                cout << "Ingrese el peso de la arista (1<=w): ";
                cin >> weight;
                grafoM.addEdge(Edge<int>(source, destination, weight));
                break;
            }
            case 3: {
                int vertex;
                cout << "Ingrese el vértice a eliminar: ";
                cin >> vertex;
                grafoM.removeVertex(vertex);
                break;
            }
            case 4: {
                int source, destination;
                cout << "Ingrese el vértice de origen: ";
                cin >> source;
                cout << "Ingrese el vértice de destino: ";
                cin >> destination;
                grafoM.removeEdge(Edge<int>(source, destination));
                break;
            }
            case 5:
                cout << "Grafo actual:\n";
                grafoM.print();
                break;
            case 6:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Por favor, elija de nuevo.\n";
        }

    } while (choice != 6);
}

void menuListGraph(Graph<int>& grafo){
    int choice;

    do {
        cout << "\n\n---------- Menú de Operaciones - Lista de adyacencias ----------\n";
        cout << "1. Agregar vértice\n";
        cout << "2. Agregar arista\n";
        cout << "3. Eliminar vértice\n";
        cout << "4. Eliminar arista\n";
        cout << "5. Imprimir grafo\n";
        cout << "6. Método DFS\n";
        cout << "7. Método BFS\n";
        cout << "8. Método Dijkstra\n";
        cout << "9. Salir\n";
        cout << "Ingrese su elección (1-8): ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int vertex;
                cout << "Ingrese el vértice a agregar: ";
                cin >> vertex;
                grafo.addVertex(vertex);
                break;
            }
            case 2: {
                int source, destination, weight;
                cout << "Ingrese el vértice de origen: ";
                cin >> source;
                cout << "Ingrese el vértice de destino: ";
                cin >> destination;
                cout << "Ingrese el peso de la arista (1<=w): ";
                cin >> weight;
                grafo.addEdge(Edge<int>(source, destination, weight));
                break;
            }
            case 3: {
                int vertex;
                cout << "Ingrese el vértice a eliminar: ";
                cin >> vertex;
                grafo.removeVertex(vertex);
                break;
            }
            case 4: {
                int source, destination;
                cout << "Ingrese el vértice de origen: ";
                cin >> source;
                cout << "Ingrese el vértice de destino: ";
                cin >> destination;
                grafo.removeEdge(Edge<int>(source, destination));
                break;
            }
            case 5:
                cout << "Grafo actual:\n";
                grafo.print();
                break;
            case 6:
                int vertex;
                cout << "\nMétodo de DFS\n";
                cout << "Ingresa el vértice: "; cin >> vertex;
                grafo.dfs(vertex);
                break;
            case 7:
                int v;
                cout << "\nMétodo de BFS\n";
                cout << "Ingresa el vértice: "; cin >> v;
                grafo.bfs(v);
                break;
            case 8:
                int v1;
                cout << "\nMétodo Dijkstra\n";
                cout << "Ingresa el vértice: "; cin >> v1;
                grafo.dijkstra(v1);
            case 9:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Por favor, elija de nuevo.\n";
        }

    } while (choice != 9);
}


void start(){

    cout << "\n---------- MENU - Inicializar Grafos ----------"<< endl;
    
    vector<int> vertex;
    vector<Edge<int>> edges;

    int t;
    cout << "Ingresa n cantidad de elementos para inicializar el grafo: "; 
    cin >> t;
    for(int i=0;i<t;i++){
        int v;
        cout << "Vertex [" << i << "]: "; cin >> v; 
        vertex.push_back(v);
    }

    int e;
    cout << "\nIngresa n cantidad de relaciones para inicializar el grafo: ";
    cin >> e;
    for(int i=0;i<e;i++){
        int s, t, w;
        cout << "Source [" << i << "]: "; cin >> s;
        cout << "Target [" << i << "]: "; cin >> t;
        cout << "Weight [" << i << "]: "; cin >> w;
        cout << endl;
        edges.emplace_back(s,t,w);
    }
    
    // Inicializar los grafos
    GraphM<int> grafoM(vertex, edges);
    Graph<int> grafo(vertex,edges);
    
    int choice;

    do
    {
        cout << "\n---------- MENU - Grafos (INT) ----------" << endl;
        cout << "1) Usar Grafo con Matriz de Adyacencia" << endl;
        cout << "2) Usar Grafo con Lista de Adyacencia" << endl;
        cout << "3) Salir" << endl;
        cout << "Ingresa una opción (1-3): ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                menuMatrixGraph(grafoM);
                break;
            case 2:
                menuListGraph(grafo);
                break;
            case 3:
                cout << "Saliendo del programa.\n";
                break;
            default:
                cout << "Opción no válida. Por favor, elija de nuevo.\n";
        }
        
    } while (choice != 3);

}


int main()
{
    start();

    // vector<int> vertices;
    // for(int i=0;i<6;i++){
    //     vertices.push_back(i);
    // }
    
    // vector<Edge<int>> edges;
    // edges.emplace_back(Edge(0,1,5));
    // edges.emplace_back(Edge(1,2,5));
    // edges.emplace_back(Edge(2,3,5));
    // edges.emplace_back(Edge(3,1,5));
    // edges.emplace_back(Edge(4,2,5));
    // edges.emplace_back(Edge(5,3,5));
    // edges.emplace_back(Edge(1,5,5));
    // edges.emplace_back(Edge(5,3,5));
    // edges.emplace_back(Edge(3,2,5));

    // Graph<int> grafo(vertices,edges);
    // grafo.print();

    // cout << endl;
    // grafo.dijkstra(1);

    return 0;
}
