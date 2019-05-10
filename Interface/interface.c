#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include </usr/include/iup/iup.h>
#include "../common/structs.h"
#include "../common/feriados.h"
#include "../common/luaCheia.h"
#include "../common/calendario.h"

int mes, cancel;
int pedirAno = 0;
int indiceFeriado2 = 0;
anos ano;

const char* retornaFeriado(int numFeriado){
  static char feriadoNome[50];
  if (numFeriado < ano.mes[mes].indiceFeriado) {
    sprintf(feriadoNome, "%d - %s", ano.mes[mes].feriado[numFeriado].dia, ano.mes[mes].feriado[numFeriado].nome);
    return feriadoNome;
  }
  else
    return "";
}


void insereAno(){
  int anoTemp = ano.ano;
  cancel = 0;
  if (!IupGetParam("Insira o ano:", 0, 0,
    "Ano: %i{Integer Tip}\n",
    &anoTemp,NULL)) cancel = 1;
  ano.ano = anoTemp;
}

void mesJan( Ihandle *self ){ mes = 0; indiceFeriado2 = 0; IupClose(); main(); }
void mesFev( Ihandle *self ){ mes = 1; indiceFeriado2 = 0; IupClose(); main(); }
void mesMar( Ihandle *self ){ mes = 2; indiceFeriado2 = 0; IupClose(); main(); }
void mesAbr( Ihandle *self ){ mes = 3; indiceFeriado2 = 0; IupClose(); main(); }
void mesMai( Ihandle *self ){ mes = 4; indiceFeriado2 = 0; IupClose(); main(); }
void mesJun( Ihandle *self ){ mes = 5; indiceFeriado2 = 0; IupClose(); main(); }
void mesJul( Ihandle *self ){ mes = 6; indiceFeriado2 = 0; IupClose(); main(); }
void mesAgo( Ihandle *self ){ mes = 7; indiceFeriado2 = 0; IupClose(); main(); }
void mesSet( Ihandle *self ){ mes = 8; indiceFeriado2 = 0; IupClose(); main(); }
void mesOut( Ihandle *self ){ mes = 9; indiceFeriado2 = 0; IupClose(); main(); }
void mesNov( Ihandle *self ){ mes = 10; indiceFeriado2 = 0; IupClose(); main(); }
void mesDez( Ihandle *self ){ mes = 11; indiceFeriado2 = 0; IupClose(); main(); }
void novoAno( Ihandle *self ){ insereAno(); mes = 0; indiceFeriado2 = 0; IupClose(); main(); }

int converteDiasPraString(short int mesTemp, char semanaString[6][7][3]){
  short int i, j;
  char temp[40];
  for (size_t i = 0; i < 6; i++) {
    for (size_t j = 0; j < 7; j++) {
      if (ano.mes[mesTemp].semana[i][j] != 0) {
        sprintf(temp, "%d", ano.mes[mesTemp].semana[i][j]);
        strcpy(semanaString[i][j], temp);
      }
      else
        strcpy(semanaString[i][j], "  ");
    }
  }
}

