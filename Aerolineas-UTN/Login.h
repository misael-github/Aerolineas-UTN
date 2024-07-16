#ifndef LOGIN_H_INCLUDED
#define LOGIN_H_INCLUDED


bool Login(){
#define USUARIO "laboratorio"
#define CONTRASENIA "universidad"

    char usuario[25];
    char clave[25];
    int intentos = 0;
    bool f = false;

    while(intentos < 3 && f == false){
        system("cls");
        titulo("INGRESO AL SISTEMA", 40,4);
        item("USUARIO: ",40,8,false);
        rlutil::locate(50,8);
        cargarCadena(usuario,24);
        item("CONTRASENIA: ",40,13,false);
        rlutil::locate(55,13);
        cargarCadena(clave,24);
        intentos++;

        if(strlen(clave) >= 8){
            if((strcmp(CONTRASENIA,clave) == 0) && (strcmp(USUARIO, usuario) == 0)){
                f = true;
                }
           else{
            itemError("ERROR, EL USUARIO O CONTRASENIA SON INCORRECTOS",40,20);
            itemPause("Presione una tecla para continuar...",40,24);
           }
    }
    else{
        itemError("ERROR, LA CONTRASENIA DEBE TENER AL MENOS 8 CARACTERES",40,20);
        itemPause("Presione una tecla para continuar...",40,24);
    }
    }
    system("cls");
    if(f == true){
        return true;
        ////titulo("¡BIENVENIDO! INGRESO AL SISTEMA CON EXTIO",40,15);
        //system("pause");
    }else {
        return false;

    }
}
#endif // LOGIN_H_INCLUDED
