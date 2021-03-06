// Classe représentant un trajet simple avec sa ville de départ, sa ville d'arrivée et son moyen de transport.

#ifndef TRAJETSIMPLE_H
#define TRAJETSIMPLE_H

#include "trajet.h"
class TrajetSimple : public Trajet
{
// Attributs
    private:
    char* depart;
    char* arrivee;
    char* moyenTransport;
// Constructeurs
    public:
    explicit TrajetSimple(const char* villeDepart, const char* villeArrivee, const char* moyenTransport);
    TrajetSimple(const TrajetSimple & t);
    TrajetSimple(TrajetSimple&&) noexcept ;
// Méthodes
    void ToString() override;
    const char* GetDepart() override;
    const char* GetArrive() override;
    const char* GetMoyenTransport();
// Destructeurs
    ~TrajetSimple();
};

#endif