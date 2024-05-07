#include <iostream>
#include <string>
using namespace std;
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
        cout<< linea;
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


    void agregar_valor(T1 linea1, T2 estacion, T3 tiempo, int posicion){
        if (posicion>tamaño || posicion<0)
        {
            cerr<<"La posicion esta fuera de rango"<<endl;
        }

        if(tamaño>=cantidad){
            nueva_dimencion();
        }
        for (int i = tamaño; i >posicion; i--)
        {
            lineas[tamaño-1]=linea1;
            estaciones[tamaño-1]=estacion;
            tiempos[tamaño-1]=tiempo;
        }
        lineas[posicion]=linea1;
        estaciones[posicion]=estacion;
        tiempos[posicion]=tiempo;
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
        cout<<con;
    }

    void saber_linea(){
        cout<<"Lineas existentes"<<endl;
        for (int i = 0; i < tamaño; i++)
        {
            cout<<lineas[i]<<" ";
        }

    }

    void saber_estacion_de_linea(T1 linea){
        cout<<endl;
        for (int i = 0; i < tamaño; i++)
        {
            if (lineas[i]==linea)
            {
                cout<<estaciones[i]<<" ";
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
                    cout<<tiempos[i];
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
            cerr<<"Error: Índice fuera de rango." <<endl;
        }
    }

};



int main() {
    /*red<string, string, string> principal;
    //El primer parametro es el nombre de la linea el segundo es el nombre de la estacion y el ultimo es el tiempo
    //principal.agregar_valor("juan", "david", "0,3");
    principal.agregar_valor("david", "A", "7,6");
    principal.agregar_valor("david", "B", "6,5");
    principal.agregar_valor("david", "C", "5,9");
    principal.agregar_valor("david", "D", "9,0");

    int n=principal.saber_indice("david", "A");
    principal.eliminarElemento(n);
    //principal.saber_estacion_de_linea("juan");
    //principal.obtener_estacion("david");
    principal.saber_estacion_de_linea("david");*/

    red<std::string, std::string, std::string> metro;
    metro.agregar_valor("david", "A", "7,6");
    int opcion = -1;
    std::string linea, estacion, tiempo;
    int posicion;
    while (opcion != 0) {
        std::cout << "\n*** Menú del sistema de metro ***\n";
        std::cout << "1. Agregar una estación a una línea\n";
        std::cout << "2. Eliminar una estación de una línea\n";
        std::cout << "3. Saber cuántas estaciones tiene una línea\n";
        std::cout << "4. Saber las estaciones de una línea\n";
        std::cout << "5. Saber si una estación dada pertenece a una línea específica\n";
        std::cout << "6. Agregar una línea a la red Metro\n";
        std::cout << "7. Eliminar una línea de la red Metro\n";
        std::cout << "8. Saber cuántas estaciones tiene una red Metro\n";
        std::cout << "0. Salir\n";
        std::cout << "Por favor, elige una opción: ";
        std::cin >> opcion;

        switch (opcion) {
        case 1:
            cout<<"En que posicion quieres crear la estacion ";
            metro.saber_linea();
            cin>>posicion;
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            std::cout << "Introduce el nombre de la estacion: ";
            std::cin >> estacion;
            std::cout << "Introduce el tiempo con respecto a las estaciones anterior y siguiente separadas con una coma (,) : ";
            std::cin >> tiempo;
            metro.agregar_valor(linea, estacion, tiempo, posicion);
            break;
        case 2:
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            std::cout << "Introduce el nombre de la estacion: ";
            std::cin >> estacion;
            int indice;
            indice = metro.saber_indice(linea, estacion);
            metro.eliminarElemento(indice);
            break;
        case 3:
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            metro.obtener_estacion(linea);
            break;
        case 4:
            std::cout << "Introduce el nombre de la linea: ";
            std::cin >> linea;
            metro.saber_estacion_de_linea(linea);
            break;
        case 5:
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
        case 6:
            std::cout << "Ingrese a una de las lineas disponibles: ";
            metro.saber_linea();
            std::cin >> linea;
            std::cout << "Apartir de que estacion deseas crear una linea nueva: ";
            //metro.saber_estacion_de_linea(linea);
            std::cin >> estacion;

            break;
        case 7:
            break;
        case 8:
            break;
        case 0:
            std::cout << "Saliendo del programa...\n";
            break;
        default:
            std::cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
            break;
        }
    }
    return 0;
}
