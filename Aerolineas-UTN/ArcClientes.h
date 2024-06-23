#ifndef ARCCLIENTES_H_INCLUDED
#define ARCCLIENTES_H_INCLUDED

class ArchivoClientes{
    private:
        char nombre[30];
    public:
        ArchivoClientes(const char *n="clientes.dat"){strcpy(nombre,n);}
        void limpiarArchivo();
        bool grabarRegistro(Cliente obj);
        void modificarCliente(Cliente obj, int pos);
        Cliente leerRegistro(int pos);
        void listarArchivo();
        int contarRegistros();
        int buscarDNI(const char *dni);
        /*
        void altaCliente();
        void eliminarCliente();
        */
};

void ArchivoClientes::limpiarArchivo(){
    FILE *p=fopen(nombre, "wb");
    if(p==NULL){return;}
    fclose(p);
}

bool ArchivoClientes::grabarRegistro(Cliente obj){
    FILE *p=fopen(nombre, "ab");
    if(p==NULL){return false;}
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    return true;
}
void altaCliente()
{
    Cliente obj;
    ArchivoClientes arcObj;
    obj.Cargar();
    if(arcObj.grabarRegistro(obj)){
        cout << "¡CLIENTE CREADO EXITOSAMENTE!"<<endl;
        system("pause");
    }
}
void eliminarCliente()
{   char dni[8];
    Cliente obj;
    ArchivoClientes arcObj;
    cout<<"INGRESE EL DNI DEL CLIENTE A DAR DE BAJA : ";
    cargarCadena(dni,7);
    int pos = arcObj.buscarDNI(dni);
    obj=arcObj.leerRegistro(pos);
    obj.setEstado(false);
    arcObj.modificarCliente(obj,pos);
    cout<<"EL CLIENTE SE DIO DE BAJA."<<endl;
    system("pause");

}

void ArchivoClientes::modificarCliente(Cliente obj, int pos){
    FILE *p=fopen(nombre, "rb+");
    if(p==NULL){return;}
    fseek(p, pos * sizeof obj, 0);
    fwrite(&obj, sizeof obj, 1, p);
    fclose(p);
    system("pause");
}

Cliente ArchivoClientes::leerRegistro(int pos){
    Cliente obj;
    obj.setDni("000000");
    FILE *p=fopen(nombre, "rb");
    if(p==NULL){
        obj.setDni("-111111");
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
    bool clientes = false;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getEstado()){
        obj.Mostrar();
        cout<<endl;
        clientes = true;
        }
    }
    if(clientes == false){
        cout << "NO HAY CLIENTES REGISTRADOS"<<endl;

    }

}

void mostrarClientes(){
    ArchivoClientes archCli;
    archCli.listarArchivo();
    system("pause");
}

int ArchivoClientes::buscarDNI(const char *dni){
    int cant=contarRegistros();
    Cliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(strcmp(dni,obj.getDni())== 0){
            return i;
        }
    }
    return -1;
}
void buscarCliente(){
    int pos;
    ArchivoClientes archCli;
    Cliente obj;
    char dni[8];
    cout << "INGRESE EL DNI DEL CLIENTE : "<<endl;
    cargarCadena(dni,7);
    pos =  archCli.buscarDNI(dni);
    if(pos >= 0){
        obj = archCli.leerRegistro(pos);
        obj.Mostrar();
        system("pause");

    }else{
        cout << "NO SE ENCONTRÓ CLIENTE CON ESE DNI"<<endl;
    }
}

#endif // ARCCLIENTES_H_INCLUDED
