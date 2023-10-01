#include <iostream>
using namespace std;

#include "Queue.h"

int main()
{
    Queue<int> lista;
    lista.push(5);
    lista.push(5);
    lista.push(5);

    lista.print();
    return 0;
}
