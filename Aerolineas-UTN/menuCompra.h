#ifndef MENUCOMPRA_H_INCLUDED
#define MENUCOMPRA_H_INCLUDED

void resumenDeCompra(const char *nom, Vuelo obj, Cliente cliente);

void menuCompra(){
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
    Destino obj;
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
        if(destino == objVuelo.getDestino().getNumDestino() && objVuelo.getEstado()){
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

    resumenDeCompra(nombre, objVuelo, cli);
    }else{
        cout << "NO SE ENCONTRO CLIENTE CON ESE DNI"<<endl;
        system("pause");
        return;
    }

}
void resumenDeCompra(const char *nombre, Vuelo obj, Cliente cliente){
    cout << "--------- RESUMEN DE COMPRA --------"<<endl;
    cout << "CLIENTE: "<<endl;
    cliente.Mostrar();
    cout << "DESTINO SELECCIONADO: "<<endl<<nombre<<endl;
    cout << "VUELO: "<<endl;
    obj.Mostrar();
    cout<<endl;
    int confirma;
    cout << "¿CONFIRMA COMPRA?"<<endl;
    cout << "1- SI "<< " 2- NO"<<endl;
    cin >> confirma;
    ArchivoVueloxCliente archVuelosCliente;
    VuelosxCliente vueloCliente;
    if(confirma == 1){
        vueloCliente.setDni(cliente.getDni());
        vueloCliente.setCodigoVuelo(obj.getCodigo());
        vueloCliente.setFecha(obj.getFecha());
        vueloCliente.setDestino(obj.getDestino());
        archVuelosCliente.grabarRegistro(vueloCliente);

    }
    system("pause");
}
#endif // MENUCOMPRA_H_INCLUDED
