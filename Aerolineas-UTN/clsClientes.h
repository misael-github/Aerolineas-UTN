#ifndef CLSCLIENTES_H_INCLUDED
#define CLSCLIENTES_H_INCLUDED
class Cliente
{
    private:
        int _dni;
        char _numTelefono[10];
        int _edad;
        char _email[50];
        bool _estado;

    public:

        void setDni(int dni);
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

void Cliente::setDni(int dni)
{
    if(dni>0)
    {
        _dni=dni;
    }
}

void Cliente::setNumTel(const char *tel)
{
    if(strlen(tel)==10)
    {
        strcpy(_numTelefono,tel);
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
    char a[10];
    cout<<"INGRESE EL NUMERO DE DNI : ";
    cin>>aux;
    setDni(aux);
    cout<<"INGRESE EL NUMERO DE TELEFONO : ";
    cargarCadena(a,9);
    setNumTel(a);
    cout<<"INGRESE LA EDAD : ";
    cin>>aux;
    setEdad(aux);
    cout<<"INGRESE EL MAIL : ";
    cin>>_email;
}

void Cliente::Mostrar()
{
    cout<<"DNI : "<<_dni<<endl;
    cout<<"NUMERO DE TELEFONO : "<<_numTelefono<<endl;
    cout<<"EDAD : "<<_edad<<endl;
    cout<<"EMAIL : "<<_email<<endl;
}

#endif // CLSCLIENTES_H_INCLUDED
