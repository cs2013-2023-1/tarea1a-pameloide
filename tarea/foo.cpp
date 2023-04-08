#include "foo.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas=3;
    columnas=3;
    ptr = new  float*[filas];
    for (int i=0;i<filas;i++){
        ptr[i]=new float[columnas];
    }
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < columnas ; j++){
            float valor=rand()%10;
            ptr[i][j] = valor/10;

        }

    }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    filas = n;
    columnas = n;
    ptr = new  float*[filas];
    for (int i=0;i<filas;i++){
        ptr[i]=new float[columnas];
    }
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < columnas ; j++){
            float valor=rand()%10;
            ptr[i][j] = valor/10;
        }

    }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    filas = n;
    columnas = m;
    ptr = new  float*[filas];
    for (int i=0;i<filas;i++){
        ptr[i]=new float[columnas];
    }
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < columnas ; j++){
            float valor=rand()%10;
            ptr[i][j] = valor/10;
        }

    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    filas = m.filas;
    columnas = m.columnas;
    ptr = new  float*[filas];
    for (int i=0;i<filas;i++){
        ptr[i]=new float[columnas];
    }
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < columnas ; j++){
            m.ptr[i][j] = ptr[i][j];//cada elemento de la matriz se copia
        }

    }
}

Matriz2D::Matriz2D(Matriz2D&& m){
    /*
    */
    // Constructor de movimiento
    filas = m.filas;
    columnas = m.columnas;
    ptr = new  float*[filas];
    for (int i=0;i<filas;i++){
        ptr[i]=new float[columnas];
    }
    for(int i=0 ; i < filas ; i++){
        for(int j=0 ; j < columnas ; j++){
            ptr[i][j]=m.ptr[i][j];//cada elemento de la matriz se copia
        }
    }
    for(int i=0 ; i<filas;i++){
        delete [] m.ptr[i];
    }
    delete []m.ptr;
    m.ptr=NULL;

}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D trans;
    trans.filas = m.columnas;
    trans.columnas=m.filas;
    trans.ptr = new  float*[trans.filas];
    for (int i=0;i<trans.filas;i++){
        trans.ptr[i]=new float[trans.columnas];
    }
    for(int i=0 ; i < m.filas ; i++){
        for(int j=0 ; j < m.columnas ; j++){
            trans.ptr[j][i] = m.ptr[i][j];//cada elemento de la matriz se intercambia
        }

    }return trans;



}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    os<<"Recibido"<<endl;
    for(int i=0 ; i < m.filas ; i++){
        for(int j=0 ; j < m.columnas ; j++){
            os<<m.ptr[i][j]<<" ";//cada elemento de la matriz se copia
        }os<<endl;
    }return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D mat(m1.filas,m1.columnas);
    //comprobar si ambas matrices son del mismo tamaño
    if((m1.filas==m2.filas)and (m1.columnas == m2.columnas)){
        for(int i=0 ; i < m1.filas ; i++){
            for(int j=0 ; j < m1.columnas ; j++){
                mat.ptr[i][j] = m1.ptr[i][j] + m2.ptr[i][j];//cada elemento de las matrices se suma
            }
        }
    }return mat;
}

Matriz2D operator-(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador -
    Matriz2D mat(m1.filas,m1.columnas);
    //comprobar si ambas matrices son del mismo tamaño
    if((m1.filas==m2.filas)and (m1.columnas == m2.columnas)){
        for(int i=0 ; i < m1.filas ; i++){
            for(int j=0 ; j < m1.columnas ; j++){
                mat.ptr[i][j] = m1.ptr[i][j] - m2.ptr[i][j];//cada elemento de las matrices se suma
            }
        }
    }return mat;
}

Matriz2D operator*(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador
    if(m1.columnas == m2.filas){
        Matriz2D mat(m1.filas, m2.columnas);

        for(int i=0 ; i < m1.filas ; i++){
            for(int j=0 ; j < m2.columnas ; j++){
                float valor=0;
                valor += (m1.ptr[i][j] * m2.ptr[i][j]);

                //asignacion
                mat.ptr[i][j] = valor ;
            }
        }return mat;

    }
    else return m1;
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D mat(m.filas, m.columnas);
    for(int i=0 ; i < m.filas ; i++){
        for(int j=0 ; j < m.columnas ; j++){
            mat.ptr[i][j] = m.ptr[i][j] + n;
        }
    }return mat;

}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
    Matriz2D mat(m.filas, m.columnas);
    for(int i=0 ; i < m.filas ; i++){
        for(int j=0 ; j < m.columnas ; j++){
            mat.ptr[i][j] = m.ptr[i][j] - n;
        }
    }return mat;
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
    Matriz2D mat(m.filas, m.columnas);
    for(int i=0 ; i < m.filas ; i++){
        for(int j=0 ; j < m.columnas ; j++){
            mat.ptr[i][j] = m.ptr[i][j] * n;
        }
    }return mat;
}

Matriz2D operator /(const Matriz2D& m, float n){
    // Sobrecarga del operador /
    Matriz2D mat(m.filas, m.columnas);
    for(int i=0 ; i < m.filas ; i++){
        for(int j=0 ; j < m.columnas ; j++){
            mat.ptr[i][j] = m.ptr[i][j] / n;
        }
    }return mat;
}

float Matriz2D::get(int i, int j){
    return ptr[i][j];
}

int Matriz2D::getFilas(){
    return filas;
}

int Matriz2D::getColumnas(){
    return columnas;
}
