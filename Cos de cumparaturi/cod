#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
class Produs
{
private:
    std::string nume;
    std::string categorie;
    float pret;
    float greutate;
public:
    Produs () {}
    std::string get_nume()
    {
        return this->nume;
    }
    void set_nume(std::string nume)
    {
        this->nume=nume;
    }
    std::string get_categorie()
    {
        return this->categorie;
    }
    void set_categorie(std::string categorie)
    {
        this->categorie=categorie;
    }
    float get_pret()
    {
        return this->pret;
    }
    void set_pret(float pret)
    {
        this->pret=pret;
    }
    float get_greutate()
    {
        return this->greutate;
    }
    void set_greutate(float greutate)
    {
        this->greutate=greutate;
    }
};

class Cos_cumparaturi
{
    public:
    Produs produse[20];
// private:
//     Cos_cumparaturi produse[20];
// public:
//     std::string get_nume(int index)
//     {
//         return this->produse[index].get_nume();
//     }
//     void set_nume(std::string nume,int index)
//     {
//         this->produse[index].set_nume(nume);
//     }
//     std::string get_categorie(int index)
//     {
//         return this->produse[index].get_categorie();
//     }
//     void set_categorie(std::string categorie,int index)
//     {
//         this->produse[index].set_categorie(categorie);
//     }
//   float get_pret(int index)
//     {
//         return this->produse[index].get_pret();
//     }
//     void set_pret(int pret,int index)
//     {
//         this->produse[index].set_pret(pret);
//     }
//     float get_greutate(int index)
//     {
//         return this->produse[index].get_greutate();
//     }
//     void set_greutate(float greutate,int index)
//     {
//         this->produse[index].set_greutate(greutate);
//     }
};

int main()
{
    int intreg,i;
    float suma=0;
    float prag;
    float cost_aditional;
    float suma2=0;
    Cos_cumparaturi c;
    std::string nume;
    std::string categorie;
    float pret;
    float greutate;
    std::cin>>intreg;
    for(i=0;i<intreg;i++)
    {
        std::cin.ignore();
        std::getline(std::cin,nume);
        std::getline(std::cin,categorie);
        std::cin>>pret;
        std::cin>>greutate;
        c.produse[i].set_nume(nume);
        c.produse[i].set_categorie(categorie);
        c.produse[i].set_pret(pret);
        c.produse[i].set_greutate(greutate);
        
    }
    int comanda;
    std::cin>>comanda;
    switch(comanda)
    {
        case 1:
        {
            for(i=0;i<intreg;i++)
            {
                std::cout<<c.produse[i].get_nume()<<", ";
                std::cout<<c.produse[i].get_categorie()<<", ";
                std::cout<<c.produse[i].get_pret()<<" lei, ";
                std::cout<<c.produse[i].get_greutate()<<" kg\n";
            }
            break;
        }
        case 2:
        {
            std::string categorie2;
            int verif=0;
            std::cin.ignore();
            std::getline(std::cin,categorie2);
            for(i=0;i<intreg;i++)
            {
                if(categorie2==c.produse[i].get_categorie())
                {
                    std::cout<<c.produse[i].get_nume()<<", ";
                    std::cout<<c.produse[i].get_categorie()<<", ";
                    std::cout<<c.produse[i].get_pret()<<" lei, ";
                    std::cout<<c.produse[i].get_greutate()<<" kg\n";
                    verif=1;
                }
            }
             if(verif==0)
             {
                 std::cout<<"N/A\n";
             }
            break;
        }
        case 3:
        {
            int vec_ap[20],k,j;
            int i_gasit;
            int verif;
            Produs prod_copie[20];
            for(i=0;i<intreg;i++)
            {
                vec_ap[i]=1;
            }
            for(i=0;i<intreg;i++)
            {
                verif=0;
                i_gasit=0;
                for(j=0;j<k;j++)
                {
                    if(prod_copie[j].get_nume()==c.produse[i].get_nume())
                    {
                        i_gasit=j;
                        verif=1;
                        break;
                    }
                }
                if(i_gasit)
                {
                    vec_ap[i_gasit]++;
                }
                else
                {
                    prod_copie[k].set_nume(c.produse[i].get_nume());
                    prod_copie[k].set_categorie(c.produse[i].get_categorie());
                    prod_copie[k].set_pret(c.produse[i].get_pret());
                    prod_copie[k].set_greutate(c.produse[i].get_greutate());
                    k++;
                }
            }
            for(i=0;i<k;i++)
            {
                std::cout<<prod_copie[i].get_nume()<<", ";
                std::cout<<prod_copie[i].get_categorie()<<", ";
                std::cout<<prod_copie[i].get_pret()<<" lei, ";
                std::cout<<prod_copie[i].get_greutate()<<" kg, ";
                std::cout<<vec_ap[i]<<" buc\n";
            }
            break;
        }
        case 4:
        {
            
            for(i=0;i<intreg;i++)
            {
                suma=suma+c.produse[i].get_greutate();
            }
           std::cout<<std::fixed<<std::setprecision(2);
            std::cout<<suma;
            break;
        }
        case 5:
        {
            std::cin>>prag;
            std::cin>>cost_aditional;
            for(i=0;i<intreg;i++)
            {
                suma=suma+c.produse[i].get_greutate();
            }
            if(suma>prag)
            {
                prag=suma-prag;
            }
             for(i=0;i<intreg;i++)
            {
                suma2=suma2+c.produse[i].get_pret();
            }
            prag=ceil(prag);
            prag=prag*cost_aditional;
            suma2=suma2+prag;
            std::cout<<suma2;
        }
    }
    return 0;
}