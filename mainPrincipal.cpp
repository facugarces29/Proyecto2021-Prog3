//
// Created by Facundo on 25/10/2021.
//
/*
#include <iostream>
#include <fstream>
#include <sstream>
#include "string.h"
#include <vector>
#include "../Proyecto2021-Prog3/ClasesUtiles/Lista.h"

using namespace std;

void exploreCSV(){
    int colDeInteres[]={0,2,3,12,13,14,17,20};
    int nColumnas = sizeof(colDeInteres) / sizeof(colDeInteres[0]);

    fstream fin;
    fin.open("./Covid19Casos10.csv", ios::in);

    vector<string> row;
    string line, word;

    for (int i = 0; i < 10; ++i) {
        row.clear();

        getline(fin,line);

        stringstream s(line);

        while (getline( s, word, ',')){           //Usamos la clase lista

            if (word.size() > 0 ){

                word = word.substr(1,word.size()-2);

            }else{
                word = "NA";
            }

        }
        row.push_back(word);                                    //push_back significa insertar al
                                                                // ultimo cada una de las palabras q separamos de la primer linea
    }

    if ( row[20].compare("Confirmado")==0){

        for (int i = 0; i < nColumnas; ++i) {
            cout << row[colDeInteres[i]] << "  ";               //Le mandamos el indice de las columnas q nos interesan
        }
        cout << endl;
    }
}

void estadistica(){
    int interest[] = { 2, 14, 20};                            //Creamos un vector con los indices de las columnas que necesitamos
    int nColumns = sizeof(interest) / sizeof(interest[0]);

    int totalMuestras = 0;                  //Inicializamos en 0 todos los contadores que nos hacen falta
    int totalInfectados = 0;
    int cantFallecidos = 0;
    float infectadosPorMuestra = 0;
    float fallecidosPorInfectados = 0;
    int cantInfectadosEdad = 0;
    int cantMuertesEdad = 0;

    fstream fin;
    fin.open("./Covid19Casos-10.csv", ios::in);       //Abrimos el archivo CSV nuevamente para despues leerlo

    vector<string> row;                       //En una lista (row) almacenamos las palabras.
    string line, word;

    while(fin.good()){
        //for(int i = 0; i < 100000; i++){
        row.clear();

        getline(fin, line);
        stringstream s(line);

        while(getline(s, word, ',')){       //Separamos las palabras, y las vamos insertando en un vector
            if(word.size() > 0){
                word = word.substr(1, word.size()-2 );
            }else{
                word = "NA";
            }
            row.push_back(word);    //push_back
        }

        if(row[20].compare("Confirmado") == 0){          //Preguntamos si el caso es confirmado
            for(int i = 0; i < nColumns; i++ ){               //Si la respuesta es asi, entonces se suma 1 al totalInfectados
                totalInfectados++;
            }
        }


        if(row[14].compare("SI") == 0){               //De la misma manera que lo anterior, si la respuesta es SI
            for(int i = 0; i < nColumns; i++ ){             //se suma 1 a cantFallecidos
                cantFallecidos++;
            }
        }


        if(atoi(row[2].c_str()) > 10){                       //Idem
            if(row[20].compare("Confirmado") == 0){
                for(int i = 0; i < nColumns; i++ ){
                    cantInfectadosEdad++;
                }
            }
            if(row[14].compare("SI") == 0){                    //Idem
                for(int i = 0; i < nColumns; i++ ){
                    cantMuertesEdad++;
                }
            }
        }

        totalMuestras++;               //Por cada muestra que se procesa se suma 1 al contador de totalMuestras

    }

    infectadosPorMuestra = (totalInfectados*100)/totalMuestras;      //Calculamos el porcentaje de infectadosPorMuestra
    fallecidosPorInfectados = (cantFallecidos*100)/totalInfectados;  //Calculamos el porcentaje de fallecidosPorInfectados

    cout << "Cantidad total de muestras: "<< totalMuestras-1 <<endl;  //Mostramos por pantalla todos los datos pedidos
    cout << "Cantidad total de infectados: "<< totalInfectados<<endl;
    cout << "Cantidad de fallecidos: "<< cantFallecidos <<endl;
    cout << "Porcentaje de infectado por muestras: "<< infectadosPorMuestra <<"%"<<endl;
    cout << "Porcentaje de fallecidos por infectados: "<< fallecidosPorInfectados <<"%"<<endl;
    cout << "Cantidad de infectados por rango etario ( rango de 10 años): " << cantInfectadosEdad <<endl;
    cout << "Cantidad de muertes por rango etario ( rango de 10 años): " << cantMuertesEdad <<endl;



}*/