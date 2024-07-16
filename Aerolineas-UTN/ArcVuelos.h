#ifndef ARCVUELOS_H_INCLUDED
#define ARCVUELOS_H_INCLUDED

class ArchivoVuelos{
    private:
        char nombre[30];
    public:
        ArchivoVuelos(const char *n="vuelos.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        bool grabarRegistro(Vuelo obj);
        bool modificarRegistro(Vuelo obj, int pos);
        Vuelo leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarCodigo(int num);
};

void ArchivoVuelos::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoVuelos::grabarRegistro(Vuelo obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}
void altaVuelo(){
    /// TENGO QUE VERIFICAR QUE EXISTA EL DESTINO PRIMERO
    ArchivoVuelos archVuelos;
    Vuelo obj;
    ArchivoDestinos archDestinos;
    Destino destino;
    bool band= false;
    if(obj.Cargar()){
    int cantRegD = archDestinos.contarRegistros();
    int pos  = archDestinos.buscarNumeroDestino(obj.getDestino().getNumDestino());
/*
    for(int i =0; i <cantRegD; i++ ){
        destino = archDestinos.leerRegistro(i);
        if(destino.getNumDestino()){
            band = true;
        }
    }*/
    //archDestinos.buscarNumeroDestino(obj.getDestino().getNumDestino())
    int pos2 = archVuelos.buscarCodigo(obj.getCodigo());

    if( pos >= 0 && pos2 < 0){
        if(archVuelos.grabarRegistro(obj)){
        item("¡VUELO CARGADO CON EXITO!",50,28,false);
        itemPause("Presione una tecla para continuar...",45,29);
        //cout << "¡VUELO CARGADO CON EXITO!"<<endl;
        }else{
            itemError("ERROR AL CARGAR VUELO, REINTENTE", 40,28);
            //cout << "ERROR AL CARGAR VUELO, REINTENTE"<<endl;
        }
        }else{cout<< "EL DESTINO NO EXISTE / YA EXISTE UN VUELO CON ESE CODIGO"<<endl;
        system("pause");

    }
    /*else{/// SERIA BUENO QUE LO DIGA APENAS SE CARGAR EL DESTINO
        itemError("EL DESTINO NO EXISTE EN EL ARCHIVO DESTINOS", 40,28);
        //cout << "EL DESTINO NO EXISTE EN EL ARCHIVO DESTINOS"<<endl;
        //system("pause");
    }*/
    /*
    else{
        itemError("NO FUE POSIBLE LA CARGA DEL VUELO, REINENTE", 40,28);
        //cout << "NO FUE POSIBLE LA CARGA DEL VUELO, REINENTE"<<endl;
    system("pause");
    }*/

    }
}
bool ArchivoVuelos::modificarRegistro(Vuelo obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

Vuelo ArchivoVuelos::leerRegistro(int pos){
    Vuelo obj;
    obj.setCodigo(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setCodigo(-2);
        return obj;
    }
    fseek(p, pos * sizeof(Vuelo), 0);
    fread(&obj, sizeof(Vuelo), 1, p);
    fclose(p);
    return obj;
}

int ArchivoVuelos::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Vuelo);
}

void ArchivoVuelos::listarArchivo(){
    system("cls");
    int cant=contarRegistros();
    Vuelo obj;
    bool vuelos = false;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getEstado()){
            obj.Mostrar();
            vuelos = true;
            cout<<endl;
        }
    }
     if(vuelos == false){
        item("NO HAY VUELOS REGISTRADOS",40,12,false);
        //cout << "NO HAY VUELOS REGISTRADOS"<<endl;

    }
    system("pause");
    //itemPause("Presione una tecla para continuar...",40,15);
}
void mostrarVuelos(){
    ArchivoVuelos archVuelos;
    archVuelos.listarArchivo();
}

int ArchivoVuelos::buscarCodigo(int cod){
    int cant=contarRegistros();
    Vuelo obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(cod==obj.getCodigo()){
            return i;
        }
    }
    return -1;
}
void buscarVuelo(){
    system("cls");
    int pos;
    ArchivoVuelos archVuelos;
    Vuelo obj;
    int cod;
    item("INGRESE EL CODIGO DE VUELO A BUSCAR: ", 40,12,false);
    //cout << "INGRESE EL CODIGO DE VUELO: "<<endl;
    rlutil::locate(40,13);
    cin >> cod;
    pos =  archVuelos.buscarCodigo(cod);
    if(pos >= 0){
        obj = archVuelos.leerRegistro(pos);

        obj.Mostrar();

    }else{
        item("NO SE ENCONTRÓ NINGUN VUELO CON ESE CODIGO: ", 40,15,false);
        //cout << "NO SE ENCONTRÓ NINGUN VUELO CON ESE CODIGO"<<endl;
    }
    itemPause("Presiones una tecla para continuar...",40,30);
}

