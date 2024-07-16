#ifndef HORARIO_H_INCLUDED
#define HORARIO_H_INCLUDED

class Horario{
private:
    int _hora;
    int _minutos;
public:
    int getHora(){return _hora;}
    int getMinutos(){return _minutos;}
    void setHora(int hra){_hora = hra;}
    void setMinutos(int mts){_minutos = mts;}
    void Cargar();
    void Mostrar();
};
void Horario::Cargar(){
    item("HORA",70,19,false);
    rlutil::locate(70,20);
    cin>> _hora;
    item("MINUTOS",70,22,false);
    rlutil::locate(70,23);
    cin>> _minutos;
}
void Horario::Mostrar(){
    cout << _hora<<":"<<_minutos<<endl;
}
#endif // HORARIO_H_INCLUDED
