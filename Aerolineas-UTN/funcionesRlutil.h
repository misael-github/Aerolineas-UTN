#ifndef FUNCIONESRLUTIL_H_INCLUDED
#define FUNCIONESRLUTIL_H_INCLUDED

void item(const char *texto, int posX, int posY, bool seleccionado){
    if(seleccionado){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    }else{
         rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
        rlutil::locate(posX,posY);
        std::cout<< texto << std::endl;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::setColor(rlutil::COLOR::WHITE);
}
void itemPause(const char *texto, int posX, int posY){
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        rlutil::locate(posX,posY);
        std::cout<< texto << std::endl;
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::anykey();
}

void itemError(const char *texto, int posX, int posY){
        rlutil::locate(posX,posY);
        rlutil::setColor(rlutil::COLOR::WHITE);
        rlutil::setBackgroundColor(rlutil::COLOR::RED);
        std::cout<< texto << std::endl;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
        //itemPause("Presione una tecla para continuar...",50,20);

}

void itemCin(int ingreso, int posX, int posY, bool seleccionado){
    if(seleccionado){
        rlutil::setBackgroundColor(rlutil::COLOR::BLUE);
    }else{
         rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
    }
        rlutil::locate(posX,posY);
        cin>>ingreso ;
       // std::cout<< texto << std::endl;
        rlutil::setBackgroundColor(rlutil::COLOR::BLACK);
}

void titulo(const char *titulo, int posX, int posY){
    rlutil::setBackgroundColor(rlutil::COLOR::LIGHTGREEN);
    rlutil::setColor(rlutil::COLOR::WHITE);
    rlutil::setConsoleTitle(titulo);
    rlutil::locate(posX,posY);
    std::cout<< titulo << std::endl;
}

#endif // FUNCIONESRLUTIL_H_INCLUDED
