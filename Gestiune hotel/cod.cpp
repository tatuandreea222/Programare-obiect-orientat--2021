#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <algorithm>

class Camera{
private:
    int nr_camera;
    int nr_persoane_max;
    int nr_persoane_cazate;
    std::string tip;
    float pret;
public:
    Camera(int nr_camera, std::string tip, int nr_persoane_cazate, float pret):
    nr_camera(nr_camera), tip(tip), nr_persoane_cazate(nr_persoane_cazate), pret(pret){
        if(tip == "single"){
            nr_persoane_max = 1;
        }
        else if (tip == "double"){
            nr_persoane_max = 2;
        }
        else if (tip == "twin"){
            nr_persoane_max = 2;
        }
        else{
            nr_persoane_max = 3;
        }
    }
    
    void afisare(){
        std::cout << nr_camera << " " << tip << " " << nr_persoane_cazate << " " << pret << "\n";
    }
    
    bool este_ocupata(){
        return (nr_persoane_cazate > 0);
    }
    
    int get_nr_persoane_max(){
        return this->nr_persoane_max;
    }
    
    int get_pret(){
        return this->pret;
    }
};

bool func(Camera c1, Camera c2){
    if (c1.get_nr_persoane_max() == c2.get_nr_persoane_max()){
        return (c1.get_pret() < c2.get_pret());
    }
    else {
        return (c1.get_nr_persoane_max() < c2.get_nr_persoane_max());
    }
}

class Hotel{
private:
    std::vector<Camera> vec;
public:
    void introducere_camera(Camera &c){
        vec.push_back(c);
    }
    
    void afisare_camere(){
        for (auto c:vec){
            c.afisare();
        }
    }
    
    float grad_ocupare(){
        int num_camere_ocupate=0;
        for (auto c:vec){
            num_camere_ocupate += c.este_ocupata();
        }
        return (float(num_camere_ocupate) / vec.size() * 100);
    }
    
    int capacitate_ramasa(){
        int capacitate_ramasa = 0;
        for (auto c:vec){
            if (!(c.este_ocupata())){
                capacitate_ramasa += c.get_nr_persoane_max();
            }
        }
        return capacitate_ramasa;
    }
    
    void sortare(){
        std::sort(vec.begin(), vec.end(), func);
    }
};




int main(){
    int comanda;
    int nr_camera;
    int nr_persoane_max;
    int nr_persoane_cazate;
    std::string tip;
    float pret;
    
    Hotel hotel;
    
    do {
        std::cin >> comanda;
        switch (comanda) {
            case 1: {
                std::cin >> nr_camera;
                std::cin >> tip;
                std::cin >> nr_persoane_cazate;
                std::cin >> pret;
                Camera c(nr_camera, tip, nr_persoane_cazate, pret);
                hotel.introducere_camera(c);
                break;
            }
            case 2: {
                hotel.afisare_camere();
                break;
            }
            case 3: {
                std::cout << std::fixed << std::setprecision(2) << hotel.grad_ocupare() << std::endl;
                break;
            }
            case 4: {
                std::cout << hotel.capacitate_ramasa() << std::endl;
                break;
            }
            case 5: {
                hotel.sortare();
                hotel.afisare_camere();
                break;
            }
        }
    } while(comanda!=-1);
    
    
    
}



