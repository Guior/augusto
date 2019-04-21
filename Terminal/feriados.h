#ifndef FERIADOS_H
#define FERIADOS_H

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

  strcpy(ano->mes[mes-1].feriado[ano->mes[mes-1].indiceFeriado].nome, "Domingo de Páscoa");
  ano->mes[mes-1].feriado[ano->mes[mes-1].indiceFeriado].dia = dia;
  ano->mes[mes-1].indiceFeriado += 1;
}

void natal(anos* ano){
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
  natal(ano);
  confraternizacaoUniversal(ano);
  aniversarioSBernardo(ano);
}

#endif
