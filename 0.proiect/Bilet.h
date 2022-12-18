#include <iostream>
#include <string>
#include <random>
#include "Eveniment.h"
using namespace std;

class Bilet
{
private:
    Eveniment* eveniment; 
    int id;
    string tip; 
    int pret; 
    int rand; 
    int loc; 

public:
  
    Bilet() 
    { 
        generateID();
        eveniment = nullptr;
        tip = "";
        pret = 0;
        rand = 0;
        loc = 0;
    }

    Bilet(Eveniment* eveniment, string tip, int pret, int rand, int loc) : Bilet()
    {
        generateID();
        this->eveniment = eveniment;
        this->tip = tip;
        this->pret = pret;
        this->rand = rand;
        this->loc = loc;
    }

    Bilet(const Bilet& bilet) 
    {
        if (bilet.eveniment != nullptr)
        {
            this->eveniment = bilet.eveniment;
        }
        else
        {
            this->eveniment = nullptr;
        }
        this->tip = bilet.tip;
        this->pret = bilet.pret;
        this->rand = bilet.rand;
        this->loc = bilet.loc;
        this->id = bilet.id;
    }

    void generateID()
    {
        
        mt19937 generator(time(nullptr));
        uniform_int_distribution<int> distribution(1, 10000);
        this->id = distribution(generator);
    }

    Bilet& operator=(const Bilet& bilet)
    {
        if (this != &bilet)
        {
            eveniment = bilet.eveniment;
            tip = bilet.tip;
            pret = bilet.pret;
            rand = bilet.rand;
            loc = bilet.loc;
            id = bilet.id;
        }
        return *this;
    }

    ~Bilet()
    {
        delete[] eveniment;
    }

    Eveniment* getEveniment()
    {
            return eveniment;  
    }
    string getTip()
    {
        return tip;
    }
    int getPret()
    {
        return pret;
    }
    int getRand()
    {
        return rand;
    }
    int getLoc()
    {
        return loc;
    }
    int getID()
    {
        return id;
    }

    void setEveniment(Eveniment* eveniment)
    {
        if (eveniment != nullptr)
            this->eveniment = eveniment;
        else cout << "Evenimentul nu este valid!";
    }
    void setTip(string tip)
    {
        if (tip != "")
            this->tip = tip;
        else
            cout << "Tipul biletului nu este valid!";
    }
    void setPret(int pret)
    {
        if (pret >= 0)
            this->pret = pret;
        else cout << "Pretul nu poate sa fie negativ!";
    }
    void setRand(int rand)
    {
        if (rand >= 0)
            this->rand = rand;
        else
            cout << "Randul nu este valid!";
    }
    void setLoc(int loc)
    {
        if (loc >= 0)
            this->loc = loc;
        else cout << "Locul nu este valid!";
    }

    int pretTotal(const Bilet* bilete,int nrBilete)
    {
        int suma = 0;
        for (int i=0;i<nrBilete;i++)
        {
            suma += bilete[i].pret;
        }
        return suma;
    }

    Bilet celMaiIeftinBilet( Bilet* bilete, int nrBilete)
    {
        Bilet ieftin = bilete[0];
        for (int i = 1; i < nrBilete; i++)
        {
            if (comparaPreturi(bilete[i], ieftin))
            {
                ieftin = bilete[i];
            }
        }
        return ieftin;
    }


    bool comparaPreturi( Bilet& b1,  Bilet& b2)
    {
        return b1.getPret() < b2.getPret();
    }

    friend bool operator<(const Bilet& b1, const Bilet& b2)
    {
        return b1.pret < b2.pret;
    }

    friend ostream& operator<<(ostream&, Bilet);
    friend istream& operator>>(istream& in, Bilet& b);
};

ostream& operator<<(ostream& out, Bilet b)
{
    out << "Eveniment: " << b.eveniment << endl;
    out << "ID: " << b.id << endl;
    out << "Tip bilet: " << b.tip << endl;
    out << "Pret bilet: " << b.pret << endl;
    out << "Rand: " << b.rand << endl;
    out << "Loc: " << b.loc << endl;
    return out;
}

istream& operator>>(istream& in, Bilet& b)
{
    cout << "Eveniment: ";
    in >> *b.eveniment;
    cout << "ID: ";
    in >> b.id;
    cout << "Tip bilet: ";
    in >> b.tip;
    cout << "Pret bilet: ";
    in >> b.pret;
    cout << "Rand: ";
    in >> b.rand;
    cout << "Loc: ";
    in >> b.loc;
    return in;
}
