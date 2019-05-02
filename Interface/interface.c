#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include </usr/include/iup/iup.h>
#include "../common/structs.h"
#include "../common/feriados.h"
#include "../common/phase.h"
#include "../common/calendario.h"

int main(int argc, char **argv)
{
  Ihandle *dlg, *frame1, *frame2, *frame3, *frame4, *frame5, *frame6, *frame7,
  *frame8, *frame9, *frame10, *frame11, *frame12, *frame13, *frame14, *frame15,
  *frame16, *coluna1, *coluna2, *coluna3, *coluna4, *coluna5, *coluna6, *coluna7,
  *coluna8, *tudo, *dataResposta, *janeiro, *fevereiro, *marco,*abril, *maio,
  *junho, *julho, *agosto, *setembro, *outubro, *novembro, *dezembro;

  int data = 2019;
  char ano[5];

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

  if (!IupGetParam("Title", 0, 0,
    "Ano: %i{Integer Tip}\n",
    &data ,NULL))
    return IUP_DEFAULT;

  sprintf(ano, "%d", data);
  dataResposta = IupSetAttributes(IupLabel(ano), "FGCOLOR=\"#FFFFFF\", FONTSIZE=28, WEIGHT=BOLD");

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

  frame3 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("01")),
      IupVbox(IupLabel("02")),
      IupVbox(IupLabel("03")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame4= IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("04")),
      IupVbox(IupLabel("05")),
      IupVbox(IupLabel("06")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame5 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("07")),
      IupVbox(IupLabel("08")),
      IupVbox(IupLabel("09")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame6 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("10")),
      IupVbox(IupLabel("11")),
      IupVbox(IupLabel("12")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame7 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("13")),
      IupVbox(IupLabel("14")),
      IupVbox(IupLabel("15")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame8 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("16")),
      IupVbox(IupLabel("17")),
      IupVbox(IupLabel("18")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame9 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("19")),
      IupVbox(IupLabel("20")),
      IupVbox(IupLabel("21")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame10 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("22")),
      IupVbox(IupLabel("23")),
      IupVbox(IupLabel("24")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame11= IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("25")),
      IupVbox(IupLabel("26")),
      IupVbox(IupLabel("27")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame12 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("28")),
      IupVbox(IupLabel("29")),
      IupVbox(IupLabel("30")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame13 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("31")),
      IupVbox(IupLabel("32")),
      IupVbox(IupLabel("33")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame14 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("34")),
      IupVbox(IupLabel("35")),
      IupVbox(IupLabel("36")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame15 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("37")),
      IupVbox(IupLabel("38")),
      IupVbox(IupLabel("39")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");

  frame16 = IupSetAttributes(
    IupVbox(
      IupVbox(IupLabel("40")),
      IupVbox(IupLabel("41")),
      IupVbox(IupLabel("42")),
      NULL),
    "FGCOLOR=\"#FFFFFF\", FONTSIZE=30, GAP=20");





  coluna1 = IupVbox(
    frame1,
    frame2,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  coluna2 = IupVbox(
    IupSetAttributes(IupLabel("  d"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame3,
    frame4,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  coluna3 = IupVbox(
    IupSetAttributes(IupLabel("  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame5,
    frame6,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  coluna4 = IupVbox(
    IupSetAttributes(IupLabel("  t"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame7,
    frame8,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  coluna5 = IupVbox(
    IupSetAttributes(IupLabel("  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame9,
    frame10,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  coluna6 = IupVbox(
    IupSetAttributes(IupLabel("  q"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame11,
    frame12,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  coluna7 = IupVbox(
    IupSetAttributes(IupLabel("  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame13,
    frame14,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

  coluna8 = IupVbox(
    IupSetAttributes(IupLabel("  s"), "FGCOLOR=\"#075656\", FONTSIZE=30, ALIGNMENT=ACENTER"),
    frame15,
    frame16,
    NULL
  );
  IupSetAttributes(tudo, "ALIGNMENT=ACENTER");

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
  IupSetAttributes (dlg, "MARGIN=10x10, TITLE = \"Calendário\", SIZE=735x295, BGCOLOR=\"#272727\", ALIGNMENT=ACENTER");

  IupShowXY (dlg, IUP_CENTER, IUP_CENTER );

  IupMainLoop ();
  IupClose ();
  return EXIT_SUCCESS;
}
