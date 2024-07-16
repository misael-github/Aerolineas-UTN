#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
class Cliente
{
    private:
        int  _dni;
        char _nombre[15];
        char _apellido[15];
        char _numTelefono[11];
        //int _edad;
        char _email[30];
        bool _estado;

    public:
        bool setDni(int dni);
        void setNombre(const char *nom){strcpy(_nombre,nom);}
        void setApellido(const char *ape){strcpy(_apellido,ape);}
        void setNumTel(const char *tel);
        //void setEdad(int edad);
        void setEmail(const char *email){strcpy(_email,email);}
        void setEstado(bool est){_estado=est;}


        int getDni(){return _dni;}
        const char *getNumTel(){return _numTelefono;}
        //int getEdad(){return _edad;}
        const char *getEmail(){return _email;}
        bool getEstado(){return _estado;}

        void Mostrar();
        void Cargar();
        int menuEditar();
        void editarNombre();
        void editarApellido();

    };

bool Cliente::setDni(int dni) {
    if(dni > 0)
    {
        _dni = dni;
        return true;
    }else{
   // cout << "DNI INCORRECTO"<<endl;
    //system("pause");
    return false;
    }
}

void Cliente::setNumTel(const char *tel)
{
    //if(strlen(tel)==10)
    //{
        strcpy(_numTelefono,tel);
    //}else{
    //    cout << "TELEFONO NO VALIDO"<<endl;
    //}
}

/*void Cliente::setEdad(int edad)
{
    if(edad>0&& edad<102)
    {
        _edad=edad;
    }
}
*/
void Cliente::Cargar()
{
    system("cls");
    titulo("                    CLIENTES                  ", 40,2);
    int aux;
    //char a[10];
    item("INGRESE EL NOMBRE: ",50,8,false);
    //cout<<"INGRESE EL NOMBRE : ";
    rlutil::locate(50,9);
    cargarCadena(_nombre,14);
    item("INGRESE EL APELLIDO: ",50,11,false);
    //cout<<"INGRESE EL APELLIDO : ";
    rlutil::locate(50,12);
    cargarCadena(_apellido,14);

    //cout<<"INGRESE EL NUMERO DE DNI : ";
    item("INGRESE EL NUMERO DE DNI: ",50,14,false);
    rlutil::locate(50,15);
    cin >> _dni;

    if(setDni(_dni)){

    item("INGRESE EL NUMERO DE TELEFONO: ",50,17,false);
    //cout<<"INGRESE EL NUMERO DE TELEFONO : ";
    rlutil::locate(50,18);
    cargarCadena(_numTelefono,10);
    setNumTel(_numTelefono);

    /*
    item("INGRESE LA EDAD: ",50,20,false);
    //cout<<"INGRESE LA EDAD : ";
    rlutil::locate(50,21);
    cin>>aux;
    setEdad(aux);
    */
      item("INGRESE EL MAIL: ",50,20,false);
    //cout<<"INGRESE EL MAIL : ";
    rlutil::locate(50,21);
    cin>>_email;
    _estado = true;

    }else{
         system("cls");
         itemError("DNI INCORRECTO",50,18);
         itemPause("Presione una tecla para continuar...",50,20);
    }


}

void Cliente::Mostrar()
{
    if(_estado){
    //rlutil::locate(40,15);
    cout<<"NOMBRE : "<<_nombre<<endl;
    //rlutil::locate(40,16);
    cout<<"APELLIDO : "<<_apellido<<endl;
    //rlutil::locate(40,17);
    cout<<"DNI : "<<_dni<<endl;
    //rlutil::locate(40,18);
    cout<<"NUMERO DE TELEFONO : "<<_numTelefono<<endl;
    //rlutil::locate(40,19);
    //cout<<"EDAD : "<<_edad<<endl;
    //
    //rlutil::locate(40,20);
    cout<<"EMAIL : "<<_email<<endl;

    }
}
int Cliente::menuEditar(){
     int op = 1, y = 0;
  rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    EDITAR                  ", 40,2);
        item("EDITAR NOMBRE", 50,8, y == 0);
        item("EDITAR APELLIDO", 50,9, y == 1);
        item("EDITAR DNI", 50,10, y == 2);
        item("EDITAR EDAD", 50,11, y == 3);
        item("EDITAR MAIL", 50,12, y == 4);
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
                    return 1;
                    break;
                case 1:
                    return 2;
                    break;
                case 2:
                    return 3;
                    break;
                case 3:
                    return 4;
                    break;
                case 4:
                    return 5;
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
#endif // CLSCLIENTES_H_INCLUDED
