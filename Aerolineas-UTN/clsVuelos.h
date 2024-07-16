#ifndef CLSVUELOS_H_INCLUDED
#define CLSVUELOS_H_INCLUDED


class Vuelo
{
    private:
        int _codigo;
        int _clase;
        Destino _destino;
        float _precio;
        Horario _hora;
        Fecha _fecha;
        //int _cantidadAsientos[50]={0};
        bool _estado;

    public:
        void setCodigo(int cod){_codigo = cod;}
        void setClase(int cl){_clase = cl;}
        void setDestino(Destino dest){_destino=dest;}
        bool setPrecio(float precio){
            if(precio > 0){
                    _precio = precio;
                    return true;
            }else{
                system("cls");
                item("NO PUEDE INGRESARSE UN PRECIO NEGATIVO",40,12,false);
                itemPause("Presione una tecla para continuar...",42,13);
                return false;
            }
        }
        void setEstado(bool est){_estado=est;}
        void setFecha(Fecha f){_fecha = f;}
        void setHora(Horario hs){_hora = hs;}
       // void *setCantidadAsientos(int *asientos){_cantidadAsientos = asientos;}

        int getCodigo(){return _codigo;}
        int getClase(){return _clase;}
        Destino getDestino(){return _destino;}
        float getPrecio(){return _precio;}
        bool getEstado(){return _estado;}
        Fecha getFecha(){return _fecha;}
        Horario getHorario(){return _hora;}
       // int *getCantidadAsientos(){return _cantidadAsientos;}
        bool Cargar();
        void Mostrar();
        int menuEditar();
};

bool Vuelo::Cargar()
{
    system("cls");
    titulo("                    VUELO                  ", 40,2);
    Fecha fechaAux;
    item("INGRESE EL CODIGO DEL VUELO: ",30,6,false);
    rlutil::locate(30,7);
    cin>>_codigo;
    setCodigo(_codigo);
    item("INGRESE LA CLASE (1, 2 o 3): ",30,9,false);
    rlutil::locate(30,10);
    cin>>_clase;
    setClase(_clase);
    ArchivoDestinos archDesti;
    int aux;
    item("INGRESE UN NUMERO DE DESTINO: ",30,12,false);
    rlutil::locate(30,13);
    cin>>aux;
    int pos = archDesti.buscarNumeroDestino(aux);
    _destino = archDesti.leerRegistro(pos);
    if(pos >=0){
    rlutil::locate(30,14);
    _destino.MostrarNombre();
    item("INGRESE EL PRECIO: ",30,16,false);
    rlutil::locate(30,17);
    cin>>_precio;
    if(setPrecio(_precio)){
    item("INGRESE LA FECHA: ",30,19,false);
    fechaAux.Cargar();
    if(compararFecha(fechaAux)){
    item("INGRESE EL HORARIO: ",70,16,false);
    rlutil::locate(70,18);
    _hora.Cargar();
    _estado=true;
    _fecha = fechaAux;
    }else{
        itemError("FECHA INGRESADA INCORRECTA",50,20);
        itemPause("Presione una tecla para continuar...",50,22);
        return false;
    }
    return true;
}else{
    return false;
    }
    }else{
        system("cls");
        item("EL DESTINO NO EXISTE",40,12,false);
        //cout << "EL DESTINO NO EXISTE"<<endl;
        itemPause("Presione una tecla para continunar...",40,12);
        return false;
    }
}
void Vuelo::Mostrar()
{   if(_estado)
{
    //system("cls");
    //rlutil::locate(40,15);
    cout<<"CODIGO: "<<_codigo<<endl;
    cout<<"CLASE: "<<_clase<<endl;
    //cout<<"DESTINO : "<<_numDestino<<endl;
    cout<<"PRECIO: $"<<_precio<<endl;
    cout<<"FECHA: "<<_fecha.getDia()<<"/"<<_fecha.getMes()<<"/"<<_fecha.getAnio()<<endl;
    cout<<"HORA: ";
    if(_hora.getHora()<10){
        cout<<"0";
    }
    cout<<_hora.getHora()<<":";
    if(_hora.getMinutos()<10){cout<<"0";}
    cout<<_hora.getMinutos()<<endl;
    cout<<"DESTINO: "<<_destino.getNombre()<<endl;
}
}
int Vuelo::menuEditar(){
     int op = 1, y = 0;
  rlutil::hidecursor();
    do{
        system("cls");
        titulo("                    EDITAR                  ", 40,2);
        item("EDITAR CLASE", 50,8, y == 0);
        item("EDITAR DESTINO", 50,9, y == 1);
        item("EDITAR PRECIO", 50,10, y == 2);
        item("EDITAR HORA", 50,11, y == 3);
        item("EDITAR FECHA", 50,12, y == 4);
        item("VOLVER AL MENU PRINCIPAL", 50,14, y == 5);
        //item("EDITAR CANTIDAD DE ASIENTOS", 50,13, y == 5);


        rlutil::locate(48,8 + y);
        cout << (char) 175 <<endl;

        int key = rlutil::getkey();

        switch(key){
            case 14: /// UP
            rlutil::locate(48,8 + y);
            cout << " " <<endl;
            y--;
            if(y < 0){
                y = 0;
            }
            break;
            case 15: /// DOWN
            rlutil::locate(48,8 + y);
            cout << " " <<endl;
            y++;
            if(y > 5){
                y = 5;
            }
            break;
            case 1: /// ENTER

                switch(y){
                case 0:
                    return 1;
                    break;
                case 1:
                    return 2;
                    break;
                case 2:
                    return 3;
                    break;
                case 3:
                    return 4;
                    break;
                case 4:
                    return 5;
                    break;
                /*
                case 5:
                    return 6;
                    break;
                */
                case 5:
                        op = 0;
                    break;
                }

                break;
        default:
            break;
        }

        }while(op != 0);
       // system("cls");
}
#endif // CLSVUELOS_H_INCLUDED
