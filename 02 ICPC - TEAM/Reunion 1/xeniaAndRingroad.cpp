#include <iostream>
using namespace std;
#include <vector>

int main()
{
    int n, m;
    cin >> n >> m;
    
    vector<int> tasks;
    for(int i=0;i<m;i++){
        int x;
        cin >> x;
        tasks.push_back(x);
    }

    int numTasks = tasks.size();
    int time = 0;
    int posicion = 1;
    
    while(numTasks != 0){
        while (tasks[0] != posicion){
            time++;     // valor de tiempo
            if (n == posicion){ // Si la posicion es la ultima casa
                posicion = 1; // reiniciar la posicion
            } else {
                posicion++; // posicion actual
            }
        }
        
        // Eliminar la primera tarea4
        tasks.erase(tasks.begin());
        // Actualizar el tamaño
        numTasks = tasks.size();
    }
    cout << time;
    return 0;
}
