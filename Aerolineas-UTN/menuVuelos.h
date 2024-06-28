#ifndef MENUVUELOS_H_INCLUDED
#define MENUVUELOS_H_INCLUDED

void menuVuelos(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU VUELOS"<<endl;
        cout << "----------------"<<endl;
        cout << "1- CREAR VUELO"<<endl;
        cout << "2- MODIFICAR VUELO"<<endl;
        cout << "3- DAR DE BAJA VUELO"<<endl;
        cout << "4- BUSCAR VUELO"<<endl;
        cout << "5- VER TODOS LOS VUELOS DISPONIBLES"<<endl;
        cout << "0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout << "----------------"<<endl;
        cout << "INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            altaVuelo();
            break;
        case 2:
//            modificarVuelo();
            break;
        case 3:
            bajaVuelo();
            break;
        case 4:
            buscarVuelo();
            break;
        case 5:
            mostrarVuelos();
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

#endif // MENUVUELOS_H_INCLUDED
