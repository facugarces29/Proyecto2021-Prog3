#ifndef U02_LISTAS_LISTA_LISTA_H_
#define U02_LISTAS_LISTA_LISTA_H_
#include "nodo.h"
/**
 * Clase que implementa una Lista Enlasada generica, ya que puede
 * almacenar cualquier tipo de dato T
 * @tparam T cualquier tipo de dato
 */
template <class T> class Lista {
private:
    nodo<T> *inicio;

public:
  Lista();

  //Constructor
  Lista(const Lista<T> &li);

  //Destructor
  ~Lista();

  //Para poder saber si esta vacia
  bool esVacia();

  //Poder saber el tamaño
  int getTamanio();

  //Insertar un dato
  void insertar(int pos, T dato);

  void insertarPrimero(T dato);

  void insertarUltimo(T dato);

  //Eliminar el dato
  void remover(int pos);

  //Obtener el dato
  T getDato(int pos);

  void reemplazar(int pos, T dato);

  //Para poder vaciar la lista
  void vaciar();

  void imprimir();
};

/**
 * Constructor de la clase Lista
 * @tparam T
 */
template <class T>
Lista<T>::Lista() {
    inicio = nullptr;
}

/**
 * Constructor por copia de la clase Lista
 * @tparam T
 * @param li
 */

template <class T>
Lista<T>::Lista(const Lista<T> &li) {

    inicio = li.inicio;

}

/**
 * Destructor de la clase Lista, se encarga de liberar la memoria de todos los
 * nodos utilizados en la lista
 * @tparam T
 */

template <class T> Lista<T>::~Lista() {
    vaciar();
}

/**
 * Metodo para saber si la lista esta vacia
 * @tparam T
 * @return true si la lista esta vacia, sino false
 */
template <class T> bool Lista<T>::esVacia() {

    return inicio == nullptr;  //es lo mismo que usar el ciclo de if

}

/**
 * Metodo para obtener la cantidad de nodos de la lista
 * @tparam T
 * @return la cantidad de nodos de la lista
 */
template <class T>
int Lista<T>::getTamanio() {

    nodo<T> *aux = inicio;
    int tam = 0;

    while(aux != nullptr){     //El nodo no tiene que ser nulo
        aux = aux ->getSiguiente();
        tam++;
    }

    return tam;

}

/**
 * Inserta un nodo con el dato en la posicion pos
 * @tparam T
 * @param pos lugar donde será insertado el dato
 * @param dato  dato a insertar
 */
template <class T>
void Lista<T>::insertar(int pos, T dato) {
    nodo<T> *aux = inicio, *nuevo;
    nuevo = new nodo<T>;
    int posActual=  0;
    nuevo->setDato(dato);

    if (pos == 0){
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (posActual < pos - 1 && posActual < pos -1){
        aux = aux ->getSiguiente();
        posActual++;
    }

    if (aux == nullptr){
        throw 400;
    }

    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);

}

/**
 * Inserta un nodo con el dato en la primera posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarPrimero(T dato) {
    insertar(0,dato);
}
/**
 * Inserta un nodo con el dato en la ultima posicion
 * @tparam T
 * @param dato dato a insertar
 */
template <class T> void Lista<T>::insertarUltimo(T dato) {
    // otro forma pero ineficiente
    // insertar(getTamanio(), dato);

    nodo<T> *aux = inicio, *nuevo;
    nuevo = new nodo<T>;
    nuevo->setDato(dato);

    if (aux == nullptr){
        nuevo->setSiguiente(inicio);
        inicio = nuevo;
        return;
    }

    while (aux->getSiguiente() != nullptr){
        aux = aux->getSiguiente();
    }

    //otra opcion nuevo->setSiguiente(nullptr);
    nuevo->setSiguiente(aux->getSiguiente());
    aux->setSiguiente(nuevo);

}

/**
 * Elimina el nodo en la posicion 'pos' de la lista enlasada
 * @tparam T
 * @param pos posicion del nodo a eliminar
 */
template <class T>
void Lista<T>::remover(int pos) {
    nodo<T> *aux= inicio, *aBorrar ;
    int posActual = 0;

    if (pos == 0){
        inicio = inicio->getSiguiente();
        delete aux;
        return;
    }

    while (aux != nullptr && posActual < pos - 1){
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr){
        throw 400;
    }

    aBorrar  = aux->getSiguiente();
    aux->setSiguiente(aBorrar->getSiguiente());

    delete aBorrar;
}

/**
 * Obtener el dato del nodo en la posicion pos
 * @tparam T
 * @param pos posicion del dato
 * @return dato almacenado en el nodo
 */
template <class T> T Lista<T>::getDato(int pos) {
    nodo<T> *aux =inicio;
    int posActual= 0;

    while (aux != nullptr && posActual < pos - 1){
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr){
        throw 400;
    }

    return aux->getDato();
}

/**
 * Reemplaza el dato almacenado en un nodo por este otro
 * @tparam T
 * @param pos posicion donde se desea reemplazar
 * @param dato nuevo dato a almacenar
 */
template <class T>
void Lista<T>::reemplazar(int pos, T dato) {
    nodo<T> *aux =inicio;
    int posActual= 0;

    while (aux != nullptr && posActual < pos - 1){
        aux = aux->getSiguiente();
        posActual++;
    }

    if (aux == nullptr){
        throw 400;
    }

    aux->setDato(dato);
}

/**
 * Función que vacia la lista enlazada
 * @tparam T
 */
template <class T>
void Lista<T>::vaciar() {
    nodo<T> *aux =inicio, *aBorrar;

    while (aux != nullptr){
        aBorrar = aux;
        aux = aux->getSiguiente();
        delete aBorrar;
    }

    inicio = nullptr;
}
/**
 * Funcion que imprime la lista enlazada
 * @tparam T
 */
template <class T>
void Lista<T>::imprimir() {
    nodo<T> *aux = inicio;

    while ( aux != nullptr ){
        std::cout << aux->getDato() ;
        aux = aux->getSiguiente();
    }
    std::cout << "NULL" <<std::endl;

}

#endif //U02_LISTAS_LISTA_LISTA_H_
