#include "tarea.h"

Matriz2D::Matriz2D(){
    // Constructor por defecto
    filas=3;
    columnas=3;
    for(int i=0 ; i < filas ; i++){
      for(int j=0 ; j < columnas ; j++){
        ptr[i][j]=rand()%2;
      }

    }
}

Matriz2D::Matriz2D(int n){
    // Constructor con un parametro
    filas = n;
    columnas = n;
    for(int i=0 ; i < filas ; i++){
      for(int j=0 ; j < columnas ; j++){
        ptr[i][j]=rand()%2;
      }

    }
}

Matriz2D::Matriz2D(int n, int m){
    // Constructor con dos parametros
    filas = n;
    columnas = m;
    for(int i=0 ; i < filas ; i++){
      for(int j=0 ; j < columnas ; j++){
        ptr[i][j]=rand()%2;
      }

    }
}

Matriz2D::Matriz2D(const Matriz2D& m){
    // Constructor de copia
    filas = m.filas;
    columnas = m.columnas;
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
    for(int i=0 ; i < filas ; i++){
      for(int j=0 ; j < columnas ; j++){
        m.ptr[i][j] = ptr[i][j];//cada elemento de la matriz se copia
      }
    }
       m.ptr=NULL;
       delete []ptr;
}

Matriz2D t(Matriz2D& m){
    // Transpuesta de una matriz
    Matriz2D trans;
    trans.filas = m.columnas;
    trans.columnas=m.filas;
    for(int i=0 ; i < m.filas ; i++){
      for(int j=0 ; j < m.columnas ; j++){
        trans.ptr[j][i] = m.ptr[i][j];//cada elemento de la matriz se intercambia
      }

    }return trans;



}

std::ostream& operator<<(std::ostream& os, const Matriz2D& m){
    // Sobrecarga del operador <<
    for(int i=0 ; i < m.filas ; i++){
      for(int j=0 ; j < m.columnas ; j++){
        os<<m.ptr[i][j]<<" ";//cada elemento de la matriz se copia
      }os<<endl;
    }return os;
}

Matriz2D operator+(const Matriz2D& m1, const Matriz2D& m2){
    // Sobrecarga del operador +
    Matriz2D mat;
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
    Matriz2D mat;
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
        int valor=0;
        for(int k=0;k<m1.columnas;k++){
          for(int l=0;l<m2.filas;i++){
            valor += m1.ptr[i][k] * m2.ptr[j][l];
          }
        }

        //asignacion
        mat.ptr[i][j] = valor ;
      }
    }return mat;
      
    }
}

Matriz2D operator+(const Matriz2D& m, float n){
    // Sobrecarga del operador +
    Matriz2D mat;
    for(int i=0 ; i < m.filas ; i++){
      for(int j=0 ; j < m.columnas ; j++){
        mat.ptr[i][j] = m.ptr[i][j] + n;
      }
    }return mat;

}

Matriz2D operator-(const Matriz2D& m, float n){
    // Sobrecarga del operador -
}

Matriz2D operator*(const Matriz2D& m, float n){
    // Sobrecarga del operador *
}

Matriz2D operator/(const Matriz2D& m, float n){
    // Sobrecarga del operador /
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
