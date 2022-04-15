#ifndef ABONAT_H_INCLUDED
#define ABONAT_H_INCLUDED

#include "persoana.h"

using namespace std;

class Abonat : public Persoana
{
protected:
    string nr_telefon;
public:
    Abonat(): Persoana(), nr_telefon("") {}
    Abonat(int id, string nume, string nr_telefon): Persoana(id, nume), nr_telefon(nr_telefon) {}
    Abonat(const Abonat& abonat)
    {
        this->id = abonat.id;
        this->nume = abonat.nume;
        this->nr_telefon = abonat.nr_telefon;
    }
    virtual ~Abonat() {}
    void setNrTelefon(string nr_telefon) {this->nr_telefon = nr_telefon;}
    string getNrTelefon() {return nr_telefon;}
    friend istream& operator>> (istream&, Abonat&);
    friend ostream& operator<< (ostream&, const Abonat&);
    Abonat& operator=(const Abonat &subscriber)
    {
        this->id=subscriber.id;
        this->nume=subscriber.nume;
        this->nr_telefon=subscriber.nr_telefon;
        return *this;
    }
};

istream& operator>> (istream& in, Abonat& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon;
    return in;
}

ostream& operator<< (ostream& out, const Abonat& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon;
    return out;
}

#endif // ABONAT_H_INCLUDED