#ifndef MENUDESTINOS_H_INCLUDED
#define MENUDESTINOS_H_INCLUDED
void menuDestinos(){
int op = 1, y = 0;
  rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    DESTINOS                  ", 40,2);
        item("ALTA DESTINO", 50,8, y == 0);
        item("MODIFICAR DESTINO", 50,9, y == 1);
        item("BAJA DESTINO", 50,10, y == 2);
        item("BUSCAR DESTINO", 50,11, y == 3);
        item("LISTAR DESTINOS", 50,12, y == 4);
        item("VOLVER AL MENU PRINCIPAL", 50,13, y == 5);

        rlutil::locate(48,8 + y);
        cout << (char) 175 <<endl;

        int key = rlutil::getkey();

        switch(key){
            case 14: /// UP
            rlutil::locate(48,8 + y);
            cout << " " <<endl;
            y--;
            if(y < 0){
                y = 0;
            }
            break;
            case 15: /// DOWN
            rlutil::locate(48,8 + y);
            cout << " " <<endl;
            y++;
            if(y > 5){
                y = 5;
            }
            break;
            case 1: /// ENTER

                switch(y){
                case 0:
                    altaDestino();
                    break;
                case 1:
                    editarDestino();
                    break;
                case 2:
                    bajaDestino();
                    break;
                case 3:
                    buscarDestino();
                    break;
                case 4:
                    mostrarDestinos();
                    break;
                case 5:
                        op = 0;
                    break;
                }

                break;
        default:
            break;
        }

        }while(op != 0);
}
/*
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
*/
#endif // MENUDESTINOS_H_INCLUDED
