#include <iostream>
#include <string>
using namespace std;
template <typename line, typename time>
class line1 {
private:
    line* keys;
    time* values;
    int capacity;
    int size;

public:
    line1() : capacity(10), size(0) {
        keys = new line[capacity];
        values = new time[capacity];
    }

    ~line1() {
        delete[] keys;
        delete[] values;
    }

    void addElement(const line& key, const time& value) {
        if (size >= capacity) {
            resize();
        }
        keys[capacity] = key;
        values[size] = value;
        size++;
    }

    time getValue(const line& key) const {
        for (int i = 0; i < size; ++i) {
            if (keys[i] == key) {
                return values[i];
            }
        }
        cerr << "Error: Clave no encontrada." << endl;
        return time();
    }

    void deleteElement(const line& key) {
        for (int i = 0; i < size; ++i) {
            if (keys[i] == key) {
                for (int j = i; j < size - 1; ++j) {
                    keys[j] = keys[j + 1];
                    values[j] = values[j + 1];
                }
                size--;
                return;
            }
        }
        cerr << "Error: Clave no encontrada." << endl;
    }

    void showElements() const {
        cout << "Elementos del mapa:" << endl;
        for (int i = 0; i < size; ++i) {
            cout << "Clave: " << keys[i] << ", Valor: " << values[i] << endl;
        }
    }

private:
    void resize() {
        capacity *= 2;
        line* newKeys = new line[capacity];
        time* newValues = new time[capacity];
        for (int i = 0; i < size; ++i) {
            newKeys[i] = keys[i];
            newValues[i] = values[i];
        }
        delete[] keys;
        delete[] values;
        keys = newKeys;
        values = newValues;
    }
};

int main() {
    line1<string, string> miMapa;
    miMapa.addElement("juan", "Uno");
    miMapa.addElement("david", "Dos");
    miMapa.addElement("ortiz", "Tres");
    miMapa.showElements();
    miMapa.addElement("diaz", "Cuatro");
    miMapa.addElement("juan", "Cinco");
    miMapa.addElement("diaz", "Seis");
    miMapa.addElement("david", "Siete");

    miMapa.showElements();

    return 0;
}
