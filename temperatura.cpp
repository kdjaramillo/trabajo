#include <iostream>
#include <vector>
#include <string>

using namespace std;

struct RegistroTemperatura {
    string fecha;
    float temperaturaManana;
    float temperaturaTarde;
    float temperaturaNoche;
};

void agregarRegistro(vector<RegistroTemperatura>& registros) {
    RegistroTemperatura registro;
    
    cout << "Ingrese la fecha (dd/mm/yyyy): ";
    cin >> registro.fecha;
    cout << "Ingrese la temperatura de la mañana: ";
    cin >> registro.temperaturaManana;
    cout << "Ingrese la temperatura de la tarde: ";
    cin >> registro.temperaturaTarde;
    cout << "Ingrese la temperatura de la noche: ";
    cin >> registro.temperaturaNoche;
    
    registros.push_back(registro);
}

void mostrarRegistros(const vector<RegistroTemperatura>& registros) {
    cout << "Registros de temperatura:" << endl;
    for (const auto& registro : registros) {
        cout << "Fecha: " << registro.fecha << ", Mañana: " << registro.temperaturaManana
             << ", Tarde: " << registro.temperaturaTarde << ", Noche: " << registro.temperaturaNoche << endl;
    }
}

float calcularPromedioDiario(const RegistroTemperatura& registro) {
    return (registro.temperaturaManana + registro.temperaturaTarde + registro.temperaturaNoche) / 3.0;
}

float calcularPromedioTotal(const vector<RegistroTemperatura>& registros) {
    float sumaTotal = 0;
    int cantidadRegistros = registros.size();
    
    for (const auto& registro : registros) {
        sumaTotal += registro.temperaturaManana + registro.temperaturaTarde + registro.temperaturaNoche;
    }
    
    return sumaTotal / (3 * cantidadRegistros);
}

int main() {
    int n;
    cout << "Ingrese el número de días a registrar: ";
    cin >> n;

    vector<RegistroTemperatura> registros;

    for (int i = 0; i < n; ++i) {
        cout << "\nRegistro del día " << (i + 1) << ":" << endl;
        agregarRegistro(registros);
    }

    mostrarRegistros(registros);

    // Calcular promedio de temperatura del día para cada registro
    cout << "\nPromedio de temperatura del día:" << endl;
    for (const auto& registro : registros) {
        cout << "Fecha: " << registro.fecha << ", Promedio: " << calcularPromedioDiario(registro) << endl;
    }

    // Calcular promedio de temperatura de todos los registros
    cout << "\nPromedio de temperatura de todos los registros: " << calcularPromedioTotal(registros) << endl;

    return 0;
}