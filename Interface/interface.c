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

int insereAno(int anoInt){
  if (!IupGetParam("Insira o ano:", 0, 0,
    "Ano: %i{Integer Tip}\n",
    &anoInt,NULL))

  printf("%d\n", anoInt);
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
  *coluna7, *coluna8, *tudo, *dataResposta, *janeiro, *fevereiro, *marco,*abril,
  *maio, *junho, *julho, *agosto, *setembro, *outubro, *novembro, *dezembro;

  short int i, j;
  char semanaString[6][7][3];
  int anoInt = 2019;
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

  if (!pedirAno) {
    anoInt = insereAno(anoInt);
    pedirAno = 1;
  }

  ano.ano = anoInt;
  sprintf(anoInput, "%d", anoInt);
  calendario(&ano);

  dataResposta = IupSetAttributes(IupLabel(anoInput), "FGCOLOR=\"#FFFFFF\", FONTSIZE=28, WEIGHT=BOLD");

  converteDiasPraString(mes, semanaString);

  frame1 = IupSetAttributes(
    IupVbox(
      dataResposta,
      IupLabel("\n\n\n"),
      NULL),
    "MARGIN=0x0, GAP=120");

  frame2 = IupSetAttributes(
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

  coluna1 = IupVbox(
    frame1,
    frame2,
    NULL
  );


  frame3 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][0])),
      IupVbox(IupLabel(semanaString[1][0])),
      IupVbox(IupLabel(semanaString[2][0])),
      IupVbox(IupLabel(semanaString[3][0])),
      IupVbox(IupLabel(semanaString[4][0])),
      IupVbox(IupLabel(semanaString[5][0])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame4 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][1])),
      IupVbox(IupLabel(semanaString[1][1])),
      IupVbox(IupLabel(semanaString[2][1])),
      IupVbox(IupLabel(semanaString[3][1])),
      IupVbox(IupLabel(semanaString[4][1])),
      IupVbox(IupLabel(semanaString[5][1])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");


  frame5 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][2])),
      IupVbox(IupLabel(semanaString[1][2])),
      IupVbox(IupLabel(semanaString[2][2])),
      IupVbox(IupLabel(semanaString[3][2])),
      IupVbox(IupLabel(semanaString[4][2])),
      IupVbox(IupLabel(semanaString[5][2])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame6 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][3])),
      IupVbox(IupLabel(semanaString[1][3])),
      IupVbox(IupLabel(semanaString[2][3])),
      IupVbox(IupLabel(semanaString[3][3])),
      IupVbox(IupLabel(semanaString[4][3])),
      IupVbox(IupLabel(semanaString[5][3])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame7 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][4])),
      IupVbox(IupLabel(semanaString[1][4])),
      IupVbox(IupLabel(semanaString[2][4])),
      IupVbox(IupLabel(semanaString[3][4])),
      IupVbox(IupLabel(semanaString[4][4])),
      IupVbox(IupLabel(semanaString[5][4])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame8 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][5])),
      IupVbox(IupLabel(semanaString[1][5])),
      IupVbox(IupLabel(semanaString[2][5])),
      IupVbox(IupLabel(semanaString[3][5])),
      IupVbox(IupLabel(semanaString[4][5])),
      IupVbox(IupLabel(semanaString[5][5])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame9 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel(semanaString[0][6])),
      IupVbox(IupLabel(semanaString[1][6])),
      IupVbox(IupLabel(semanaString[2][6])),
      IupVbox(IupLabel(semanaString[3][6])),
      IupVbox(IupLabel(semanaString[4][6])),
      IupVbox(IupLabel(semanaString[5][6])),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");


  coluna2 = IupVbox(
    IupSetAttributes(IupLabel("  d"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame3,
    NULL
  );


  coluna3 = IupVbox(
    IupSetAttributes(IupLabel("  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame4,
    NULL
  );


  coluna4 = IupVbox(
    IupSetAttributes(IupLabel("  t"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame5,
    NULL
  );


  coluna5 = IupVbox(
    IupSetAttributes(IupLabel("  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame6,
    NULL
  );


  coluna6 = IupVbox(
    IupSetAttributes(IupLabel("  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame7,
    NULL
  );


  coluna7 = IupVbox(
    IupSetAttributes(IupLabel("  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame8,
    NULL
  );


  coluna8 = IupVbox(
    IupSetAttributes(IupLabel("  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame9,
    NULL
  );



  tudo = IupHbox(
    coluna1,
    IupLabel("\t\t\t\t\t\t\t\t\t"),
    coluna2,
    coluna3,
    coluna4,
    coluna5,
    coluna6,
    coluna7,
    coluna8,
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
  IupClose ();
  return EXIT_SUCCESS;
}
