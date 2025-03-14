/*
Samuel Gonzalez Vazquez 
A01412958
Algoritmos Avanzados
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Función para comparar sufijos.
 * @param a: Primer sufijo.
 * @param b: Segundo sufijo.
 * @return true si a es menor que b, false en caso contrario.
 */
bool compareSuffixes(const pair<string, int>& a, const pair<string, int>& b) {
    return a.first < b.first;
}

/**
 * Función para calcular el Suffix Array de un string.
 * @param s: El string de entrada.
 * @return Un vector con los índices de los sufijos ordenados.
 */
vector<int> computeSuffixArray(const string& s) {
    int n = s.length();
    vector<pair<string, int>> suffixes;

    // Generar todos los sufijos y almacenarlos con su índice original
    for (int i = 0; i < n; i++) {
        suffixes.push_back({ s.substr(i), i });
    }

    // Ordenar los sufijos alfabéticamente
    sort(suffixes.begin(), suffixes.end(), compareSuffixes);

    // Extraer los índices de los sufijos ordenados
    vector<int> suffixArray;
    for (const auto& suffix : suffixes) {
        suffixArray.push_back(suffix.second);
    }

    return suffixArray;
}

int main() {
    string input;
    cout << "Ingrese el string: ";
    getline(cin, input);

    // Calcular el Suffix Array
    vector<int> suffixArray = computeSuffixArray(input);

    // Mostrar los índices de los sufijos ordenados
    cout << "Suffix Array:" << endl;
    for (int index : suffixArray) {
        cout << index << endl;
    }

    return 0;
}