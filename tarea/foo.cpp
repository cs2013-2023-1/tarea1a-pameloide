//
// Created by Camila on 04/04/2023.
//

#include <iostream>

using namespace std;

class Matriz2D{
    friend Matriz2D t(Matriz2D&);
    friend ostream& operator<<(ostream&, const Matriz2D&);
    friend Matriz2D operator+(const Matriz2D&, const Matriz2D&);
    friend Matriz2D operator-(const Matriz2D&, const Matriz2D&);
    friend Matriz2D operator*(const Matriz2D&, const Matriz2D&);
    friend Matriz2D operator+(const Matriz2D&, float);
    friend Matriz2D operator-(const Matriz2D&, float);
    friend Matriz2D operator*(const Matriz2D&, float);
    friend Matriz2D operator/(const Matriz2D&, float);
public:
    Matriz2D();
    Matriz2D(int);
    Matriz2D(int, int);
    Matriz2D(const Matriz2D&);
    Matriz2D(Matriz2D&&);

    float get(int, int);
    int getFilas();
    int getColumnas();
private:
    float** ptr;
    int filas;
    int columnas;
};

//Matriz2D t(Matriz2D&);
 //ostream& operator<<(ostream&, const Matriz2D&);
 //Matriz2D operator+(const Matriz2D&, const Matriz2D&);
//Matriz2D operator-(const Matriz2D&, const Matriz2D&);
 //Matriz2D operator*(const Matriz2D&, const Matriz2D&);
//Matriz2D operator+(const Matriz2D&, float);
//Matriz2D operator-(const Matriz2D&, float);
//Matriz2D operator*(const Matriz2D&, float);
//Matriz2D operator/(const Matriz2D&, float);
