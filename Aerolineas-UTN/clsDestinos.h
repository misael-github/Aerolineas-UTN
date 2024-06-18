#ifndef CLSDESTINOS_H_INCLUDED
#define CLSDESTINOS_H_INCLUDED

class Destinos
{
    private:
        int _numDestino;
        char _nombre[30];
        bool _estado;
    public:

        void setNumDestino(int Dest);
        void setNombre(const char *n){strcpy(_nombre,n);}
        void setEstado(bool est){_estado=est;}

        int getNumDestino(){return _numDestino;}
        const char *getNombre(){return _nombre;}
        bool getEstado(){return _estado;}
        void Cargar();
        void Mostrar();


};

void Destinos::Cargar()
{   int aux;
    cout<<"INGRESE UN NUMERO DE DESTINO : ";
    cin>>aux;
    setNumDestino(aux);
    cout<<"INGRESE EL NOMBRE DEL DESTINO : ";
    CargarCadena(_nombre,29);

}

void Destinos::Mostrar()
{
    cout<<"NUMERO DE DESTINO : "<<_numDestino<<endl;
    cout<<"NOMBRE DEL DESTINO : "<<_nombre<<endl;
}


#endif // CLSDESTINOS_H_INCLUDED
