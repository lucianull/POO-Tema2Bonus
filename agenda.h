#ifndef AGENDA_H_INCLUDED
#define AGENDA_H_INCLUDED

#include <vector>
#include "abonat_skype_romania.h"
#include "abonat_skype.h"
#include "abonat_skype_extern.h"

using namespace std;

class Agenda
{
private:
    vector <Abonat_Skype *> lista_abonati;
public:
    Agenda() : lista_abonati() {}

    Agenda(const Agenda& obiect)
    {
        for(Abonat_Skype* i: obiect.lista_abonati)
        {
            Abonat_Skype *pointer = new Abonat_Skype(*i);
            this->lista_abonati.push_back(pointer);
        }
    }

    ~Agenda()
    {
        Abonat_Skype *q;
        int n = this->lista_abonati.size() - 1;
        while(this->lista_abonati.empty() == 0)
        {
            q = this->lista_abonati[n];
            this->lista_abonati.pop_back();
            delete q;
            n--;
        }
    }
    Agenda& operator=(const Agenda &obiect)
    {

        Abonat_Skype *q;
        int n = this->lista_abonati.size() - 1;
        while(this->lista_abonati.empty() == 0)
        {
            q = this->lista_abonati[n];
            this->lista_abonati.pop_back();
            delete q;
            n--;
        }

        for(Abonat_Skype* i: obiect.lista_abonati)
        {
            Abonat_Skype *pointer = new Abonat_Skype(*i);
            this->lista_abonati.push_back(pointer);
        }

        return *this;
    }
    void Adaugare_element(Abonat_Skype &obiect)
    {
        Abonat_Skype *pointer=new Abonat_Skype(obiect);
        this->lista_abonati.push_back(pointer);
    }
    void Adaugare_element_romania(int id, string nume, string nr_tel, string id_skype, string adresa_mail)
    {
        Abonat_Skype_Romania *q = new Abonat_Skype_Romania(id, nume, nr_tel, id_skype, adresa_mail);
        this->lista_abonati.push_back(q);
    }
    void Adaugare_element_extern(int id, string nume, string nr_tel, string id_skype, string tara)
    {
        Abonat_Skype_Extern *q = new Abonat_Skype_Extern(id, nume, nr_tel, id_skype, tara);
        this->lista_abonati.push_back(q);
    }
    void Eliminare_element(int index)
    {
        if(index <= this->lista_abonati.size())
        {
            std :: vector <Abonat_Skype* > :: iterator it = this->lista_abonati.begin() + index - 1;
            Abonat_Skype* q = this->lista_abonati[index - 1];
            this->lista_abonati.erase(it);
            delete q;
        }
        else
        {
            cout << "Nu exista nici un abonat cu indexul " << index << '\n';
        }
    }
    Abonat_Skype* operator[] (string nume)
    {
        for(Abonat_Skype* i: this->lista_abonati)
            if(i->getNume() == nume)
                return i;
        return NULL;
    }
    int getNrAbonatiRomania() {return Abonat_Skype_Romania::getNrAbonatiRomania();}
    int getNrAbonatiExtern() {return Abonat_Skype_Extern::getNrAbonatiExtern();}
};

#endif // AGENDA_H_INCLUDED