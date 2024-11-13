#include <iostream>
class Carte
{
  private:
    std::string titlu;
    std::string nume_autor;
    int an_lansare;
    int nr_pagini;
    int pret;
public:
    Carte(std::string titlu="",std::string nume_autor="",int an_lansare=0,int nr_pagini=0,int pret=0)
    {
        this->titlu=titlu;
        this->nume_autor=nume_autor;
        this->an_lansare=an_lansare;
        this->nr_pagini=nr_pagini;
        this->pret=pret;
    }
    std::string get_titlu()
    {
        return this-> titlu;
    }
    std::string get_nume_autor()
    {
        return this->nume_autor;
    }
    int get_an_lansare()
    {
        return this->an_lansare;
    }
    int get_nr_pagini()
    {
        return this->nr_pagini;
    }
    int get_pret()
    {
        return this->pret;
    }
    void display()
    {
        std::cout<< this->titlu<<"\n";
        std::cout<< this->nume_autor<<"\n";
        std::cout<< this->an_lansare<<"\n";
        std::cout<<this->nr_pagini<<"\n";
        std::cout<<this->pret<<"\n";
    }
};

int main()
{
    int nrcarti, comanda, i;
    std::string titlu;
    std::string nume_autor;
    int an_lansare;
    int nr_pagini;
    int pret;
    std::cin>>nrcarti;
    Carte *c[nrcarti];
    for(i=0;i<nrcarti;i++)
    {
        std::getline(std::cin,titlu);
        std::getline(std::cin,titlu);
        std::getline(std::cin,nume_autor);
        std::cin>>an_lansare;
        std::cin>>nr_pagini;
        std::cin>>pret;
        c[i]=new Carte(titlu,nume_autor,an_lansare,nr_pagini,pret);
    }
    std::cin>>comanda;
    switch(comanda)
    {
        case 1:
        {
            std::string t_autor;
            std::getline(std::cin,t_autor);
            std::getline(std::cin,t_autor);
            int verif=0;
            for(i=0;i<nrcarti;i++)
            {
                if(t_autor==c[i]->get_nume_autor() && verif==0)
                {
                    std::cout<<c[i]->get_nume_autor()<<"\n";
                    verif=1;
                }
                if(t_autor==c[i]->get_nume_autor())
                {
                    std::cout<<c[i]->get_titlu()<<", ";
                }
            }
            break;
        }
        case 2:
        {
            int minim=c[0]->get_nr_pagini(),nr=0;
            for(i=1;i<nrcarti;i++)
            {
                if(c[i]->get_nr_pagini()<minim)
                {
                    minim=c[i]->get_nr_pagini();
                    nr=i;
                }
            }
            c[nr]->display();
            break;
        }
        case 3:
        {
            int recent=c[0]->get_an_lansare(),nr=0;
            for(i=1;i<nrcarti;i++)
            {
                if(c[i]->get_nr_pagini()>recent)
                {
                    recent=c[i]->get_nr_pagini();
                    nr=i;
                }
            }
            c[nr]->display();
            break;
        }
    }
    
    return 0;
}