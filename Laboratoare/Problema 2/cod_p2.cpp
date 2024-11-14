#include <iostream>
#include <string>

class Echipament_electronic
{
  protected:
    float tensiune;
    float intensitate;
public:
    Echipament_electronic(float tensiune,float intensitate):tensiune(tensiune),intensitate(intensitate){}
};
class Telefon: private Echipament_electronic
{
    protected:
        float get_tensiune()
        {
            return this->tensiune;
        }
        float get_intensitate()
        {
            return this->intensitate;
        }
        std::string nr_tel;
    public:
        Telefon(float tensiune,float intensitate, std::string nr_tel):Echipament_electronic(tensiune,intensitate), nr_tel(nr_tel){}
        void suna(std::string nr_tel)
        {
            std::cout<<"Calling: "<< nr_tel;
            std::cout<<"\n";
        }
};
class Telefon_mobil:protected Telefon
{
  private:
    int baterie;
public:
    Telefon_mobil(float tensiune,float intensitate, std::string nr_tel, int baterie):Telefon(tensiune,intensitate,nr_tel),baterie(baterie){}
    void suna(std:: string nr_tel, int nr_min)
    {
        std::cout<<"Outgoing number: "<<Telefon::nr_tel<<"\n"; // this->nr_tel;
        Telefon::suna(nr_tel);
        for(int i=0;i<nr_min;i++)
         {
             baterie=baterie-(get_tensiune()*get_intensitate())/100;
         }
         //std::cout<<"\n";
         std::cout<<baterie<<"\n";
    }
};
 int main()
 {
     float tensiune,intensitate;
     std::string numar_tel;
     int baterie;
     std::string numar_apelat;
     int durata;
     std::cin>>tensiune>>intensitate;
     std::cin>>numar_tel;
     std::cin>>baterie;
     std::cin>>numar_apelat;
     std::cin>>durata;
     Echipament_electronic e2 (tensiune,intensitate);
     Telefon t2 (tensiune,intensitate,numar_tel);
     Telefon_mobil t3(tensiune,intensitate,numar_tel,baterie);
     
     t3.suna(numar_apelat, durata);
     
 }