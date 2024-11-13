#include<iostream>
#include<string>
#include<algorithm>
#include<vector>


class Angajat{
    protected:
    std::string nume, functie;
    float salariu_baza, procent_taxe_salariu;
    
    public:
    Angajat(std::string nume, float salariu_baza, std::string functie):
    nume(nume), salariu_baza(salariu_baza), functie(functie){
        this->procent_taxe_salariu=40;}
    
   
    std::string get_nume(){
        return this->nume;
    }
    
    float get_salariu(){
        return this->salariu_baza;
    }
    
    virtual std::string get_functie()=0;
        
    
    float get_procent_taxe_salariu(){
        return this->procent_taxe_salariu;
    }
    
    virtual int  get_vechime(){ return 0; }
   
    virtual float get_procentdeduceresalariu(){ return 0;}
    virtual float get_bonusvechime(){return 0;}
    
};

class Analist: public Angajat{
    public:
    Analist(std::string nume, float salariu_baza, std::string functie):
    Angajat(nume, salariu_baza, functie){}
    
    std::string get_functie(){
        return this->functie;
    }
};

class Programator: public Analist{
    protected:
    float procent_deducere_salariu_it;
    
    public:
    Programator(std::string nume, float salariu_baza, std::string functie):
    Analist(nume, salariu_baza, functie){
        this->procent_deducere_salariu_it=10;}
    
    float get_procentdeduceresalariu(){
        return this->procent_deducere_salariu_it;
    }
    
     std::string get_functie(){
        return this->functie;
    }
};

class LiderEchipaProgramare: public Programator{
    private:
    float bonus_vechime_functie;
    int vechime_functie=0;
    
    public:
    LiderEchipaProgramare(std::string nume, float salariu_baza, std::string functie, int vechime_functie):
    Programator(nume, salariu_baza,functie),vechime_functie(vechime_functie){}
    
    float get_bonusvechime(){
        return this->bonus_vechime_functie;
    }
    
    int get_vechime(){
        return this->vechime_functie;
    }
     std::string get_functie(){
        return this->functie;
    }
};


class FirmaProgramare{
    private:
    std::vector<Angajat*> vector; //vector de clase
    
    public:
    void adauga(Angajat *a){
        vector.push_back(a);
    }
    
    void afisare(){
        for(int i=0; i<vector.size(); ++i){
            std::cout<<vector[i]->get_nume()<<"\n"<<vector[i]->get_functie()<<"\n";
        }
    }
    
    void salariu(){
        float net, brut;
        for(int i=0; i<vector.size(); ++i)
        {
            brut=(vector[i]->get_salariu() + vector[i]->get_bonusvechime() *vector[i]->get_vechime());
            net=((vector[i]->get_salariu()  + vector[i]->get_bonusvechime() * vector[i]->get_vechime())*(100 - vector[i]->get_procent_taxe_salariu() + vector[i]-> get_procentdeduceresalariu()))/100;
            
            std::cout<<vector[i]->get_nume()<<"\n";
            std::cout<<"Salariu brut: "<<brut<<"\n";
            std::cout<<"Salariu Net: "<<net<<"\n";
        }
    }
};

int main(){
     int nr,vechime, test;
     std::string nume, rol;
     float salariu;
     
     FirmaProgramare vector;
     
     std::cin>>nr;
     for(int i=0; i<nr; ++i){
         std::cin.ignore();
         std::getline(std::cin, nume);
         std::getline(std::cin, rol);
         std::cin>>salariu;
         
         if(rol == "Analist"){
             vector.adauga(new Analist(nume, salariu, rol));
         }
         else
         if(rol== "Programator"){
             vector.adauga(new Programator(nume, salariu, rol));
         }
         else
         if(rol == "LiderEchipaProgramare"){
             std::cin>>vechime;
             
             vector.adauga(new LiderEchipaProgramare(nume, salariu, rol, vechime));
         }
     }
     std::cin>>test;
     
     if(test==1){
         vector.afisare();
     }
     
     if(test==2){
         vector.salariu();
     }
}