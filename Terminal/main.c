#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"
#include "feriados.h"

void insereAno(anos* ano){
  short int anoTemp, inseridos;

  while(1){
		puts("Insira o ano do calendário: ");
		char buffer[10];

		fgets(buffer, sizeof(buffer), stdin);
		inseridos = sscanf(buffer, "%d", &anoTemp);

		if (inseridos == 0 || anoTemp < 1)
			puts("Entrada não é válida");
    else
      break;
	}
  ano->ano = anoTemp;
  system("clear");
}

void verificaBissexto(anos* ano){
  if (((ano->ano % 4) == 0) && ((ano->ano % 100) != 0) && ((ano->ano % 400) != 0)) {
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
  dia = 1;

	m = ((mes < 3) ? (mes + 12) : mes);
	y = ((m > 12) ? (ano - 1) : ano);
	q = (dia + (((m+1)*26)/10) + y + (y/4) + (6*(y/100)) + (y/400));

	ret = (q % 7);

  if(ret == 0)
    return (ret+6);
  else
    return (ret-1);
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

void exibeCalendario(anos* ano) {
  short int i, j, k;

  printf("Ano: %d\n", ano->ano);

  for (size_t k = 0; k < 12; k++) {
    printf("\n%s\n", ano->mes[k].nome);
    puts(" d  s  t  q  q  s  s \t|   Feriados:");
    for (size_t i = 0; i < 6; i++) {
      for (size_t j = 0; j < 7; j++) {
        if(ano->mes[k].semana[i][j] == 0){
          printf("   ");
        }
        else
          printf("%2d ", ano->mes[k].semana[i][j]);
        }
        printf("\t|");
        if (ano->mes[k].indiceFeriado == 0 && i == 0)
          printf("   Nenhum");
        else if (i < ano->mes[k].indiceFeriado) {
          printf("   %d - %s", ano->mes[k].feriado[i].dia, ano->mes[k].feriado[i].nome);
        }
      puts("");
    }
    puts("\n");
  }
}


int main(int argc, char const *argv[]) {
  anos ano;

  insereAno(&ano);
  verificaBissexto(&ano);
  zerarMeses(&ano);
  preencheCalendario(&ano);
  preencheFeriados(&ano);
  exibeCalendario(&ano);

  return 0;
}
