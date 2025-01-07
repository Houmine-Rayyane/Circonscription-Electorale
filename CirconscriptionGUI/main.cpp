/*
 * File:   main.cpp
 * Author: Rayyane Houmine & Hassan Alaoui
 *
 * Created on 3 décembre 2024, 00 h 49
 */

#include <QApplication>
#include "PersonneGUI.h"

int
main (int argc, char *argv[])
{
  // initialize resources, if needed
  // Q_INIT_RESOURCE(resfile);

  QApplication app (argc, argv);

  // create and show your widgets here
  
  PersonneGUI FenetrePrincipale;
  FenetrePrincipale.show();

  return app.exec ();
}
