#ifndef PERSOANA_H_INCLUDED
#define PERSOANA_H_INCLUDED

#include <string>
#include <iostream>
#include <fstream>

using namespace std;

class Persoana
{
protected:
    int id;
    string nume;
public:
    Persoana(): id(0), nume("") {}
    Persoana(int id, string nume): id(id), nume(nume) {}

    Persoana(const Persoana& persoana)
    {
        this->id = persoana.id;
        this->nume = persoana.nume;
    }

    virtual ~Persoana() {}

    void setId(int x) {this->id = id;}
    void setNume(string nume) {this->nume = nume;}
    int getId() {return id;}

    string getNume() {return nume;}

    friend istream& operator>> (istream&, Persoana&);
    friend ostream& operator<< (ostream&, const Persoana&);

    Persoana& operator=(const Persoana &person)
    {
        this->id=person.id;
        this->nume=person.nume;
        return *this;
    }
};

istream& operator>> (istream& in, Persoana& persoana)
{
    in >> persoana.id >> persoana.nume;
    return in;
}

ostream& operator<< (ostream& out, const Persoana& persoana)
{
    out << persoana.id << ' ' << persoana.nume;
    return out;
}

#endif //PERSOANA_H_INCLUDED