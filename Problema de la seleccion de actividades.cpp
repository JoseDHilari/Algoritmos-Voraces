#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Actividad {
    int inicio;
    int fin;

    Actividad(int i, int f) : inicio(i), fin(f) {}
};

bool comparar(const Actividad& a, const Actividad& b) {
    return a.fin < b.fin;
}

vector<Actividad> seleccionarActividades(vector<Actividad>& actividades) {
    sort(actividades.begin(), actividades.end(), comparar);

    vector<Actividad> seleccionadas;
    int tiempoFinAnterior = 0;

    for (const auto& actividad : actividades) {
        if (actividad.inicio >= tiempoFinAnterior) {
            seleccionadas.push_back(actividad);
            tiempoFinAnterior = actividad.fin;
        }
    }

    return seleccionadas;
}

int main() {
    int numActividades;
    cout << "Ingrese el numero de actividades: ";
    cin >> numActividades;

    vector<Actividad> actividades;
    for (int i = 0; i < numActividades; i++) {
        int inicio, fin;
        cout << "Ingrese el tiempo de inicio y fin de la actividad " << i + 1 << ": ";
        cin >> inicio >> fin;
        actividades.emplace_back(inicio, fin);
    }

    vector<Actividad> seleccionadas = seleccionarActividades(actividades);

    cout << "Las actividades seleccionadas son: " << endl;
    for (const auto& actividad : seleccionadas) {
        cout << "Inicio: " << actividad.inicio << ", Fin: " << actividad.fin << endl;
    }

    cout << "Numero total de actividades seleccionadas: " << seleccionadas.size() << endl;

    return 0;
}
