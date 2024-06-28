#ifndef MENUCOMPRA_H_INCLUDED
#define MENUCOMPRA_H_INCLUDED

bool resumenDeCompra(const char *nom, int  codigo, Cliente cliente);

void comprar(){
    Cliente cli;
    int dni;
    cout << "INGRESE EL DNI DEL CLIENTE : ";
    cin >> dni;
    ArchivoClientes archClie;
    int pos = archClie.buscarDNI(dni);
    if(pos >= 0){
    cli = archClie.leerRegistro(pos);
    cout << "DESTINOS DISPONIBLES"<<endl;
    cout << "--------------"<<endl;

    int destino, pos;
    char nombre[30];
    ArchivoDestinos archDesti;
    Destino objDestino;
    archDesti.listarArchivo();

    cout << "SELECCIONE EL NUMERO DE DESTINO : ";
    cin >> destino;
    pos = archDesti.buscarNumeroDestino(destino);
    objDestino = archDesti.leerRegistro(pos);
    cout<<endl;
    system("cls");

    cout << "VUELOS DISPONIBLES"<<endl;
    cout << "--------------"<<endl;
    ArchivoVuelos archVuelos;
    Vuelo objVuelo;
    int cant = archVuelos.contarRegistros();
    bool encontrado = false;
    /// SI NO EXISTE UN VUELO CARGADO PARA EL DESTINO QUE SELECCIONO NO ME DEJA COMPRAR
    for(int i = 0; i < cant ;i++){
        objVuelo = archVuelos.leerRegistro(i);
        if(objDestino.getNumDestino() == objVuelo.getDestino().getNumDestino() && objVuelo.getEstado()){
            objVuelo.Mostrar();
            strcpy(nombre,objDestino.getNombre());
            encontrado = true;
        }
    }
    /*}else{
         cout << "EL DESTINO SELECCIONADO ES INCORRECTO"<<endl;
        system("pause");
        return;
    }*/
    if(encontrado == false){
        cout << "NO HAY VUELOS PARA EL DESTINO SELECCIONADO"<<endl;
        system("pause");
        return;
    }
    int codigo;
    cout<<endl;
    cout << "SELECCIONE EL CODIGO DE VUELO : ";
    cin >> codigo;
    system("cls");
    cout << "vuelo que paso por parametro"<<endl;
    objVuelo.Mostrar();
    if(resumenDeCompra(nombre, codigo, cli)){
        cout << "¡COMPRA CARGADA CON EXITO!"<<endl;
        system("pause");
    }else{
        cout << "COMPRA CANCELADA"<<endl;
        system("pause");
    }
    }else{
        cout << "NO SE ENCONTRO CLIENTE CON ESE DNI"<<endl;
        system("pause");
        return;
    }

}
bool resumenDeCompra(const char *nombre, int cod, Cliente cliente){
    ArchivoVuelos archVuelos;
    Vuelo vuelo;
    cout << "--------- RESUMEN DE COMPRA --------"<<endl;
    cout << "CLIENTE: "<<endl;
    cliente.Mostrar();
    cout << endl;
    cout << "DESTINO SELECCIONADO: "<<nombre<<endl;
    cout << endl;
    cout << "VUELO: "<<endl;
    int pos = archVuelos.buscarCodigo(cod);
    if(pos >= 0){
       vuelo = archVuelos.leerRegistro(pos);
       vuelo.Mostrar();
        cout<<endl;
    int confirma;
    cout << "¿CONFIRMA COMPRA?"<<endl;
    cout << "1- SI "<< " 2- NO"<<endl;
    cin >> confirma;
    ArchivoVueloxCliente archVuelosCliente;
    VuelosxCliente compra;
    if(confirma == 1){
        compra.setDni(cliente.getDni());
        compra.setCodigoVuelo(vuelo.getCodigo());
        compra.setFecha(vuelo.getFecha());
        compra.setDestino(vuelo.getDestino());
        compra.setPrecio(vuelo.getPrecio());
        if(archVuelosCliente.grabarRegistro(compra)){
            return true;
        }

    }else{
        return false;
    }
    }
    //vuelo.Mostrar();
    return false;
}
#endif // MENUCOMPRA_H_INCLUDED
