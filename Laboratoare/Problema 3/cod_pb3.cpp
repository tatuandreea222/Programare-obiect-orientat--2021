#include <iostream>
#include <cmath>

class Poligon{
public:
    virtual float aria()=0;
    virtual float perimetru()=0;
    virtual ~Poligon(){}
};
class Triunghi: public Poligon
{
private:
    float l1,l2,l3;
public:
    Triunghi(float l1, float l2, float l3):l1(l1),l2(l2),l3(l3){}
    float aria()
    {
        float p;
        p=(l1+l2+l3)/2;
        float a;
        a=sqrt(p*(p-l1)*(p-l2)*(p-l3));
        return a;
    }
    float perimetru()
    {
        return (l1+l2+l3);
    }
    ~Triunghi(){}
};

class Patrulater: public Poligon
{
private:
    float l1,l2,l3,l4;
public:
    Patrulater(float l1,float l2, float l3, float l4):l1(l1),l2(l2),l3(l3),l4(l4){}
    float perimetru()
    {
        return (l1+l2+l3+l4);
    }
    float aria()
    {
        float a;
        a=l1*l2;
        return a;
    }
    ~Patrulater(){}
};

class Dreptunghi: public Patrulater
{
private:
    float l,L;
public:
    Dreptunghi(float L, float l): Patrulater(L,l,L,l){}
    ~Dreptunghi(){}
};

class Patrat:public Dreptunghi
{
private:
    float l;
public:
    Patrat(float l):Dreptunghi(l,l){}
    ~Patrat(){}
};

// TODO: adaugati clasele aici

int main(){
    Poligon *p[3] = {new Triunghi(2, 3, 4), new Patrat(3), new Dreptunghi(3, 8)};
    for (int i=0; i<3; i++){
        std::cout << p[i]->aria() << " " << p[i]->perimetru() << std::endl;
        delete p[i];
    }
    return 0;
}