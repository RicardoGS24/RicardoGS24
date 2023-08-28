#include <iostream>
#include <vector>
using namespace std;

void binarySearch(const string& list,char valorUnico,int& Comparisons){
    // Inicializar left y right
    int left = 0, right = list.size()-1, tipoResiduo = 0;

    while(left <= right){
        Comparisons++;
        //Calcular el valor de en medio
        int mid = left + (right - left)/2;
        tipoResiduo = list.size() - (mid+1);

        if (list[mid] == valorUnico){
            cout << list[mid] << " " << Comparisons << endl;
            return;
        }
        else if (tipoResiduo%2 != 0){
            if(list[mid] == list[mid-1]){
                left = mid+1;
            }
            else {
                right = mid-1;
            }
        }
        else {
            if (list[mid] == list[mid-1]){
                right = mid - 2;
            }
            else {
                left = mid + 2;
            }
        }

        if (right-left <= 1 && list.size() == 3){
            if (list[mid] == list[mid-1]){
                cout << list[mid+1] << " " << Comparisons << endl;
            }
            else {
                cout << list[mid-1] << " " << Comparisons << endl;
            }
            left = right + 1;
        }
    }

}


void secuencialSearch(string list, int& comparisons){
    for(int k=0; k < list.size()-1;k++){  //Iterar para obtener cada caracter del string
        comparisons++;
        if(list[k] == list[k+1]){
            k++;
        }
        else {
            cout << list[k] << " " << comparisons;
            return;
        }
    }
    cout << list[list.size()-1] << " " << comparisons;
}

int main()
{
    vector<string> list = {};
    int n = 0;
    string x = "";
    cout << "Ingrese n: ";
    cin >> n;

    for(int i=0;i<n;i++){
        cout << "Teclee el valor: ";
        cin >> x;
        list.push_back(x);
    }

    for(const string& str : list){
        char uniqueChar;
        int secuencialComparisons = 0, binaryComparisons = 0;

        // Encontrar el valor único   
        for (int i = 0; i < str.size(); i += 2) {
            if (i == str.size() - 1 || str[i] != str[i + 1]) {
                uniqueChar = str[i];
                break;
            }
        }

        secuencialSearch(str, secuencialComparisons);
        cout << " ";
        binarySearch(str, uniqueChar, binaryComparisons);

    }

    return 0;
}


// Ejecución del Programa:
// Ingrese n: 4
// Teclee el valor: AACCZZTTVXX
// Teclee el valor: AAB
// Teclee el valor: CCAAXWWTT
// Teclee el valor: XXYYZZAAC
// V 5 V 2
// B 1 B 1
// X 3 X 1
// C 4 C 3