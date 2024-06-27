#ifndef CLSFECHA_H_INCLUDED
#define CLSFECHA_H_INCLUDED

#include <chrono>
#include <ctime>

// Obtener el tiempo actual del sistema
    auto now = chrono::system_clock::now();
    time_t now_time = std::chrono::system_clock::to_time_t(now);

    tm* local_time = std::localtime(&now_time);

    // Obtener los componentes de la fecha actual
    int year = local_time->tm_year + 1900;   // Ajuste para el año real
    int month = local_time->tm_mon + 1;
    int day = local_time->tm_mday;
    int hour = local_time->tm_hour;
    int min = local_time->tm_min;
    int sec = local_time->tm_sec;

    //cout << "Fecha y hora actual: ";
    //cout << year << '-' << month << '-' << day << ' ' << hour << ':' << min << ':' << sec <<endl;



class Fecha
{
private:
    int _d;
    int _m;
    int _a;
public:
    Fecha(int dia=0, int mes=0, int anio=0000)
    {
      _d=dia;
      _m=mes;
      _a=anio;

    }

    void setDia(int dia);
    void setMes(int mes);
    void setAnio(int anio);

    int getDia(){return _d;}
    int getMes(){return _m;}
    int getAnio(){return _a;}
    int getAnioActual(){return year;}
    int getMesActual(){return month;}
    int getDiaActual(){return day;}

    void Cargar();
    void Mostrar();

};

void Fecha::setAnio(int anio)
{
    if(anio>=getAnioActual()&&anio<2026)
    {
        _a=anio;
    }
    else
    {
        system("cls");
        cout<<"FECHA INGRESADA INCORRECTA,VUELVA A INGRESAR :"<<endl;
        cout<<"ANIO : ";
        cin>>anio;
        setAnio(anio);

    }
}

void Fecha::setMes(int mes)
{   bool validar=false;
    if(mes>0 &&mes<13)
    {
       if(mes==1 || mes==3 || mes==5 || mes<9 && mes>6 || mes==10 || mes==12)
       {

    if(getDia()>0  && getDia()<32)
    {
        validar=true;
        _m=mes;
    }}
    else if(mes==4 || mes==6 || mes==9 || mes==11)
    {
        if(getDia()>0 && getDia()<31)
        {
            validar=true;
            _m=mes;
        }
    }
    else if(mes==2 )
    {
        if(getDia()>0 && getDia() >= day &&getDia()<30)
        {
            validar=true;
            _m=mes;
        }
    }
    }
    if(validar==false)
    {   system("cls");
        cout<<"FECHA INGRESADA INCORRECTA,VUELVA A INGRESAR :"<<endl;
        cout<<"MES : ";
        cin>>mes;
        setMes(mes);

    }
}

void Fecha::setDia(int dia)
{   bool validar=false;
   if(dia>0&&dia<32)
   {
       _d=dia;
   }
   else
    {
        system("cls");
        cout<<"FECHA INGRESADA INCORRECTA,VUELVA A INGRESAR :"<<endl;
        cout<<"DIA : ";
        cin>>dia;
        setDia(dia);
    }
}

void Fecha::Cargar()
{   int aux;
    cout<<"INGRESE DIA : ";
    cin>>aux;
    setDia(aux);
    cout<<"INGRESE MES : ";
    cin>>aux;
    setMes(aux);
    cout<<"INGRESE ANIO : ";
    cin>>aux;
    setAnio(aux);
}
void Fecha::Mostrar()
{
    cout<<"FECHA : "<<_d<<"/"<<_m<<"/"<<_a<<endl;
}
#endif // CLSFECHA_H_INCLUDED
