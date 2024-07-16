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
        int buscarDNI(int dni);
        void mostrarCliente();
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
    int pos = arcObj.buscarDNI(obj.getDni());
    if(pos >= 0){
        system("cls");
        itemError("ERROR, CLIENTE EXISTENTE",50,14);
       itemPause("Presione una tecla para continuar...",50,16);
       return;
    }
    if(arcObj.grabarRegistro(obj)){
        item("¡CLIENTE CREADO EXITOSAMENTE!",50,28,false);
        //cout << "¡CLIENTE CREADO EXITOSAMENTE!"<<endl;
        itemPause("Presione una tecla para continuar...",50,29);
        //system("pause");
    }
}

void eliminarCliente()
{
    system("cls");
    int  dni;
    Cliente obj;
    ArchivoClientes arcObj;
    system("cls");
    item("INGRESE EL DNI DEL CLIENTE A DAR DE BAJA: ", 40,12,false);
    rlutil::locate(50,13);
    cout << (char) 175;
    rlutil::locate(52,13);
    cin>> dni ;
    int pos = arcObj.buscarDNI(dni);
    if(pos >= 0){
    obj=arcObj.leerRegistro(pos);
    obj.setEstado(false);
    arcObj.modificarCliente(obj,pos);
    item("¡EL CLIENTE SE DIO DE BAJA EXITOSAMENTE!",50,14,false);
    itemPause("Presione una tecla para continuar...",50,16);
    rlutil::anykey();
    }else{
        system("cls");
        itemError("DNI INCORRECTO",50,14);
        itemPause("Presione una tecla para continuar...",50,16);
    }
    //cout<<"¡EL CLIENTE SE DIO DE BAJA EXITOSAMENTE!"<<endl;
    //system("pause");

}
void editarCliente(){
    system("cls");
    ArchivoClientes archCli;
    Cliente cliente;
    char nombre[15], apellido[15], mail[30];
    int dni, edad;
    item("DNI DE CLIENTE A EDITAR: ",40,12,false);
    //cout<<"DNI DE CLIENTE A EDITAR: ";
    rlutil::locate(40,13);
    cin>>dni;
    int pos = archCli.buscarDNI(dni);
    if(pos >= 0){
    cliente = archCli.leerRegistro(pos);
    int opc = cliente.menuEditar();
    system("cls");
    switch(opc){
    case 1:
    item("INGRESE EL NUEVO NOMBRE: ",40,12,false);
    //cout << "INGRESE EL NUEVO NOMBRE: ";
    rlutil::locate(40,13);
    cargarCadena(nombre,14);
    cliente.setNombre(nombre);
    archCli.modificarCliente(cliente,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,12,false);
    itemPause("Presione una tecla para continuar...",40,14);
    //cout << "¡DATOS ACTUALIZADOS EXITOSAMENTE!"<<endl;
    //system("pause");
    break;
    case 2:
    item("INGRESE EL NUEVO APELLIDO",40,12,false);
    //cout << "INGRESE EL NUEVO APELLIDO: ";
    rlutil::locate(40,13);
    cargarCadena(apellido,14);
    cliente.setApellido(apellido);
    archCli.modificarCliente(cliente,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,12,false);
    itemPause("Presione una tecla para continuar...",40,14);
    //cout << "¡DATOS ACTUALIZADOS EXITOSAMENTE!"<<endl;
    //system("pause");
    break;
    case 3:
    item("INGRESE EL NUEVO DNI:",40,12,false);
    //cout << "INGRESE EL NUEVO DNI: ";
    rlutil::locate(40,13);
    cin>>dni;
    cliente.setDni(dni);
    archCli.modificarCliente(cliente,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,12,false);
    itemPause("Presione una tecla para continuar...",40,14);
    //cout << "¡DATOS ACTUALIZADOS EXITOSAMENTE!"<<endl;
    //system("pause");
    break;
    /*
    case 4:
    item("INGRESE LA NUEVA EDAD:",40,12,false);
    //cout << "INGRESE LA NUEVA EDAD: ";
    rlutil::locate(40,13);
    cin >> edad;
    cliente.setEdad(edad);
    archCli.modificarCliente(cliente,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,12,false);
    itemPause("Presione una tecla para continuar...",40,14);
    //cout << "¡DATOS ACTUALIZADOS EXITOSAMENTE!"<<endl;
    //system("pause");
    break;
    */
    case 5:
    item("INGRESE EL NUEVO MAIL:",40,12,false);
    //cout << "INGRESE EL NUEVO MAIL: ";
    rlutil::locate(40,13);
    cargarCadena(mail,29);
    cliente.setEmail(mail);
    archCli.modificarCliente(cliente,pos);
    item("¡DATOS ACTUALIZADOS EXITOSAMENTE!",40,12,false);
    itemPause("Presione una tecla para continuar...",40,14);
    //cout << "¡DATOS ACTUALIZADOS EXITOSAMENTE!"<<endl;
    //system("pause");
    break;
    }
    }else {
        item("CLIENTE INEXISTENTE",40,12,false);
        itemPause("Presione una tecla para continuar...",40,14);
        //cout << "CLIENTE INEXISTENTE"<<endl;
        //system("pause");
    }
}
void ArchivoClientes::modificarCliente(Cliente obj, int pos){
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
int ArchivoClientes::buscarDNI(int dni){
    int cant=contarRegistros();
    Cliente obj;
    for(int i=0; i<cant; i++){
        obj=leerRegistro(i);
        if(obj.getDni() == dni){
            return i;
        }
    }
    return -1;
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
    system("cls");
    ArchivoClientes archCli;
    archCli.listarArchivo();
    system("pause");
}



void mostrarCliente(){
    system("cls");
    int pos;
    ArchivoClientes archCli;
    Cliente obj;
    int dni;
    item("INGRESE EL DNI DEL CLIENTE:",40,12,false);
    //cout << "INGRESE EL DNI DEL CLIENTE : "<<endl;
    rlutil::locate(40,13);
    cin>> dni;
    system("cls");
    pos =  archCli.buscarDNI(dni);
    obj = archCli.leerRegistro(pos);
    if(pos >= 0 && obj.getEstado()){

        obj.Mostrar();
        cout<<endl;
        itemPause("Presione una tecla para continuar...",40,30);

    }else{
       // cout << "NO SE ENCONTRÓ CLIENTE CON ESE DNI"<<endl;
        item("NO SE ENCONTRO CLIENTE CON ESE DNI",40,14,false);
        itemPause("Presione una tecla para continuar...",40,30);
    }
}


#endif // ARCCLIENTES_H_INCLUDED
