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
        void Mostrar();


};

<<<<<<< HEAD
void Destinos::Cargar()
{   _estado=true;
    int aux;
=======


void Destino::Cargar()
{   int aux;
>>>>>>> 2986cb9d63d4802e1f0d97a0a0391d447626606c
    cout<<"INGRESE UN NUMERO DE DESTINO : ";
    cin>>aux;
    setNumDestino(aux);
    cout<<"INGRESE EL NOMBRE DEL DESTINO : ";
    cargarCadena(_nombre,29);
<<<<<<< HEAD

=======
    _estado = true;
>>>>>>> 2986cb9d63d4802e1f0d97a0a0391d447626606c
}

void Destino::Mostrar()
{
    if(_estado){
    cout<<"NUMERO DE DESTINO : "<<_numDestino<<endl;
    cout<<"NOMBRE DEL DESTINO : "<<_nombre<<endl;
    }
}


#endif // CLSDESTINOS_H_INCLUDED
