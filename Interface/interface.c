#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include </usr/include/iup/iup.h>
#include "../common/structs.h"
#include "../common/feriados.h"
#include "../common/phase.h"
#include "../common/calendario.h"

int mes;
int pedirAno = 0;
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


int insereAno(int anoInt){
  if (!IupGetParam("Insira o ano:", 0, 0,
    "Ano: %i{Integer Tip}\n",
    &anoInt,NULL));

  return anoInt;
}

void mesJan( Ihandle *self ){ mes = 0; IupClose(); main(); }
void mesFev( Ihandle *self ){ mes = 1; IupClose(); main(); }
void mesMar( Ihandle *self ){ mes = 2; IupClose(); main(); }
void mesAbr( Ihandle *self ){ mes = 3; IupClose(); main(); }
void mesMai( Ihandle *self ){ mes = 4; IupClose(); main(); }
void mesJun( Ihandle *self ){ mes = 5; IupClose(); main(); }
void mesJul( Ihandle *self ){ mes = 6; IupClose(); main(); }
void mesAgo( Ihandle *self ){ mes = 7; IupClose(); main(); }
void mesSet( Ihandle *self ){ mes = 8; IupClose(); main(); }
void mesOut( Ihandle *self ){ mes = 9; IupClose(); main(); }
void mesNov( Ihandle *self ){ mes = 10; IupClose(); main(); }
void mesDez( Ihandle *self ){ mes = 11; IupClose(); main(); }

