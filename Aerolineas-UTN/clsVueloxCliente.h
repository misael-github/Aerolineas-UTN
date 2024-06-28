#ifndef CLSVUELOXCLIENTE_H_INCLUDED
#define CLSVUELOXCLIENTE_H_INCLUDED

class VuelosxCliente
{
<<<<<<< HEAD
    private:
        int _dni;
        int _NumAciento;
        int _NumVuelo;
        Fecha _fecha;
        bool _estado;
    public:
        void setDni(int dni);
        void setNumeroA(int numeroAciento);
        void setNumeroV(int numeroVuelo);
        void setFecha(Fecha fec);
        void setEstado(bool estado);

        int getDni(){return _dni;}
        int getNumeroA(){return _NumAciento;}
        int getNumeroV(){return _NumVuelo;}
        Fecha getFecha(){return _fecha;}
        bool getEstado(){return _estado;}

        void Cargar()
        {
            _estado=true;
            int aux;
            cout<<"INGRESE EL NUMERO DE DNI : ";
            cin>>aux;
            setDni(aux);
            cout<<"INGRESE EL NUMERO DE ASIENTO : ";
            cin>>aux;
            setNumeroA(aux);
            cout<<"INGRESE EL NUMERO DE VUELO : ";
            cin>>aux;
            setNumeroV(aux);
            cout<<"INGRESE UNA FECHA : "<<endl;
            _fecha.Cargar();

        }

        void Mostrar()
        {
            cout<<"DNI : "<<_dni<<endl;
            cout<<"NUMERO DE ASIENTO : "<<_NumAciento<<endl;
            cout<<"NUMERO DE VUELO : "<<_NumVuelo<<endl;
            cout<<"FECHA : "<<endl;
            _fecha.Mostrar();
        }
=======
private:
    int _dni;
    int _NumAsiento;
    Fecha _fecha;
    int _codigoVuelo;
    Destino _destino;
    float _precio;
    bool estado;
public:
    void setDni(int dni)
    {
        _dni = dni;
    }
    void setCodigoVuelo(int cod)
    {
        _codigoVuelo = cod;
    }
    void setFecha(Fecha f)
    {
        _fecha = f;
    }
    void setDestino(Destino des)
    {
        _destino = des;
    }
    void setPrecio(float pre)
    {
        _precio = pre;
    }

    float getPrecio()
    {
        return _precio;
    }
    bool getEstado()
    {
        return estado;
    }
    int getDni()
    {
        return _dni;
    }
    Fecha getFecha()
    {
        return _fecha;
    }
    int getCodigoVuelo()
    {
        return _codigoVuelo;
    }
    Destino getDestino()
    {
        return _destino;
    }
    void Mostrar();
>>>>>>> 2986cb9d63d4802e1f0d97a0a0391d447626606c
};

void VuelosxCliente::Mostrar(){
    cout << "DNI: "<<_dni<<endl;
    cout << "CODIGO DE VUELO: "<<_codigoVuelo<<endl;
    cout << "FECHA: "<<_fecha.getDia()<<"/"<<_fecha.getMes()<<"/"<<_fecha.getAnio()<<endl;
    cout << "DESTINO: "<<_destino.getNombre()<<endl;
    cout << "PRECIO: $"<<_precio<<endl;
}


#endif // CLSVUELOXCLIENTE_H_INCLUDED
