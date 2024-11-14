#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h>
#include <iomanip>

class MathFunction
{
protected:
    std::string function_name;
    int value;
    int max_value;
public:
    MathFunction(std::string function_name):function_name(function_name){}
    float get_value()
    {
        return this->value;
    }
    float get_max_value(float nr,float nr2)
    {
        if(nr>=nr2)
        {
            return nr;
        }
        else
        {
            return nr2;
        }
    }
    std::string get_nume_functie()
    {
        return this->function_name;
    }
    virtual void afisare(){}
    virtual void print_roots(){}
    virtual void calcul(float i){}
    virtual int get_calcul(float i,float a, float b){return 0;}
};

class Polynomial: public MathFunction
{
protected:
    float coefficients[10];
    int nr_coef;
public:
    Polynomial(std::string function_name, int nr_coef,float coefficients[10]):MathFunction(function_name), nr_coef(nr_coef)
    {
        for(int i=0;i<nr_coef;i++)
        {
            this->coefficients[i]=coefficients[i];
        }
    }
    virtual void print_roots(){}
    
    int calcul(float i,float a, float b)
    {
        float nr,nr2;
        nr=nr+coefficients[0];
        for(int j=0;j<nr_coef;j++)
        {
             nr=nr+coefficients[j]*a;
        }
        std::cout<<nr<<" ";
        for(int k=a+1;k<b+1;k++)
        {
            nr2=0;
            nr2=nr2+coefficients[0];
            for(int j=1;j<nr_coef;j++)
            {
                 nr2=nr2+coefficients[j]*k;
            }
            nr=get_max_value(nr,nr2);
        }
        return nr;
    }
  
  virtual  void afisare()
    {
        std::cout<<"Polynomial\n";
        std::cout<<"f(x) = ";
        std::cout<<coefficients[0];
        if(coefficients[1]<0 && coefficients[1]==1)
        {
            std::cout<<" - ";
            std::cout<<"x";
        }
        else if(coefficients[1]>0 && coefficients[1]==1 )
        {
            std::cout<<" + ";
            std::cout<<"x";
        }
        else if(coefficients[1]<0 && coefficients[1]!=1 &&coefficients[1]!=0)
        {
            std::cout<<" - "<<coefficients[1];
            std::cout<<"x";
        }
        else if(coefficients[1]!=0)
        {
            std::cout<<" + "<<coefficients[1];
            std::cout<<"x";
        }
       // std::cout<<coefficients[2]<<"x^2";
        for(int i=2;i<nr_coef;i++)
        {
            if(coefficients[i]<0 && (coefficients[i]==1 ||coefficients[i]==-1 ))
            {
                 std::cout<<" - ";
                 std::cout<<"x^"<<i;
            }
            else if(coefficients[i]>0 && (coefficients[i]==1||coefficients[i]==-1))
            {
                std::cout<<" + ";
                std::cout<<"x^"<<i;
            }
            else if(coefficients[i]<0 && coefficients[i]!=1 && coefficients[i]!=0)
            {
                std::cout<<" - "<<coefficients[i];
                std::cout<<"x^"<<i;
            }
            else if(coefficients[i]!=0)
            {
                std::cout<<" + "<<coefficients[i];
                std::cout<<"x^"<<i;
            }
        }
        std::cout<<"\n";
    }
};

