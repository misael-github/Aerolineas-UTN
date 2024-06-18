#ifndef ARCCLIENTES_H_INCLUDED
#define ARCCLIENTES_H_INCLUDED

class ArchivoClientes{
    private:
        char nombre[30];
    public:
        ArchivoClientes(const char *n="clientes.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        void grabarRegistro(Cliente obj);
        void modificarRegistro(Cliente obj, int pos);
        Cliente leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarDNI(int dni);
};

void ArchivoClientes::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

void ArchivoClientes::grabarRegistro(Cliente obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

void ArchivoClientes::modificarRegistro(Cliente obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
}

Cliente ArchivoClientes::leerRegistro(int pos){
    Cliente obj;
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

int ArchivoClientes::contarRegistros(){
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){return -1;}
    fseek(p, 0, 2);
    int cantBytes=ftell(p);
    fclose(p);
    return cantBytes/sizeof (Cliente);
}

void ArchivoClientes::listarArchivo(){
    int cant=contarRegistros();
    Cliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}

int ArchivoClientes::buscarDNI(int dni){
    int cant=contarRegistros();
    Cliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(dni==obj.getDni()){
            return i;
        }
    }
    return -1;
}


#endif // ARCCLIENTES_H_INCLUDED
