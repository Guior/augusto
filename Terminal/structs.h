#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct{
  char nome[40];
  unsigned short int dia;
}feriados;

typedef struct{
  char nome[16];
  feriados feriado[20];
  unsigned short int indiceFeriado ;
  unsigned short int semana[6][7]; //primeiro array pra número da semana e segundo pra dia da semana
}meses;

typedef struct{
  unsigned short int ano;
  meses mes[12];
  int bissexto ;
}anos;

#endif
