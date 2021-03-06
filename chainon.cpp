#include "chainon.h"
#include "CouleurTTY.h"
#include <iostream>
using namespace std;

// Constructeurs
Chainon::Chainon(Trajet* t, Chainon* suivant = nullptr)
{
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au constructeur de Chainon" << CouleurTTY(RESET) << endl;
#endif
    this->suivant = suivant;
    this->trajet = t;
    t->NouvelleReference();
}

Chainon::~Chainon() {
#ifdef MAP
    cout << CouleurTTY(JAUNE) << "MAP : Appel au destructeur de Chainon" << CouleurTTY(RESET) << endl;
#endif
    if (trajet->GetNbReferences() > 1)
        trajet->EnleverReference();
    else
        delete trajet;
}

// Get Set
void Chainon::SetSuivant(Chainon *c) {
    this->suivant = c;
}

void Chainon::SetTrajet(Trajet *t) {
    this->trajet = t;
}

Chainon* Chainon::GetSuivant() {
    return this->suivant;
}

Trajet* Chainon::GetTrajet() {
    return this->trajet;
}

// Méthodes
void Chainon::ToString() {
    cout << "Chainon : ";
    if(this->trajet == nullptr)
    {
        cout << "vide" << endl;
        return;
    }
    cout << endl;
    this->trajet->ToString();
    if(this->suivant == nullptr)
    {
        cout << "chainon suivant inexistant" << endl;
        return;
    }
    cout << "chainon suivant défini" << endl;
}