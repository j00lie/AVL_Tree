/*Tietorakenteet ja algoritmit kurssin harjoitustyö
Joonas Liedes*/

#include <stdio.h>
#include <stdlib.h>
#define rivin_pituus 100
#define COUNT 10
typedef struct solmu
{
  int avain;
  int korkeus;
  struct solmu *vas;
  struct solmu *oik;
} SOLMU;

SOLMU *lue();
void kysyNimi(char *tdsto_nimi);
int laskeKorkeus(SOLMU *ptr);
SOLMU *teeUusi(int avain);
SOLMU *lisaaPuuhun(SOLMU *solmu, int avain);
void tulosta(SOLMU *solmu);
void print2D(SOLMU *root, int space);
SOLMU *haeAvain(SOLMU *juuri, int avain);
