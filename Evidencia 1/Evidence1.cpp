// Jesús Ricardo Guerrero Silvestre
// A00835912
// Ingenería en Robótica y Sistemas Digitales
// Fecha: 10 de Septiembre de 2023

#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include "Log.h"
using namespace std;

// FUNCIÓN PARA IMPRIMIR UN VECTOR
void print(vector<Log> list){
    for (auto l : list) {
        cout << l.month << " " << l.day << " "<< l.year << " " << l.time << " " << l.ip << " " << l.message << endl;  
    }
    cout << endl;
}

// OBTENER UN VECTOR CON LOS DATOS DEL ARCHIVO TXT
vector<Log> obtenerList(string n){
    ifstream fileIn(n);
    string line;
    string word;

    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;

    vector<Log> logs;

    while (getline(fileIn,line)) { 
        stringstream ss(line);
        ss >> month >> day >> year >> time >> ip >> message;
        while (ss >> word) {
            message = message + " " + word;
        }
        Log log(year, month, day, time, ip, message);
        logs.push_back(log);
    }
    return logs;
}

// GUARDA EL VECTOR EN EL ARCHIVO TXT
void guardarEnTxt(vector<Log> logs,string n){
    ofstream fileOut(n);
    if (!fileOut)
    {
        cout << "Error al abrir \n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < logs.size(); ++i){
        fileOut << logs[i].month << " " << logs[i].day << " "<< logs[i].year << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;  
    }
}

// FUNCIÓN PARA CAMBIAR 2 ELEMENTOS DENTRO DE UN VECTOR
template<class T>
void swap(vector<T> &list, int a, int b){
    if (a != b) {
        T aux = list[a];
        list[a] = list[b];
        list[b] = aux;
    }
}

// ELIMINAR UN ELEMENTO DEL VECTOR
template <typename T>
void remove(std::vector<T>& v, size_t index){
    v.erase(v.begin() + index);
}


template<class T>
int getPivot(vector<T> &list, int left, int right){
    int pivot = right;
    int auxIndex = left-1;

    for(int index=left;index < right;index++){
        if (list[index] < list[pivot]){
            auxIndex++;
            swap(list, index, auxIndex);
        }
    }

    // Incrementamos el índice auxiliar
    auxIndex++;
    // Intercambiamos el indice auxiliar con el pivot
    swap(list, pivot, auxIndex);    
    // Regresamoe el indice auxliar
    return auxIndex;
}

// MÉTODO DE QUICK SORT
template<class T>
void quickSort(vector<T> &list, int left, int right) {
    if (left < right) {
        int pivot = getPivot(list, left, right);
        quickSort(list, left, pivot-1);
        quickSort(list, pivot+1, right);
    }
}


// BÚSQUEDA BINARIA
vector<Log> binarySearch(vector<Log> list, long timeI, long timeF){
    
    vector<Log> listAux;
    int left = 0;
    int right = list.size() - 1;

    while(left <= right){
        int mid = left + (right - left)/2;
        
        if (list[mid].key >= timeI && list[mid].key <= timeF){
            listAux.push_back(list[mid]);
            remove(list, mid);
        }
        else {
            if (list[mid].key > timeF){
                right = mid-1;
            }
            else if (list[mid].key < timeI){
                left = mid+1;
            }
        }
    }
    return listAux;
}


// OBTENER LA FECHA
long obtenerFecha(){
    long keyResult;

    int year = 0;
    int month = 0;
    string monthString = "";
    int day = 0;

    int hora = 0;
    int minute = 0;
    int seconds = 0;

    cout << endl << "Ingresa el año: ";
    cin >> year;

    cout << "Ingresa el mes en formato de tres letras (Jan,Feb,Mar): ";
    cin >> monthString;

    cout << "Ingresa el día (1 - 31): ";
    cin >> day;

    cout << "Ingresa la hora (00 - 23): ";
    cin >> hora;

    cout << "Ingresa los minutos (00 - 59): ";
    cin >> minute;

    cout << "Ingresa los segundos (00 - 59): ";
    cin >> seconds;

    if (monthString == "Jan"){
        month = 1;
    }
    else if (monthString == "Feb"){
        month = 2;
    }
    else if (monthString == "Mar"){
        month = 3;
    }
    else if (monthString == "Apr"){
        month = 4;
    }
    else if (monthString == "May"){
        month = 5;
    }
    else if (monthString == "Jun"){
        month = 6;
    }
    else if (monthString == "Jul"){
        month = 7;
    }
    else if (monthString == "Aug"){
        month = 8;
    }
    else if (monthString == "Sep"){
        month = 9;
    }
    else if (monthString == "Oct"){
        month = 10;
    }
    else if (monthString == "Nov"){
        month = 11;
    }
    else if (monthString == "Dec"){
        month = 12;
    }


    long yearLong = year * 10000000000;
    long monthLong = month * 100000000;
    long dayLong = day * 1000000;
    hora = hora * 10000;
    minute = minute * 100;
    keyResult = yearLong + monthLong + dayLong + hora + minute + seconds;
    
    return keyResult;
}


// MENÚ
void start(){
    int opcion = 0;
    
    vector<Log> logs;
    vector<Log> logsOrdenada;
    vector<Log> logsAux;
    
    logs = obtenerList("log602.txt");

    logsOrdenada = logs;
    quickSort(logsOrdenada, 0, logsOrdenada.size()-1);
    guardarEnTxt(logsOrdenada,"output602.txt"); 

    while(opcion != 4){
        cout << endl << "MENU GENERAL" << endl;
        cout << "1) Consultar lista original" << endl;
        cout << "2) Consultar lista ordenada" << endl;
        cout << "3) Realizar búsqueda" << endl;
        cout << "4) Salir" << endl;
        cout << "Ingresa el número de la opción: " ;
        cin >> opcion;
        cout << endl;
        
        if (opcion == 1){
            cout << "Lista Original: " << endl;
            print(logs);
        }
        else if (opcion == 2){           
            cout << "Lista Ordenada: " << endl;    
            print(logsOrdenada);
        }
        else if (opcion == 3){
            long fI, fF;
            cout << "Fecha Inicial";
            fI = obtenerFecha();

            cout << endl << "Fecha Final";
            fF = obtenerFecha();

            while(fI > fF){
                cout << endl << "La fecha Inicial debe ser mayor a la fecha Final." << endl;
                cout << "Escribe las fechas correctamente." << endl;
                
                cout << endl << "Fecha Inicial";
                fI = obtenerFecha();
                cout << endl << "Fecha Final";
                fF = obtenerFecha();
            }
            
            logsAux = binarySearch(logsOrdenada,fI,fF);
            guardarEnTxt(logsAux,"range602.txt");

            cout << endl << "Eventos que coinciden con la búsqueda: " << endl;
            print(logsAux);
        }
    }
}

int main() {
    start();
    return 0;
}