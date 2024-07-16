#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


void vueloCliente(){
    int dni;
    ArchivoVueloxCliente archVueloCliente;
    int cantReg  = archVueloCliente.contarRegistros();
    ArchivoClientes archClientes;
    VueloxCliente compra;
    system("cls");
    cout << "INGRESE DNI DEL CLIENTE: ";
    cin >> dni;
    int pos = archClientes.buscarDNI(dni);
    if(pos >= 0){
    int pos2 = archVueloCliente.buscarRegistro(dni);
    if(pos2 >= 0){
        for(int i =0; i < cantReg; i++){/// ME MUESTRA 2 VECES LA MISMA COMPRA
        compra = archVueloCliente.leerRegistro(i);
        compra.Mostrar();
        cout<<endl;
        }

    }else{
         cout << "NO HAY VUELOS REGISTRADOS DE EL CLIENTE"<<endl;
    }
    }else{
        cout << "NO EXISTE CLIENTE CON EL DNI INGRESADO"<<endl;
    }
    system("pause");
}
/// VUELOS POR CLIENTES = COMPRAS
void mostrarVector(int *vec, int tam){
    for(int i=0; i < tam;i++ ){
        cout<<"SE VENDIERON " << vec[i]<<" PASAJES PARA EL DESTINO "<<i + 1<<endl;
    }
}
void ponerEnceroVector(int *destinos,int cant){
    for(int i=0; i < cant;i++){
        destinos[i] = 0;
    }
}
int contarPasajesVendidosPorDestino(int *destinos){

        ArchivoVueloxCliente archiVuelosComprados;
        VueloxCliente obj;
        int cantCompras = archiVuelosComprados.contarRegistros();
        for(int i=0; i < cantCompras;i++){
        obj = archiVuelosComprados.leerRegistro(i);
        int numDestino = obj.getDestino().getNumDestino();
        destinos[numDestino -1]++;
    }

}
void pasajesVendidosPorDestino(){
        ArchivoDestinos archDesti;
        int cantReg  = archDesti.contarRegistros();
        int *destinos = new int[cantReg];
        if(destinos == nullptr){
        cout << "ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return ;
        }
        ponerEnceroVector(destinos,cantReg);

        contarPasajesVendidosPorDestino(destinos);
        system("cls");
        mostrarVector(destinos,cantReg);
        system("pause");

        delete destinos;

}
int buscarMenor(int *vec, int tam){
    int pos = 0;
    for(int i=1; i <= tam; i++){
        if(vec[i] < vec[pos] ){
            pos = i;
        }
    }
    return pos;
}
int buscarMayor(int *vec, int tam){
    int pos = 0;
    for(int i=1; i <= tam; i++){
        if(vec[i] > vec[pos] ){
            pos = i;
        }
    }
    return pos;
}
void destinoConMenorVentas(){
 ArchivoDestinos archDesti;
    int cantReg  = archDesti.contarRegistros();
    int *destinos = new int[cantReg];
    if(destinos == nullptr){
        cout << "ERROR DE ASIGNACION DE MEMORIA"<<endl;
        return;
    }
    ponerEnceroVector(destinos,cantReg);

    ArchivoVueloxCliente archiVuelosComprados;
    VueloxCliente obj;
    int cantCompras = archiVuelosComprados.contarRegistros();
    for(int i=0; i < cantCompras;i++){
    obj = archiVuelosComprados.leerRegistro(i);
    int numDestino = obj.getDestino().getNumDestino();
    destinos[numDestino -1]++;

    }
    int pos = buscarMenor(destinos, cantReg);
    system("cls");
    rlutil::locate(40,12);
    cout << "EL DESTINO CON MENOR CANTIDAD DE PASAJES VENDIDOS ES EL "<< pos + 1<<endl;
    system("pause");
}
void mesDeMayorRecaudacion(){
    ArchivoVueloxCliente archiVuelosComprados;
    VueloxCliente obj;
    int meses[12] = {0};
    int cantCompras = archiVuelosComprados.contarRegistros();
    for(int i = 0; i < cantCompras; i++){
        obj = archiVuelosComprados.leerRegistro(i);
        meses[obj.getFecha().getMes()] += obj.getPrecio();
        //obj.Mostrar();
    }

    int pos = buscarMayor(meses, 11);
    system("cls");
    rlutil::locate(40,12);
    cout << "EL MES CON MAYOR RECAUDACION FUE EL MES "<< pos<<endl;

system("pause");
}
void listarCompras(){

    ArchivoVueloxCliente archCompras;
    VueloxCliente obj;
    int cantReg = archCompras.contarRegistros();
    bool encontrado = false;
    for(int i=0; i < cantReg;i++){
         obj=   archCompras.leerRegistro(i);
        obj.Mostrar();
        encontrado = true;
        cout<<endl;

    } if(encontrado == false){
        cout << "NO HAY COMPRAS CARGADAS"<<endl;
    }
    system("pause");
}
#endif // REPORTES_H_INCLUDED