void bajaVuelo()
{
    system("cls");
    ArchivoVuelos archVuelos;
    Vuelo obj;
    int pos;
    int codigo;
    item("INGRESE EL CODIGO DE VUELO A DAR DE BAJA: ", 40,12,false);
    //cout << " "<<endl;
    rlutil::locate(40,13);
    cin >> codigo;
    pos = archVuelos.buscarCodigo(codigo);
    if(pos >= 0)
    {
        obj = archVuelos.leerRegistro(pos);
        obj.setEstado(false);
        if(archVuelos.modificarRegistro(obj,pos))
        {
            item("¡EL VUELO SE DIO DE BAJA EXITOSAMENTE! ", 40,15,false);
            //cout << "EL VUELO SE DIO DE BAJA CORRECTAMENTE"<<endl;
            itemPause("Presiones una tecla para continuar...",40,17);
        }

    }
        else
        {
            system("cls");
            itemError("CODIGO INCORRECTO, NO FUE POSIBLE DAR DE BAJA EL VUELO ", 40,12);
             itemPause("Presiones una tecla para continuar...",40,17);
            //cout << "NO FUE POSIBLE DAR DE BAJA EL VUELO"<<endl;
        }
}

void editarVuelo(){
    system("cls");
    ArchivoVuelos archVuelos;
    Vuelo vuelo;
    int codigo, clase;
    float precio;
    Destino destino;
    Horario hora;
    Fecha fecha;
    item("CODIGO DE VUELO A EDITAR: ",40,12,false);
    rlutil::locate(40,13);
    cin>>codigo;
    int pos = archVuelos.buscarCodigo(codigo);
    if(pos >= 0){
    vuelo = archVuelos.leerRegistro(pos);
    int opc = vuelo.menuEditar();
    system("cls");
    switch(opc){
    case 1:
    item("INGRESE LA NUEVA CLASE: ", 40,12,false);
    rlutil::locate(40,13);
    cin>> clase;
    vuelo.setClase(clase);
    archVuelos.modificarRegistro(vuelo,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,16,false);
    itemPause("Presione una tecla para continuar...",40,18);
    break;
    case 2:
    item("INGRESE EL NUEVO DESTINO: ", 40,12,false);
    rlutil::locate(40,13);
    destino.Cargar();
    vuelo.setDestino(destino);
    archVuelos.modificarRegistro(vuelo,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,16,false);
    itemPause("Presione una tecla para continuar...",40,18);
    break;
    case 3:
    item("INGRESE EL NUEVO PRECIO: ", 40,12,false);
    rlutil::locate(40,13);
    cin>>precio;
    vuelo.setPrecio(precio);
    archVuelos.modificarRegistro(vuelo,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,16,false);
    itemPause("Presione una tecla para continuar...",40,18);
    break;
    case 4:
    item("INGRESE LA NUEVA HORA: ", 40,12,false);
    rlutil::locate(40,13);
    hora.Cargar();
    vuelo.setHora(hora);
    archVuelos.modificarRegistro(vuelo,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,16,false);
    itemPause("Presione una tecla para continuar...",40,18);
    system("pause");
    break;
    case 5:
    item("INGRESE LA NUEVA FECHA: ", 40,12,false);
    rlutil::locate(40,13);
    fecha.Cargar();
    vuelo.setFecha(fecha);
    archVuelos.modificarRegistro(vuelo,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,16,false);
    itemPause("Presione una tecla para continuar...",40,18);
    //cout << "¡DATOS ACTUALIZADOS EXITOSAMENTE!"<<endl;
    //system("pause");
    break;
    /*
    case 6:
    cout << "INGRESE LA NUEVA CANTIDAD DE ASIENTOS: ";
    cin>>asientos;
    vuelo.setCantidadAsientos(asientos);
    archVuelos.modificarRegistro(vuelo,pos);
    cout << "¡DATOS ACTUALIZADOS EXITOSAMENTE!"<<endl;
    system("pause");
    break;
    */
    }
    }else {
        system("cls");
        //rlutil::locate(40,12);
       // cout << "VUELO INEXISTENTE"<<endl;
        item("VUELO INEXISTENTE",40,14,false);
        itemPause("Presione una tecla para continuar...",40,16);
    }
}
#endif // ARCVUELOS_H_INCLUDED
