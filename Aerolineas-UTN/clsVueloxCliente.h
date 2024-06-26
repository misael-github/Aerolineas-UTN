#ifndef CLSVUELOXCLIENTE_H_INCLUDED
#define CLSVUELOXCLIENTE_H_INCLUDED

class VuelosxCliente
{
    private:
        int _dni;
        int _NumAsiento;
        Fecha _fecha;
        int _codigoVuelo;
        bool estado;
    public:
       void setDni(int dni){_dni = dni;}
       void setCodigoVuelo(int cod){_codigoVuelo = cod;}
       void setFecha(Fecha f){_fecha = f;}

       bool getEstado(){return estado;}
       int getDni(){return _dni;}
        Fecha getFecha(){return _fecha;}
        int getCodigoVuelo(return _codigoVuelo;)
       void Mostrar(){};
};
/*
void VuelosxCliente::Mostrar(){
    cout << <<endl;
    cout << <<endl;
    cout << <<endl;
    cout << <<endl;
    cout << <<endl;
}
*/

#endif // CLSVUELOXCLIENTE_H_INCLUDED
