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
    long key;

    long keyGenerator();
    bool operator<(Log log);
    bool operator>(Log log);
    Log(string year, string month, string day, string time, string ip, string message);
};

Log::Log(string year, string month, string day, string time, string ip, string message) {
    this->year = year;
    this->month = month;
    this->day = day;
    this->time = time;
    this->ip = ip;
    this->message = message;
    
    // Hacer una función que genere la llave
    key = keyGenerator();
}

long Log::keyGenerator(){
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

bool Log::operator<(Log log) {
    return this->key < log.key;
}

bool Log::operator>(Log log) {
    return this->key > log.key;
}
