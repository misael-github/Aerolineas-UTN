#include <iostream>

using namespace std;

int main()
{
     while(true){
        int opc;
        system("cls");
        cout<<"MENU PRINCIPAL"<<endl;
        cout<<"--------------"<<endl;
        cout<<"1 - MENU CLIENTES"<<endl;
        cout<<"2 - MENU VUELOS"<<endl;
        cout<<"3 - MENU DESTINOS"<<endl;
        cout<<"4 - COMPRAR"<<endl;
        cout<<"5 - REPORTES"<<endl;
        cout<<"0 - SALIR"<<endl;
        cout<<"----------------------------------------"<<endl;
        cout<<"INGRESE LA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
            case 1:
                menuClientes();
                break;
            case 2:
                menuVuelos();
                break;
            case 3:
                menuDestinos();
                break;
            case 4:
                menuCompra();
                break;
            case 5:
                reportes();
          case 0:
                return 0;
            default:
                cout<<"LA OPCION INGRESADA NO ES CORRECTA"<<endl;
                system("pause");
                break;
        }
    }
    return 0;
}
