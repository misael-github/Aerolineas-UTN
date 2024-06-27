#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


void vueloCliente(){
    int dni;
    ArchivoVueloxCliente archVueloCliente;
    int cantReg  = archVueloCliente.contarRegistros();
    ArchivoClientes archClientes;
    VuelosxCliente compra;
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
void contarPasajesVendidosPorDestino(int *destinos){

        ArchivoVueloxCliente archiVuelosComprados;
        VuelosxCliente obj;
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
        return;
    }
    ponerEnceroVector(destinos,cantReg);
    contarPasajesVendidosPorDestino(destinos);

    mostrarVector(destinos,cantReg);
    system("pause");
    delete destinos;

}
void destinoConMenorVentas(){

}
#endif // REPORTES_H_INCLUDED
