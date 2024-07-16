#ifndef MENUCLIENTES_H_INCLUDED
#define MENUCLIENTES_H_INCLUDED

menuClientes(){

  int op = 1, y = 0;
  rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    CLIENTES                  ", 40,2);
        item("ALTA CLIENTE", 50,8, y == 0);
        item("MODIFICAR CLIENTE", 50,9, y == 1);
        item("BAJA CLIENTE", 50,10, y == 2);
        item("BUSCAR CLIENTE", 50,11, y == 3);
        item("LISTAR CLIENTES", 50,12, y == 4);
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
                    altaCliente();
                    break;
                case 1:
                    editarCliente();
                    break;
                case 2:
                    eliminarCliente();
                    break;
                case 3:
                    mostrarCliente();
                    break;
                case 4:
                    mostrarClientes();
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
       // system("cls");
}

#endif // MENUCLIENTES_H_INCLUDED
