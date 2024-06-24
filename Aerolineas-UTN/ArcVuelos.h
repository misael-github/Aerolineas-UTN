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
    ArchivoVuelos archVuelos;
    Vuelo obj;
    obj.Cargar();
    if(archVuelos.grabarRegistro(obj)){
        cout << "¡VUELO CARGADO CON EXITO!"<<endl;
        system("pause");
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
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
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
        cout << "NO HAY VUELOS REGISTRADOS"<<endl;

    }
    system("pause");
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
    int pos;
    ArchivoVuelos archVuelos;
    Vuelo obj;
    int cod;
    cout << "INGRESE EL CODIGO DE VUELO : "<<endl;
    cin >> cod;
    pos =  archVuelos.buscarCodigo(cod);
    if(pos >= 0){
        obj = archVuelos.leerRegistro(pos);
        obj.Mostrar();

    }else{
        cout << "NO SE ENCONTRÓ NINGUN VUELO CON ESE CODIGO"<<endl;
    }
    system("pause");
}

void bajaVuelo()
{
    ArchivoVuelos archVuelos;
    Vuelo obj;
    int pos;
    int codigo;
    cout << "INGRESE EL CODIGO DE VUELO A DAR DE BAJA : "<<endl;
    cin >> codigo;
    pos = archVuelos.buscarCodigo(codigo);
    if(pos >= 0)
    {
        obj = archVuelos.leerRegistro(pos);
        obj.setEstado(false);
        if(archVuelos.modificarRegistro(obj,pos))
        {
            cout << "EL VUELO SE DIO DE BAJA CORRECTAMENTE"<<endl;
            system("pause");
        }
        else
        {
            cout << "NO FUE POSIBLE DAR DE BAJA EL VUELO"<<endl;
            system("pause");
        }

    }
}


#endif // ARCVUELOS_H_INCLUDED
