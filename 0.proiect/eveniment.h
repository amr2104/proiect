#include<iostream>
#include<string>
using namespace std;
class Eveniment
{
private:
    char* nume;
    string data;
    string ora;

public:

    Eveniment()
    {
        nume = nullptr;
        data = "";
        ora = "";
    }

    Eveniment(const char* nume, string data, string ora) :Eveniment()
    {
        if (nume != nullptr)
        {
            this->nume = new char[strlen(nume) + 1];
            strcpy(this->nume, nume);
        }
        if (data != "")
        {
            this->data = data;
        }
        if (ora != "")
        {
            this->ora = ora;
        }
    }

    ~Eveniment()
    {
        if (this->nume != nullptr)
        {
            delete[] this->nume;
        }
    }

    Eveniment(const Eveniment& e)
    {
        if (e.nume != nullptr)
        {
            this->nume = new char[strlen(e.nume) + 1];
            strcpy(this->nume, e.nume);
        }
        else
            this->nume = nullptr;
        this->data = e.data;
        this->ora = e.ora;
    }

    Eveniment& operator=(const Eveniment& e)
    {
        if (this != &e)
        {
            if (this->nume != nullptr)
            {
                delete[] this->nume;
            }
            if (e.nume != nullptr)
            {
                this->nume = new char[strlen(e.nume) + 1];
                strcpy(this->nume, e.nume);
            }
            else
            {
                this->nume = nullptr;
            }
        }
        return *this;
    }

    const char* getNume() 
    {
        return nume;
    }

    string getData()
    {
        return data;
    }

    string getOra()
    {
        return ora;
    }
   
    void setNume(const char* nume)
    {
        if (nume != nullptr)
        {
            delete[] this->nume;
            this->nume = new char[strlen(nume) + 1];
            strcpy(this->nume, nume);
        }
        else cout << "Numele nu este invalid!";
    }

    void setData(string data)
    {
        if (data != "")
        {
            this->data = data;
        }
        else
            cout << "Data introdusa este invalida!";
    }

    void setOra(string ora)
    {
        if (ora != "")
        {
            this->ora = ora;
        }
        else 
            cout << "Ora introdusa este invalida!";
    }

    static bool comparaData(Eveniment e1, Eveniment e2)
    {
        return (e1.data < e2.data);
    }

    bool evenimentIdentic(Eveniment e)
    {
        return (strcmp(nume, e.nume) == 0 && data == e.data && ora == e.ora);
    }

    Eveniment operator++()
    {
        int h = stoi(ora.substr(0, 2));
        int m = stoi(ora.substr(3, 2));
        h++;
        if (h > 23)
        {
            h = 0;
            int y = stoi(data.substr(0, 4));
            int mon = stoi(data.substr(5, 2));
            int d = stoi(data.substr(8, 2));
            d++;
            if (d > nrZileLuna(mon, y))
            {
                d = 1;
                mon++;
                if (mon > 12)
                {
                    mon = 1;
                    y++;
                }
            }
            if (d < 10)
            {
                data = to_string(y) + "-";
                if (mon < 10)
                {
                    data += "0" + to_string(mon) + "-0" + to_string(d);
                }
                else
                {
                    data += to_string(mon) + "-0" + to_string(d);
                }
            }
            else
            {
                data = to_string(y) + "-";
                if (mon < 10)
                {
                    data += "0" + to_string(mon) + "-" + to_string(d);
                }
                else
                {
                    data += to_string(mon) + "-" + to_string(d);
                }
                if (h < 10)
                {
                    ora = "0" + to_string(h) + ":";
                }
                else
                {
                    ora = to_string(h) + ":";
                }
                if (m < 10)
                {
                    ora += "0" + to_string(m);
                }
                else
                {
                    ora += to_string(m);
                }
                return *this;
            }
        }
    }
    int nrZileLuna(int mon, int y)
            {
                if (mon == 2)
                {
                    if (y % 4 == 0)
                    {
                        if (y % 100 == 0)
                        {
                            if (y % 400 == 0)
                            {
                                return 29;
                            }
                            else
                            {
                                return 28;
                            }
                        }
                        else
                        {
                            return 29;
                        }
                    }
                    else
                    {
                        return 28;
                    }
                }
                else if (mon == 4 || mon == 6 || mon == 9 || mon == 11)
                {
                    return 30;
                }
                else
                {
                    return 31;
                }
            }

    Eveniment operator++()
    {
        Eveniment copie = *this;
        int h = stoi(ora.substr(0, 2));
        int m = stoi(ora.substr(3, 2));
        h++;
        if (h > 23)
        {
            h = 0;
            int y = stoi(data.substr(0, 4));
            int mon = stoi(data.substr(5, 2));
            int d = stoi(data.substr(8, 2));
            d++;
            if (d > nrZileLuna(mon, y))
            {
                d = 1;
                mon++;
                if (mon > 12)
                {
                    mon = 1;
                    y++;
                }
            }
            if (d < 10)
            {
                data = to_string(y) + "-";
                if (mon < 10)
                {
                    data += "0" + to_string(mon) + "-0" + to_string(d);
                }
                else
                {
                    data += to_string(mon) + "-0" + to_string(d);
                }
            }
            else
            {
                data = to_string(y) + "-";
                if (mon < 10)
                {
                    data += "0" + to_string(mon) + "-" + to_string(d);
                }
                else
                {
                    data += to_string(mon) + "-" + to_string(d);
                }
                if (h < 10)
                {
                    ora = "0" + to_string(h) + ":";
                }
                else
                {
                    ora = to_string(h) + ":";
                }
                if (m < 10)
                {
                    ora += "0" + to_string(m);
                }
                else
                {
                    ora += to_string(m);
                }
                return copie;
            }
        }
    }

