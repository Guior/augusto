#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../common/calendario.h"
#include "../common/structs.h"
#include "../common/feriados.h"
#include "../common/phase.h"

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

void exibeCalendario(anos* ano) {
  short int i, j, k;

  printf("  Ano: %d\n", ano->ano);

  for (size_t k = 0; k < 12; k++) {
    printf("\n  %s\n", ano->mes[k].nome);
    puts("   d  s  t  q  q  s  s \t|   Feriados:");
    for (size_t i = 0; i < 6; i++) {
      printf("  ");
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
          printf("   %2d - %s", ano->mes[k].feriado[i].dia, ano->mes[k].feriado[i].nome);
        }
      puts("");
    }
    puts("\n");
  }
}


int main(int argc, char const *argv[]) {
  anos ano;
  insereAno(&ano);
  calendario(&ano);
  exibeCalendario(&ano);
  return 0;
}
