#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iomanip>

class Angajat
{
private:
    std::string nume;
    std::string departament;
    std::string tip_angajat;
public:
    virtual void afisare(){}
    Angajat(std::string nume,std::string departament,std::string tip_angajat)
    {
        this->nume=nume;
        this->departament=departament;
        this->tip_angajat=tip_angajat;
    }
    std::string get_tip_angajat()
    {
        return this->tip_angajat;
    }
    std::string get_departament()
    {
        return this->departament;
    }
    std::string get_nume()
    {
        return this->nume;
    }
    virtual float rentabilitate_angajat(){return 0;}
    virtual float salariu_brut(){return 0;}
    virtual float salariu_brut_IT(){return 0;}
    virtual int concediu(){return 0;}
};

class Salariat: public Angajat
{
private:
    int norma;
    int vechime;
    int salariu_net;
public:
    Salariat(std::string nume,std::string departament,std::string tip_angajat, int norma, int vechime,int salariu_net):Angajat(nume,departament, tip_angajat), norma(norma),vechime(vechime),salariu_net(salariu_net){}
    void afisare()
    {
        std::cout<<get_nume()<<" "<<norma<<" "<<vechime<<" "<<salariu_net<<std::endl;
    }
    float salariu_brut()
    {
        float salariu_brut=0;
        salariu_brut=salariu_net*12/0.55;
        return salariu_brut;
    }
    float salariu_brut_IT()
    {
        float salariu_brut_IT=0;
        salariu_brut_IT=salariu_net*12/0.65;
        return salariu_brut_IT;
    }
    int concediu()
    {
        int concediu=0;
        concediu=vechime/3;
        return concediu;
    }
    float rentabilitate_angajat()
    {
        float rentabilitate_angajat=0;
        if(get_departament()=="IT")
        {
            rentabilitate_angajat=norma*(250-concediu())/salariu_brut_IT();
        }
        if(get_departament()!="IT")
        {
            rentabilitate_angajat=norma*(250-concediu())/salariu_brut();
        }
        return rentabilitate_angajat;
    }
};

class Colaborator:public Angajat
{
private:
    float onorariu;
    float nr_prestari_anuale;
public:
    Colaborator(std::string nume,std::string departament,std::string tip_angajat, float onorariu, float nr_prestari_anuale):Angajat(nume,departament, tip_angajat), onorariu(onorariu),nr_prestari_anuale(nr_prestari_anuale){}
    void afisare()
    {
        std::cout<<get_nume()<<" "<<onorariu<<" "<<nr_prestari_anuale<<std::endl;
    }
    float salariu_brut()
    {
        float salariu_brut=0;
        salariu_brut=onorariu*nr_prestari_anuale/0.55;
        return salariu_brut;
    }
    float salariu_brut_IT()
    {
        float salariu_brut_IT=0;
        salariu_brut_IT=onorariu*nr_prestari_anuale/0.65;
        return salariu_brut_IT;
    }
};
int main()
{
    int n;
    std::cin>>n;
    std::string nume;
    std::string departament;
    std::string tip_angajat;
    int norm, vechim,sal_net;
    int onorariul, prestari_anuale;
    // std::vector<Angajat> vec_angajat;
    std::vector<Angajat*> vec_angajat;
    for(int i=0;i<n;i++)
    {
        std::cin>>tip_angajat;
        std::cin>>nume;
        std::cin>>departament;
        if(tip_angajat=="salariat")
        {
            std::cin>>norm;
            std::cin>>vechim;
            std::cin>>sal_net;
            // Salariat a(nume,departament,tip_angajat,norm,vechim,sal_net);
            Salariat* a = new Salariat(nume,departament,tip_angajat,norm,vechim,sal_net);
            vec_angajat.push_back(a);
        }
        if(tip_angajat=="colaborator")
        {
            std::cin>>onorariul;
            std::cin>>prestari_anuale;
            // Colaborator c(nume,departament,tip_angajat,onorariul,prestari_anuale);
            Colaborator* c = new Colaborator(nume,departament,tip_angajat,onorariul,prestari_anuale);
            vec_angajat.push_back(c);
        }
    }
    int comanda;
    std::cin>>comanda;
    switch(comanda)
    {
        case 1:
        {
            std::string departament2;
            std::cin>>departament2;
            // for(Angajat a_i:vec_angajat)
            for(Angajat* a_i:vec_angajat)
            {
                // if(departament2==a_i.get_departament())
                if(departament2==a_i->get_departament())
                {
                    // a_i.afisare();
                    a_i->afisare();
                }
                
            }
            break;
        }
        case 2:
        {
            std::string nume2;
            std::cin>>nume2;
            int sal_brut;
            for(Angajat* a_i:vec_angajat)
            {
                if(nume2==a_i->get_nume())
                {
                    if(a_i->get_departament()=="IT")
                    {
                        sal_brut=a_i->salariu_brut_IT();
                        std::setprecision(2);
                        std::cout<<sal_brut;
                    }
                    if(a_i->get_departament()!="IT")
                    {
                        sal_brut=a_i->salariu_brut();
                        std::setprecision(2);
                        std::cout<<sal_brut;
                    }
                }
            }
            break;
        }
        case 3:
        {
            int poz=0;
            int i,j;
            int rentabilitate_max=0;
            int verif=0; // contor pt rentabilitate.
            // for(Angajat* a_i:vec_angajat)
            // {
            //     if(a_i->get_tip_angajat()=="salariat")
            //     {
            //         rentabilitate_max=a_i->rentabilitate_angajat();
            //         break;
            //     }
            // }
            // for(Angajat* a_i:vec_angajat)
            for(i=0;i<vec_angajat.size();i++)
            {
                if(vec_angajat[i]->get_tip_angajat()=="salariat")
                {
                    rentabilitate_max=vec_angajat[i]->rentabilitate_angajat();
                    j=i;
                    break;
                }
            }
            for( i=j+1; i<vec_angajat.size(); i++)
            {
                // if(a_i->get_tip_angajat()=="salariat")
                if(vec_angajat[i]->get_tip_angajat()=="salariat")
                {
                    // verif=a_i->rentabilitate_angajat();
                    verif=vec_angajat[i]->rentabilitate_angajat();
                    if(rentabilitate_max<verif)
                    {
                        rentabilitate_max=verif;
                        // poz=
                        poz=i;
                    }
                }
            }
            // std::cout<< a_poz->get_nume();
            std::cout<< vec_angajat[poz+4]->get_nume();
            break;
        }
        case 4:
        {
            std::string departament3;
            std::cin>>departament3;
            int sal_mediu=0;
            for(Angajat* a_i:vec_angajat)
            {
                if(departament3==a_i->get_departament())
                {
                    sal_mediu=sal_mediu+a_i->salariu_brut();
                }
            }
            std::setprecision(2);
            std::cout<<sal_mediu/2;
            break;
        }
    }  
    return 0;
}