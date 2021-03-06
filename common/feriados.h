#ifndef FERIADOS_H
#define FERIADOS_H

#include<math.h>
#include "luaCheia.h"

int quantidadeDias(int mes, anos* ano);

void adicionaFeriado(anos* ano, short int mes, short int dia, char nome[40]){
  strcpy(ano->mes[mes-1].feriado[ano->mes[mes-1].indiceFeriado].nome, nome);
  ano->mes[mes-1].feriado[ano->mes[mes-1].indiceFeriado].dia = dia;
  ano->mes[mes-1].indiceFeriado += 1;
}

void ordenarFeriados(anos* ano){  //Bubble Sort
  short int dataTemp;
  char nomeTemp[50];

  for (size_t i = 0; i < 12; i++) { //percorre os meses
    if (ano->mes[i].indiceFeriado > 1) { //verifica se tem ao menos 2 elementos
      for (size_t j = 0; j < (ano->mes[i].indiceFeriado-1); j++) {//realiza apenas a quantidade de iterações necessárias
        for (size_t k = 0; k < (ano->mes[i].indiceFeriado-1-j); k++) {//percorre os elementos não ordenados ainda
          if (ano->mes[i].feriado[k].dia > ano->mes[i].feriado[k+1].dia) {
            dataTemp = ano->mes[i].feriado[k+1].dia;
            ano->mes[i].feriado[k+1].dia = ano->mes[i].feriado[k].dia;
            ano->mes[i].feriado[k].dia = dataTemp;

            strcpy(nomeTemp, ano->mes[i].feriado[k+1].nome);
            strcpy(ano->mes[i].feriado[k+1].nome, ano->mes[i].feriado[k].nome);
            strcpy(ano->mes[i].feriado[k].nome, nomeTemp);
          }
        }
      }
    }
  }
}

void qFCinzas(anos* ano, short int dia, short int mes){
  for (size_t i = 0; i < 46; i++) {
    dia -= 1;
    if (dia == 0) {
      mes -= 1;
      dia = quantidadeDias(mes - 1, ano);
    }
  }
  adicionaFeriado(ano, mes, dia, "Quarta-Feira de Cinzas");
}

void paixaoDeCristo(anos* ano, short int dia, short int mes){
  for (size_t i = 0; i < 2; i++) {
    dia -= 1;
    if (dia == 0) {
      mes -= 1;
      dia = quantidadeDias(mes - 1, ano);
    }
  }
  adicionaFeriado(ano, mes, dia, "Paixão de Cristo");
}

void pascoa(anos* ano){
  // algoritmo de cálculo de páscoa retirado de http://ghiorzi.org/portug2.htm
  short int year, a, b, c, d, e, f, g, h, i, k, l, m, p, q, dia, mes;
  year = ano->ano;

  if (year >= 1583) {
    a = year % 19;
    b = year / 100;
    c = year % 100;
    d = b / 4;
    e = b % 4;
    f = ((b + 8) / 25);
    g = ((b - f + 1) / 3);
    h = ((19 * a + b - d - g + 15) % 30);
    i = c / 4;
    k = c % 4;
    l = ((32 + (2 * e) + (2 * i) - h - k) % 7);
    m = ((a + (11 * h) + (22 * l)) / 451);
    mes = ((h + l - (7 * m) + 114) / 31);
    dia = (((h + l - (7 * m) + 114) % 31) + 1);
    adicionaFeriado(ano, mes, dia, "Domingo de Páscoa (cristão)");

    luaCheia(ano);
    paixaoDeCristo(ano, dia, mes);
    qFCinzas(ano, dia, mes);
  }
  else{
    a = (year % 4);
    b = (year % 7);
    c = (year % 19);
    d = (((19 * c) + 15) % 30);
    e = (((2 * a) + (4 * b) - d + 34) % 7);
    mes = ((d + e + 114) / 31);
    dia = (((d + e + 114) % 31) + 1);
    adicionaFeriado(ano, mes, dia, "Páscoa (judaica)");
  }
}

void aniversarioSB(anos* ano){
  if(ano->ano >= 1553) //São Bernardo não existia antes de 1553
    adicionaFeriado(ano, 8, 20, "Aniversário de São Bernardo do Campo");
}

void confraterizacaoUniversal(anos* ano) {
  if(ano->ano >= 1936) //Criado por Getúlio Vargas em 29 de outubro de 1935
    adicionaFeriado(ano, 1, 1, "Confraternização Universal");
  else if(ano->ano >= 1910) //Feriado com mesmo nome em Portugal criado em 1910
    adicionaFeriado(ano, 10, 5, "Confraternização Universal (Portugal)");
}

void preencheFeriados(anos* ano) {
  pascoa(ano);
  adicionaFeriado(ano, 12, 25, "Natal");
  confraterizacaoUniversal(ano);
  aniversarioSB(ano);

  adicionaFeriado(ano, 9, 23, "Inicio da Primavera");
  adicionaFeriado(ano, 12, 21, "Inicio do Verão");
  adicionaFeriado(ano, 3, 20, "Inicio do Outono");
  adicionaFeriado(ano, 6, 21, "Inicio do Inverno");

  adicionaFeriado(ano, 9, 23, "Equinócio de Primavera");
  adicionaFeriado(ano, 3, 20, "Equinócio de Outono");

  ordenarFeriados(ano);
}

#endif
