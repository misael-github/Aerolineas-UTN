#ifndef CONFIGURACIONES_H_INCLUDED
#define CONFIGURACIONES_H_INCLUDED


void copiaClientes();
void copiaDestinos();
void copiaVuelos();
void copiaCompras();

void restaurarClientes();
void restaurarDestinos();
void restaurarVuelos();
void restaurarCompras();

void establecerDatosIni();

void copiaClientes()
{
     ArchivoClientes archClientes,bkpClie("clientes.bkp");
     FILE *p=fopen("clientes.bkp","wb");
    fclose(p);
    int contarReg=archClientes.contarRegistros();
    Cliente obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = archClientes.leerRegistro(i);
        bkpClie.grabarRegistro(obj);
    }
    cout<<"ARCHIVO COPIADO"<<endl;
    system("pause");
}

void copiaDestinos()
{
    ArchivoDestinos archDesti,bkpDesti("destinos.bkp");
    FILE *p=fopen("destinos.bkp","wb");
    fclose(p);
    int contarReg=archDesti.contarRegistros();
    Destino obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = archDesti.leerRegistro(i);
        bkpDesti.grabarRegistro(obj);
    }
    cout<<"ARCHIVO COPIADO"<<endl;
    system("pause");
}
void copiaVuelos()
{
    ArchivoVuelos archVuelos,bkpVuelos("vuelos.bkp");
    FILE *p=fopen("vuelos.bkp","wb");
    fclose(p);
    int contarReg=archVuelos.contarRegistros();
    Vuelo obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = archVuelos.leerRegistro(i);
        bkpVuelos.grabarRegistro(obj);
    }
    cout<<"ARCHIVO COPIADO"<<endl;
    system("pause");
}
void copiaCompras()
{
    ArchivoVueloxCliente archVuelosxCliente,bkpVuelosxCliente("vuelosxcliente.bkp");
    FILE *p=fopen("vuelosxcliente.bkp","wb");
    fclose(p);
    int contarReg=archVuelosxCliente.contarRegistros();
    VueloxCliente obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = archVuelosxCliente.leerRegistro(i);
        bkpVuelosxCliente.grabarRegistro(obj);
    }
    cout<<"ARCHIVO COPIADO"<<endl;
    system("pause");
}
void restaurarClientes()
{
    ArchivoClientes archClientes,bkpClientes("clientes.bkp");
    FILE *p=fopen("clientes.dat","wb");
    fclose(p);
    int contarReg=bkpClientes.contarRegistros();
    Cliente obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = bkpClientes.leerRegistro(i);
        archClientes.grabarRegistro(obj);
    }
     cout<<"ARCHIVO RESTABLECIDO"<<endl;
    system("pause");
}
void restaurarDestinos()
{
     ArchivoDestinos archDesti,bkpDesti("destinos.bkp");
     FILE *p=fopen("destinos.dat","wb");
    fclose(p);
    int contarReg=bkpDesti.contarRegistros();
    Destino obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = bkpDesti.leerRegistro(i);
        archDesti.grabarRegistro(obj);
    }
    cout<<"ARCHIVO RESTABLECIDO"<<endl;
    system("pause");
}

void restaurarVuelos()
{
    ArchivoVuelos archVuelos,bkpVuelos("vuelos.bkp");
    FILE *p=fopen("vuelos.dat","wb");
    fclose(p);
    int contarReg=bkpVuelos.contarRegistros();
    Vuelo obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = bkpVuelos.leerRegistro(i);
        archVuelos.grabarRegistro(obj);
    }
     cout<<"ARCHIVO RESTABLECIDO"<<endl;
    system("pause");
}

void restaurarCompras()
{
    ArchivoVueloxCliente archVuelosCliente,bkpVuelosCliente("vuelosxcliente.bkp");
    FILE *p=fopen("vuelosxcliente.dat","wb");
    fclose(p);
    int contarReg=bkpVuelosCliente.contarRegistros();
    VueloxCliente obj;
    for (int i=0;i<contarReg;i++)
    {
        obj = bkpVuelosCliente.leerRegistro(i);
        archVuelosCliente.grabarRegistro(obj);
    }
     cout<<"ARCHIVO RESTABLECIDO"<<endl;
    system("pause");
}
void establecerDatosIni()
{
    ArchivoClientes archClientes,arcClientesIni("clientes.ini");
    FILE *p=fopen("clientes.ini","wb");
    fclose(p);
    int contarReg=archClientes.contarRegistros();
    Cliente objCli;
    for (int i=0;i<contarReg;i++)
    {
       objCli=archClientes.leerRegistro(i);
       arcClientesIni.grabarRegistro(objCli);
    }

    ArchivoDestinos archDesti,arcDestiIni("destinos.ini");
    FILE *b=fopen("destinos.ini","wb");
    fclose(b);
    contarReg=archDesti.contarRegistros();
    Destino objDes;
    for(int i=0;i<contarReg;i++)
    {
        objDes=archDesti.leerRegistro(i);
        arcDestiIni.grabarRegistro(objDes);
    }

    ArchivoVuelos archVuelos,archVuelosIni("vuelos.ini");
    FILE *v=fopen("vuelos.ini","wb");
    fclose(v);
    int contarRegVue=archVuelos.contarRegistros();
    Vuelo objVuelo;
    for (int i=0;i<contarRegVue;i++)
    {
       objVuelo=archVuelos.leerRegistro(i);
       archVuelosIni.grabarRegistro(objVuelo);
    }
    cout<<"ARCHIVO ESTABLECIDO"<<endl;
    system("pause");
}

void restablecerDatosIni()
{
    ArchivoClientes archClientes,archClieIni("clientes.ini");
    FILE *p=fopen("clientes.dat","wb");
    fclose(p);
    int contarReg=archClieIni.contarRegistros();

    Cliente objClie;
    for (int i=0;i<contarReg;i++)
    {
        objClie=archClieIni.leerRegistro(i);
        archClientes.grabarRegistro(objClie);
    }

    ArchivoDestinos archDesti,arcDestiIni("destinos.ini");
    FILE *b=fopen("destinos.dat","wb");
    fclose(b);
    contarReg=arcDestiIni.contarRegistros();
    Destino objDesti;
    for(int i=0;i<contarReg;i++)
    {
        objDesti=arcDestiIni.leerRegistro(i);
        archDesti.grabarRegistro(objDesti);
    }
    ArchivoVuelos archVuelos,archVueIni("vuelos.ini");
    FILE *v=fopen("vuelos.dat","wb");
    fclose(v);
    contarReg=archVueIni.contarRegistros();
    Vuelo objVuelo;
    for(int i=0;i<contarReg;i++)
    {
        objVuelo=archVueIni.leerRegistro(i);
        archVuelos.grabarRegistro(objVuelo);
    }
    cout<<"ARCHIVO RESTABLECIDO"<<endl;
    system("pause");
}
#endif // CONFIGURACIONES_H_INCLUDED
