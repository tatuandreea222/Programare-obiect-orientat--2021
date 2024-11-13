#include <iostream>
#include <string>
 
class Echipa{
    private:
        std::string nume;
        int win,draw,lose;
    public:
        Echipa(std::string nume, int win, int draw, int lose){
            this->nume = nume;
            this->win = win;
            this->draw = draw;
            this->lose = lose;
        }
        void display(){
            std::cout << nume << " " << win << " " << draw << " " << lose << std::endl;
        }
        std::string get_nume(){
            return nume;
        }
        int get_win(){
            return win;
        }
        int get_draw(){
            return draw;
        }
        int get_lose(){
            return lose;
        }
        void set_win(int q){
            win=q;
        }
        void set_draw(int q){
            draw=q;
        }
        void set_lose(int q){
            lose=q;
        }
        int get_games(){
            return win+draw+lose;
        }
        int get_pct(){
            return 3*win + draw;
        }
};
 
class Liga{
    private:
        Echipa** v;
        int n;
    public:
        Liga():v(nullptr), n(0){}
        void add_team(Echipa z){
            if(v == nullptr){
                v = new Echipa*[1];
                *v = new Echipa(z);
                n++;
            }
            else{
                Echipa** vnou;
                vnou = new Echipa*[n+1];
                for(int i = 0; i < n; i++)
                    vnou[i] = v[i];
                vnou[n] = new Echipa(z);
                v = vnou;
                n++;
            }
        }
        void c1(){
            for(int i = 0; i < n; i++)
                v[i]->display();
        }
        void c2(){
            for(int i = 0; i < n; i++)
                std::cout << v[i]->get_nume() << " " << v[i]->get_pct() << std::endl;
        }
        void c3(){
            int x, s1, s2;
            std::string t1, t2;
            std::cin >> x;
            for(int j = 0; j < x; j++){
              std::cin.ignore();
              std::cin >> t1 >> s1 >> s2 >> t2;
              for(int i = 0; i < n; i++){
                if(v[i]->get_nume() == t1){
                    if(s1 > s2)
                        v[i]->set_win(v[i]->get_win()+1);
                    else if(s1 == s2)
                        v[i]->set_draw(v[i]->get_draw()+1);
                    else v[i]->set_lose(v[i]->get_lose()+1);
                }
                else if(v[i]->get_nume() == t2){
                    if(s1 < s2)
                        v[i]->set_win(v[i]->get_win()+1);
                    else if(s1 == s2)
                        v[i]->set_draw(v[i]->get_draw()+1);
                    else v[i]->set_lose(v[i]->get_lose()+1);
                }
            }
            }
            int afis;
            std::cin >> afis;
 
            if(afis == 1){
                for(int i = 0; i < n; i++)
                    v[i]->display();
            }
            else if(afis == 2){
                for(int i = 0; i < n; i++)
                    std::cout << v[i]->get_nume() << " " << v[i]->get_pct() << std::endl;
            }
        }
        void c4(){
            int g = 0, w = 0, p = 0;
            std::string castig;
            for(int i = 0; i < n; i++){
                if(p < v[i]->get_pct())
                    {castig = v[i]->get_nume(); g = v[i]->get_games(); w = v[i]->get_win(); p = v[i]->get_pct();}
                else if(p == v[i]->get_pct() && w < v[i]->get_win())
                    {castig = v[i]->get_nume(); g = v[i]->get_games(); w = v[i]->get_win(); p = v[i]->get_pct();}
                else if (p == v[i]->get_pct() && w == v[i]->get_win() && g >= v[i]->get_games())
                    {castig = v[i]->get_nume(); g = v[i]->get_games(); w = v[i]->get_win(); p = v[i]->get_pct();}
            }
            std::cout << "Locul 1: " <<  castig << std::endl;
        }
        void c5(int nr){
            int g = (nr-1)*2;
            int p = 0, j = 0;
            bool ok = 1;
            for(int i = 0; i < n; i++)
                if(p <= v[i]->get_pct())
                    j = i, p = v[i]->get_pct();
            for(int i = 0; i < n; i++)
                if(i != j){
                    if(p <= v[i]->get_pct()+3*(g-v[i]->get_games()))
                        ok = 0;
                }
            if(ok == 1)
                std::cout << v[j]->get_nume() << " a castigat!" << std::endl;
            else std::cout << "Nu exista castigator!" << std::endl;
        }
};
 
int main(){
    Liga A;
 
    std::string nume;
    int nr, win, draw, lose;
    std::cin >> nr;
    for(int i = 0; i < nr; i++){
        std::cin.ignore();
        std::cin >> nume >> win >> draw >> lose;
        Echipa z(nume,win,draw,lose);
        A.add_team(z);
    }
    int t;
    std::cin >> t;
    if(t == 1) A.c1();
    if(t == 2) A.c2();
    if(t == 3) A.c3();
    if(t == 4) A.c4();
    if(t == 5) A.c5(nr);
    return 0;
}