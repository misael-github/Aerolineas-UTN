#ifndef MENUREPORTES_H_INCLUDED
#define MENUREPORTES_H_INCLUDED

void menuReportes(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU REPORTES"<<endl;
        cout << "----------------"<<endl;
        cout << "1- BUSCAR VUELOS POR CLIENTE"<<endl;
        cout << "2- CANTIDAD DE PASAJES VENDIDOS POR DESTINO"<<endl;
        cout << "3- DESTINO CON MENOR CANTIDAD DE PASAJES VENDIDOS"<<endl;
        cout << "4- MES CON MAYOR RECAUDACIÓN"<<endl;
        cout << "0- VOLVER AL MENU PRINCIPAL"<<endl;
        cout << "----------------"<<endl;
        cout << "INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:
            vuelosPorcliente();
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

#endif // MENUREPORTES_H_INCLUDED
