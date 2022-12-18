#include <iostream>
using namespace std;


class Locatie
{
private:
    static int nrMaxLocuri;
    int nrRanduri;
    string zona;
    int nrLocuriPerRand;
    const string locatie;
    int** locuriOcupate;

public:
    Locatie() : locatie("")
    {
        nrRanduri = 0;
        zona = "";
        nrLocuriPerRand = 0;
        locuriOcupate = nullptr;
    }

    Locatie(int nrRanduri, string zona, int nrLocuriPerRand, string locatie) : locatie(locatie)
    {
        this->nrRanduri = nrRanduri;
        this->zona = zona;
        this->nrLocuriPerRand = nrLocuriPerRand;
        locuriOcupate = new int* [nrRanduri];
        for (int i = 0; i < nrRanduri; i++)
        {
            locuriOcupate[i] = new int[nrLocuriPerRand];
        }
    }

    Locatie(const Locatie& l) :locatie(l.locatie)
    {
        nrRanduri = l.nrRanduri;
        zona = l.zona;
        nrLocuriPerRand = l.nrLocuriPerRand;
        locuriOcupate = new int* [nrRanduri];
        for (int i = 0; i < nrRanduri; i++)
        {
            locuriOcupate[i] = new int[nrLocuriPerRand];
        }
        for (int i = 0; i < nrRanduri; i++)
        {
            for (int j = 0; j < nrLocuriPerRand; j++)
            {
                locuriOcupate[i][j] = l.locuriOcupate[i][j];
            }
        }
    }

    Locatie& operator=(const Locatie& l)
    {
        if (this != &l)
        {
            nrRanduri = l.nrRanduri;
            nrLocuriPerRand = l.nrLocuriPerRand;
            zona = l.zona;
            for (int i = 0; i < nrRanduri; i++)
            {
                delete[] locuriOcupate[i];
            }
            delete[] locuriOcupate;
            locuriOcupate = new int* [nrRanduri];
            for (int i = 0; i < nrRanduri; i++)
            {
                locuriOcupate[i] = new int[nrLocuriPerRand];
            }
            for (int i = 0; i < nrRanduri; i++)
            {
                for (int j = 0; j < nrLocuriPerRand; j++)
                {
                    locuriOcupate[i][j] = l.locuriOcupate[i][j];
                }
            }
        }
        return *this;
    }


    ~Locatie()
    {
        for (int i = 0; i < nrRanduri; i++)
        {
            delete[] locuriOcupate[i];
        }
        delete[] locuriOcupate;
    }

    void setNrRanduri(int nrRanduri)
    {
        if (nrRanduri > 0)
        {
            for (int i = 0; i < this->nrRanduri; i++)
            {
                delete[] locuriOcupate[i];
            }
            delete[] locuriOcupate;
            
            locuriOcupate = new int* [nrRanduri];
            for (int i = 0; i < nrRanduri; i++)
            {
                locuriOcupate[i] = new int[nrLocuriPerRand];
            }
            this->nrRanduri = nrRanduri;
        }
        else
        {
            cout << "Numarul de randuri trebuie sa fie pozitiv!" << endl;
        }
    }

    void setNrLocuriPerRand(int nrLocuriPerRand)
    {
        if (nrLocuriPerRand > 0)
        {
            for (int i = 0; i < nrRanduri; i++)
            {
                delete[] locuriOcupate[i];
            }
            delete[] locuriOcupate;
            
            locuriOcupate = new int* [nrRanduri];
            for (int i = 0; i < nrRanduri; i++)
            {
                locuriOcupate[i] = new int[nrLocuriPerRand];
            }
            this->nrLocuriPerRand = nrLocuriPerRand;
        }
        else
        {
            cout << "Numarul de locuri pe rand trebuie sa fie pozitiv!" << endl;
        }
    }

    void setZona(string zona)
    {
        if (zona != "")
        {
            this->zona = zona;
        }
        else
        {
            cout << "Zona nu poate sa fie vida!" << endl;
        }
    }

    
    int getNrRanduri() 
    {
        return nrRanduri;
    }

    string getZona()
    {
        return zona;
    }

    int getNrLocuriPerRand()
    {
        return nrLocuriPerRand;
    }

    string getLocatie()
    {
        return locatie;
    }

    int getMaxNrRanduri(Locatie l1, Locatie l2)
    {
        return (l1.nrRanduri > l2.nrRanduri ? l1.nrRanduri : l2.nrRanduri);
    }

    int getMinNrRanduri(Locatie l1, Locatie l2)
    {
        return (l1.nrRanduri < l2.nrRanduri ? l1.nrRanduri : l2.nrRanduri);
    }

    bool esteLocLiber(int rand, int loc)
    {
        if (rand >= 0 && rand < nrRanduri && loc >= 0 && loc < nrLocuriPerRand)
        {
            return locuriOcupate[rand][loc] == 0;
        }
        else
        {
            return false;
        }
    }

    void marcheazaLocOcupat(int rand, int loc)
    {
        if (rand >= 0 && rand < nrRanduri && loc >= 0 && loc < nrLocuriPerRand)
        {
            locuriOcupate[rand][loc] = 1;
        }
    }

    void marcheazaToateLocurileLibere()
    {
        for (int i = 0; i < nrRanduri; i++)
        {
            for (int j = 0; j < nrLocuriPerRand; j++)
            {
                locuriOcupate[i][j] = 0;
            }
        }
    }

    friend bool operator>(const Locatie& l1, const Locatie& l2)
    {
        int locuri1 = l1.nrRanduri * l1.nrLocuriPerRand;
        int locuri2 = l2.nrRanduri * l2.nrLocuriPerRand;
        return locuri1 > locuri2;
    }

    bool operator!()
    {
        return nrMaxLocuri != 0;
    }

    friend ostream& operator<<(ostream& out, Locatie l)
    {
        out << "Nr randuri: " << l.nrRanduri << endl;
        out << "Zona: " << l.zona << endl;
        out << "Nr locuri per rand: " << l.nrLocuriPerRand << endl;
        out << "Locatie: " << l.locatie << endl;
        out << "Locuri ocupate: " << endl;
        for (int i = 0; i < l.nrRanduri; i++)
        {
            for (int j = 0; j < l.nrLocuriPerRand; j++)
            {
                out << l.locuriOcupate[i][j] << " ";
            }
            out << endl;
        }
        return out;
    }

    friend istream& operator>>(istream& in, Locatie& l)
    {
    cout << "Nr randuri: ";
    in >> l.nrRanduri;
    cout << "Zona: ";
    in >> l.zona;
    cout << "Nr locuri per rand: ";
    in >> l.nrLocuriPerRand;
    
    l.locuriOcupate = new int* [l.nrRanduri];
    for (int i = 0; i < l.nrRanduri; i++)
    {
        l.locuriOcupate[i] = new int[l.nrLocuriPerRand];
    }
    
    cout << "Introduceti valorile pentru matricea de ocupare (0 = liber, 1 = ocupat):" << endl;
    for (int i = 0; i < l.nrRanduri; i++)
    {
        for (int j = 0; j < l.nrLocuriPerRand; j++)
        {
            cout << "Loc [" << i << "][" << j << "]: ";
            in >> l.locuriOcupate[i][j];
        }
    }
    return in;
    }

};

int Locatie::nrMaxLocuri = 100;