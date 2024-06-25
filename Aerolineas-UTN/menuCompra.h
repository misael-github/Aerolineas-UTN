#ifndef MENUCOMPRA_H_INCLUDED
#define MENUCOMPRA_H_INCLUDED

void resumenDeCompra(const char *nom, Vuelo obj);
void menuCompra(){
    cout << "DESTINOS DISPONIBLES"<<endl;
    cout << "--------------"<<endl;
    int destino;
    char nombre[30];
    ArchivoDestinos archDesti;
    Destino obj;
    int pos;
    archDesti.listarArchivo();

    cout << "SELECCIONE EL NUMERO DE DESTINO : ";
    cin >> destino;
    pos = archDesti.buscarNumeroDestino(destino);
    obj = archDesti.leerRegistro(pos);
    cout<<endl;
    system("cls");
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
            //cout << "DESTINO "<< obj.getNombre();
            strcpy(nombre,obj.getNombre());
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
    system("cls");
    resumenDeCompra(nombre, objVuelo);

}
void resumenDeCompra(const char *nombre, Vuelo obj){
    cout << "--------- RESUMEN DE COMPRA --------"<<endl;
    cout << "DESTINO SELECCIONADO: "<<endl<<nombre<<endl;
    cout << "VUELO: "<<endl;
    obj.Mostrar();
    cout<<endl;
    int confirma;
    cout << "¿CONFIRMA COMPRA?"<<endl;
    cout << "1- SI "<< " 2- NO"<<endl;
    cin >> confirma;
    if(confirma == 1){
        ArchivoVueloxCliente archVuelosCliente;

    }
    system("pause");
}
#endif // MENUCOMPRA_H_INCLUDED
