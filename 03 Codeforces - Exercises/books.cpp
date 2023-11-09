#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    vector<int> v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    
    int max_books = 0;
    
    int current_time = 0;
    int j = 0;
    for(int i = 0; i < n; i++){
        // Añadir el libro actual al tiempo total
        current_time += v[i];
        
        // Mientras el tiempo total exceda el tiempo disponible,
        // quitar libros desde el principio de la ventana.
        while(current_time > t && j <= i){
            current_time -= v[j];
            j++;
        }
        
        // Actualizar la cantidad máxima de libros si es necesario
        max_books = max(max_books, i - j + 1);
    }
    
    cout << max_books << endl;
    return 0;
}
