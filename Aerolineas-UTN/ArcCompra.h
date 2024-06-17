#ifndef ARCCOMPRA_H_INCLUDED
#define ARCCOMPRA_H_INCLUDED

class ArchivoCompra{
    private:
        char nombre[30];
    public:
        ArchivoCompra(const char *n="compra.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Compra obj);
        void modificarRegistro(Compra obj, int pos);
        Compra leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarRegistro(int num);
};

void ArchivoCompra::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoCompra::grabarRegistro(Compra obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoCompra::modificarRegistro(Compra obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Compra ArchivoCompra::leerRegistro(int pos){
    Compra obj;
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

int ArchivoCompra::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Compra);
}

void ArchivoCompra::listarArchivo(){
    int cant=contarRegistros();
    Compra obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoCompra::buscarRegistro(int num){
    int cant=contarRegistros();
    Compra obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getNumero()){
            return i;
        }
    }
    return -1;
}



#endif // ARCCOMPRA_H_INCLUDED
