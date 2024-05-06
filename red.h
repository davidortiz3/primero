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
    int tamaño;

    void nueva_dimencion(){
        cantidad*=2;
        T1* nuevo=new T1[cantidad];
        T2* nuevo1=new T2[cantidad];
        T3* nuevo2=new T3[cantidad];
        for (int i = 0; i < tamaño; i++)
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
    red() : cantidad(10), tamaño(0){
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
        if(tamaño>=cantidad){
            nueva_dimencion();
        }

        lineas[tamaño]=linea1;
        estaciones[tamaño]=estacion;
        tiempos[tamaño]=tiempo;
        tamaño++;
    }

    void obtener_estacion(const T1& temp){
        int con=0;
        for (int i = 0; i < tamaño; i++)
        {
            if(lineas[i]==temp){
                con++;
            }
        }
        std::cout<<con;
    }

    void saber_linea(){
        for (int i = 0; i < tamaño; i++)
        {
            std::cout<<lineas[i]<<" ";
        }
    }

    void saber_estacion_de_linea(T1 linea){
        for (int i = 0; i < tamaño; i++)
        {
            if (lineas[i]==linea)
            {
                std::cout<<estaciones[i]<<" ";
            }
        }
    }

    void saber_tiempo(T1 linea, T2 estacion){
        for (int i = 0; i < tamaño; i++)
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
        for (int i = 0; i < tamaño; i++)
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

    void eliminarElemento(int indice) {
        if (indice >= 0 && indice < tamaño) {
            for (int i = indice; i < tamaño - 1; ++i) {
                lineas[i] = lineas[i + 1];
                estaciones[i] = estaciones[i + 1];
                tiempos[i] = tiempos[i + 1];
            }
            tamaño--;
        } else {
            std::cerr<<"Error: Índice fuera de rango." <<std::endl;
        }
    }
};

#endif // RED_H
