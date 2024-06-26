#ifndef REPORTES_H_INCLUDED
#define REPORTES_H_INCLUDED


void vueloCliente(){
    int dni;
    ArchivoVueloxCliente archVueloCliente;
    ArchivoClientes archClientes;
    VuelosxCliente vueloClie;
    cout << "INGRESE DNI DEL CLIENTE: ";
    cin >> dni;
    int pos = archClientes.buscarDNI(dni);
    cout<<pos<<endl;
    if(pos >= 0){
    int pos2 = archVueloCliente.buscarRegistro(dni);
    cout<<pos2<<endl;
    if(pos2 >= 0){
        vueloClie = archVueloCliente.leerRegistro(pos);
        vueloClie.Mostrar();

    }else{
         cout << "NO HAY VUELOS REGISTRADOS DE EL CLIENTE"<<endl;
    }
    }else{
        cout << "NO EXISTE CLIENTE CON EL DNI INGRESADO"<<endl;
    }
    system("pause");
}

#endif // REPORTES_H_INCLUDED
