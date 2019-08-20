#include <iostream>
#include <string>
#include <fstream>
#define _WIN32_WINNT 0x0500
#include <windows.h>
#include <cstdlib>
using namespace std;

class WebsiteLink{
    int choices;

public:
    void add_website_link();
    void menu();
    void PlaceCursor(const int x, const int y);
};

void WebsiteLink::menu(){

    cout << "WEBSITE BOOKMARKING SYSTEM" << "\n\n\n";
    int i = 0;
    do{
        cout << "\t\t\t1 - ADD A WEBSITE LINK" << endl;
        cout << "\t\t\t2 - MODIFY A WEBSITE LINK" << endl;
        cout << "\t\t\t3 - DELETE A WEBSITE LINK" << endl;
        cout << "\t\t\t4 - CLEAR ALL" << endl;
        cout << "\t\t\t5 - EXIT" << endl << endl;

        cout << "\t\t\tSelect from 1 - 5: ";
        cin >> choices;
        cout << endl;

        switch(choices){
        case 1:
            add_website_link();
            cout << endl << "\t\t\tLink Added" << "\n\n";
            cout << "\t\t----------------------------------------------" << endl << endl;
            break;
        case 2:
            cout << "Link Modified" << endl;
            break;
        case 3:
            cout << "Link Deleted" << endl;
            break;
        case 4:
            cout << "Links Cleared" << endl;
            break;
        case 5:
            cout << "Exiting System..." << endl;
            exit(0);
            break;
        default:
            cout << "No commands available..." << endl;
        }
        i++;
    }while(i < 15);
    PlaceCursor(25,3);
}

void WebsiteLink::add_website_link(){
    string link;
    cout << "\t\t\tType a link: ";

    ofstream linkFile;
    linkFile.open("website-links.txt", ios::app);

    cin >> link;

    linkFile << "https://" << link  << "/" << endl;
    linkFile.close();

}

void WebsiteLink::PlaceCursor(const int x, const int y){
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD PlaceCursorHere;
    PlaceCursorHere.X = x;
    PlaceCursorHere.Y = y;

    SetConsoleCursorPosition(hConsole, PlaceCursorHere);
    return;
}


void SetWindow(int Width, int Height){
    _COORD coord;
    coord.X = Width;
    coord.Y = Height;

    _SMALL_RECT Rect;
    Rect.Top = 0;
    Rect.Left = 0;
    Rect.Bottom = Height - 1;
    Rect.Right = Width - 1;

    HANDLE Handle = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleScreenBufferSize(Handle, coord);
    SetConsoleWindowInfo(Handle, TRUE, &Rect);
}

int main(){
    SetWindow(100, 50);
    WebsiteLink wblkObj;
    wblkObj.PlaceCursor(24,3);
    wblkObj.menu();
    return 0;
}

























