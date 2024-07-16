#ifndef MENUVUELOS_H_INCLUDED
#define MENUVUELOS_H_INCLUDED
void menuVuelos(){
int op = 1, y = 0;
  rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    VUELOS                  ", 40,2);
        item("ALTA VUELO", 50,8, y == 0);
        item("MODIFICAR VUELO", 50,9, y == 1);
        item("BAJA VUELO", 50,10, y == 2);
        item("BUSCAR VUELO", 50,11, y == 3);
        item("LISTAR VUELOS", 50,12, y == 4);
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
                    altaVuelo();
                    break;
                case 1:
                    editarVuelo();
                    break;
                case 2:
                    bajaVuelo();
                    break;
                case 3:
                    buscarVuelo();
                    break;
                case 4:
                    mostrarVuelos();
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
*/

#endif // MENUVUELOS_H_INCLUDED
