#ifndef FERIADOS_H
#define FERIADOS_H

void pascoa(anos* ano){
  strcpy(ano->mes[11].feriado[ano->mes[11].indiceFeriado].nome, "Natal");
  ano->mes[11].feriado[ano->mes[11].indiceFeriado].dia = 25;
  ano->mes[11].indiceFeriado += 1;
}

void confraternizacaoUniversal(anos* ano){
  strcpy(ano->mes[0].feriado[ano->mes[0].indiceFeriado].nome, "Confraternização Universal");
  ano->mes[0].feriado[ano->mes[0].indiceFeriado].dia = 1;
  ano->mes[0].indiceFeriado += 1;
}

void aniversarioSBernardo(anos* ano){
  strcpy(ano->mes[7].feriado[ano->mes[7].indiceFeriado].nome, "Aniversário de São Bernardo do Campo");
  ano->mes[7].feriado[ano->mes[7].indiceFeriado].dia = 20;
  ano->mes[7].indiceFeriado += 1;
}

void preencheFeriados(anos* ano) {
  pascoa(ano);
  confraternizacaoUniversal(ano);
  aniversarioSBernardo(ano);
}

#endif
