// Jesús Ricardo Guerrero Silvestre
// A00835912
// Ingenería en Robótica y Sistemas Digitales
// Fecha: 10 de Septiembre de 2023

#include <iostream>
using namespace std;

#include <fstream>
#include <sstream>
#include <string.h>
#include "DoublyLinkedList.h"
#include "Log.h"

// OBTENER UNA DOUBLY LINKED LIST CON LOS DATOS DEL ARCHIVO TXT
DoublyLinkedList<Log> obtenerList(string n){
    ifstream fileIn(n);
    string line;
    string word;

    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;

    DoublyLinkedList<Log> logs;

    while (getline(fileIn,line)) { 
        stringstream ss(line);
        ss >> month >> day >> year >> time >> ip >> message;
        while (ss >> word) {
            message = message + " " + word;
        }
        Log aux(year, month, day, time, ip, message);
        logs.addLast(aux);
    }
    return logs;
}

// GUARDA EL VECTOR EN EL ARCHIVO TXT
void guardarEnTxt(DoublyLinkedList<Log> logs,string n,string mode){
    if (mode == "asc"){
        ofstream fileOut(n);
        if (!fileOut)
        {
            cout << "Error al abrir \n";
            exit(EXIT_FAILURE);
        }
        for (int i = 0; i < logs.getSize(); ++i){
            fileOut << logs[i].month << " " << logs[i].day << " "<< logs[i].year << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;  
        }
    } else {
        ofstream fileOut(n);
        if (!fileOut)
        {
            cout << "Error al abrir \n";
            exit(EXIT_FAILURE);
        }
        for (int i = logs.getSize()-1; i > -1; --i){
            fileOut << logs[i].month << " " << logs[i].day << " "<< logs[i].year << " " << logs[i].time << " " << logs[i].ip << " " << logs[i].message << endl;  
        }
    }
}

// BÚSQUEDA SECUENCIAL
DoublyLinkedList<Log> secuencialSearch(DoublyLinkedList<Log> list,int ipInicio,int ipFinal){
    DoublyLinkedList<Log> datosEncontrados;
    bool cont = false;

    for(int i=0; i < list.getSize(); i++){
        if(list[i].getIP() >= ipInicio && list[i].getIP() <= ipFinal){
            datosEncontrados.addLast(list[i]);
            cont = true;
        }
    }
    
    if(!cont){
        throw out_of_range("No sé encontraron valores que coincideran");
    }

    return datosEncontrados;
}

// OBTENER MES SEGUN UN ENTERO
string returnMonth(int data){
    switch (data)
    {
    case 1:
        return "Jan";
        break;
    case 2:
        return "Feb";
        break;
    case 3:
        return "Mar";
        break;
    case 4:
        return "Apr";
        break;
    case 5:
        return "May";
        break;
    case 6:
        return "Jun";
        break;
    case 7:
        return "Jul";
        break;
    case 8:
        return "Aug";
        break;
    case 9:
        return "Sep";
        break;
    case 10:
        return "Oct";
        break;
    case 11:
        return "Nov";
        break;
    case 12:
        return "Dec";
        break;
    default:
        throw out_of_range ("No se encuentra ese mes");
        break; 
    }
}

// CONVERTIR IP DE STRING A INT
int getIP(string ip){
   
    // Quitarle los signos al IPs
    string ip1String;
    string ip2String;
    string ip3String;
    string ip4String;
    int ip1 = 0;
    int ip2 = 0;
    int ip3 = 0;
    int ip4 = 0;
 
    int contador = 0;
    for (char c : ip) {
        if (c != '.' && contador == 0) {
            ip1String += c;
        } else if (c != '.' && contador == 1) {
            ip2String += c;
        } else if (c != '.' && contador == 2) {
            ip3String += c;
        } else if (c != '.' && contador == 3) {
            ip4String += c;
        } else if (c == '.'){
            contador++;
        }
    }

    ip1 = stoi(ip1String);
    ip2 = stoi(ip2String);
    ip3 = stoi(ip3String);
    ip4 = stoi(ip4String);

    // Convertimos IP
    ip1 *= 100000000;
    ip2 *= 1000000;
    ip3 *= 1000;

    // Convertimos IP de INT a STRING
   long ipEntero = ip1 + ip2 + ip3 + ip4;

   return ipEntero;
}


