/*Tietorakenteet ja algoritmit kurssin harjoitustyö
Joonas Liedes*/
#include "avlFunktiot.h"

SOLMU *lue()
{
    FILE *tiedosto;
    char tdsto_nimi[30];
    char rivi[rivin_pituus];
    SOLMU *pUusi = NULL, *pJuuri = NULL, *ptr = NULL;
    int num = 0;

    kysyNimi(tdsto_nimi);
    tiedosto = fopen(tdsto_nimi, "r");
    // Virheenkäsittely
    if (tiedosto == NULL)
    {
        perror("Tiedoston lukeminen epäonnistui");
        exit(0);
    }
    while (fgets(rivi, rivin_pituus, tiedosto) != NULL)
    {
        num = atoi(rivi);
        pJuuri = lisaaPuuhun(pJuuri, num);
        print2D(pJuuri, 0);
    }
    fclose(tiedosto);
    return pJuuri;
}

void kysyNimi(char *tdsto_nimi)
{
    printf("Anna tiedoston nimi: ");
    scanf("%s", tdsto_nimi);
}

SOLMU *teeUusi(int avain)
{
    SOLMU *pUusi = (SOLMU *)malloc(sizeof(SOLMU));
    if (pUusi == NULL)
    {
        perror("Muistinvaraus epäonnistui");
        exit(0);
    }
    pUusi->avain = avain;
    pUusi->korkeus = 1; // Koska kyseessä yksittäinen alkio -->lehtisolmu
    pUusi->vas = NULL;
    pUusi->oik = NULL;

    return pUusi;
}
SOLMU *lisaaPuuhun(SOLMU *solmu, int avain)
{
    if (solmu == NULL)
    {
        return teeUusi(avain);
    }
    if (avain < solmu->avain)
        solmu->vas = lisaaPuuhun(solmu->vas, avain);
    else if (avain > solmu->avain)
        solmu->oik = lisaaPuuhun(solmu->oik, avain);
    else // Ei samoja arvoja binäärihakupuussa
        return solmu;

    solmu->korkeus = 1 + max(laskeKorkeus(solmu->vas), laskeKorkeus(solmu->oik)); // Päivitä lisätyn korkeus
    int tp = laskeTasapaino(solmu);                                               // Haetaan lisätyn solmun tasapainoarvo

    // 4 vaihtoehtoa jos epätasapainossa
    //  Vasen vasen epätasapaino
    if (tp > 1 && avain < solmu->vas->avain)
    {
        return oikRot(solmu);
    }
    // Oikea oikea
    if (tp < -1 && avain > solmu->oik->avain)
    {
        return vasRot(solmu);
    }
    // Vasen oikea
    if (tp > 1 && avain > solmu->vas->avain)
    {
        solmu->vas = vasRot(solmu->vas);
        return oikRot(solmu);
    }
    // Oikea vasen
    if (tp < -1 && avain < solmu->oik->avain)
    {
        solmu->oik = oikRot(solmu->oik);
        return vasRot(solmu);
    }
    return solmu;
}

void print2D(SOLMU *root, int tasovali)
{
    if (root == NULL)
        return;
    tasovali += COUNT;            // kasvata puun tasojen väliä
    print2D(root->oik, tasovali); // oik oksan rekursio
    printf("\n");
    for (int i = root->korkeus; i < tasovali; i++)
        printf(" ");
    printf("%d\n", root->avain);
    print2D(root->vas, tasovali); // vas oksan rekursio
}

SOLMU *haeAvain(SOLMU *juuri, int avain)
{
    // rekursion kanta:
    if (juuri == NULL || juuri->avain == avain)
    {
        return juuri;
    }
    // Jos haettava suurempi kuin juuri --> käydään puun oik. puoli läpi
    if (juuri->avain < avain)
    {
        return haeAvain(juuri->oik, avain);
    }
    // Jos haettava on pienempi kuin juuri niin käydään puun vas. puoli läpi
    return haeAvain(juuri->vas, avain);
}

/*void tulosta(SOLMU *solmu) {
    if (solmu != NULL) {
        SOLMU *ptr = solmu;
        tulosta(ptr->vas);
        printf("%d, ", ptr->avain);
        tulosta(ptr->oik);
    }
    return;
}*/