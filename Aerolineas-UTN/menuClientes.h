#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED

void menuClientes(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU CLIENTES"<<endl;
        cout << "----------------"<<endl;
        cout << "1- CREAR CLIENTE"<<endl;
        cout << "2- MODIFICAR CLIENTE"<<endl;
        cout << "3- DAR DE BAJA CLIENTE"<<endl;
        cout << "4- BUSCAR CLIENTE"<<endl;
        cout << "5- VER TODOS LOS CLIENTES"<<endl;
        cout << "0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout << "----------------"<<endl;
        cout << "INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            altaCliente();
            break;
        case 2:
            modificarCliente();
            break;
        case 3:
            bajaCliente();
            break;
        case 4:
            buscarCliente();
            break;
        case 5:
            mostrarClientes();
            break;
        case 0:
            return;
            break;
        default:
            cout << "LA OPCION INGRESADA ES INCORRECTA, REINTENTE"<<endl;
            system("pause");
            break;
        }
    }
}

#endif // MENUCLIENTES_H_INCLUDED
