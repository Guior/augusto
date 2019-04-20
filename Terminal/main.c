#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "feriados.h"

void insereAno(anos* ano){
  puts("Insira o ano do calendário: ");
  scanf("%d", &(ano->ano));
  system("clear");
}

void verificaBissexto(anos* ano){
  if (((ano->ano % 4) == 0) && ((ano->ano % 100) != 0) && ((ano->ano % 400) != 0)) {
    ano->bissexto = 1;
  }
  else
    ano->bissexto = 0;
}

unsigned short int calculaDiaSemana(unsigned short int ano, unsigned short int mes){

unsigned short int q, m, ret, y, dia;

	m = (mes <3) ? (mes + 12) : mes;
	y = ((m>12) ? (ano-1) : ano);
	q = dia + (((m+1)*26)/10) + y + (y/4) + 6*(y/100) + (y/400);

	ret = (q % 7);

	return ret;

}

int quantidadeDiasEInfo(int mes, anos* ano){
  if (ano->bissexto && mes == 1) {
    strcpy(ano->mes[mes].nome, "      Fevereiro    ");
    return 29;
  }
  else{
    switch (mes) {
      case 0:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "      Janeiro");
        return 31;
      case 1:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "      Fevereiro");
        return 28;
      case 2:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "        Março");
        return 31;
      case 3:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "        Abril");
        return 30;
      case 4:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "        Maio");
        return 31;
      case 5:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "       Junho");
        return 30;
      case 6:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "       Julho");
        return 31;
      case 7:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "       Agosto");
        return 31;
      case 8:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "      Setembro");
        return 30;
      case 9:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "      Outubro");
        return 31;
      case 10:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "      Novembro");
        return 30;
      case 11:
        ano->mes[mes].indiceFeriado = 0;
        strcpy(ano->mes[mes].nome, "      Dezembro");
        return 31;
    }
  }
}

void preencheCalendario(anos* ano){
  short int i, j, k, diaInicial, diafinal;
  short int dia = 1;

  for (size_t i = 0; i < 12; i++) {
    diaInicial = calculaDiaSemana(ano->ano, i+1);
    diafinal = quantidadeDiasEInfo(i, ano);
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

void exibeCalendario(anos* ano) {
  short int i, j, k;

  printf("Ano: %d\n", ano->ano);

  for (size_t k = 0; k < 12; k++) {
    printf("\n%s\n", ano->mes[k].nome);
    puts(" d  s  t  q  q  s  s ");
    for (size_t i = 0; i < 6; i++) {
      for (size_t j = 0; j < 7; j++) {
        if(ano->mes[k].semana[i][j] == 0){
          printf("   ");
        }
        else
          printf("%2d ", ano->mes[k].semana[i][j]);
      }
      puts("");
    }
    for (size_t i = 0; i < ano->mes[k].indiceFeriado; i++) {
      printf("%d - %s\n", ano->mes[k].feriado[i].dia, ano->mes[k].feriado[i].nome);
    }
    puts("");
  }
}


int main(int argc, char const *argv[]) {
  anos ano;

  //insereAno(&ano);
  ano.ano = 2019;
  verificaBissexto(&ano);
  preencheCalendario(&ano);
  preencheFeriados(&ano);
  exibeCalendario(&ano);

  return 0;
}
