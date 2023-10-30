#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <algorithm>

// Estructura para almacenar información de IP y su recuento
struct IPInfo {
    std::string ip;
    int count;
};

// Función para dividir una cadena en palabras
std::vector<std::string> splitString(const std::string &s, char delimiter) {
    std::vector<std::string> tokens;
    std::istringstream tokenStream(s);
    std::string token;
    while (std::getline(tokenStream, token, delimiter)) {
        tokens.push_back(token);
    }
    return tokens;
}

int main() {
    std::string filename = "log602-3.txt"; // Reemplaza con la ruta de tu archivo

    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error al abrir el archivo." << std::endl;
        return 1;
    }

    std::map<std::string, int> ipCounts; // Mapa para contar las IPs
    std::string line;

    // Leer el archivo línea por línea
    while (std::getline(file, line)) {
        std::vector<std::string> words = splitString(line, ' ');
        if (words.size() >= 5) {
            std::string ip = words[4];
            ipCounts[ip]++;
        }
    }

    // Crear un vector de IPInfo a partir del mapa
    std::vector<IPInfo> ipInfoList;
    for (const auto &entry : ipCounts) {
        IPInfo info;
        info.ip = entry.first;
        info.count = entry.second;
        ipInfoList.push_back(info);
    }

    // Ordenar el vector de IPInfo por recuento en orden descendente
    std::sort(ipInfoList.begin(), ipInfoList.end(), [](const IPInfo &a, const IPInfo &b) {
        return a.count > b.count;
    });

    // Mostrar las 10 IP más repetidas
    std::cout << "Las 10 IPs con más repeticiones son:" << std::endl;
    for (int i = 0; i < std::min(10, static_cast<int>(ipInfoList.size())); i++) {
        std::cout << "IP: " << ipInfoList[i].ip << ", Repeticiones: " << ipInfoList[i].count << std::endl;
    }

    file.close();

    return 0;
}
