#ifndef MENUCOMPRA_H_INCLUDED
#define MENUCOMPRA_H_INCLUDED

void compra(){
    int opc;
    while(true){
        system("cls");
        cout << "MENU COMPRA"<<endl;
        cout << "----------------"<<endl;

        cout << "----------------"<<endl;
        cout << "INGRESE UNA OPCION: ";
        cin>>opc;
        system("cls");
        switch(opc){
        case 1:

            break;
        case 2:

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

#endif // MENUCOMPRA_H_INCLUDED
