#ifndef CLSVUELOXCLIENTE_H_INCLUDED
#define CLSVUELOXCLIENTE_H_INCLUDED

class VuelosxCliente
{
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
};


#endif // CLSVUELOXCLIENTE_H_INCLUDED
