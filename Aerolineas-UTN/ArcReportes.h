#ifndef ARCREPORTES_H_INCLUDED
#define ARCREPORTES_H_INCLUDED

class ArchivoReportes{
    private:
        char nombre[30];
    public:
        ArchivoReportes(const char *n="reportes.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Reportes obj);
        void modificarRegistro(Reportes obj, int pos);
        Reportes leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarRegistro(int num);
};

void ArchivoReportes::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoReportes::grabarRegistro(Reportes obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoReportes::modificarRegistro(Reportes obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Reportes ArchivoReportes::leerRegistro(int pos){
    Reportes obj;
    obj.setNumero(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setNumero(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoReportes::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Reportes);
}

void ArchivoReportes::listarArchivo(){
    int cant=contarRegistros();
    Reportes obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoReportes::buscarRegistro(int num){
    int cant=contarRegistros();
    Reportes obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getNumero()){
            return i;
        }
    }
    return -1;
}


#endif // ARCREPORTES_H_INCLUDED