class Quadratic: public Polynomial
{
public:
    Quadratic(std::string function_name, int nr_coef,float coefficients[10]):Polynomial(function_name,nr_coef,coefficients){}
    void print_roots()
    {
        float delta;
        float X1,X2;
        delta=sqrt(coefficients[1]*coefficients[1]-4*coefficients[0]*coefficients[2]);
        if(delta==0)
        {
            std::cout<<"X1 = X2 = ";
            X1=(-coefficients[1]+delta)/(2.0*coefficients[2]);
           // std::setw(20);
            // std::setprecision(2);
            std::cout << std::fixed << std::setprecision(2);
            // std::cout<<X1;
            std::cout<<X1 << "\n";
            //printf("%.2f",X1);
        }
        else
        {
            std::cout<<"X1 = ";
            // std::setprecision(2);
            std::cout << std::fixed << std::setprecision(2);
            std::cout<<(-coefficients[1]+delta)/(2*coefficients[2])<<"\n";
            std::cout<<"X2 = ";
            // std::setprecision(2);
            std::cout<<(-coefficients[1]-delta)/(2.0*coefficients[2])<<"\n";
        }
    }
    virtual  void afisare()
    {
        std::cout<<"Quadratic\n";
        std::cout<<"f(x) = ";
        std::cout<<coefficients[0];
        if(coefficients[1]<0 && coefficients[1]==1)
        {
            std::cout<<" - ";
            std::cout<<"x";
        }
        else if(coefficients[1]>0 && coefficients[1]==1 )
        {
            std::cout<<" + ";
            std::cout<<"x";
        }
        else if(coefficients[1]<0 && coefficients[1]!=1 &&coefficients[1]!=0)
        {
            std::cout<<" - "<<coefficients[1];
            std::cout<<"x";
        }
        else if(coefficients[1]!=0)
        {
            std::cout<<" + "<<coefficients[1];
            std::cout<<"x";
        }
      if(coefficients[2]<0 && coefficients[2]==1)
        {
            std::cout<<" - ";
            std::cout<<"x^2";
        }
        else if(coefficients[2]>0 && coefficients[2]==1)
        {
            std::cout<<" + ";
            std::cout<<"x^2";
        }
        else if(coefficients[2]<0 && coefficients[2]!=1 && coefficients[2]!=0)
        {
            std::cout<<" - "<<coefficients[2];
            std::cout<<"x^2";
        }
        else if(coefficients[2]!=0)
        {
            std::cout<<" + "<<coefficients[2];
            std::cout<<"x^2";
        }
        std::cout<<"\n";
    }
};

class Exponential:public MathFunction
{
 private:
    const float e=2.71;
    float constant;
    float exp_coeff;
public:
    Exponential(std::string function_name,float constant, float exp_coeff):MathFunction(function_name),constant(constant),exp_coeff(exp_coeff){}
    void afisare()
    {
        std::cout<<"Exponential\n";
        std::cout<<"f(x) = ";
        std::cout<<constant<<" + ";
        std::cout<<exp_coeff<<"e^x";
        std::cout<<"\n";
    }
    
};

class DiscreteFunction:public MathFunction
{
public:
    float x_values[10];
    float y_values[10];
    // std::string find_best_approximation()
    // {
        
    // }
};

int main()
{
    int nr_functii;
    float coef[10], termeni;
    float constanta,exp_coef;
    std::string nume_functie;
    std::cin>>nr_functii;
    std::vector<MathFunction*> vec_functie;
    for(int i=0;i<nr_functii;i++)
    {
        std::cin>>nume_functie;
        if(nume_functie=="Polynomial")
        {
            std::cin>>termeni;
            for(int j=0;j<termeni;j++)
            {
                std::cin>>coef[j];
            }
            MathFunction* p=new Polynomial(nume_functie,termeni,coef);
            vec_functie.push_back(p);
        }
        if(nume_functie=="Quadratic")
        {
            // for(int j=0;j<2;j++)
            for(int j=0;j<3;j++)
            {
                std::cin>>coef[j];
            }
            // MathFunction* g=new Quadratic(nume_functie,2,coef);
            MathFunction* g=new Quadratic(nume_functie,3,coef);
            vec_functie.push_back(g);
        }
        if(nume_functie=="Exponential")
        {
            std::cin>>constanta;
            std::cin>>exp_coef;
           MathFunction* e= new Exponential(nume_functie,constanta,exp_coef);
            vec_functie.push_back(e);
        }
    }
    int comanda;
    std::cin>>comanda;
    switch(comanda)
    {
        case 1:
        {
            for(MathFunction* f_i:vec_functie)
            {
                f_i->afisare();
            }
            // for(int i=0;i<nr_functii;i++)
            // {
            //     vec_functie[i]->afisare();
            // }
            break;
        }
        case 2:
        {
            for(MathFunction* f_i:vec_functie)
            {
                if(f_i->get_nume_functie()=="Quadratic")
                {
                    f_i->print_roots();
                }
            }
            break;
        }
        case 3:
        {
            float a,b;
            float nr;
            std::cin>>a>>b;
          //  nr=vec_functie[a]->get_calcul(a);
            for(float i=0;i<nr_functii;i++)
            {
                nr=vec_functie[i]->get_calcul(i,a,b);
                std::cout << std::fixed << std::setprecision(2);
                std::cout<<nr<< "\n";
            }
            // for(MathFunction* f_i:vec_functie)
            // {
            //     nr=f_i->get_calcul(i,a,b);
            //     std::cout << std::fixed << std::setprecision(2);
            //     std::cout<<nr<< "\n";
            // }
            break;
        }
    }
}