#include <iostream>
#include <string>
using namespace std;
template <typename linea, typename tiempo>
class linea1 {
private:
    linea* claves;
    tiempo* valores;
    int capacidad;
    int tamano;

public:
    linea1() : capacidad(10), tamano(0) {
        claves = new linea[capacidad];
        valores = new tiempo[capacidad];
    }

    ~linea1() {
        delete[] claves;
        delete[] valores;
    }

    void agregarElemento(const linea& clave, const tiempo& valor) {
        if (tamano >= capacidad) {
            redimensionar();
        }
        claves[tamano] = clave;
        valores[tamano] = valor;
        tamano++;
    }

    tiempo obtenerValor(const linea& clave) const {
        for (int i = 0; i < tamano; ++i) {
            if (claves[i] == clave) {
                return valores[i];
            }
        }
        cerr << "Error: Clave no encontrada." << endl;
        return tiempo();
    }

    void eliminarElemento(const linea& clave) {
        for (int i = 0; i < tamano; ++i) {
            if (claves[i] == clave) {
                for (int j = i; j < tamano - 1; ++j) {
                    claves[j] = claves[j + 1];
                    valores[j] = valores[j + 1];
                }
                tamano--;
                return;
            }
        }
        cerr << "Error: Clave no encontrada." << endl;
    }

    void mostrarElementos() const {
        cout << "Elementos del mapa:" << endl;
        for (int i = 0; i < tamano; ++i) {
            cout << "Clave: " << claves[i] << ", Valor: " << valores[i] << endl;
        }
    }

private:
    void redimensionar() {
        capacidad *= 2;
        linea* nuevasClaves = new linea[capacidad];
        tiempo* nuevosValores = new tiempo[capacidad];
        for (int i = 0; i < tamano; ++i) {
            nuevasClaves[i] = claves[i];
            nuevosValores[i] = valores[i];
        }
        delete[] claves;
        delete[] valores;
        claves = nuevasClaves;
        valores = nuevosValores;
    }
};

int main() {
    linea1<string, string> miMapa;
    miMapa.agregarElemento("juan", "Uno");
    miMapa.agregarElemento("david", "Dos");
    miMapa.agregarElemento("ortiz", "Tres");
    miMapa.mostrarElementos();
    miMapa.agregarElemento("diaz", "Cuatro");
    miMapa.agregarElemento("juan", "Cinco");
    miMapa.agregarElemento("diaz", "Seis");
    miMapa.agregarElemento("david", "Siete");

    miMapa.mostrarElementos();

    return 0;
}
