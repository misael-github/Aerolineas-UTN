#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
class Cliente
{
    private:
        int  _dni;
        char _nombre[15];
        char _apellido[15];
        char _numTelefono[11];
        int _edad;
        char _email[50];
        bool _estado;

    public:
        bool setDni(int dni);
        void setNombre(const char *nom){strcpy(_nombre,nom);}
        void setApellido(const char *ape){strcpy(_apellido,ape);}
        void setNumTel(const char *tel);
        void setEdad(int edad);
        void setEmail(const char *email){strcpy(_email,email);}
        void setEstado(bool est){_estado=est;}

        int getDni(){return _dni;}
        const char *getNumTel(){return _numTelefono;}
        int getEdad(){return _edad;}
        const char *getEmail(){return _email;}
        bool getEstado(){return _estado;}

        void Mostrar();
        void Cargar();

    };

bool Cliente::setDni(int dni) {
    if(dni > 0)
    {
        _dni = dni;
        return true;
    }
    return false;
}

void Cliente::setNumTel(const char *tel)
{
    if(strlen(tel)==10)
    {
        strcpy(_numTelefono,tel);
    }else{
        cout << "TELEFONO NO VALIDO"<<endl;
    }
}

void Cliente::setEdad(int edad)
{
    if(edad>0&& edad<102)
    {
        _edad=edad;
    }
}

void Cliente::Cargar()
{
    int aux;
    //char a[10];
    cout<<"INGRESE EL NOMBRE : ";
    cargarCadena(_nombre,14);
    cout<<"INGRESE EL APELLIDO : ";
    cargarCadena(_apellido,14);
    cout<<"INGRESE EL NUMERO DE DNI : ";
    cin >> _dni;
    if(setDni(_dni) == false){
        cout << "DNI ERRONEO"<<endl;

    }

    cout<<"INGRESE EL NUMERO DE TELEFONO : ";
    cargarCadena(_numTelefono,10);
    setNumTel(_numTelefono);

    cout<<"INGRESE LA EDAD : ";
    cin>>aux;
    setEdad(aux);
    cout<<"INGRESE EL MAIL : ";
    cin>>_email;
    _estado = true;

}

void Cliente::Mostrar()
{
    if(_estado){

    cout<<"NOMBRE : "<<_nombre<<endl;
    cout<<"APELLIDO : "<<_apellido<<endl;
    cout<<"DNI : "<<_dni<<endl;
    cout<<"NUMERO DE TELEFONO : "<<_numTelefono<<endl;
    cout<<"EDAD : "<<_edad<<endl;
    cout<<"EMAIL : "<<_email<<endl;

    }
}

#endif // CLSCLIENTES_H_INCLUDED