// REGISTRAR FECHAS
int obtenerFecha(int mode){
    string ip = " ";
    int ipInt = 0;
    if (mode == 1){
        cout << "Registrar fecha Inicial" << endl;
        cout << "Ingresa el ip: "; cin >> ip;
        ipInt = getIP(ip);
        return ipInt;
    } else if (mode == 2){
        cout << "Registrar fecha Final" << endl;
        cout << "Ingresa el ip: "; cin >> ip;
        ipInt = getIP(ip);
        return ipInt;
    }
    return -1;
}

void start(){
    int option = 0;
    
    // Crear la DLL
    DoublyLinkedList<Log> dll;
    // Guardar los datos del TXT en la DLL
    dll = obtenerList("log602-2.txt");

    // DLL auxiliar para realizar la búsqueda
    DoublyLinkedList<Log> resultOfSearch;

    while (option != 5){
        cout << endl << "--------- MENU GENERAL ---------" << endl;
        cout << "1) Orden los datos por fecha y hora." << endl;
        cout << "2) Ordena los datos por ip, fecha y hora." << endl;
        cout << "3) Búsqueda por rango de ip's." << endl;
        cout << "4) Sumatoria de datos." << endl;
        cout << "5) Salir." << endl;
        cout << "Ingresa el número de la opción: " ;
        cin >> option;
        cout << endl;   

        if (option == 1){
            cout << "Orden los datos por fecha y hora." << endl;
            // Ordenar DLL por fecha y hora
            dll.quickSort(dll.getHead(),dll.getTail(),1);
            guardarEnTxt(dll,"output602-1.out","asc");
            dll.print("asc");
        } 
        else if (option == 2){
            cout << "Ordena los datos por ip, fecha y hora." << endl;
            // Ordenar DLL por IPs, fecha y hora
            dll.quickSort(dll.getHead(),dll.getTail(),2);
            guardarEnTxt(dll,"output602-2.out","asc");
            dll.print("asc");
        } 
        else if (option == 3){
            cout << "Búsqueda por rango de ip's." << endl;
            int fI = obtenerFecha(1);
            int fF = obtenerFecha(2);

            while (fI >= fF){
                cout << endl << "--------- ERROR ---------" << endl;
                cout << "¡¡¡Fecha Inicial debe ser menor a Fecha Final!!!" << endl;
                int fI = obtenerFecha(1);
                int fF = obtenerFecha(2);
            }

            // Hay que asegurar que los datos están ordenados
            dll.quickSort(dll.getHead(),dll.getTail(),2);
            resultOfSearch = secuencialSearch(dll,fI,fF);
            resultOfSearch.quickSort(resultOfSearch.getHead(),resultOfSearch.getTail(),2);

            // Guardar los datos de la búsqueda
            guardarEnTxt(resultOfSearch,"iprange602-a.out","asc");
            guardarEnTxt(resultOfSearch,"iprange602-d.out","des");    
            
            // Impresión de la lista obtenida
            cout << "Resultados de los datos de la búsqueda: " << endl;
            resultOfSearch.print("asc");
        }
        else if (option == 4){
            // Sumatoria de datos
            DNode<Log>* aux = dll.getHead();
            int yearMax;
            int yearMin;
            // Obtener el año menor y mayor
            if (aux != nullptr) {
                yearMax = aux->data.getYear();
                yearMin = aux->data.getYear();

                aux = aux->next;

                while (aux != nullptr) {
                    int currentYear = aux->data.getYear();
                    if (currentYear > yearMax) {
                        yearMax = currentYear;
                    } else if (currentYear < yearMin) {
                        yearMin = currentYear;
                    }

                    aux = aux->next;
                }
            }

            cout << "Cantidad de IPs por año y mes:" << endl;
            
            for (int i = yearMin;i<=yearMax;i++){ // Recorrer por año
                cout << endl << i << endl;
                for (int j=1;j<=12;j++){    // Recorrer por mes
                    cout << returnMonth(j) << ": ";
                    // Contar mes y año
                    DNode<Log>* auxLog = dll.getHead();
                    int count = 0;

                    while (auxLog != nullptr) {
                        int currentYear = auxLog->data.getYear();
                        int currentMonth = auxLog->data.getMonthInt();
                        
                        if (currentYear == i && currentMonth == j) { // Llevar contador de mes y año
                            count++;
                        }

                        auxLog = auxLog->next;
                    }
                    cout << count << endl;
                }
            }
        }
    }
}

int main() {
    start();
    return 0;
}
