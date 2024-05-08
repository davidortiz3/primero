#ifndef RED_H
#define RED_H

#include <iostream>
#include <string>

template <typename T>
class lineaP
{
private:
    T linea;
    T estacion;
    T time;
public:
    void agregar_valores(T lineas,T estaciones,T time1){
        linea=lineas;
        estacion=estaciones;
        time=time1;
    }
    void saber_linea(){
        std::cout<< linea;
    }

    T saber_estacion(){
        return estacion;
    }

    T saber_time(){
        return time;
    }
};

template<typename T1, typename T2, typename T3>
class red
{
private:
    T1* lineas;
    T2* estaciones;
    T3* tiempos;
    int cantidad;
    int tamano;

    void nueva_dimencion(){
        cantidad*=2;
        T1* nuevo=new T1[cantidad];
        T2* nuevo1=new T2[cantidad];
        T3* nuevo2=new T3[cantidad];
        for (int i = 0; i < tamano; i++)
        {
            nuevo[i]=lineas[i];
            nuevo1[i]=estaciones[i];
            nuevo2[i]=tiempos[i];
        }
        delete[] lineas;
        delete[] estaciones;
        delete[] tiempos;
        lineas=nuevo;
        estaciones=nuevo1;
        tiempos=nuevo2;
    }
public:
    red() : cantidad(10), tamano(0){
        lineas=new T1[cantidad];
        estaciones=new T2[cantidad];
        tiempos=new T3[cantidad];
    }
    ~red(){
        delete[] lineas;
        delete[] estaciones;
        delete[] tiempos;
    }

    void agregar_valor(T1 linea1, T2 estacion, T3 tiempo){
        if(tamano>=cantidad){
            nueva_dimencion();
        }

        lineas[tamano]=linea1;
        estaciones[tamano]=estacion;
        tiempos[tamano]=tiempo;
        tamano++;
    }

    void obtener_estacion(const T1& temp){
        int con=0;
        for (int i = 0; i < tamano; i++)
        {
            if(lineas[i]==temp){
                con++;
            }
        }
        std::cout<<con;
    }

    void saber_linea(){
        for (int i = 0; i < tamano; i++)
        {
            std::cout<<lineas[i]<<" ";
        }
    }

    void saber_estacion_de_linea(T1 linea){
        for (int i = 0; i < tamano; i++)
        {
            if (lineas[i]==linea)
            {
                std::cout<<estaciones[i]<<" ";
            }
        }
    }

    bool estacionExisteEnLinea(T1 linea, T2 estacion){
        for (int i = 0; i < tamano; i++)
        {
            if (lineas[i]==linea && estaciones[i]==estacion)
            {
                return true;
            }
        }
        return false;
    }

    void saber_tiempo(T1 linea, T2 estacion){
        for (int i = 0; i < tamano; i++)
        {
            if (lineas[i]==linea)
            {
                if (estaciones[i]==estacion)
                {
                    std::cout<<tiempos[i];
                }
            }
        }
    }

    int saber_indice(T1 linea, T2 estacion){
        for (int i = 0; i < tamano; i++)
        {
            if (lineas[i]==linea)
            {
                if (estaciones[i]==estacion)
                {
                    return i;
                }
            }
        }
    }

    void imprimir_red() {
        if (tamano == 0) {
            std::cout << "La red está vacía." << std::endl;
            return;
        }
        std::cout << "Linea: " << lineas[0] << ", Estaciones: " << estaciones[0];
        for (int i = 1; i < tamano; i++) {
            if (lineas[i] != lineas[i - 1]) {
                std::cout << std::endl << "Linea: " << lineas[i] << ", Estaciones: " << estaciones[i];
            } else {
                std::cout << ", " << estaciones[i];
            }
        }
        std::cout << std::endl;
    }

    void eliminarElemento(int indice) {
        if (indice >= 0 && indice < tamano) {
            for (int i = indice; i < tamano - 1; ++i) {
                lineas[i] = lineas[i + 1];
                estaciones[i] = estaciones[i + 1];
                tiempos[i] = tiempos[i + 1];
            }
            tamano--;
        } else {
            std::cerr<<"Error: Indice fuera de rango." <<std::endl;
        }
    }
};

#endif // RED_H

