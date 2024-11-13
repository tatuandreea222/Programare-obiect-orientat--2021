#include <iostream>
#include <string>

class Magazin
{
private:
    std::string denumire_produs;
    int pret;
    int stoc;
public:
    // Magazin(std::string denumire_produs="", int pret=0,int stoc=0):
    // denumire_produs(denumire_produs),pret(pret),stoc(stoc){}
    void set_denumire_produs(std::string denumire_produs)
    {
        this->denumire_produs=denumire_produs;
    }
    void set_pret(int pret)
    {
        this->pret=pret;
    }
    void set_stoc(int stoc)
    {
        this->stoc=stoc;
    }
    std::string get_denumire_produs()
    {
        return this-> denumire_produs;
    }
    int get_pret()
    {
        return this->pret;
    }
    int get_stoc()
    {
        return this->stoc;
    }
};

class Produs
{
private:
    Magazin produse[10];
    int nr_produse;
public:
    Produs (int nr_produse=0):nr_produse(nr_produse){}
    void set_nr_produse(int nr_produse)
    {
        this->nr_produse=nr_produse;
    }
    int get_nr_produse()
    {
        return this->nr_produse;
    }
    void set_denumire_produs(std::string denumire_produs,int index)
    {
        this->produse[index].set_denumire_produs(denumire_produs);
    }
    std::string get_denumire_produs(int index)
    {
        return this->produse[index].get_denumire_produs();
    }
    void set_pret(int pret, int index)
    {
        this->produse[index].set_pret(pret);
    }
    int get_pret(int index)
    {
        return this->produse[index].get_pret();
    }
    void set_stoc(int stoc, int index)
    {
        this->produse[index].set_stoc(stoc);
    }
    int get_stoc(int index)
    {
        return this->produse[index].get_stoc();
    }
};

class Cos_cumparaturi
{
private:
    Magazin cosul[10];
    int nr_prod;
public:
    void set_nr_prod(int nr_prod)
    {
        this->nr_prod=nr_prod;
    }
     int get_nr_prod()
    {
        return this->nr_prod;
    }
    void set_denumire_produs(std::string denumire_produs,int index)
    {
        this->cosul[index].set_denumire_produs(denumire_produs);
    }
    std::string get_denumire_produs(int index)
    {
        return this->cosul[index].get_denumire_produs();
    }
    void set_pret(int pret, int index)
    {
        this->cosul[index].set_pret(pret);
    }
    int get_pret(int index)
    {
        return this->cosul[index].get_pret();
    }
    void set_stoc(int stoc, int index)
    {
        this->cosul[index].set_stoc(stoc);
    }
    int get_stoc(int index)
    {
        return this->cosul[index].get_stoc();
    }
};

class Reducere
{
    
};
void lipire(std::string nume, std::string veriff)
{
    
}
int main()
{
    Produs p;
    std::string nume_produs="da";
    int pret;
    int stoc;
    int comanda;
    int i=0;
   // std::string verif="da";
    // while(verif!="STOP")
    while(1)
    {
        std::getline(std::cin,nume_produs);
        if (nume_produs == "STOP"){
            break;
        }
        else {
            std::cin>>pret;
            std::cin>>stoc;
            p.set_denumire_produs(nume_produs,i);
            p.set_pret(pret,i);
            p.set_stoc(stoc,i);
            // std::cin>>verif;
            std::cin.ignore();
            i++;
        }
    }
    p.set_nr_produse(i);
    std::cin>>comanda;
  
switch(comanda)
   {
       case 1:
       {
           for(int i=0;i<p.get_nr_produse();i++)
           {
               if(p.get_stoc(i)!=0)
               {
                   std::cout<<p.get_denumire_produs(i)<<"\n";
                   std::cout<<p.get_pret(i)<<"\n";
                   std::cout<<p.get_stoc(i)<<"\n";
               }
           }
           break;
       }
       case 2:
       {
           int i=0;
           int suma=0;
           Cos_cumparaturi c;
           while(1)
          {
            std::getline(std::cin,nume_produs);
            if (nume_produs == "STOP"){
                 break;
                 }
            else {
                std::cin>>stoc;
                c.set_denumire_produs(nume_produs,i);
                c.set_stoc(stoc,i);
            // std::cin>>verif;
                std::cin.ignore();
                i++;
            }
          }
           c.set_nr_prod(i);
           for(i=0;i<c.get_nr_prod();i++)
           {
               for(int k=0;k<p.get_nr_produse();k++)
               {
                   if(c.get_denumire_produs(i)==p.get_denumire_produs(k))
                    {
                         if(c.get_stoc(i)>p.get_stoc(k))
                         {
                            std::cout<<"Produsul";
                            std::cout<<p.get_denumire_produs(k)<<" mai are doar";
                            std::cout<<p.get_stoc(k)<<"bucati in stoc";
                         }
                    }
                    else
                    {
                       suma=suma+c.get_stoc(i)*p.get_pret(k);
                    }
                }
            }
            std::cout<<"Total de plata"<<"\n";
            std::cout<<suma;
            break;
        }
    }
}