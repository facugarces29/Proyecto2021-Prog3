//
// Created by Facundo on 23/9/2021.
//

#ifndef EJERCICIOS_U02_COLA_H
#define EJERCICIOS_U02_COLA_H
#include "nodo.h"
/**
 * Clase que implementa una Cola generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Cola {
private:

    nodo<T> *tope, *fondo;

public:
    Cola();

    ~Cola();

    void encolar(T dato);

    T desencolar();

    bool esVacia();

    T peek();

};

/**
 * Constructor de la clase Cola
 * @tparam T
 */
template <class T> Cola<T>::Cola() {
    tope = nullptr;
    fondo = nullptr;
}

/**
 * Destructor de la clase Cola, se encarga de liberar la memoria de todos los
 * nodos utilizados en la Cola
 * @tparam T
 */
template <class T> Cola<T>::~Cola() {
    while (!esVacia()){
        desencolar();
    }

    delete tope;
    delete fondo;
}

/**
 * Inserta un dato en la Cola
 * @tparam T
 * @param dato  dato a insertar
 */
template <class T> void Cola<T>::encolar(T dato) {

    nodo<T> *nuevoNodo = new nodo<T>;
    nuevoNodo ->setDato(dato);
    nuevoNodo ->setSiguiente(nullptr);

    if ( fondo == nullptr ){
        tope = nuevoNodo;
    }else{
        fondo ->setSiguiente(nuevoNodo);
    }

    fondo = nuevoNodo;


}

/**
 * Obtener el dato de la Cola
 * @tparam T
 * @return dato almacenado en el nodo
 */
template <class T> T Cola<T>::desencolar() {
    if (esVacia() ){
        throw 400;
    }

    T dato = tope ->getDato();
    nodo<T> *aBorrar = tope;

    tope = tope->getSiguiente();

    //si la cola tenia un solo nodo, le decimos
    //que el fondo es mulo
    if ( tope == nullptr){
        fondo = nullptr;
    }

    delete aBorrar;
    return dato;

}

/**
 * Responde si la Cola se encuentra Vacía
 * @tparam T
 * @return
 */
template <class T> bool Cola<T>::esVacia() {

    return fondo == nullptr;
    /* if (fondo == nullptr) {
        return true;
    } else {
        return false;
    }
    */
}
template<class T>
T Cola<T>::peek() {
    if ( esVacia() ){
        throw 404;
    }
    return tope->getDato();
}


#endif //EJERCICIOS_U02_COLA_H
