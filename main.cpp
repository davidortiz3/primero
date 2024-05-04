#include <iostream>
#include <string>
using namespace std;
template <typename clave>
class estaciones
{
private:
    /* data */
public:
    estacion(/* args */);
    estacion();
};

template <typename clave, estaciones<typename estaciones>>
class MapaGenerico {
private:
    clave* claves;
    estaciones* valores;
    int capacidad;
    int tamano;

public:
    MapaGenerico() : capacidad(10), tamano(0) {
        claves = new clave[capacidad];
        valores = new valor[capacidad];
    }

    ~MapaGenerico() {
        delete[] claves;
        delete[] valores;
    }

    void agregarElemento(const clave& clave1, const valor& valor1) {
        if (tamano >= capacidad) {
            redimensionar();
        }
        claves[tamano] = clave1;
        valores[tamano] = valor1;
        tamano++;
    }

    valor obtenerValor(const clave& clave1) const {
        for (int i = 0; i < tamano; ++i) {
            if (claves[i] == clave1) {
                return valores[i];
            }
        }
        cerr << "Error: Clave no encontrada." << endl;
        return valor();
    }



    void eliminarElemento(const clave& clave1) {
        for (int i = 0; i < tamano; ++i) {
            if (claves[i] == clave1) {
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
        clave* nuevasClaves = new clave[capacidad];
        valor* nuevosValores = new valor[capacidad];
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

template <typename clave, typename ValueType>
class red
{
private:
    MapaGenerico < clave, MapaGenerico<typename clave1, typename valor>> mapa;
public:
    red() : red("medellin"){}

    void agregarlinea(clave1 name, valor num){
        if (mapa.obtenervalor(name)==name, )
        {
            /* code */
        }

    }

};


int main() {

    MapaGenerico<string, string> miMapa;

    miMapa.agregarElemento("uno", "Uno");
    miMapa.agregarElemento("dos", "Dos");
    miMapa.agregarElemento("tres", "Tres");
    miMapa.mostrarElementos();
    return 0;
}
