#ifndef MENUCOMPRA_H_INCLUDED
#define MENUCOMPRA_H_INCLUDED


void menuCompra(){
    cout << "DESTINOS DISPONIBLES"<<endl;
    cout << "--------------"<<endl;
    int destino;
    ArchivoDestinos archDesti;
    Destino obj;
    archDesti.listarArchivo();
    cout << "SELECCIONE EL NUMERO DE DESTINO : ";
    cin >> destino;
    cout<<endl;
    cout << "VUELOS DISPONIBLES"<<endl;
    cout << "--------------"<<endl;
    ArchivoVuelos archVuelos;
    Vuelo objVuelo;
    int cant = archVuelos.contarRegistros();
    bool encontrado = false;
    for(int i = 0; i < cant ;i++){
        objVuelo = archVuelos.leerRegistro(i);
        if(destino == objVuelo.getNumDestino() && objVuelo.getEstado()){
            objVuelo.Mostrar();
            encontrado = true;
        }
    }
    if(encontrado == false){
        cout << "NO EXISTE EL DESTINO SELECCIONADO"<<endl;
        system("pause");
        return;
    }
    int codigo;
    cout<<endl;
    cout << "SELECCIONE EL CODIGO DE VUELO : ";
    cin >> codigo;
    system("pause");

}

#endif // MENUCOMPRA_H_INCLUDED
