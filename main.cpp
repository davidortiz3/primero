#include <iostream>
#include <string>
using namespace std;

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

    void agregar_valor(const T1& linea1, const T2& estacion, const T3& tiempo){
        if(tamano>=cantidad){
            nueva_dimencion();
        }

        lineas[tamano]=linea1;
        estaciones[tamano]=estacion;
        tiempos[tamano]=tiempo;
        tamano++;
    }

    T3 separar_tiempo(const T3& time, const int& n){
        string primero, segundo;
        int comaPos = time.find(',');
        primero = time.substr(0, comaPos);
        segundo = time.substr(comaPos + 1);
        if (n==1){
            return primero;
        }else if (n==2)
        {
            return segundo;
        }



    }


    int agregar_estacion(const T1& linea1, const T2& estacion, const T3& tiempo, const int& posicion){
        cout<<endl;
        if (obtener_estacion1(linea1, estacion))
        {
            cout<<"Esta estacion no se puede crear ya que no pueden haber dos con el mismo nombre:"<<endl;
            return -1;
        }

        if (posicion>tamano || posicion<0)
        {
            cerr<<"La posicion esta fuera de rango"<<endl;
            return -1;
        }
        if(tamano>=cantidad){
            nueva_dimencion();
        }
        for (int i = tamano; i >posicion; i--)
        {
            lineas[i]=lineas[i-1];
            estaciones[i]=estaciones[i-1];
            tiempos[i]=tiempos[i-1];
        }
        lineas[posicion]=linea1;
        estaciones[posicion]=estacion;
        tiempos[posicion]=tiempo;

        if (posicion>0 || posicion<tamano)
        {
            string time1=tiempos[posicion-1];
            //cout<<endl<<time1<<"..."<<endl;
            string time2=separar_tiempo(time1, 1);
            //cout<<endl<<time2<<endl;
            string time=separar_tiempo(tiempo, 1);
            string result;
            result.append(time2);
            result.append(",");
            result.append(time);
            tiempos[posicion-1]=result;

            string n=tiempos[posicion+1];
            //cout<<endl<<n<<"..."<<endl;
            string n1=separar_tiempo(n, 2);
            //cout<<endl<<n1<<"."<<endl;
            string time3=separar_tiempo(tiempo, 2);
            //cout<<endl<<time3<<"."<<endl;
            string result1;
            result1.append(time3);
            result1.append(",");
            result1.append(n1);
            //cout<<endl<<result1<<endl;
            tiempos[posicion+1]=result1;
            tamano++;
            cout<<"La estacion se creo correctamente:"<<endl;
            return -1;
        }
        else if (posicion==tamano)
        {
            string time1=tiempos[posicion-1];
            string time2=separar_tiempo(time1, 1);
            string time=separar_tiempo(tiempo, 1);
            time2.append(",");
            time2.append("0");
            tiempos[posicion]=time2;
            tamano++;
            cout<<"La estacion se creo correctamente:"<<endl;
            return -1;
        }
    }
    void obtener_estacion(const T1& temp){
        int con=0;
        cout<<endl<<"La cantidad de estaciones que tiene esta linea es: "<<endl;
        for (int i = 0; i < tamano; i++)
        {
            if(lineas[i]==temp){
                con++;
            }
        }
        cout<<con;
    }

    bool obtener_estacion1(const T1& temp, const T2& estacion){
        int con=0;
        for (int i = 0; i < tamano; i++)
        {
            if(lineas[i]==temp){
                if (estaciones[i]==estacion)
                {
                    con++;
                }
            }
        }
        if (con!=0)
        {
            return true;
        }else{
            return false;
        }

    }

    bool estaRepetido(const T1& cadena, const int& n) {
        for (int i = 0; i < n; ++i) {
            if (cadena == lineas[i]) {
                return true;
            }
        }
        return false;
    }
    void saber_linea(){
        int con=1;
        cout<<"Lineas existentes"<<endl;
        for (int i = 0; i < tamano; ++i) {
            if (!estaRepetido(lineas[i], i)) {
                cout<<con<<". "<< lineas[i] << endl;
                con++;
            }
        }

    }

    void saber_linea(const int& n){
        int con=0;
        cout<<endl<<"La cantidad de lineas es:"<<endl;
        for (int i = 0; i < tamano; ++i) {
            if (!estaRepetido(lineas[i], i)) {
                con++;
            }
        }
        cout << con << endl;
    }

    void saber_estacion_de_linea(const T1& linea){
        cout<<endl;
        int con=1;
        for (int i = 0; i < tamano; i++)
        {
            if (lineas[i]==linea)
            {
                cout<<con<<". "<<estaciones[i]<<endl;
                con++;
            }
        }
    }

    void saber_tiempo(const T1& linea, const T2& estacion){
        cout<<"El tiempo es:"; cout<<endl;
        for (int i = 0; i < tamano; i++)
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

    T3 saber_tiempo(const T1& linea, const T2& estacion, const int& n){
        for (int i = 0; i < tamano; i++)
        {
            if (lineas[i]==linea)
            {
                if (estaciones[i]==estacion)
                {
                    return tiempos[i];
                }
            }
        }
    }

    int saber_indice(const T1& linea, const T2& estacion){
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
            cout << "La red está vacía." << endl;
            return;
        }
        cout << "Linea: " << lineas[0] << ", Estaciones: " << estaciones[0];
        for (int i = 1; i < tamano; i++) {
            if (lineas[i] != lineas[i - 1]) {
                cout << endl << "Linea: " << lineas[i] << ", Estaciones: " << estaciones[i];
            } else {
                cout << ", " << estaciones[i];
            }
        }
        cout << endl;
    }

    void eliminarElemento( const int& indice, const T2& estacion) {
        if(verificacion(estacion, 1)){
            cout<<"La linea no se puede eliminar ya que pertenece a una estacion de trasferencia :("<<endl;
        }
        else if (indice >= 0 && indice < tamano) {
            for (int i = indice; i < tamano - 1; ++i) {
                lineas[i] = lineas[i + 1];
                estaciones[i] = estaciones[i + 1];
                tiempos[i] = tiempos[i + 1];
            }
            tamano--;
        } else {
            cerr<<"Error: Índice fuera de rango." <<endl;
        }
    }

    bool verificacion(const T3& buscado) {
        for (int i = 0; i < tamano; ++i) {
            if (lineas[i] == buscado) {
                cout<<"La linea no se puede eliminar ya que pertenece a una estacion de trasferencia :("<<endl;
                return true;
            }
        }
        cout<<"La linea que ingresaste no pertenece a la red metro :("<<endl;
        return false;
    }

    bool verificacion(const T3& buscado, const int& n) {
        for (int i = 0; i < tamano; ++i) {
            if (lineas[i] == buscado) {
                return true;
            }
        }
        return false;
    }

    void total_estaciones() {
        cout << "El total de estaciones en la red Metro es: " << tamano << endl;
    }

    int tiempo_individual(const T1& linea , string estacion){
        T3 time =saber_tiempo(linea, estacion,1);
        T3 tiempo_anterior=separar_tiempo(time, 1);
        int tiempo=stoi(tiempo_anterior);
        return tiempo;
    }

    void contar_tiempo(const T1& linea, const T3& estacion, const T3& estacion2){
        int indice, result=0, indice2;
        indice=saber_indice(linea, estacion);
        indice2=saber_indice(linea, estacion2);
        for (int i = indice; i <indice2 ; ++i) {
            string time=estaciones[i];
            result+=tiempo_individual(linea, time);
        }
        cout<<endl<<"El tiempo hasta la proxima esa estacion es: "<<result<<endl;
    }

    void menu_principal(){
        agregar_valor("universidades", "A", "0,6");
        agregar_valor("universidades", "B", "6,8");
        agregar_valor("universidades", "C", "8,0");
        int opcion = -1;
        string linea, estacion, tiempo, estacion1;
        int posicion;
        while (opcion != 0) {
            cout << "\n*** Menu del sistema de metro ***\n";
            cout << "1. Agregar una estacion a una linea\n";
            cout << "2. Eliminar una estacion de una linea\n";
            cout << "3. Saber cuantas lineas tiene una red Metro \n";
            cout << "4. Saber las estaciones de una linea\n";
            cout << "5. Saber si una estacion dada pertenece a una linea especifica\n";
            cout << "6. Agregar una linea a la red Metro\n";
            cout << "7. Eliminar una linea de la red Metro\n";
            cout << "8. Saber cuantas estaciones tiene una red Metro\n";
            cout << "9. Si deseas visualizar la red\n";
            cout << "10. Si deseas visualizar el tiempo de alguna estacion\n";
            cout << "11. Calcular tiempo entre estaciones de la misma linea\n";
            cout << "0. Salir\n";
            cout << "Por favor, elige una opcion: ";
            cin >> opcion;

            switch (opcion) {
            case 1:
                saber_linea(); cout<<endl;
                cout << "Introduce el nombre de la linea: ";
                cin >> linea;
                cout << "Introduce el nombre de la estacion: ";
                cin >> estacion;
                cout << "Introduce el tiempo con respecto a las estaciones anterior y siguiente separadas con una coma (,) : ";
                cin >> tiempo;
                cout<<"En que posicion deseas crear la estacion donde la primera estacion es '0':"<<endl;
                saber_estacion_de_linea(linea);
                cin>>posicion;
                agregar_estacion(linea, estacion, tiempo, posicion);
                cout<<endl;
                break;
            case 2:
                saber_linea(); cout<<endl;
                cout << "Introduce el nombre de la linea: ";
                cin >> linea;
                cout << "Introduce el nombre de la estacion: ";
                cin >> estacion;
                int indice;
                indice = saber_indice(linea, estacion);
                eliminarElemento(indice, estacion);
                break;
            case 3:
                saber_linea(1);
                break;
            case 4:
                cout << "Introduce el nombre de la linea: ";
                cin >> linea;
                obtener_estacion(linea);
                break;
            case 5:
                cout << "Introduce el nombre de la linea: ";
                cin >> linea;
                cout << "Introduce el nombre de la estacion: ";
                cin >> estacion;
                if (saber_indice(linea, estacion) != -1) {
                    cout << "La estacion " << estacion << " pertenece a la linea " << linea << ".\n";
                } else {
                    cout << "La estacion " << estacion << " no pertenece a la linea " << linea << ".\n";
                }
                break;
            case 6:
                cout << "Ingrese a una de las lineas disponibles: ";
                saber_linea();
                cin >> linea;
                cout << "Apartir de que estacion deseas crear una linea nueva: ";
                saber_estacion_de_linea(linea);
                cin >> estacion;
                cout<<"Ingresa el nombre de la primera estacion: ";
                cin>>estacion1;
                cout << "Introduce el tiempo con respecto a las estaciones anterior y siguiente separadas con una coma (,) : ";
                cin>>tiempo;
                agregar_valor(estacion,estacion1, tiempo);
                cout<<endl<<"La linea se agrego correctamente :) "<<endl;
                break;
            case 7:
                cout << "Ingrese la linea que deseas eliminar: ";
                saber_linea();
                cin >> linea;
                verificacion(linea);
                break;
            case 8:
                cout << "Calculando el total de estaciones en la red Metro...\n";
                total_estaciones();
                break;
            case 9:
                imprimir_red();
                cout<<endl;
                break;
            case 10:
                cout << "Ingrese la linea a la que desea acceder: ";
                saber_linea();
                cin>>linea;
                cout << endl<<"Ingrese la linea que desea revisar: ";
                saber_estacion_de_linea(linea);
                cin >> estacion;
                saber_tiempo(linea,estacion); cout<<endl;
                break;
            case 11:
                cout << "Ingrese a una de las lineas disponibles: ";
                saber_linea();
                cin >> linea;
                cout << "Apartir de que estacion deseas iniciar: ";
                saber_estacion_de_linea(linea);
                cin >> estacion;
                cout << "Hasta que estacion deseas ir? ";
                saber_estacion_de_linea(linea);
                cin >> estacion;
                contar_tiempo(linea, estacion, estacion1);
            case 0:
                cout << "Saliendo del programa...\n";
                break;
            default:
                cout << "Opcion no valida. Por favor, intenta de nuevo.\n";
                break;
            }
        }
    }

};




int main() {
    red<string, string, string> metro;
    metro.menu_principal();
    return 0;
}
