// Jesús Ricardo Guerrero Silvestre
// A00835912
// Ingenería en Robótica y Sistemas Digitales
// Fecha: 26 de Octubre de 2023

#include <iostream>
using namespace std;

#include <fstream>
#include <sstream>
#include <string.h>
#include "Heap.h"
#include "MinHeap.h"
#include "BST.h"
#include "Log.h"
#include "contadorIP.h"

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

    vector<Log> list;

    while (getline(fileIn,line)) { 
        stringstream ss(line);
        ss >> month >> day >> year >> time >> ip >> message;
        while (ss >> word) {
            message = message + " " + word;
        }
        Log aux(year, month, day, time, ip, message);
        list.push_back(aux);
    }
    return list;
}

// GUARDA EL VECTOR EN EL ARCHIVO TXT
void guardarEnTxt(vector<Log> &list,string n){
    ofstream fileOut(n);
    if (!fileOut)
    {
        cout << "Error al abrir \n";
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < list.size(); ++i){
        fileOut << list[i].month << " " << list[i].day << " "<< list[i].year << " " << list[i].time << " " << list[i].ip << " " << list[i].message << endl;  
    }
}

// ALGORITMO DE ORDENAMIENTO HEAP SORT
template <class T>
void heapSort(vector<T> &list, string order) {
    if (order == "des") {
        Heap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    } else if (order == "asc") {
        MinHeap<T> heap(list);
        for (int i = 0; i < list.size(); i++) {
            list[i] = heap.pop();
        }
    }
}

// Encontrar las IPs
Heap<contadorIP> encontrarIPs(vector<Log> logLines) {
    vector<contadorIP> listIPs;

    // Pasar por todos los Logs
    for (Log& log : logLines) {
        bool found = false;

        // Pasar por todas la IPs halladas
        for (contadorIP& ipCount : listIPs) {
            if (ipCount.getIP() == log.getIP()) {
                ipCount.reps++;
                found = true;
                break;
            }
        }

        // Se encontró un elemento y no se repite
        if (!found) {
            contadorIP ipCount;
            ipCount.IP = log.ip;
            ipCount.reps = 1;
            listIPs.push_back(ipCount);
        }
    }
    
    // Ordenar la lista de valores encontrados
    Heap<contadorIP> ipsEncontrados;
    ipsEncontrados = Heap<contadorIP>(listIPs);
    heapSort(ipsEncontrados.returnList(),"des");

    // Regresar una lista ya ordenada
    return ipsEncontrados;
}

// MENU PRINCIPAL
void start(){
    // Obtener la lectura del vector
    vector<Log> list;
    list = obtenerList("log602-3.txt");
    // Crear un Heap de la lista
    Heap<Log> heap1 = list;
    int option = 0;

    while (option != 5){
        cout << endl << "--------- MENU GENERAL ---------" << endl;
        cout << "1) Guardar datos de Mayor a Menor - Ordena los datos por IP, fecha y hora." << endl;
        cout << "2) Guardar datos de Menor a Mayor - Ordena los datos por IP, fecha y hora." << endl;
        cout << "3) Imprimir 10 ip's con mayor número de registros." << endl;
        cout << "4) Búsqueda de una ip en un árbol binario de búsqueda." << endl;
        cout << "5) Salir." << endl;
        cout << "Ingresa el número de la opción: " ;
        cin >> option;
        cout << endl;   

        while(option < 1 || option > 5){
            cout << endl << "--------- MENU GENERAL ---------";
            cout << endl << "----- Respuesta no válida ------" << endl;
            cout << "1) Guardar datos de Mayor a Menor - Ordena los datos por IP, fecha y hora." << endl;
            cout << "2) Guardar datos de Menor a Mayor - Ordena los datos por IP, fecha y hora." << endl;
            cout << "3) Imprimir 10 ip's con mayor número de registros." << endl;
            cout << "4) Búsqueda de una ip en un árbol binario de búsqueda." << endl;
            cout << "5) Salir." << endl;
            cout << "Ingresa el número de la opción: " ;
            cin >> option;
            cout << endl; 
        }  

        if (option == 1){
            cout << "Guardar datos de Mayor a Menor." << endl;
            // Mayor -> Menor
            heapSort(heap1.returnList(),"des");
            guardarEnTxt(heap1.returnList(),"output602-1.out");
        } 
        else if (option == 2){
            cout << "Guardar datos de Menor a Mayor." << endl;
            // Menor -> Mayor
            heapSort(heap1.returnList(),"asc");
            guardarEnTxt(heap1.returnList(),"output602-2.out");
        } 
        else if (option == 3){
            cout << "Imprimir 10 ip's con mayor frecuencia" << endl;
            Heap<contadorIP> ipsEncontradas;
            ipsEncontradas = encontrarIPs(list);
            // Copiar los 10 elementos
            for(int i=0;i<10;i++){
                cout << "IP: " << ipsEncontradas.returnList()[i].IP << "  Total: " << ipsEncontradas.returnList()[i].reps << endl; 
            }
        }
        else if (option == 4){            
            BST<string> tree;
            string ipX;
            cout << "Búsqueda de una IP" << endl;
            cout << "Ingresa el IP: "; 
            cin >> ipX;

            for(int i=0;i<list.size();i++){
                tree.insert(list[i].ip);
            }
            
            cout << "Repeticiones de IP: " << tree.findNumRepsIP(ipX) << endl;
        }
    }
}

int main()
{
    start();

    return 0;
}