#pragma once
#include <string>
#include <iostream>
using namespace std;

struct Log {
    string year;
    string month;
    string day;
    string time;
    string ip;
    string message;
    
    long keyFH;
    string keyIP;
    long keyFHGenerator();
    string keyIPGenerator();

    int getIP();
    int getMonthInt();
    int getYear();

    Log();
    Log(string year, string month, string day, string time, string ip, string message);
};

// Constructor Default
Log::Log(){
    year = " ";
    month = " ";
    day = " ";
    time = " ";
    ip = " ";
    message = " ";
    keyFH = 0;
    keyIP = " ";
}

// Constructor
Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    
    // Hacer una función que genere la llave
    keyFH = keyFHGenerator();
    keyIP = keyIPGenerator();
}

// Generador de llaves Fecha - Hora
long Log::keyFHGenerator(){
    long keyResult;
    int monthEntero = 0;
    int yearEntero = stoi(year);
    int dayEntero = stoi(day);
    
    // Quitarle los signos a la hora
    string timeSinSignos;
    for (char c : time) {
        if (c != ':') {
            timeSinSignos += c;
        }
    }
    int timeEntero = stoi(timeSinSignos);

    if (month == "Jan"){
        monthEntero = 1;
    }
    else if (month == "Feb"){
        monthEntero = 2;
    }
    else if (month == "Mar"){
        monthEntero = 3;
    }
    else if (month == "Apr"){
        monthEntero = 4;
    }
    else if (month == "May"){
        monthEntero = 5;
    }
    else if (month == "Jun"){
        monthEntero = 6;
    }
    else if (month == "Jul"){
        monthEntero = 7;
    }
    else if (month == "Aug"){
        monthEntero = 8;
    }
    else if (month == "Sep"){
        monthEntero = 9;
    }
    else if (month == "Oct"){
        monthEntero = 10;
    }
    else if (month == "Nov"){
        monthEntero = 11;
    }
    else if (month == "Dec"){
        monthEntero = 12;
    }

    long yearLong = yearEntero * 10000000000;
    long monthLong = monthEntero * 100000000;
    long dayLong = dayEntero * 1000000;
    keyResult = yearLong + monthLong + dayLong + timeEntero;
    
    return keyResult;
}

// Generador de llaves Ip - Fecha - Hora
string Log::keyIPGenerator(){
    string keyResult;

    // Inicializar variables para los atributos
    int monthEntero = 0;
    int yearEntero = stoi(year);
    int dayEntero = stoi(day);
    
    // Quitarle los signos a la hora
    string timeSinSignos;
    for (char c : time) {
        if (c != ':') {
            timeSinSignos += c;
        }
    }
    // Obtener el tiempo en formato INT
    int timeEntero = stoi(timeSinSignos);

    // -------------------------------------------

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
    int ipEntero = ip1 + ip2 + ip3 + ip4;
    string ipSinSignos = to_string(ipEntero);

    // -------------------------------------------

    //Cambiar el Mes a Entero
    if (month == "Jan"){
        monthEntero = 1;
    }
    else if (month == "Feb"){
        monthEntero = 2;
    }
    else if (month == "Mar"){
        monthEntero = 3;
    }
    else if (month == "Apr"){
        monthEntero = 4;
    }
    else if (month == "May"){
        monthEntero = 5;
    }
    else if (month == "Jun"){
        monthEntero = 6;
    }
    else if (month == "Jul"){
        monthEntero = 7;
    }
    else if (month == "Aug"){
        monthEntero = 8;
    }
    else if (month == "Sep"){
        monthEntero = 9;
    }
    else if (month == "Oct"){
        monthEntero = 10;
    }
    else if (month == "Nov"){
        monthEntero = 11;
    }
    else if (month == "Dec"){
        monthEntero = 12;
    }

    //-------------------------------------------
    
    // Convertir TIEMPO
    long yearLong = yearEntero * 10000;
    long monthLong = monthEntero * 100;
    long dayLong = dayEntero;

    long sumFecha = yearLong + monthLong + dayLong;
    string fechaString = to_string(sumFecha);

    keyResult = ipSinSignos + fechaString + timeSinSignos;
    return keyResult;
}

int Log::getIP(){
   
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

int Log::getMonthInt(){
    if (month == "Jan"){
        return 1;
    }
    else if (month == "Feb"){
        return 2;
    }
    else if (month == "Mar"){
        return 3;
    }
    else if (month == "Apr"){
        return 4;
    }
    else if (month == "May"){
        return 5;
    }
    else if (month == "Jun"){
        return 6;
    }
    else if (month == "Jul"){
        return 7;
    }
    else if (month == "Aug"){
        return 8;
    }
    else if (month == "Sep"){
        return 9;
    }
    else if (month == "Oct"){
        return 10;
    }
    else if (month == "Nov"){
        return 11;
    }
    else if (month == "Dec"){
        return 12;
    }
    return 0;    
}

int Log::getYear(){
    return stoi(year);
}