int main(int argc, char **argv){
  IupOpen(&argc, &argv);

  short int i, j, k;
  char semanaString[6][7][3];
  char anoInput[5];

  Ihandle *dlg, *frame1, *frame2, *frame3, *frame4, *frame5, *frame6, *frame7,
  *frame8, *frame9, *coluna1, *coluna2, *coluna3, *coluna4, *coluna5, *coluna6,
  *coluna7, *coluna8, *coluna9, *tudo, *dataResposta, *dias[6][7];

  Ihandle *meses[12] = {
    IupButton("Janeiro", NULL),
    IupButton("Fevereiro", NULL),
    IupButton("Março", NULL),
    IupButton("Abril", NULL),
    IupButton("Maio", NULL),
    IupButton("Junho", NULL),
    IupButton("Julho", NULL),
    IupButton("Agosto", NULL),
    IupButton("Setembro", NULL),
    IupButton("Outubro", NULL),
    IupButton("Novembro", NULL),
    IupButton("Dezembro", NULL),
  };
  IupSetAttributes(meses[mes], "FGCOLOR=\"#85892c\"");

  if (!pedirAno) {
    ano.ano = 2019;
    insereAno();
    pedirAno = 1;
  }

  sprintf(anoInput, "%d", ano.ano);
  calendario(&ano);

  dataResposta = IupSetAttributes(IupButton(anoInput, NULL), "FGCOLOR=\"#FFFFFF\", FLAT=YES, FONTSIZE=40, WEIGHT=BOLD");

  converteDiasPraString(mes, semanaString);

  for (size_t i = 0; i < 6; i++) {
    for (size_t j = 0; j < 7; j++) {
      dias[i][j] = IupLabel(semanaString[i][j]);
    }
  }

  for (size_t i = 0; i < 6; i++) {
    for (size_t j = 0; j < 6; j++) {
      for (size_t k = 0; k < 7; k++) {
        if (indiceFeriado2 < ano.mes[mes].indiceFeriado) {
          if (ano.mes[mes].semana[j][k] == ano.mes[mes].feriado[indiceFeriado2].dia) {
            IupSetAttribute(dias[j][k], "FGCOLOR", "#60206E");
            indiceFeriado2++;
          }
        }
      }
    }
  }

  frame1 = IupSetAttributes(
    IupVbox(meses[0], meses[1],meses[2], meses[3], meses[4], meses[5], meses[6],
      meses[7], meses[8], meses[9], meses[10], meses[11], NULL),
    "MARGIN=0x0, ALIGNMENT=ALEFT, FLAT=YES, FGCOLOR=\"#FFFFFF\"");

  frame2 = IupSetAttributes(
    IupVbox(dias[0][0], dias[1][0], dias[2][0], dias[3][0], dias[4][0], dias[5][0], NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame3 = IupSetAttributes(
    IupVbox(dias[0][1], dias[1][1], dias[2][1], dias[3][1], dias[4][1], dias[5][1], NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame4 = IupSetAttributes(
    IupVbox(dias[0][2], dias[1][2], dias[2][2], dias[3][2], dias[4][2], dias[5][2], NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame5 = IupSetAttributes(
    IupVbox(dias[0][3], dias[1][3], dias[2][3], dias[3][3], dias[4][3], dias[5][3], NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame6 = IupSetAttributes(
    IupVbox(dias[0][4], dias[1][4], dias[2][4], dias[3][4], dias[4][4], dias[5][4], NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame7 = IupSetAttributes(
    IupVbox(dias[0][5], dias[1][5], dias[2][5], dias[3][5], dias[4][5], dias[5][5], NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame8 = IupSetAttributes(
    IupVbox(dias[0][6], dias[1][6], dias[2][6], dias[3][6], dias[4][6], dias[5][6], NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  coluna1 = IupVbox(
    dataResposta,
    IupLabel("\n\n\n\n\n\n\n\n"),
    frame1,
    NULL);

  coluna2 = IupVbox(
    IupSetAttributes(IupLabel("\n  d"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame2,
    NULL);

  coluna3 = IupVbox(
    IupSetAttributes(IupLabel("\n  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame3,
    NULL);

  coluna4 = IupVbox(
    IupSetAttributes(IupLabel("\n  t"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame4,
    NULL);

  coluna5 = IupVbox(
    IupSetAttributes(IupLabel("\n  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame5,
    NULL);

  coluna6 = IupVbox(
    IupSetAttributes(IupLabel("\n  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame6,
    NULL);

  coluna7 = IupVbox(
    IupSetAttributes(IupLabel("\n  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame7,
    NULL);

  coluna8 = IupVbox(
    IupSetAttributes(IupLabel("\n  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame8,
    NULL);

  coluna9 = IupVbox(
    IupSetAttributes(IupLabel("Feriados:\n"), "FGCOLOR=\"#60206E\", FONTSIZE=24"),
    IupSetAttributes(IupLabel(retornaFeriado(0)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(1)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(2)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(3)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(4)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(5)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(6)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    NULL);

  tudo = IupHbox(
    coluna1,
    IupLabel("\t\t\t\t\t\t\t"),
    coluna2, coluna3, coluna4, coluna5, coluna6, coluna7, coluna8,
    IupLabel("\t\t\t"),
    coluna9,
    NULL);
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  dlg = IupDialog(tudo);
  IupSetAttributes (dlg, "MARGIN=10x10, TITLE = \"Calendário\", BGCOLOR=\"#272727\", ALIGNMENT=ACENTER");

  IupSetCallback(meses[0], "ACTION", (Icallback) mesJan);
  IupSetCallback(meses[1], "ACTION", (Icallback) mesFev);
  IupSetCallback(meses[2], "ACTION", (Icallback) mesMar);
  IupSetCallback(meses[3], "ACTION", (Icallback) mesAbr);
  IupSetCallback(meses[4], "ACTION", (Icallback) mesMai);
  IupSetCallback(meses[5], "ACTION", (Icallback) mesJun);
  IupSetCallback(meses[6], "ACTION", (Icallback) mesJul);
  IupSetCallback(meses[7], "ACTION", (Icallback) mesAgo);
  IupSetCallback(meses[8], "ACTION", (Icallback) mesSet);
  IupSetCallback(meses[9], "ACTION", (Icallback) mesOut);
  IupSetCallback(meses[10], "ACTION", (Icallback) mesNov);
  IupSetCallback(meses[11], "ACTION", (Icallback) mesDez);
  IupSetCallback(dataResposta, "ACTION", (Icallback) novoAno);

  if (cancel == 0) {
    IupShowXY (dlg, IUP_LEFT, IUP_TOP );
    IupMainLoop();
  }
  IupClose();
  return EXIT_SUCCESS;
}
