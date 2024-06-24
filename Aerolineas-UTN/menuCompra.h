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
    ArchivoVuelos archVuelos;
    Vuelo objVuelo;
    int cant = archVuelos.contarRegistros();
    for(int i = 0; i < cant ;i++){
        objVuelo = archVuelos.leerRegistro(i);
        if(destino == objVuelo.getNumDestino() && objVuelo.getEstado()){
            objVuelo.Mostrar();
            cout<<endl;
        }
        cout << "arch vuelos"<<endl;
    }
    int codigo;
    cout << "SELECCIONE EL CODIGO DE VUELO : ";
    cin >> codigo;
    system("pause");

}

#endif // MENUCOMPRA_H_INCLUDED
