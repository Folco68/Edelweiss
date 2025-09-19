#ifndef LOGGER_HPP
#define LOGGER_HPP

#include <QObject>
#include <QString>

class Logger: public QObject
{
    Q_OBJECT

  public:
    static Logger* instance();
    static void    release();
    void           addEntry(QString entry);
    void           appendEntry(QString entry);

  private:
    static Logger* logger;
    Logger();
    bool    FirstEntry;
    QString Log;

  signals:
    void entryAdded(QString entry);
};

#endif //LOGGER_HPP
