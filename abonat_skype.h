#ifndef ABONAT_SKYPE_H_INCLUDED
#define ABONAT_SKYPE_H_INCLUDED

#include "abonat.h"

using namespace std;

class Abonat_Skype: public Abonat
{
protected:
    string id_skype;
public:
    Abonat_Skype():Abonat(), id_skype("") {}
    Abonat_Skype(int id, string nume, string nr_telefon, string id_skype): Abonat(id, nume, nr_telefon), id_skype(id_skype) {}
    Abonat_Skype(const Abonat_Skype& abonat)
    {
        this->id = abonat.id;
        this->nume = abonat.nume;
        this->nr_telefon = abonat.nr_telefon;
        this->id_skype = abonat.id_skype;
    }
    virtual ~Abonat_Skype() {}
    void setIdSkype(string id_skype) {this->id_skype = id_skype;}
    string getIdSkype() {return id_skype;}
    friend istream& operator>> (istream&, Abonat_Skype&);
    friend ostream& operator<< (ostream&, const Abonat_Skype&);
    Abonat_Skype& operator=(const Abonat_Skype &subscriber)
    {
        this->id=subscriber.id;
        this->nume=subscriber.nume;
        this->nr_telefon=subscriber.nr_telefon;
        this->id_skype=subscriber.id_skype;
        return *this;
    }

};

istream& operator>> (istream& in, Abonat_Skype& abonat)
{
    in >> abonat.id >> abonat.nume >> abonat.nr_telefon >> abonat.id_skype;
    return in;
}

ostream& operator<< (ostream& out, const Abonat_Skype& abonat)
{
    out << abonat.id << ' ' << abonat.nume << ' ' << abonat.nr_telefon << ' ' << abonat.id_skype;
    return out;
}


#endif // ABONAT_SKYPE_H_INCLUDED