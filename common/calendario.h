#ifndef CALENDARIO_H
#define CALENDARIO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "feriados.h"
#include "luaCheia.h"

void verificaBissexto(anos* ano){
  if (((ano->ano % 4) == 0) && ((ano->ano % 100) != 0) || ((ano->ano % 400) == 0)) {
    ano->bissexto = 1;
  }
  else
    ano->bissexto = 0;
}

void zerarMeses(anos *ano){
  short int mes;
  for (size_t mes = 0; mes < 12; mes++) {
    ano->mes[mes].indiceFeriado = 0;
    if (mes == 0)
      strcpy(ano->mes[mes].nome, "      Janeiro");
    else if(mes == 1)
      strcpy(ano->mes[mes].nome, "      Fevereiro");
    else if(mes == 2)
      strcpy(ano->mes[mes].nome, "        Março");
    else if(mes == 3)
      strcpy(ano->mes[mes].nome, "        Abril");
    else if(mes == 4)
      strcpy(ano->mes[mes].nome, "        Maio");
    else if(mes == 5)
      strcpy(ano->mes[mes].nome, "       Junho");
    else if(mes == 6)
      strcpy(ano->mes[mes].nome, "       Julho");
    else if(mes == 7)
      strcpy(ano->mes[mes].nome, "       Agosto");
    else if(mes == 8)
      strcpy(ano->mes[mes].nome, "      Setembro");
    else if(mes == 9)
      strcpy(ano->mes[mes].nome, "      Outubro");
    else if(mes == 10)
      strcpy(ano->mes[mes].nome, "      Novembro");
    else if(mes == 11)
      strcpy(ano->mes[mes].nome, "      Dezembro");
  }
}

int calculaDiaSemana(unsigned short int ano, unsigned short int mes){

  short int q, m, ret, y, dia;
  dia = 0;

	m = ((mes < 3) ? (mes + 12) : mes);
	y = ((m > 12) ? (ano - 1) : ano);
	q = (dia + (((m+1)*26)/10) + y + (y/4) + (6*(y/100)) + (y/400));

	ret = (q % 7);

  return (ret);
}

int quantidadeDias(int mes, anos* ano){
  if(mes == 0)
    return 31;
  else if (!ano->bissexto && mes == 1)
    return 28;
  else if (ano->bissexto && mes == 1)
    return 29;
  else if(mes == 2)
    return 31;
  else if(mes == 3)
    return 30;
  else if(mes == 4)
    return 31;
  else if(mes == 5)
    return 30;
  else if(mes == 6)
    return 31;
  else if(mes == 7)
    return 31;
  else if(mes == 8)
    return 30;
  else if(mes == 9)
    return 31;
  else if(mes == 10)
    return 30;
  else if(mes == 11)
    return 31;
}

void preencheCalendario(anos* ano){
  unsigned short int i, j, k, diaInicial, diafinal;
  unsigned short int dia = 1;

  for (size_t i = 0; i < 12; i++) {
    diaInicial = calculaDiaSemana(ano->ano, i+1);
    diafinal = quantidadeDias(i, ano);
    for (size_t j = 0; j < 6; j++) {
      for (size_t k = 0; k < 7; k++) {
        ano->mes[i].semana[j][k] = 0;
        if (dia <= diafinal) {
          if (j == 0 && k >= diaInicial) {
            ano->mes[i].semana[j][k] = dia;
            dia++;
          }
          else if (j != 0) {
            ano->mes[i].semana[j][k] = dia;
            dia++;
          }
        }
      }
    }
    dia = 1;
  }
}


void calendario(anos*ano) {
  verificaBissexto(ano);
  zerarMeses(ano);
  preencheCalendario(ano);
  preencheFeriados(ano);
}

#endif
