#ifndef CLSVUELOXCLIENTE_H_INCLUDED
#define CLSVUELOXCLIENTE_H_INCLUDED

class VuelosxCliente
{
    private:
        int _dni;
        int _NumAciento;
        //int _NumVuelo;
        Fecha _fecha;
        Vuelo vuelo;
        bool estado;
    public:
       void setDni(int dni){_dni = dni;}
       void Mostrar(){};
       bool getEstado(){return estado;}
       int getDni(){return _dni;}
       void Mostrar();
};
void VuelosxCliente::Mostrar(){
    cout << <<endl;
    cout << <<endl;
    cout << <<endl;
    cout << <<endl;
    cout << <<endl;
}

#endif // CLSVUELOXCLIENTE_H_INCLUDED
