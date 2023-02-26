// Kuko Framework - https://github.com/Rejcx/Kuko - Rachel J. Morris - MIT License
#ifndef _KUKO_LOGGER
#define _KUKO_LOGGER

#include <chrono>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

class Logger
{
    public:
    static void Setup( bool loud = false );
    static void Setup( int logLevel, const std::string& filter );
    static void Cleanup();
    static void SetLogLevel( int val );
    static void SetFilterWord( const std::string& filter );

    static void Out( const std::string& message, const std::string& location = "", const std::string& category = "", bool condition = true, int level = 0 );
    static void OutHighlight( const std::string& message, const std::string& location = "", int color = 1);
    static void Error( const std::string& message, const std::string& location = "" );

    static double GetTimestamp();
    static std::string GetFormattedTimestamp();

    private:
    static std::ofstream m_file;
    static time_t m_startTime;
    static time_t m_lastTimestamp;
    static int m_logLevel;
    static std::string m_categoryFilter;
    static int m_rowCount;
    static bool m_isLoud;
};

// Shortcut expressions for logger
#define LOG( msg ) dal::Logger::Out( msg );
#define LOGLOC( msg, loc ) dal::Logger::Out( msg, loc );
#define ERR( msg, loc ) dal::Logger::Error( msg, loc );


#endif

