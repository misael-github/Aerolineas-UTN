#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

#include "rlutil.h"
#include "funcionesRlutil.h"
#include "cargarCadena.h"
#include "Login.h"
#include "Horario.h"
#include "clsFecha.h"
#include "clsClientes.h"
#include "clsReportes.h"
#include "clsDestinos.h"
#include "clsVueloxCliente.h"
#include "ArcClientes.h"
#include "ArcDestinos.h"
#include "clsVuelos.h"
#include "ArcReportes.h"
#include "ArcVuelos.h"
#include "ArcVueloxCliente.h"
#include "menuClientes.h"
#include "menuDestinos.h"
#include "Reportes.h"
#include "menuReportes.h"
#include "menuVuelos.h"
#include "menuVueloxCliente.h"
#include "Configuraciones.h"
#include "menuConfiguraciones.h"
#include "menuCompra.h"

void menuPrincipal();


void menuPrincipal(){
    int op = 1, y = 0;
    rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    INICIO                  ", 40,2);
        item("MENU CLIENTES", 50,8, y == 0);
        item("MENU VUELOS", 50,9, y == 1);
        item("MENU DESTINOS", 50,10, y == 2);
        item("COMPRAR", 50,11, y == 3);
        item("MENU REPORTES", 50,12, y == 4);
        item("MENU CONFIGURACIONES", 50,13, y == 5);

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
                    menuClientes();
                    break;
                case 1:
                    menuVuelos();
                    break;
                case 2:
                    menuDestinos();
                    break;
                case 3:
                    comprar();
                    break;
                case 4:
                    menuReportes();
                    break;
                case 5:
                    menuConfiguraciones();
                    break;
                    case 6:
                        op = 0;
                    break;
                }

                break;
        default:
            break;
        }

        }while(op != 0);
}
int main(){

    if(Login()){
    titulo("¡BIENVENIDO! INGRESO AL SISTEMA CON EXITO!",40,10);
    itemPause("Presione una tecla para continuar...",45,23);
    menuPrincipal();
    }else{
        itemError("USTED INTENTO 3 VECES SIN EXTIO. PRUEBE MAS TARDE",40,20);
        itemPause("Presione una tecla para continuar...",45,23);
    }

return 0;
}
