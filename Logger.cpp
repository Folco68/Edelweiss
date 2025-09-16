#include "Logger.hpp"

Logger* Logger::logger = nullptr;

Logger::Logger()
{
    this->FirstEntry = true;
}

Logger* Logger::instance()
{
    if (logger == nullptr) {
        logger = new Logger;
    }
    return logger;
}

void Logger::release()
{
    if (logger != nullptr) {
        delete logger;
        logger = nullptr;
    }
}

void Logger::addEntry(QString entry)
{
    if (this->FirstEntry) {
        this->FirstEntry = false;
    }
    else {
        entry.prepend('\n');
    }

    this->Log.append(entry);
    emit entryAdded(entry);
}
