#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED
void menuReportes(){
int op = 1, y = 0;
  rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    REPORTES                  ", 40,2);
        item("LISTAR VUELOS POR CLIENTE", 50,12, y == 0);
        item("CANTIDAD DE PASAJES VENDIDOS POR DESTINO", 50,13, y == 1);
        item("DESTINO CON MENOR CANTIDAD DE PASAJES VENDIDO", 50,14, y == 2);
        item("MES CON MAYOR RECAUDACION", 50,15, y == 3);
        item("LISTAR TODAS LAS COMPRAS", 50,16, y == 4);
        item("VOLVER AL MENU PRINCIPAL", 50,17, y == 5);

        rlutil::locate(48,12 + y);
        cout << (char) 175 <<endl;

        int key = rlutil::getkey();

        switch(key){
            case 14: /// UP
            rlutil::locate(48,12 + y);
            cout << " " <<endl;
            y--;
            if(y < 0){
                y = 0;
            }
            break;
            case 15: /// DOWN
            rlutil::locate(48,12 + y);
            cout << " " <<endl;
            y++;
            if(y > 5){
                y = 5;
            }
            break;
            case 1: /// ENTER
                switch(y){
                case 0:
                    vueloCliente();
                    break;
                case 1:
                  pasajesVendidosPorDestino();
                    break;
                case 2:
                    destinoConMenorVentas();
                    break;
                case 3:
                    mesDeMayorRecaudacion();
                    break;
                case 4:
                    listarCompras();
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
void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU REPORTES"<<endl;
        cout << "----------------"<<endl;
        cout << "1- BUSCAR VUELOS POR CLIENTE"<<endl;
        cout << "2- CANTIDAD DE PASAJES VENDIDOS POR DESTINO"<<endl;
        cout << "3- DESTINO CON MENOR CANTIDAD DE PASAJES VENDIDOS"<<endl;
        cout << "4- MES CON MAYOR RECAUDACION"<<endl;
        cout << "5- LISTAR TODAS LAS COMPRAS"<<endl;
        cout << "0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout << "----------------"<<endl;
        cout << "INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            vueloCliente();
            break;
        case 2:
            pasajesVendidosPorDestino();
            break;
        case 3:
            destinoConMenorVentas();
            break;
        case 4:
            mesDeMayorRecaudacion();
            break;
        case 5:
            listarCompras();
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
#endif // MENUREPORTES_H_INCLUDED
