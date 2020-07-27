#include "principal.h"
#include <QApplication>
#include <QTranslator>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator T;
    QStringList langs;
    langs << "Español" << "Portugues" << "English" << "Japonés";
    const QString lang = QInputDialog::getItem(NULL,
                                               "Idioma",
                                               "Seleccione un idioma",
                                               langs);
    if (lang == "Portugués"){
        T.load(":/portugues.qm");
    }else if (lang == "English"){
        T.load(":/ingles.qm");
    }else if (lang == "Japonés"){
        T.load(":/japones.qm");
}
    if (lang != "Español"){
        a.installTranslator(&T);
    }
    a.setStyle("fusion");
    Principal w;
    w.show();
    return a.exec();
}
