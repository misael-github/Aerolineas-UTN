#ifndef CLSVUELOS_H_INCLUDED
#define CLSVUELOS_H_INCLUDED

class Vuelo
{
    private:
        int _codigo;
        int _clase;
        Destino _destino;
        int _numDestino;
        float _precio;
        char _horario[6];
        bool _estado;

    public:

        void setCodigo(int cod){_codigo = cod;}
        void setClase(int cl){_clase = cl;}
        void setNumDestino(int des){_numDestino = des;}
        void setDestino(Destino dest){_destino=dest;}
        void setPrecio(float precio){_precio = precio;}
        void setHorario(const char *hr){strcpy(_horario,hr);}
        void setEstado(bool est){_estado=est;}

        int getCodigo(){return _codigo;}
        int getClase(){return _clase;}
        int getNumDestino(){return _numDestino;}
        float getPrecio(){return _precio;}
        const char *getHorario(){return _horario;}
        bool getEstado(){return _estado;}

        void Cargar();
        void Mostrar();
};

void Vuelo::Cargar()
{
    //int aux;
    //float aux2;
    cout<<"INGRESE EL CODIGO DEL VUELO : ";
    cin>>_codigo;
    setCodigo(_codigo);
    cout<<"INGRESE LA CLASE (1, 2 o 3) : ";// NO FUNCIONA SI SE INGRESA UNA LETRA
    cin>>_clase;
    setClase(_clase);
    cout << "INGRESE EL NUMERO DE DESTINO : ";
    cin >> _numDestino;
    cout<<"INGRESE EL PRECIO : ";
    cin>>_precio;
    setPrecio(_precio);
    cout<<"INGRESE EL HORARIO : ";
    cargarCadena(_horario,5);
    _estado=true;


}

void Vuelo::Mostrar()
{   if(_estado)
{


    cout<<"CODIGO DE VUELO : "<<_codigo<<endl;
    cout<<"CLASE : "<<_clase<<endl;
    cout<<"NUMERO DESTINO : "<<_numDestino<<endl;
    cout<<"PRECIO : $"<<_precio<<endl;
    cout<<"HORARIO : "<<_horario<<"hs"<<endl;
}
}

#endif // CLSVUELOS_H_INCLUDED
