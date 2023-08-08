#include <iostream>
using namespace std;

int main()
{
    string name, id, degree, collage;
    cout << "INFORMACIÓN GENERAL" << endl;
    cout << "Nombre: ";
    cin >> name;
    cout << "Matricula: ";
    cin >> id;
    cout << "Carrera (Siglas): ";
    cin >> degree;
    cout << "Universidad: ";
    cin >> collage; 
    
    cout << "\nINFORMACIÓN GENERAL" << endl;
    cout << "Sr. " << name << ", se le informa que el día de mañana viernes el " << collage << " realiza un festival, solo presenta tu matricula "<< id << " y menciona las siglas de tu carrera " << degree << endl;
}
