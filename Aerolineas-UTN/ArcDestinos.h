#ifndef ARCDESTINOS_H_INCLUDED
#define ARCDESTINOS_H_INCLUDED

class ArchivoDestinos{
    private:
        char nombre[30];
    public:
        ArchivoDestinos(const char *n="clientes.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        bool grabarRegistro(Destino obj);
        bool modificarRegistro(Destino obj, int pos);
        Destino leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        //int buscarDestino(int num);
        int buscarNumeroDestino(int num);
};

void ArchivoDestinos::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoDestinos::grabarRegistro(Destino obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}
void altaDestino()
{
    Destino obj;
    ArchivoDestinos arcDesti;
    obj.Cargar();
    if(arcDesti.grabarRegistro(obj)){
        cout << "�DESTINO CREADO EXITOSAMENTE!"<<endl;
        system("pause");
    }
}
bool ArchivoDestinos::modificarRegistro(Destino obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return false;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}

Destino ArchivoDestinos::leerRegistro(int pos){
    Destino obj;
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
    return cantBytes/sizeof (Destino);
}

void ArchivoDestinos::listarArchivo(){
    int cant=contarRegistros();
    Destino obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        obj.Mostrar();
        if(obj.getEstado()==true){cout<<endl;}
    }
}
void mostrarDestinos(){
    ArchivoDestinos archDesti;
    archDesti.listarArchivo();
}

int ArchivoDestinos::buscarNumeroDestino(int num){
    int cant=contarRegistros();
    Destino obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(num==obj.getNumDestino()){
            return i;
        }
    }
    return -1;
}
void buscarDestino(){
    int pos;
    ArchivoDestinos archDesti;
    Destino obj;
    int num;
    cout << "INGRESE NUMERO DE DESTINO : "<<endl;
    cin >> num;
    pos =  archDesti.buscarNumeroDestino(num);
    if(pos >= 0){
        obj = archDesti.leerRegistro(pos);
        obj.Mostrar();

    }else{
        cout << "NO SE ENCONTR� NINGUN DESTINO CON ESE NUMERO"<<endl;
    }
}
void bajaDestino()
{
    ArchivoDestinos archDesti;
    Destino obj;
    int pos;
    int num;
    cout << "INGRESE EL NUMERO DE DESTINO A DAR DE BAJA : "<<endl;
    cin >> num;
    pos = archDesti.buscarNumeroDestino(num);
    if(pos >= 0)
    {
        obj = archDesti.leerRegistro(pos);
        obj.setEstado(false);
        if(archDesti.modificarRegistro(obj,pos))
        {
            cout << "EL VUELO SE DIO DE BAJA CORRECTAMENTE"<<endl;
            system("pause");
        }
        else
        {
            cout << "NO FUE POSIBLE DAR DE NAJA EL VUELO"<<endl;
            system("pause");
        }

    }
    else
    {
        cout << "NO SE ENCONTR� EL CODIGO DE VUELO"<<endl;
        system("pause");
    }

}

#endif // ARCDESTINOS_H_INCLUDED
