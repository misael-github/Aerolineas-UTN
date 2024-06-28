#ifndef CLSVUELOXCLIENTE_H_INCLUDED
#define CLSVUELOXCLIENTE_H_INCLUDED

class VuelosxCliente
{
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
};

void VuelosxCliente::Mostrar(){
    cout << "DNI: "<<_dni<<endl;
    cout << "CODIGO DE VUELO: "<<_codigoVuelo<<endl;
    cout << "FECHA: "<<_fecha.getDia()<<"/"<<_fecha.getMes()<<"/"<<_fecha.getAnio()<<endl;
    cout << "DESTINO: "<<_destino.getNombre()<<endl;
    cout << "PRECIO: $"<<_precio<<endl;
}


#endif // CLSVUELOXCLIENTE_H_INCLUDED
