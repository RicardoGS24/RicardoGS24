#pragma once
#include <string>
#include <iostream>
using namespace std;

struct contadorIP {
    string IP;
    int reps;
    int getIP();

    contadorIP();
    contadorIP(string IP,int reps);

};

contadorIP::contadorIP(){
    IP = " ";
    reps = 0;
}

contadorIP::contadorIP(string IP,int reps){
    this->IP = IP;
    this->reps = reps;
}

bool operator>(const contadorIP& c1, const contadorIP& c2) {
    // Define aquí cómo comparar dos objetos Log
    if (c1.reps > c2.reps){
        return true;
    } else {
        return false;
    }
}

bool operator<(const contadorIP& c1, const contadorIP& c2) {
    // Define aquí cómo comparar dos objetos Log
    if (c1.reps < c2.reps){
        return true;
    } else {
        return false;
    }
}

int contadorIP::getIP(){
   
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
    for (char c : IP) {
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