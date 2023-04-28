#include <QRegExp>
#include <QtPlugin>

#include "regexpplugin.h"

QString RegExpPlugin::regexp(const QString& message)
{
    QRegExp rx("\\d+");
    rx.indexIn(message);
    QString str = rx.cap(0);
    return str;
}
