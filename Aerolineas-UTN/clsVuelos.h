#ifndef CLSVUELOS_H_INCLUDED
#define CLSVUELOS_H_INCLUDED

class Vuelo
{
    private:
        int _codigo;
        int _clase;
        Destino _destino;
        float _precio;
        char _horario[5];
        bool _estado;

    public:

        void setCodigo(int cod);
        void setClase(int cl);
        void setDestino(Destino dest){_destino=dest;}
        void setPrecio(float precio);
        void setHorario(const char *hr);
        void setEstado(bool est){_estado=est;}

        int getCodigo(){return _codigo;}
        int getClase(){return _clase;}
        Destino getDestino(){return _destino;}
        float getPrecio(){return _precio;}
        const char *getHorario(){return _horario;}
        bool getEstado(){return _estado;}

        void Cargar();
        void Mostrar();
};

void Vuelo::Cargar()
{
    _estado=true;
    int aux;
    float aux2;
    cout<<"INGRESE EL CODIGO : ";
    cin>>aux;
    setCodigo(aux);
    cout<<"INGRESE LA CLASE : ";
    cin>>aux;
    setClase(aux);
    cout<<"INGRESE EL PRECIO : ";
    cin>>aux2;
    setPrecio(aux2);
    cout<<"INGRESE EL HORARIO : ";
    cargarCadena(_horario,4);


}

void Vuelo::Mostrar()
{   if(_estado)
{


    cout<<"CODIGO : "<<_codigo<<endl;
    cout<<"CLASE : "<<_clase<<endl;
    cout<<"PRECIO : "<<_precio<<endl;
    cout<<"HORARIO : "<<_horario<<endl;
}
}

#endif // CLSVUELOS_H_INCLUDED
