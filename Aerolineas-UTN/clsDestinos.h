#ifndef CLSDESTINOS_H_INCLUDED
#define CLSDESTINOS_H_INCLUDED


class Destino
{
    private:
        int _numDestino;
        char _nombre[30];
        bool _estado;
    public:

        void setNumDestino(int dest){_numDestino = dest;}
        void setNombre(const char *n){strcpy(_nombre,n);}
        void setEstado(bool est){_estado=est;}

        int getNumDestino(){return _numDestino;}
        const char *getNombre(){return _nombre;}
        bool getEstado(){return _estado;}
        void Cargar();
        void CargarNumero();
        void MostrarNombre();
        void Mostrar();
        int menuEditar();


};



void Destino::Cargar()
{
    system("cls");
    int aux;
    cout<<"INGRESE UN NUMERO DE DESTINO : ";
    cin>>aux;
    setNumDestino(aux);
    cout<<"INGRESE EL NOMBRE DEL DESTINO : ";
    cargarCadena(_nombre,29);
    _estado = true;
}


void Destino::MostrarNombre(){
   // item("DESTINO: ",30,15,false);
    cout<<_nombre<<endl;

}
void Destino::Mostrar()
{
    cout<<"NUMERO DE DESTINO : "<<_numDestino<<endl;
    cout<<"NOMBRE : "<<_nombre<<endl;
}
int Destino::menuEditar(){
    int op = 1, y = 0;
    rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    EDITAR                  ", 40,2);
        item("EDITAR NOMBRE", 50,8, y == 0);
        item("VOLVER AL MENU PRINCIPAL", 50,9, y == 1);

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
                    return 1;
                    break;
                case 1:
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

#endif // CLSDESTINOS_H_INCLUDED
