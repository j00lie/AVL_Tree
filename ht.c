/*Tietorakenteet ja algoritmit kurssin harjoitustyö
Joonas Liedes
Ohjelma AVL-puun tekoon, lisäksi hakutoiminnallisuus*/

#include "ht.h"

int valikko()
{
    int valinta;
    printf("\n1) Lue avaimet tiedostosta\n"
           "2) Tulosta puu\n"
           "3) Hae avain puusta\n"
           "4) Lisää avain puuhun\n"
           "0) Lopeta\n");
    printf("Valintasi: ");
    scanf("%d", &valinta);
    return valinta;
}
int main()
{
    SOLMU *juuri = NULL, *ptr;
    int valinta;
    do
    {
        valinta = valikko();
        if (valinta == 1)
        {
            juuri = lue();
        }
        else if (valinta == 2)
        {
            print2D(juuri, 0);
        }
        else if (valinta == 3)
        {
            int haettava;
            clock_t alku, loppu;

            printf("Anna haettava avain: ");
            scanf(" %d", &haettava);

            alku = clock();
            ptr = haeAvain(juuri, haettava);
            loppu = clock();
            float kulunut_aika = ((float)(loppu - alku)) / CLOCKS_PER_SEC;
            printf("Aikaa hakuun kului: %f\n", kulunut_aika);
            if (ptr != NULL)
            {
                printf("Avain löytyi: %d\n", ptr->avain);
            }
            else
            {
                printf("Haettu avain ei ole puussa\n");
            }
        }
        else if (valinta == 4)
        {
            int arvo = 0;
            printf("Anna lisättävä arvo:");
            scanf("%d", &arvo);
            juuri = lisaaPuuhun(juuri, arvo);
            print2D(juuri, 0);
        }

    } while (valinta != 0);

    return 0;
}