#ifndef MENUCOMPRA_H_INCLUDED
#define MENUCOMPRA_H_INCLUDED

bool resumenDeCompra(int  codigo, Cliente cliente);

void comprar(){
    system("cls");
    //titulo("                     COMPRA                  ", 40,2);
    Cliente cliente;
    int dni;
    //item("INGRESE EL DNI DEL CLIENTE: ",50,12, false);

    cout << "INGRESE EL DNI DEL CLIENTE : ";
    cin >> dni;
    ArchivoClientes archClie;
    /// CORROBORO QUE EXISTA EL CLIENTE Y EL ESTADO
    int pos = archClie.buscarDNI(dni);
    cliente = archClie.leerRegistro(pos);
    if(pos >= 0 && cliente.getEstado()){
    /// MUESTROS LOS DETINOS
    system("cls");
    cout << "DESTINOS DISPONIBLES"<<endl;
    cout << "--------------"<<endl;
    int destino, pos;
    //char nombre[30];
    ArchivoDestinos archDesti;
    Destino objDestino;

    int cantReg = archDesti.contarRegistros();
    for(int i = 1; i < cantReg;i++){
       objDestino = archDesti.leerRegistro(i);
       if(objDestino.getEstado()){
            objDestino.Mostrar();
            cout<<endl;
       }
    }
    //archDesti.listarArchivo();
    /// SELECCIONO NRO DESTINO Y LO BUSCO EN MI ARCHIVO DESTINOS
    cout << "SELECCIONE EL NUMERO DE DESTINO : ";
    cin >> destino;
    pos = archDesti.buscarNumeroDestino(destino);
    objDestino = archDesti.leerRegistro(pos);
    if(destino == objDestino.getNumDestino()){
    cout<<endl;
    system("cls");
    /// MUESTROS LOS VUELOS DISPONIBLES PARA ESE DESTINO
    cout << "VUELOS DISPONIBLES"<<endl;
    cout << "--------------"<<endl;
    ArchivoVuelos archVuelos;
    Vuelo objVuelo;
    int cant = archVuelos.contarRegistros();
    bool encontrado = false;
    /// VALIDO EL DESTINO Y MUESTRO LOS VUELOS QUE HAY PARA ESE DESTINO
    /// SI NO EXISTE UN VUELO CARGADO PARA EL DESTINO QUE SELECCIONADO NO ME DEJA COMPRAR
    for(int i = 0; i < cant ;i++){
        objVuelo = archVuelos.leerRegistro(i);
        if(objDestino.getNumDestino() == objVuelo.getDestino().getNumDestino() && objVuelo.getEstado()){
            objVuelo.Mostrar();
            cout<<endl;
            encontrado = true;
        }
    }
    if(encontrado == false){
        cout << "NO HAY VUELOS PARA EL DESTINO SELECCIONADO"<<endl;
        system("pause");
        return;
    }
    /// SELECCIONO EL CODIGO DE VUELO QUE QUIERO
    int codigo;
    cout<<endl;
    cout << "SELECCIONE EL CODIGO DE VUELO : ";
    cin >> codigo;
    int pos2 = archVuelos.buscarCodigo(codigo);
    if(pos2 >= 0){

    objVuelo = archVuelos.leerRegistro(pos2);
    if(codigo == objVuelo.getCodigo()&& objDestino.getNumDestino() == objVuelo.getDestino().getNumDestino() && objVuelo.getEstado()){
    system("cls");
    if(resumenDeCompra(codigo, cliente)){
        cout << "¡COMPRA CARGADA CON EXITO!"<<endl;
        system("pause");
    }else{
        cout << "COMPRA CANCELADA"<<endl;
        system("pause");
    }
    }else{
        cout << "CODIGO DE VUELO SELECCIONADO INCORRECTO"<<endl;
        system("pause");
        return;
    }

    }else{
         cout << " INCORRECTO"<<endl;
        system("pause");
        return;
    }
}else{
        cout<<"CODIGO DE VUELO SELECCIONADO INCORRECTO0"<<endl;
        system("pause");
        system("cls");
        return;
    }
    }else{
    system("cls");
    //item("CODIGO DE VUELO SELECCIONADO INCORRECTO",40,12,false);
     cout << "NO SE ENCONTRO CLIENTE CON ESE DNI / CLIENTE DADO DE BAJA"<<endl;
    system("pause");
    }
}

bool resumenDeCompra(int cod, Cliente cliente){
    ArchivoVuelos archVuelos;
    Vuelo vuelo;

    cout << "--------- RESUMEN DE COMPRA --------"<<endl;
    cout << "*CLIENTE* "<<endl;
    cout<<endl;
    cliente.Mostrar();
    cout << endl;
    cout << "*VUELO SELECCIONADO*"<<endl;
    cout<<endl;
    int pos = archVuelos.buscarCodigo(cod);
    if(pos >= 0){
       vuelo = archVuelos.leerRegistro(pos);
       vuelo.Mostrar();
//    cout << "ASIENTO SELECCIONADO: "<<asiento<<endl;;
    int confirma;
    cout<<endl;

    cout << "¿CONFIRMA COMPRA?"<<endl;
    cout << "1- SI "<< " 2- NO"<<endl;
    cin >> confirma;
    ArchivoVueloxCliente archVuelosxCliente;
    VueloxCliente compra;
    if(confirma == 1){
        compra.setDni(cliente.getDni());
        compra.setCodigoVuelo(vuelo.getCodigo());
        compra.setFecha(vuelo.getFecha());
        compra.setDestino(vuelo.getDestino());
        compra.setPrecio(vuelo.getPrecio());
        if(archVuelosxCliente.grabarRegistro(compra)){

            return true;
        }

    }else{

        return false;
    }
    }

    return false;
}
#endif // MENUCOMPRA_H_INCLUDED
