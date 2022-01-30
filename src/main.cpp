#include "testconnectionmainwindow.h"

#include <QApplication>
#include <QtCore>

int main(int argc, char *argv[]) {
  QApplication a(argc, argv);
  QApplication::setOrganizationName("BMSTU");
  QApplication::setOrganizationDomain("bmstu.ru");

  QTranslator translator;
  translator.load("qt_en",
                  QLibraryInfo::location(QLibraryInfo::TranslationsPath));
  qApp->installTranslator(&translator);

  TestConnectionMainWindow w;
  w.show();
  return a.exec();
}