int converteDiasPraString(short int mesTemp, char semanaString[6][7][3]){
  short int i, j;
  char temp[] = "fweuygfwuygfwyu";
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
  Ihandle *dlg, *frame1, *frame2, *frame3, *frame4, *frame5, *frame6, *frame7,
  *frame8, *frame9, *coluna1, *coluna2, *coluna3, *coluna4, *coluna5, *coluna6,
  *coluna7, *coluna8, *coluna9, *tudo, *dataResposta, *janeiro, *fevereiro, *marco,
  *abril, *maio, *junho, *julho, *agosto, *setembro, *outubro, *novembro, *dezembro,
  *dia1, *dia2, *dia3, *dia4, *dia5, *dia6, *dia7, *dia8, *dia9, *dia10, *dia11,
  *dia12, *dia13, *dia14, *dia15, *dia16, *dia17, *dia18, *dia19, *dia20, *dia21,
  *dia22, *dia23, *dia24, *dia25, *dia26, *dia27, *dia28, *dia29, *dia30, *dia31,
  *dia32, *dia33, *dia34, *dia35, *dia36, *dia37, *dia38, *dia39, *dia40, *dia41,
  *dia42;

  short int i, j;
  char semanaString[6][7][3];
  char anoInput[5];

  IupOpen(&argc, &argv);

  janeiro = IupButton("Janeiro", NULL);
  fevereiro = IupButton("Fevereiro", NULL);
  marco = IupButton("Março", NULL);
  abril = IupButton("Abril", NULL);
  maio = IupButton("Maio", NULL);
  junho = IupButton("Junho", NULL);
  julho = IupButton("Julho", NULL);
  agosto = IupButton("Agosto", NULL);
  setembro = IupButton("Setembro", NULL);
  outubro = IupButton("Outubro", NULL);
  novembro = IupButton("Novembro", NULL);
  dezembro = IupButton("Dezembro", NULL);

  if (mes == 0)
    IupSetAttributes(janeiro, "FGCOLOR=\"#85892c\"");
  else if (mes == 1)
    IupSetAttributes(fevereiro, "FGCOLOR=\"#85892c\"");
  else if (mes == 2)
    IupSetAttributes(marco, "FGCOLOR=\"#85892c\"");
  else if (mes == 3)
    IupSetAttributes(abril, "FGCOLOR=\"#85892c\"");
  else if (mes == 4)
    IupSetAttributes(maio, "FGCOLOR=\"#85892c\"");
  else if (mes == 5)
    IupSetAttributes(junho, "FGCOLOR=\"#85892c\"");
  else if (mes == 6)
    IupSetAttributes(julho, "FGCOLOR=\"#85892c\"");
  else if (mes == 7)
    IupSetAttributes(agosto, "FGCOLOR=\"#85892c\"");
  else if (mes == 8)
    IupSetAttributes(setembro, "FGCOLOR=\"#85892c\"");
  else if (mes == 9)
    IupSetAttributes(outubro, "FGCOLOR=\"#85892c\"");
  else if (mes == 10)
    IupSetAttributes(novembro, "FGCOLOR=\"#85892c\"");
  else if (mes == 11)
    IupSetAttributes(dezembro, "FGCOLOR=\"#85892c\"");

  if (!pedirAno) {
    ano.ano = 2019;
    ano.ano = insereAno(ano.ano);
    pedirAno = 1;
  }

  sprintf(anoInput, "%d", ano.ano);
  calendario(&ano);

  dataResposta = IupSetAttributes(IupLabel(anoInput), "FGCOLOR=\"#FFFFFF\", FONTSIZE=40, WEIGHT=BOLD");

  converteDiasPraString(mes, semanaString);

  frame1 = IupSetAttributes(
    IupVbox(
      janeiro,
      fevereiro,
      marco,
      abril,
      maio,
      junho,
      julho,
      agosto,
      setembro,
      outubro,
      novembro,
      dezembro,
      NULL),
    "MARGIN=0x0, ALIGNMENT=ALEFT, FLAT=YES, FGCOLOR=\"#FFFFFF\"");


  frame2 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][0])),
      IupVbox(IupLabel(semanaString[1][0])),
      IupVbox(IupLabel(semanaString[2][0])),
      IupVbox(IupLabel(semanaString[3][0])),
      IupVbox(IupLabel(semanaString[4][0])),
      IupVbox(IupLabel(semanaString[5][0])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame3 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][1])),
      IupVbox(IupLabel(semanaString[1][1])),
      IupVbox(IupLabel(semanaString[2][1])),
      IupVbox(IupLabel(semanaString[3][1])),
      IupVbox(IupLabel(semanaString[4][1])),
      IupVbox(IupLabel(semanaString[5][1])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");


  frame4 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][2])),
      IupVbox(IupLabel(semanaString[1][2])),
      IupVbox(IupLabel(semanaString[2][2])),
      IupVbox(IupLabel(semanaString[3][2])),
      IupVbox(IupLabel(semanaString[4][2])),
      IupVbox(IupLabel(semanaString[5][2])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame5 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][3])),
      IupVbox(IupLabel(semanaString[1][3])),
      IupVbox(IupLabel(semanaString[2][3])),
      IupVbox(IupLabel(semanaString[3][3])),
      IupVbox(IupLabel(semanaString[4][3])),
      IupVbox(IupLabel(semanaString[5][3])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame6 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][4])),
      IupVbox(IupLabel(semanaString[1][4])),
      IupVbox(IupLabel(semanaString[2][4])),
      IupVbox(IupLabel(semanaString[3][4])),
      IupVbox(IupLabel(semanaString[4][4])),
      IupVbox(IupLabel(semanaString[5][4])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame7 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][5])),
      IupVbox(IupLabel(semanaString[1][5])),
      IupVbox(IupLabel(semanaString[2][5])),
      IupVbox(IupLabel(semanaString[3][5])),
      IupVbox(IupLabel(semanaString[4][5])),
      IupVbox(IupLabel(semanaString[5][5])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame8 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][6])),
      IupVbox(IupLabel(semanaString[1][6])),
      IupVbox(IupLabel(semanaString[2][6])),
      IupVbox(IupLabel(semanaString[3][6])),
      IupVbox(IupLabel(semanaString[4][6])),
      IupVbox(IupLabel(semanaString[5][6])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  coluna1 = IupVbox(
    dataResposta,
    IupLabel("\n\n\n\n\n\n\n\n"),
    frame1,
    NULL
  );

  coluna2 = IupVbox(
    IupSetAttributes(IupLabel("\n  d"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame2,
    NULL
  );

  coluna3 = IupVbox(
    IupSetAttributes(IupLabel("\n  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame3,
    NULL
  );

  coluna4 = IupVbox(
    IupSetAttributes(IupLabel("\n  t"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame4,
    NULL
  );

  coluna5 = IupVbox(
    IupSetAttributes(IupLabel("\n  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame5,
    NULL
  );

  coluna6 = IupVbox(
    IupSetAttributes(IupLabel("\n  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame6,
    NULL
  );

  coluna7 = IupVbox(
    IupSetAttributes(IupLabel("\n  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame7,
    NULL
  );

  coluna8 = IupVbox(
    IupSetAttributes(IupLabel("\n  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame8,
    NULL
  );

  coluna9 = IupVbox(
    IupSetAttributes(IupLabel("Feriados:\n"), "FGCOLOR=\"#60206E\", FONTSIZE=24"),
    IupSetAttributes(IupLabel(retornaFeriado(0)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(1)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(2)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(3)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(4)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(5)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    IupSetAttributes(IupLabel(retornaFeriado(6)), "FGCOLOR=\"#60206E\", FONTSIZE=18"),
    NULL
  );

  tudo = IupHbox(
    coluna1,
    IupLabel("\t\t\t\t\t\t\t"),
    coluna2,
    coluna3,
    coluna4,
    coluna5,
    coluna6,
    coluna7,
    coluna8,
    IupLabel("\t\t\t"),
    coluna9,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  dlg = IupDialog(tudo);
  IupSetAttributes (dlg, "MARGIN=10x10, TITLE = \"Calendário\", BGCOLOR=\"#272727\", ALIGNMENT=ACENTER");

  IupSetCallback(janeiro, "ACTION", (Icallback) mesJan);
  IupSetCallback(fevereiro, "ACTION", (Icallback) mesFev);
  IupSetCallback(marco, "ACTION", (Icallback) mesMar);
  IupSetCallback(abril, "ACTION", (Icallback) mesAbr);
  IupSetCallback(maio, "ACTION", (Icallback) mesMai);
  IupSetCallback(junho, "ACTION", (Icallback) mesJun);
  IupSetCallback(julho, "ACTION", (Icallback) mesJul);
  IupSetCallback(agosto, "ACTION", (Icallback) mesAgo);
  IupSetCallback(setembro, "ACTION", (Icallback) mesSet);
  IupSetCallback(outubro, "ACTION", (Icallback) mesOut);
  IupSetCallback(novembro, "ACTION", (Icallback) mesNov);
  IupSetCallback(dezembro, "ACTION", (Icallback) mesDez);

  IupShowXY (dlg, IUP_LEFT, IUP_TOP );

  IupMainLoop();
  IupClose();
  return EXIT_SUCCESS;
}
