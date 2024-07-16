#ifndef MENUCONFIGURACIONES_H_INCLUDED
#define MENUCONFIGURACIONES_H_INCLUDED
void menuConfiguraciones(){

 int op = 1, y = 0;
  rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    CONFIGURACIONES                  ", 40,2);
        item("COPIA DE SEGURIDAD DEL ARCHIVO  CLIENTES", 50,8, y == 0);
        item("COPIA DE SEGURIDAD DEL ARCHIVO  DESTINOS", 50,9, y == 1);
        item("COPIA DE SEGURIDAD DEL ARCHIVO  VUELOS", 50,10, y == 2);
        item("COPIA DE SEGURIDAD DEL ARCHIVO COMPRAS", 50,11, y == 3);
        item("RESTAURAR EL ARCHIVO DE CLIENTES", 50,12, y == 4);
        item("RESTAURAR EL ARCHIVO DE DESTINOS", 50,13, y == 5);
        item("RESTAURAR EL ARCHIVO DE VUELOS", 50,14, y == 6);
        item("RESTAURAR EL ARCHIVO COMPRAS", 50,15, y == 7);
        item("ESTABLECER DATOS DE INICIO", 50,16, y == 8);
        item("RESTABLECER DATOS DE INICIO", 50,17, y == 9);
        item("VOLVER AL MENU PRINCIPAL", 50,18, y == 10);


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
            if(y > 10){
                y = 10;
            }
            break;
            case 1: /// ENTER

                switch(y){
                case 0:
                    copiaClientes();
                    break;
                case 1:
                    copiaDestinos();
                    break;
                case 2:
                    copiaVuelos();
                    break;
                case 3:
                    copiaCompras();
                    break;
                case 4:
                    restaurarClientes();
                    break;
                case 5:
                    restaurarDestinos();
                    break;
                case 6:
                    restaurarVuelos();
                    break;
                case 7:
                    restaurarCompras();
                    break;
                case 8:
                    establecerDatosIni();
                    break;

                case 9:
                    restablecerDatosIni();
                    break;
                case 10:
                        op = 0;
                    break;
                }

                break;
        default:
            break;
        }

        }while(op != 0);
       // system("cls");
}

/*
void menuConfiguraciones(){
 int opc;
     while(true){
        system("cls");
        cout<<"MENU CONFIGURACION"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - COPIA DE SEGURIDAD DEL ARCHIVO  CLIENTES"<<endl;
        cout<<"2 - COPIA DE SEGURIDAD DEL ARCHIVO DESTINOS"<<endl;
        cout<<"3 - COPIA DE SEGURIDAD DEL ARCHIVO VUELOS"<<endl;
        cout<<"4 - RESTAURAR EL ARCHIVO DE CLIENTES"<<endl;
        cout<<"5 - RESTAURAR EL ARCHIVO DE DESTINOS"<<endl;
        cout<<"6 - RESTAURAR EL ARCHIVO DE VUELOS"<<endl;
        cout<<"7 - ESTABLECER DATOS DE INICIO"<<endl;
        cout<<"8 - RESTABLECER DATOS DE INICIO"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout <<"0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                copiaClientes();
                break;
            case 2:
                copiaDestinos();
                break;
            case 3:
                copiaVuelos();
                break;
            case 4:
                restablecerClientes();
                break;
            case 5:
                restablecerDestinos();
                break;
            case 6:
                restablecerVuelos();
                break;
            case 7:
                establecerDatosIni();
                break;
            case 8:restablecerDatosIni();
                break;
            case 0:
                return;
            break;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
    }
}
*/

#endif // MENUCONFIGURACIONES_H_INCLUDED
