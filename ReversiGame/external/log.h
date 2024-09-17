#ifndef LOG_H
#define LOG_H

#include <iostream>
#include <time.h>
#include <string>
#include <fstream>

using namespace std;

enum typelog {
    DEBUG,
    INFO,
    WARN,
    ERROR
};

struct structlog {
    structlog(){
        ofstream clearFile;
        clearFile.open("logs.log", ios::out | ios::trunc);
    };
    typelog level = WARN;
    string filePath = "";
    bool headers = false;
    bool ENABLE = false;
};

extern structlog LOGCFG;

class LOG {
public:
    LOG() {}
    LOG(typelog type) {
        if (LOGCFG.ENABLE) {
            msglevel = type;
            outfile.open("logs.log", ios::out | ios::app);
            if(LOGCFG.headers) 
                outfile << (currentDateTime() +" ["+getLabel(type)+"] ");
        }
    }
    ~LOG() {
        if(opened) {
            outfile << endl;
            outfile.close();
        }
        opened = false;
    }
    template<class T>
    LOG &operator<<(const T &msg) {
        if(msglevel >= LOGCFG.level && LOGCFG.ENABLE) {
            //cout << msg;
            outfile << msg;
            opened = true;
        }
        return *this;
    }
private:
    bool opened = false;
    //bool openFile = false;
    typelog msglevel = DEBUG;
    ofstream outfile;
    inline string getLabel(typelog type) {
        string label;
        switch(type) {
            case DEBUG: label = "DEBUG"; break;
            case INFO:  label = "INFO"; break;
            case WARN:  label = "WARN"; break;
            case ERROR: label = "ERROR"; break;
        }
        return label;
    }
    inline const std::string currentDateTime() {
        time_t     now = time(0);
        struct tm  tstruct;
        char       buf[80];
        tstruct = *localtime(&now);
        strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);
        return buf;
    };
};

#endif  /* LOG_H */