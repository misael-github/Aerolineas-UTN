#ifndef ARCVUELOS_H_INCLUDED
#define ARCVUELOS_H_INCLUDED

class ArchivoVuelos{
    private:
        char nombre[30];
    public:
        ArchivoVuelos(const char *n="vuelos.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Vuelos obj);
        void modificarRegistro(Vuelos obj, int pos);
        Vuelos leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarCodigo(int num);
};

void ArchivoVuelos::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoVuelos::grabarRegistro(Vuelos obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoVuelos::modificarRegistro(Vuelos obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Vuelos ArchivoVuelos::leerRegistro(int pos){
    Vuelos obj;
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
    return cantBytes/sizeof (Vuelos);
}

void ArchivoVuelos::listarArchivo(){
    int cant=contarRegistros();
    Vuelos obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoVuelos::buscarCodigo(int cod){
    int cant=contarRegistros();
    Vuelos obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(cod==obj.getCodigo()){
            return i;
        }
    }
    return -1;
}


#endif // ARCVUELOS_H_INCLUDED
