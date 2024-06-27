#ifndef CLSVUELOS_H_INCLUDED
#define CLSVUELOS_H_INCLUDED

class Vuelo
{
    private:
        int _codigo;
        int _clase;
        Destino _destino;
       // int _numDestino;
        float _precio;
        char _horario[6];
        Fecha _fecha;
        bool _estado;

    public:

        void setCodigo(int cod){_codigo = cod;}
        void setClase(int cl){_clase = cl;}
        //void setNumDestino(int des){_numDestino = des;}
        void setDestino(Destino dest){_destino=dest;}
        void setPrecio(float precio){_precio = precio;}
        void setHorario(const char *hr){strcpy(_horario,hr);}
        void setEstado(bool est){_estado=est;}
        void setFecha(Fecha f){_fecha = f;}

        int getCodigo(){return _codigo;}
        int getClase(){return _clase;}
        Destino getDestino(){return _destino;}
        float getPrecio(){return _precio;}
        const char *getHorario(){return _horario;}
        bool getEstado(){return _estado;}
        Fecha getFecha(){return _fecha;}

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
    _destino.Cargar();///ERROR PORQUE EL NOMBRE QUE CARGO NO NECESARIAMENTE COINCIDE CON EL NOMBRE QUE ESTA EN EL ARCHIVO DESTINOs
    cout<<"INGRESE EL PRECIO : ";
    cin>>_precio;
    setPrecio(_precio);
    _fecha.Cargar();
    cout<<"INGRESE EL HORARIO : ";
    cargarCadena(_horario,5);
    _estado=true;


}

void Vuelo::Mostrar()
{   if(_estado)
{


    cout<<"CODIGO : "<<_codigo<<endl;
    cout<<"CLASE : "<<_clase<<endl;
    //cout<<"DESTINO : "<<_numDestino<<endl;
    cout<<"PRECIO : $"<<_precio<<endl;
    cout<<"FECHA : "<<_fecha.getDia()<<"/"<<_fecha.getMes()<<"/"<<_fecha.getAnio()<<endl;
    cout<<"HORARIO : "<<_horario<<"hs"<<endl;
    cout<<"DESTINO : "<<_destino.getNombre()<<endl;
}
}

#endif // CLSVUELOS_H_INCLUDED
