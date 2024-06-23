#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
class Cliente
{
    private:
        char _dni[8];
        char _nombre[15];
        char _apellido[15];
        char _numTelefono[10];
        int _edad;
        char _email[50];
        bool _estado;

    public:
        bool setDni(const char *dni);
        void setNombre(const char *nom){strcpy(_nombre,nom);}
        void setApellido(const char *ape){strcpy(_apellido,ape);}
        void setNumTel(const char *tel);
        void setEdad(int edad);
        void setEmail(const char *email){strcpy(_email,email);}
        void setEstado(bool est){_estado=est;}

        const char *getDni(){return _dni;}
        const char *getNumTel(){return _numTelefono;}
        int getEdad(){return _edad;}
        const char *getEmail(){return _email;}
        bool getEstado(){return _estado;}

        void Mostrar();
        void Cargar();

    };

bool Cliente::setDni(const char *dni) // RECIBE UN VECTOR DE 8 POR ESO SIEMPRE ES VERDADERO
{
    if(strlen(dni)<= 8)
    {
        strcpy(_dni,dni);//
        cout << strlen(dni)<<endl;
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
    //char dni[8];
    cout<<"INGRESE EL NOMBRE : ";
    cargarCadena(_nombre,14);
    cout<<"INGRESE EL APELLIDO : ";
    cargarCadena(_apellido,14);
    cout<<"INGRESE EL NUMERO DE DNI : ";
    cargarCadena(_dni,7);
    if(setDni(_dni)){// DA SIEMPRE VERDADERO PORQUE EL VECTOR ES ESTATICO DE 8 POSICIONES
    cout<<"INGRESE EL NUMERO DE TELEFONO : ";
    cargarCadena(_numTelefono,9);
    setNumTel(_numTelefono);
    cout<<"INGRESE LA EDAD : ";
    cin>>aux;
    setEdad(aux);
    cout<<"INGRESE EL MAIL : ";
    cin>>_email;
    _estado = true;

    }else{
        cout << "DNI NO VALIDO, REINTENTAR"<<endl;

    }

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
    cout<<"estado : "<<_estado<<endl;
    }
}

#endif // CLSCLIENTES_H_INCLUDED
