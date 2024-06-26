#ifndef ARCVUELOXCLIENTE_H_INCLUDED
#define ARCVUELOXCLIENTE_H_INCLUDED

class ArchivoVueloxCliente{
    private:
        char nombre[30];
    public:
        ArchivoVueloxCliente(const char *n="vuelosxcliente.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        bool grabarRegistro(VuelosxCliente obj);
        void modificarRegistro(VuelosxCliente obj, int pos);
        VuelosxCliente leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarRegistro(int num);
};

void ArchivoVueloxCliente::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoVueloxCliente::grabarRegistro(VuelosxCliente obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

void ArchivoVueloxCliente::modificarRegistro(VuelosxCliente obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

VuelosxCliente ArchivoVueloxCliente::leerRegistro(int pos){
    VuelosxCliente obj;
    obj.setDni(-1);
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setDni(-2);
        return obj;
    }
    fseek(p, pos * sizeof obj, 0);
    fread(&obj, sizeof obj, 1, p);
    fclose(p);
    return obj;
}

int ArchivoVueloxCliente::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (VuelosxCliente);
}

void ArchivoVueloxCliente::listarArchivo(){
    int cant=contarRegistros();
    VuelosxCliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoVueloxCliente::buscarRegistro(int num){
    int cant=contarRegistros();
    VuelosxCliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getDni()){
            return i;
        }
    }
    return -1;
}


#endif // ARCVUELOXCLIENTE_H_INCLUDED
