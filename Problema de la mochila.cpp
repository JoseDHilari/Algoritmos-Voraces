#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Articulo {
    int peso;
    int valor;

    Articulo(int p, int v) : peso(p), valor(v) {}
};

bool comparar(const Articulo& a, const Articulo& b) {
    double razon1 = (double) a.valor / a.peso;
    double razon2 = (double) b.valor / b.peso;
    return razon1 > razon2;
}

double mochila(int capacidad, vector<Articulo>& articulos) {
    sort(articulos.begin(), articulos.end(), comparar);

    double valorTotal = 0.0;
    int pesoActual = 0;

    for (const auto& articulo : articulos) {
        if (pesoActual + articulo.peso <= capacidad) {
            pesoActual += articulo.peso;
            valorTotal += articulo.valor;
        } else {
            int capacidadRestante = capacidad - pesoActual;
            valorTotal += articulo.valor * ((double) capacidadRestante / articulo.peso);
            break;
        }
    }

    return valorTotal;
}

int main() {
    int capacidad;
    int numArticulos;

    cout << "Ingrese la capacidad maxima de la mochila: ";
    cin >> capacidad;
    cout << "Ingrese el numero de articulos: ";
    cin >> numArticulos;

    vector<Articulo> articulos;

    for (int i = 0; i < numArticulos; i++) {
        int peso, valor;
        cout << "Ingrese el peso y el valor del articulo " << i + 1 << ": ";
        cin >> peso >> valor;
        articulos.emplace_back(peso, valor);
    }

    double valorMaximo = mochila(capacidad, articulos);

    cout << "El valor maximo que se puede obtener en la mochila es: " << valorMaximo << endl;

    return 0;
}
