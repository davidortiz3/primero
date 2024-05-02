#include <iostream>
#include <string>
using namespace std;
template<typename T>

class ContenedorGenerico {
private:
    T* elementos;
    int capacidad;
    int tamano;    

public:

    ContenedorGenerico(int capacidadInicial = 10) {
        capacidad = capacidadInicial;
        elementos = new T[capacidad];
        tamano = 0;
    }

    ~ContenedorGenerico() {
        delete[] elementos;
    }


    void agregarElemento(const T& elemento) {
        if (tamano >= capacidad) {

            capacidad *= 2;
            T* nuevoArreglo = new T[capacidad];
            for (int i = 0; i < tamano; ++i) {
                nuevoArreglo[i] = elementos[i];
            }
            delete[] elementos;
            elementos = nuevoArreglo;
        }
        elementos[tamano++] = elemento;
    }

    void eliminarUltimoElemento() {
        if (tamano > 0) {
            --tamano;
        }
    }


    bool buscarElemento(const T& elemento) const {
        for (int i = 0; i < tamano; ++i) {
            if (elementos[i] == elemento) {
                return true;
            }
        }
        return false;
    }

    void mostrarElementos() const {
        cout << "Elementos del contenedor:" << endl;
        for (int i = 0; i < tamano; ++i) {
            cout << elementos[i] << endl;
        }
    }

    void eliminarElemento(const T& elemento) {
        for (int i = 0; i < tamano; ++i) {
            if (elementos[i] == elemento) {

                for (int j = i; j < tamano - 1; ++j) {
                    elementos[j] = elementos[j + 1];
                }
                --tamano;
                return;
            }
        }
    }



    void agregarElementoEnPosicion(const T& elemento, int posicion) {
        if (posicion < 0 || posicion > tamano) {
            std::cerr << "Error: Posición fuera de rango." << endl;
            return;
        }

        if (tamano >= capacidad) {

            capacidad *= 2;
            T* nuevoArreglo = new T[capacidad];
            for (int i = 0; i < posicion; ++i) {
                nuevoArreglo[i] = elementos[i];
            }
            nuevoArreglo[posicion] = elemento;
            for (int i = posicion + 1; i <= tamano; ++i) {
                nuevoArreglo[i] = elementos[i - 1];
            }
            delete[] elementos;
            elementos = nuevoArreglo;
        } else {
            for (int i = tamano; i > posicion; --i) {
                elementos[i] = elementos[i - 1];
            }
            elementos[posicion] = elemento;
        }

        ++tamano;
    }

    void saber_capacidad(){
        cout<<tamaño;
    }
};

int main() {
    string dato;
    int con=0;
    cout<<"Se creo la linea principal "<<endl;
    ContenedorGenerico<string> miContenedor;
    while (con==0){
        cout<<"Si quieres agregar una linea nueva ingresa a"<<endl;
        cout<<"Si desea eliminar una linea ingrese b"<<endl;
        cout<<"Si desea saber la cantidad de lineas de la red metro ingrese c"<<endl;
        cout<<"Si desea saber la cantidad de "<<endl;
        cin>>dato;
        if(dato=="a"){
            miContenedor.agregar_posicion_intermedia_o_extremo();
            //miContenedor.mostrarElementos();
        }else if (dato=="b")
        {
            miContenedor.mostrarElementos();
            cout<<"Ingrese la estacion que desea eliminar"<<endl;
            cin>>dato;
            miContenedor.eliminarElemento(dato);
        }else if(dato=="c"){

        }else if (dato=="d")
        {
            miContenedor.cantidad_de_estaciones();
        }else if (dato=="e")
        {
            cout<<"Ingrese la estacion que desea buscar: "; cin>>dato;
            miContenedor.buscarElemento(dato);
        }else if (dato=="f")
        {
            /* code */
        }else if(dato=="g"){

        }else if (dato=="h")
        {
            /* code */
        }





        cout<<"Si deseas volver al menu principal ingrese 0 "; cin>>con;
    }
    return 0;
}

    return 0;
}
