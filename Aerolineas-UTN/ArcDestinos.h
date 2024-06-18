#ifndef ARCDESTINOS_H_INCLUDED
#define ARCDESTINOS_H_INCLUDED

class ArchivoDestinos{
    private:
        char nombre[30];
    public:
        ArchivoDestinos(const char *n="clientes.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Destinos obj);
        void modificarRegistro(Destinos obj, int pos);
        Destinos leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarDestino(int num);
};

void ArchivoDestinos::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoDestinos::grabarRegistro(Destinos obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoDestinos::modificarRegistro(Destinos obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Destinos ArchivoDestinos::leerRegistro(int pos){
    Destinos obj;
    obj.setNumDestino(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setNumDestino(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoDestinos::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Destinos);
}

void ArchivoDestinos::listarArchivo(){
    int cant=contarRegistros();
    Destinos obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoDestinos::buscarDestino(int num){
    int cant=contarRegistros();
    Destinos obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getNumDestino()){
            return i;
        }
    }
    return -1;
}



#endif // ARCDESTINOS_H_INCLUDED