     Eveniment operator++()
    {
        int h = stoi(ora.substr(0, 2));
        int m = stoi(ora.substr(3, 2));
        h++;
        if (h > 23)
        {
            h = 0;
            int y = stoi(data.substr(0, 4));
            int mon = stoi(data.substr(5, 2));
            int d = stoi(data.substr(8, 2));
            d++;
            if (d > nrZileLuna(mon, y))
            {
                d = 1;
                mon++;
                if (mon > 12)
                {
                    mon = 1;
                    y++;
                }
            }
            if (d < 10)
            {
                data = to_string(y) + "-";
                if (mon < 10)
                {
                    data += "0" + to_string(mon) + "-0" + to_string(d);
                }
                else
                {
                    data += to_string(mon) + "-0" + to_string(d);
                }
            }
            else
            {
                data = to_string(y) + "-";
                if (mon < 10)
                {
                    data += "0" + to_string(mon) + "-" + to_string(d);
                }
                else
                {
                    data += to_string(mon) + "-" + to_string(d);
                }
                if (h < 10)
                {
                    ora = "0" + to_string(h) + ":";
                }
                else
                {
                    ora = to_string(h) + ":";
                }
                if (m < 10)
                {
                    ora += "0" + to_string(m);
                }
                else
                {
                    ora += to_string(m);
                }
                return *this;
            }
        }
    }

     Eveniment operator--()
     {
         int h = stoi(ora.substr(0, 2));
         int m = stoi(ora.substr(3, 2));
         h--;
         if (h < 0)
         {
             h = 23;
             int y = stoi(data.substr(0, 4));
             int mon = stoi(data.substr(5, 2));
             int d = stoi(data.substr(8, 2));
             d--;
             if (d < 1)
             {
                 mon--;
                 if (mon < 1)
                 {
                     mon = 12;
                     y--;
                 }
                 d = nrZileLuna(mon, y);
             }
             if (d < 10)
             {
                 data = to_string(y) + "-";
                 if (mon < 10)
                 {
                     data += "0" + to_string(mon) + "-0" + to_string(d);
                 }
                 else
                 {
                     data += to_string(mon) + "-0" + to_string(d);
                 }
             }
             else
             {
                 data = to_string(y) + "-";
                 if (mon < 10)
                 {
                     data += "0" + to_string(mon) + "-" + to_string(d);
                 }
                 else
                 {
                     data += to_string(mon) + "-" + to_string(d);
                 }
             }
         }
         if (h < 10)
         {
             ora = "0" + to_string(h) + ":";
         }
         else
         {
             ora = to_string(h) + ":";
         }
         if (m < 10)
         {
             ora += "0" + to_string(m);
         }
         else
         {
             ora += to_string(m);
         }
         return *this;
     }

     Eveniment operator--()
     {
         Eveniment copie = *this;
         int h = stoi(ora.substr(0, 2));
         int m = stoi(ora.substr(3, 2));
         h--;
         if (h < 0)
         {
             h = 23;
             int y = stoi(data.substr(0, 4));
             int mon = stoi(data.substr(5, 2));
             int d = stoi(data.substr(8, 2));
             d--;
             if (d < 1)
             {
                 mon--;
                 if (mon < 1)
                 {
                     mon = 12;
                     y--;
                 }
                 d = nrZileLuna(mon, y);
             }
             if (d < 10)
             {
                 data = to_string(y) + "-";
                 if (mon < 10)
                 {
                     data += "0" + to_string(mon) + "-0" + to_string(d);
                 }
                 else
                 {
                     data += to_string(mon) + "-0" + to_string(d);
                 }
             }
             else
             {
                 data = to_string(y) + "-";
                 if (mon < 10)
                 {
                     data += "0" + to_string(mon) + "-" + to_string(d);
                 }
                 else
                 {
                     data += to_string(mon) + "-" + to_string(d);
                 }
             }
         }
         if (h < 10)
         {
             ora = "0" + to_string(h) + ":";
         }
         else
         {
             ora = to_string(h) + ":";
         }
         if (m < 10)
         {
             ora += "0" + to_string(m);
         }
         else
         {
             ora += to_string(m);
         }
         return copie;
     }

    friend ostream& operator<<(ostream&, Eveniment);
    friend istream& operator>>(istream& in, Eveniment& e);
};

ostream& operator<<(ostream& out, Eveniment e)
{
    out << "Nume: " << e.nume << endl;
    out << "Data: " << e.data << endl;
    out << "Ora: " << e.ora << endl;
    return out;
}

istream& operator>>(istream& in, Eveniment& e)
{
    cout << "Nume: ";
    delete[] e.nume;
    string buffer;
    in >> buffer;
    e.nume = new char[buffer.length() + 1];
    strcpy(e.nume, buffer.c_str());
    cout << "Data: ";
    in >> e.data;
    cout << "Ora: ";
    in >> e.ora;
    return in;
}


