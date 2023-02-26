#include "Utilities.hpp"

// OUTPUT
void Menu::Header( const string& header )
{
    DrawHorizontalBar( 80 );
    string head = "| " + header + " |";
    cout << " " << head << endl << " ";
    DrawHorizontalBar( head.size() );
    cout << endl;
}

void Menu::DrawHorizontalBar( int width, char symbol )
{
    for ( int i = 0; i < width; i++ )
    {
        cout << symbol;
    }
    cout << endl;
}

// MENUS and INPUT/OUTPUT
void Menu::ShowMenu( const vector<string> options, bool vertical )
{
    if ( vertical )
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ".\t" << options[i] << endl;
        }
    }
    else
    {
        for ( unsigned int i = 0; i < options.size(); i++ )
        {
            cout << " " << (i+1) << ". " << options[i] << "\t";
        }
        cout << endl;
    }
}

int Menu::ShowIntMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    return choice;
}

string Menu::ShowStringMenuWithPrompt( const vector<string> options, bool vertical )
{
    ShowMenu( options, vertical );
    int choice = GetValidChoice( 1, options.size() );
    string value = options[ choice-1 ];
    return value;
}

int Menu::GetValidChoice( int min, int max, const string& message )
{
    if ( message != "" )
    {
        cout << endl;
        DrawHorizontalBar( message.size() + 2 );
        cout << " " << message << endl;
    }

    int choice = GetIntChoice();

    while ( choice < min || choice > max )
    {
        cout << "Invalid selection. Try again." << endl;
        choice = GetIntChoice();
    }

    return choice;
}

string Menu::GetStringChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }

    cout << endl << " >> ";
    string choice;
    cin >> choice;
    cin.ignore();
    cout << endl;
    return choice;
}

string Menu::GetStringLine( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    string choice;
    cout << endl << " >> ";
    getline( cin, choice );
    cout << endl;
    return choice;
}

int Menu::GetIntChoice( const string& message )
{
    if ( message != "" )
    {
        cout << " " << message << endl;
    }
    cout << endl << " >> ";
    int choice;
    cin >> choice;
    cin.ignore();
    cout << endl;
    return choice;
}

// HANDY TRICKS
void Menu::ClearScreen()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "cls" );
    #else
        system( "clear" );
    #endif
}

void Menu::Pause()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "pause" );
    #else
        cout << endl << " Press ENTER to continue..." << endl;
        cin.ignore( std::numeric_limits <std::streamsize> ::max(), '\n' );
    #endif
}

void Menu::PrintPwd()
{
    #if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
        system( "echo %cd%" );
    #else
        system( "pwd" );
    #endif
}


int StringUtil::StringToInt( const string& str )
{
    istringstream ss( str );
    int val;
    ss >> val;
    return val;
}

string StringUtil::ToUpper( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += toupper( val[i] );
    }
    return upper;
}

string StringUtil::ToLower( const string& val )
{
    string upper = "";
    for ( unsigned int i = 0; i < val.size(); i++ )
    {
        upper += tolower( val[i] );
    }
    return upper;
}

string StringUtil::ColumnText( int colWidth, const string& text )
{
    string adjusted = text;
    for ( int i = 0; i < colWidth - text.size(); i++ )
    {
        adjusted += " ";
    }
    return adjusted;
}


