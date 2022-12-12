#*************************************************************************
# CT60A2500 C-ohjelmoinnin perusteet
# Tekijä: Otto Åhlfors
# Opiskelijanumero: 0611874
# Päivämäärä: 14.07.2022
# Palauttamalla tämän työn arvioitavaksi vakuutan, että
# 1) Olen itse kirjoittanut kaiken tässä tiedostossa olevan koodin
# 2) En ole antanut tätä koodia kenenkään muun käyttöön
#
# Kurssin oppimateriaalien lisäksi työhön ovat vaikuttaneet seuraavat
# lähteet ja henkilöt, ja se näkyy koodissa seuraavissa kohdissa:
# - StackOwerflow, yleinen apu
# - Konsta Keski-Mattinen, apu data-analyysi aliohjelmassa
#
#*************************************************************************
# Harjoitustyö perustaso, tiedoston nimi Makefile *

HTPerustaso: HTPerustaso.o HTPerusKirjasto.o
	gcc HTPerustaso.o HTPerusKirjasto.o -o HTPerustaso
HTPerustaso.o: HTPerustaso.c HTPerusKirjasto.h
	gcc HTPerustaso.c -c -std=c99 -pedantic -Wall
HTPerusKirjasto.o: HTPerusKirjasto.c HTPerusKirjasto.h
	gcc HTPerusKirjasto.c -c -std=c99 -pedantic -Wall