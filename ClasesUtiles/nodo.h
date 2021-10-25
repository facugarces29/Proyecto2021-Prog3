//
// Created by Facundo on 19/8/2021.
//

#ifndef EJERCICIOS_U02_NODO_H
#define EJERCICIOS_U02_NODO_H
//Nodo
//2 campos
//1 para almacenar el dato (la informacion)
//1 para almacenar la direccion de memoria del proximp nodo


template<class T>
class nodo{

    private:
        T dato;
        nodo<T> *siguiente;

    public:
        T getDato(){
            return dato;
        }

        void setDato( T d){
            dato=d;
        }

        nodo<T> *getSiguiente(){
            return siguiente;
        }

        void setSiguiente(nodo<T> *s){
            this->siguiente = s;

        }
};



#endif //EJERCICIOS_U02_NODO_H
