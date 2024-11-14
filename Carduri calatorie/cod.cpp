#include <iostream>
#include <vector>

using namespace std;

class Card_calatorie
{
protected:
    int id;
    int moment_ultima_validare;

public:
    Card_calatorie(int id) : id(id), moment_ultima_validare(0) {}

    virtual void afisare() const = 0;
    virtual void incarcare(int sold_cantitate) = 0;
    virtual void validare(int moment) = 0;
    virtual void transfer(Card_calatorie* card_destinatie, int suma) = 0;
    virtual char get_tip() const = 0;
    int get_id() const { return id; }
    int get_moment_ultima_validare() const { return moment_ultima_validare; }
    void set_moment_ultima_validare(int moment) { moment_ultima_validare = moment; }
};

class Card_autobuz : public Card_calatorie
{
private:
    int sold;

public:
    Card_autobuz(int id, int sold) : Card_calatorie(id), sold(sold) {}

    void afisare() const override
    {
        cout << get_id() << " a " << sold << " " << get_moment_ultima_validare() << endl;
    }

    void incarcare(int sold_cantitate) override
    {
        sold += sold_cantitate;
    }

    void validare(int moment) override
    {
        if (moment - get_moment_ultima_validare() <= 90)
        {
            set_moment_ultima_validare(moment);
        }
        else
        {
            if (sold >= 3)
            {
                sold -= 3;
                set_moment_ultima_validare(moment);
            }
            else
            {
                cout << "Sold insuficient" << endl;
            }
        }
    }

    void transfer(Card_calatorie* card_destinatie, int suma) override
    {
        if (get_tip() == card_destinatie->get_tip())
        {
            if (sold >= suma)
            {
                sold -= suma;
                card_destinatie->incarcare(suma);
            }
            else
            {
                cout << "Transfer nereusit" << endl;
            }
        }
        else
        {
            cout << "Transfer nereusit" << endl;
        }
    }

    char get_tip() const override
    {
        return 'a';
    }
};

class Card_metrou : public Card_calatorie
{
private:
    int numar_calatorii;

public:
    Card_metrou(int id, int numar_calatorii) : Card_calatorie(id), numar_calatorii(numar_calatorii) {}

    void afisare() const override
    {
        cout << get_id() << " m " << numar_calatorii << " " << get_moment_ultima_validare() << endl;
    }

    void incarcare(int numar_calatorii_cantitate) override
    {
        numar_calatorii += numar_calatorii_cantitate;
    }

    void validare(int moment) override
    {
        if (moment - get_moment_ultima_validare() <= 90)
        {
            set_moment_ultima_validare(moment);
        }
        else
        {
            if (numar_calatorii > 0)
            {
                numar_calatorii--;
                set_moment_ultima_validare(moment);
            }
            else
            {
                cout << "Numar calatorii insuficient" << endl;
            }
        }
    }

    void transfer(Card_calatorie* card_destinatie, int numar_calatorii_transferate) override
    {
        if (get_tip() == card_destinatie->get_tip())
        {
            if (numar_calatorii >= numar_calatorii_transferate)
            {
                numar_calatorii -= numar_calatorii_transferate;
                card_destinatie->incarcare(numar_calatorii_transferate);
            }
            else
            {
                cout << "Transfer nereusit" << endl;
            }
        }
        else
        {
            cout << "Transfer nereusit" << endl;
        }
    }

    char get_tip() const override
    {
        return 'm';
    }
};

int main()
{
    int n;
    cin >> n;

    vector<Card_calatorie*> carduri;

    for (int i = 0; i < n; i++)
    {
        char tip;
        int id, valoare;
        cin >> tip >> id >> valoare;

        if (tip == 'a')
        {
            Card_calatorie* card = new Card_autobuz(id, valoare);
            carduri.push_back(card);
        }
        else if (tip == 'm')
        {
            Card_calatorie* card = new Card_metrou(id, valoare);
            carduri.push_back(card);
        }
    }

    int comanda;
    while (cin >> comanda)
    {
        if (comanda == 1)
        {
            for (Card_calatorie* card : carduri)
            {
                card->afisare();
            }
        }
        else if (comanda == 2)
        {
            int id, cantitate;
            cin >> id >> cantitate;

            for (Card_calatorie* card : carduri)
            {
                if (card->get_id() == id)
                {
                    card->incarcare(cantitate);
                    break;
                }
            }
        }
        else if (comanda == 3)
        {
            int id, moment;
            cin >> id >> moment;

            for (Card_calatorie* card : carduri)
            {
                if (card->get_id() == id)
                {
                    card->validare(moment);
                    break;
                }
            }
        }
        else if (comanda == 4)
        {
            int id_sursa, id_destinatie, suma;
            cin >> id_sursa >> id_destinatie >> suma;

            Card_calatorie* card_sursa = nullptr;
            Card_calatorie* card_destinatie = nullptr;

            for (Card_calatorie* card : carduri)
            {
                if (card->get_id() == id_sursa)
                {
                    card_sursa = card;
                }
                else if (card->get_id() == id_destinatie)
                {
                    card_destinatie = card;
                }
            }

            if (card_sursa != nullptr && card_destinatie != nullptr)
            {
                card_sursa->transfer(card_destinatie, suma);
            }
        }
        else if (comanda == 5)
        {
            // Free allocated memory
            for (Card_calatorie* card : carduri)
            {
                delete card;
            }
            break; // Exit the program
        }
    }

    return 0;
}
