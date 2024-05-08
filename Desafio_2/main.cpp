#include <iostream>
#include "red.h"

int main() {
    red<std::string, std::string, std::string> metro;
    int opcion = -1;
    std::string linea, estacion, tiempo;

    while (opcion != 0) {
        std::cout << "\n*** Menu del sistema de metro ***\n";
        std::cout << "1. Agregar una estacion a una linea\n";
        std::cout << "2. Eliminar una estacion de una linea\n";
        std::cout << "3. Saber cuantas estacion tiene una linea\n";
        std::cout << "4. Saber las estaciones de una linea\n";
        std::cout << "5. Saber si una estacion dada pertenece a una linea especifica\n";
        std::cout << "6. Agregar una linea a la red Metro\n";
        std::cout << "7. Eliminar una linea de la red Metro\n";
        std::cout << "8. Saber cuantas estaciones tiene una red Metro\n";
        std::cout << "0. Salir\n";
        std::cout << "Por favor, elige una opcion: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:{
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            std::cout << "Introduce el nombre de la estacion: ";
            std::cin >> estacion;
            bool verificar = metro.estacionExisteEnLinea(linea,estacion);
            if(verificar == true){
                std::cout << "La estacion ya existe en la linea";
                break;
            }
            else{
                metro.agregar_valor(linea, estacion, tiempo);
                std::cout << "Introduce el tiempo con respecto a las estaciones anterior y siguiente separadas con una coma (,) : ";
                std::cin >> tiempo;
                break;
            }
        }
        case 2:{
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            std::cout << "Introduce el nombre de la estacion: ";
            std::cin >> estacion;
            int indice;
            indice = metro.saber_indice(linea, estacion);
            metro.eliminarElemento(indice);
            break;
        }
        case 3:{
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            metro.obtener_estacion(linea);
            break;
        }
        case 4:{
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            metro.saber_estacion_de_linea(linea);
            break;
        }
        case 5:{
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            std::cout << "Introduce el nombre de la estacion: ";
            std::cin >> estacion;
            if (metro.saber_indice(linea, estacion) != -1) {
                std::cout << "La estacion " << estacion << " pertenece a la linea " << linea << ".\n";
            } else {
                std::cout << "La estacion " << estacion << " no pertenece a la linea " << linea << ".\n";
            }
            break;
        }
        case 6:{
            break;
        }
        case 7:{
            break;
        }
        case 8:{
            break;
        }
        case 0:{
            std::cout << "Saliendo del programa...\n";
            break;
        }
        default:{
            std::cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
            break;
        }
        }
    }

    return 0;
}
