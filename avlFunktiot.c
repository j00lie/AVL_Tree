/*Tietorakenteet ja algoritmit kurssin harjoitustyö
Joonas Liedes */
#include "avlFunktiot.h"

int laskeKorkeus(SOLMU *ptr)
{
    if (ptr == NULL)
    {
        return 0;
    }
    return ptr->korkeus;
}
int laskeTasapaino(SOLMU *ptr)
{
    if (ptr == NULL)
        return 0;
    return laskeKorkeus(ptr->vas) - laskeKorkeus(ptr->oik);
}
int max(int a, int b)
{
    return (a > b) ? a : b; // ehtolause palauttaa a, jos ehto a>b täyttyy, muuten b
}
SOLMU *oikRot(SOLMU *juuri)
{
    SOLMU *lapsi = juuri->vas;
    SOLMU *lehti = lapsi->oik; // juuri>lapsi & lehti>lapsi

    // Tehdään oikea rotaatio
    // lapsisolmusta tulee juurisolmu
    lapsi->oik = juuri;
    juuri->vas = lehti;

    // Lasketaan uudet korkeudet
    juuri->korkeus = max(laskeKorkeus(juuri->vas), laskeKorkeus(juuri->oik)) + 1;
    lapsi->korkeus = max(laskeKorkeus(lapsi->vas), laskeKorkeus(lapsi->oik)) + 1;

    return lapsi;
}

SOLMU *vasRot(SOLMU *juuri)
{
    SOLMU *lapsi = juuri->oik;
    SOLMU *lehti = lapsi->vas; // juuri<lapsi & lehti<lapsi

    // Vasen rotaatio
    // lapsesta juuri ja vastaavas
    lapsi->vas = juuri;
    juuri->oik = lehti;

    // lasketaan uudet korkeudet
    juuri->korkeus = max(laskeKorkeus(juuri->vas), laskeKorkeus(juuri->oik)) + 1;
    lapsi->korkeus = max(laskeKorkeus(lapsi->vas), laskeKorkeus(lapsi->oik)) + 1;

    return lapsi;
}