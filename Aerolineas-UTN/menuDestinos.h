#ifndef MENUDESTINOS_H_INCLUDED
#define MENUDESTINOS_H_INCLUDED


void menuDestinos(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU DESTINOS"<<endl;
        cout << "----------------"<<endl;
        cout << "1- CREAR DESTINO"<<endl;
        cout << "2- MODIFICAR DESTINO"<<endl;
        cout << "3- DAR DE BAJA DESTINO"<<endl;
        cout << "4- BUSCAR DESTINO"<<endl;
        cout << "5- VER TODOS LOS DESTINOS DISPONIBLES"<<endl;
        cout << "0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout << "----------------"<<endl;
        cout << "INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            altaDestino();
            break;
//        case 2:
//            modificarDestino();
            break;
        case 3:
            bajaDestino();
            break;
        case 4:
            buscarDestino();
            break;
        case 5:
            mostrarDestinos();
            break;
        case 0:
            return;
        default:
            cout << "LA OPCION INGRESADA ES INCORRECTA, REINTENTE"<<endl;
            system("pause");
            break;
        }
    }
}
#endif // MENUDESTINOS_H_INCLUDED
