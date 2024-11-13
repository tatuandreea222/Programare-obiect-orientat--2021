#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
class Student
{
private:
    std::string nume;
    int nr_note;
    int note[10];
public:
    Student (std::string nume, int nr_note, int note[10]):nume(nume), nr_note(nr_note)
    {
        for(int i=0;i<nr_note;i++)
        {
            this->note[i]=note[i];
        }
    }
    void afisare2()
    {
        std::cout<<nume<<"\n";
    }
    bool operator<(const Student &rhs)
    {
        if(this->nume<rhs.nume)
        {
            return true;
            
        }
        else
        {
            return false;
        }
    }
    float medie()
    {
        float s=0;
        for(int i=0;i<nr_note;i++)
        {
            s+=note[i];
        }
        return s/nr_note;
    }
};
bool functie_comparatie(Student lhs, Student rhs)
{
    if(lhs.medie()<rhs.medie())
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::string temp;
    std::string nume;
    int n;
    int note[20];
    std::vector<Student>vec_student;
    while(1)
    {
        std::cin>>nume;
        if(nume=="STOP")
        {
            break;
        }
        else
        {
            std::cin>>n;
        for(int i=0;i<n;i++)
        {
            std::cin>>note[i];
        }
        Student s(nume,n,note); //note<=>&note[0]
        vec_student.push_back(s);
        }
    }
    int comanda;
    std::cin>>comanda;
    switch(comanda)
    {
        case 1:
        {
            std::sort(vec_student.begin(),vec_student.end());
            for(Student s_i:vec_student)
            {
                s_i.afisare2();
            }
            break;
        }
        case 2:
        {
            std::sort(vec_student.begin(),vec_student.end(), functie_comparatie);
            for(Student s_i:vec_student)
            {
                s_i.afisare2();
            }
            break;
        }
    }
    return 0;
}