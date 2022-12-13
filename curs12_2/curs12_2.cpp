
#include <iostream>

using namespace std;

class op {

};

template<class T = double>
class MaiMic {
public:
    bool operator()(T a, T b) {
        return a < b;
    }
};

class Auto {
    string id, marca;
public:
    Auto(string newId = "B-00-ABC", string newMarca = "Dacia") : id(newId), marca(newMarca) {}

    friend ostream& operator<<(ostream& out, const Auto& a) {
        out << "\n-------------------------------------------";
        out << "\nID: " << a.id;
        out << "\nMarca: " << a.marca;
        out << "\n-------------------------------------------";
        return out;
    }
    
    bool operator<(Auto& b) {
        return this->id < b.id;
    }
};

template<class T>
class Vector
{
    int dim;
    T* pe;
    
public:
    static T errPoint;
    Vector(int d = 1) :dim(d)
    {
        pe = new T[dim];
        for (int i = 0; i < dim; i++) pe[i] = T();
    }
    // Vector(int d, double *vd)
    ~Vector() { if (pe != nullptr) delete[] pe; }
    Vector(Vector& src) : dim(src.dim)
    {
        pe = new T[dim];
        for (int i = 0; i < dim; i++) pe[i] = src.pe[i];
    }
    Vector& operator= (const Vector& src)
    {
        if (pe != src.pe) // this!=&src
        {
            dim = src.dim;
            delete[] pe; pe = new T[dim];
            for (int i = 0; i < dim; i++) pe[i] = src.pe[i];
        }
        else cerr << "\nErr auto-asignare";
        return *this;
    }
    T& operator[](int idx)
    {
        if (idx >= 0 && idx < dim)
            return pe[idx];
        else
        {
            cerr << "\nOut of range";
            return errPoint;
        }
    }

    friend ostream& operator<<(ostream& ost, Vector& v)
    {
        ost << endl;
        for (int i = 0; i < v.dim; i++)
            ost << v.pe[i] << "\t";
        return ost;
    }

    void sort(MaiMic<T> mm) {
        for (int i = 0; i < dim - 1; i++) {
            for (int j = i + 1; j < dim; j++) {
                if (!mm(pe[i], pe[j])) {
                    T aux = pe[i];
                    pe[i] = pe[j];
                    pe[j] = aux;
                }
            }
        }
    }
};

template<class T>
T Vector<T>::errPoint = T();

int main()
{
    Vector<double> v1(5);
    Vector<int> vv[50];
    vv[49][0] = 1;
    v1[3] = 3.3; 
    v1[0] = 100;
    v1[2] = 222;
    v1[4] = 4;
    
    cout << v1;
    MaiMic<> mm;
    v1.sort(mm);

    Vector<Auto> va(4);
    va[0] = Auto("TL-25-ASA", "Opel");
    va[1] = Auto("SM-99-SAB", "Renault");
    va[2] = Auto("VL-22-MAR", "BMW");
    va[3] = Auto("MH-99-ANA");
    v1.sort(mm);
    cout << va;
    MaiMic<Auto> mma;
    va.sort(mma);
    cout << va;
    
    //tema: declarati o clasa generica (template) abstracta numita comparator, derivati din ea MaiMic, MaiMare si in main avem un singur comparator care va primi obiect de tip MaiMic/MaiMare
}

