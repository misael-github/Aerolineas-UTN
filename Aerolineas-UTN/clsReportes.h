#ifndef CLSREPORTES_H_INCLUDED
#define CLSREPORTES_H_INCLUDED

class Reportes
{
    private:
        bool _estado;
        int numero;

    public:
        void setNumero(int num){numero = num;}
        void setEstado(bool estado){_estado=estado;}
        bool getEstado(){return _estado;}
        int getNumero(){return numero;}
        void Mostrar(){};
};



#endif // CLSREPORTES_H_INCLUDED
