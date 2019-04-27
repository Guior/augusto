#ifndef FERIADOS_H
#define FERIADOS_H

int quantidadeDias(int mes, anos* ano);

void adicionaFeriado(anos* ano, short int mes, short int dia, char nome[40]){
  strcpy(ano->mes[mes-1].feriado[ano->mes[mes-1].indiceFeriado].nome, nome);
  ano->mes[mes-1].feriado[ano->mes[mes-1].indiceFeriado].dia = dia;
  ano->mes[mes-1].indiceFeriado += 1;
}

void ordenarFeriados(anos* ano){  //Bubble Sorte
  short int i, j, dataTemp;
  char nomeTemp[40];

  for (size_t i = 0; i < 12; i++) {  //Percorre os meses
    if(ano->mes[i].indiceFeriado > 1){ //verifica se aquele mês tem mais de um feriado
      for (size_t j = 0; j < (ano->mes[i].indiceFeriado - 1); j++) { //faz a quantidade de iterações necessária pra ficar ordenado
        if (ano->mes[i].feriado[j].dia > ano->mes[i].feriado[j + 1].dia) {
          strcpy(nomeTemp, ano->mes[i].feriado[j + 1].nome);
          dataTemp = ano->mes[i].feriado[j + 1].dia;

          strcpy(ano->mes[i].feriado[j + 1].nome, ano->mes[i].feriado[j].nome);
          ano->mes[i].feriado[j + 1].dia = ano->mes[i].feriado[j].dia;

          strcpy(ano->mes[i].feriado[j].nome, nomeTemp);
          ano->mes[i].feriado[j].dia = dataTemp;
        }
      }
    }
  }
}

void qFCinzas(anos* ano, short int dia, short int mes){
  short int i;
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
  short int i;
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

  }
  else{
    a = (year % 4);
    b = (year % 7);
    c = (year % 19);
    d = (((19 * c) + 15) % 30);
    e = (((2 * a) + (4 * b) - d + 34) % 7);
    mes = ((d + e + 114) / 31);
    dia = (((d + e + 114) % 31) + 1);
  }

  adicionaFeriado(ano, mes, dia, "Domingo de Páscoa");

  paixaoDeCristo(ano, dia, mes);
  qFCinzas(ano, dia, mes);
}

void preencheFeriados(anos* ano) {
  pascoa(ano);
  adicionaFeriado(ano, 12, 25, "Natal");
  adicionaFeriado(ano, 1, 1, "Confraternização Universal");
  adicionaFeriado(ano, 8, 20, "Aniversário de São Bernardo do Campo");
  ordenarFeriados(ano);
}

#endif
