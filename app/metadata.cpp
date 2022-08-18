#include <iostream>
#include <fstream>
#include <conio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
using namespace std;

string exview = "https://drive.google.com/uc?export=view&id=";
char input_song[100];
char album_link[100];
char song_title[100];
char song_artist[100];
char song_album[100];
char song_genre[100];
char song_year[100];
char song_diff[100];
char yn;
int guitar, rhythm, bass, keys, drums;
string initial, title, artist;
string guitarl, rhythml, bassl, keysl, drumsl;
string preview_link, line_satu, line_tujuh, line_empat, line_delapan;
string download_link, line_duabelas, line_empatbelas, line_all;

void input_initial();
void input_thesong();
void link_album();
void metadata_input();
void diff_guitar();
void diff_rhythm();
void diff_bass();
void diff_keys();
void diff_drums();
void preview_input();
void download_input();
void sunsun();

int main()
{
    system("cls");
    cout << "=============== Program Input Metadata for Website ===============" << endl;
    input_initial();
    system("cls");
    cin.ignore();
    link_album();
    system("cls");
    cin.ignore();
    metadata_input();
    system("cls");
    diff_guitar();
    cout << "\n==============================================================\n"
         << endl;
    diff_rhythm();
    cout << "\n==============================================================\n"
         << endl;
    diff_bass();
    cout << "\n==============================================================\n"
         << endl;
    diff_keys();
    cout << "\n==============================================================\n"
         << endl;
    diff_drums();
    system("cls");
    preview_input();
    system("cls");
    download_input();
    system("cls");
    sunsun();

    // move line_all to MyFile
    string namefile = initial + ".txt";
    ofstream MyFile(namefile);
    MyFile << line_all;
    MyFile.close();

    int peleh;
reinput:
    cout << line_all;
    cout << endl;
    cout << "==============================================================" << endl;
    cout << "================ Metadata Input is Completed! ================" << endl;
    cout << "==============================================================" << endl;
    cout << "1. Open file" << endl;
    cout << "2. Input another metadata" << endl;
    cout << "3. Exit" << endl;
    cout << ">> ";
    cin >> peleh;
    if (peleh == 1)
    {
        system(("start " + namefile).c_str());
        system("cls");
        goto reinput;
    }
    else if (peleh == 2)
    {
        system("start metadata.exe");
        exit(0);
    }
    else if (peleh == 3)
    {
        cout << "Thank you for using this program!" << endl;
        Sleep(100);
    }
    else
    {
        cout << "Invalid input!" << endl;
        system("cls");
        goto reinput;
    }
    return 0;
}

void input_initial()
{

    cout << "Input initial: ";
    cin >> initial;

    line_satu = "<!-- Card " + initial + " -->";
}

void link_album()
{
    int pilih;
    cout << "Album Cover Link: " << endl;
    cout << "1. Embedded Link" << endl;
    cout << "2. Link to Embed" << endl;
    cout << ">> ";
    cin >> pilih;

    if (pilih == 1)
    {
        cout << "Input Link: ";
        string album_lin_embedded;
        cin >> album_lin_embedded;
        line_empat = "<img src=\"" + album_lin_embedded + "\" alt=\"chart_album\">";
    }
    else if (pilih == 2)
    {
        cin.ignore();
        cout << "Input Link: ";
        gets(album_link);

        string album_link_id;
        for (int i = 32; i <= 64; i++)
        {
            album_link_id += album_link[i];
        }

        line_empat = "<img src=\"" + exview + album_link_id + "\" alt=\"chart_album\">";
    }

    else
    {
        cout << "Invalid Input!" << endl;
        link_album();
    }
}

void metadata_input()
{
    cout << "Title \t\t: ";
    gets(song_title);
    cout << "Artist \t\t: ";
    gets(song_artist);
    cout << "Album \t\t: ";
    gets(song_album);
    cout << "Genre \t\t: ";
    gets(song_genre);
    cout << "Year \t\t: ";
    gets(song_year);
    cout << "Difficulty \t: ";
    gets(song_diff);
    // convert song_title to string
    title = song_title;
    // convert song_artist to string
    artist = song_artist;
    // convert song_album to string
    string album = song_album;
    // convert song_genre to string
    string genre = song_genre;
    // convert song_year to string
    string year = song_year;
    // convert song_diff to string
    string diff = song_diff;

    //<p>🎵 title<br>🗣️ artist<br>💿 album<br>&nbsp;⚧&ensp;genre<br>📅 year<br>💥 difficulty</p>
    line_delapan = "<p>🎵 " + title + "<br>🗣️ " + artist + "<br>💿 " + album + "<br>&nbsp;⚧&ensp;" + genre + "<br>📅 " + year + "<br>💥 " + diff + "</p>";
}

void diff_guitar()
{
    cout << "Add Lead Guitar Difficulty? (y/n) : ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        cout << "Lead Guitar Difficulty : ";
        cin >> guitar;
        switch (guitar)
        {
        case 1:
            guitarl = "https://drive.google.com/uc?export=view&id=1GX-Yj0_ow0r8pEve9jds53hmht9W-4Lt";
            break;
        case 2:
            guitarl = "https://drive.google.com/uc?export=view&id=1GbEdqecJov6uL4zSHNfqQldBM9uT1ddb";
            break;
        case 3:
            guitarl = "https://drive.google.com/uc?export=view&id=1ZOUDUNPLO09ZVpXx2w-kdvvqL58Sue-3";
            break;
        case 4:
            guitarl = "https://drive.google.com/uc?export=view&id=1NRuSvwYFHa13aB43hsGOGKC378sX2qu2";
            break;
        case 5:
            guitarl = "https://drive.google.com/uc?export=view&id=1Xf837zoJEJEG1zkiElWZPr6_wBk0qaCM";
            break;
        case 6:
            guitarl = "https://drive.google.com/uc?export=view&id=1RURUFUI4EF7vKLn7Kfd0UNdozl6GQmst";
            break;
        }
    }
    else if (yn == 'n' || yn == 'N')
    {
        guitarl = "#";
    }
    else
    {
        cout << "Wrong input!" << endl;
        diff_guitar();
    }
}

void diff_rhythm()
{
    cout << "Add Rhythm Difficulty? (y/n) : ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        cout << "Rhythm Difficulty : ";
        cin >> rhythm;
        switch (rhythm)
        {
        case 1:
            rhythml = "https://drive.google.com/uc?export=view&id=1nT4WjyFOOdiLW2ehOpgSjTnoxEC4OwU8";
            break;
        case 2:
            rhythml = "https://drive.google.com/uc?export=view&id=1R-XK7vZqns9LsNQ9fzQrf1xQZ8drBsHD";
            break;
        case 3:
            rhythml = "https://drive.google.com/uc?export=view&id=1o39xotA7UnvKKgPFQQJQLkqN2Ux6_gJU";
            break;
        case 4:
            rhythml = "https://drive.google.com/uc?export=view&id=1Kp-lHh-VmMxRPfwRbpwYkRpVK45wzHdy";
            break;
        case 5:
            rhythml = "https://drive.google.com/uc?export=view&id=1AqsDoDXq-riTt_3unea4lVS0LGTjq2Qs";
            break;
        case 6:
            rhythml = "https://drive.google.com/uc?export=view&id=1eByssqa7NJEXDrYo8EqT9WwGZIdUo44n";
            break;
        }
    }
    else if (yn == 'n' || yn == 'N')
    {
        rhythml = "#";
    }
    else
    {
        cout << "Wrong input!" << endl;
        diff_rhythm();
    }
}

void diff_bass()
{
    cout << "Add Bass Difficulty? (y/n) : ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        cout << "Bass Difficulty : ";
        cin >> bass;
        switch (bass)
        {
        case 1:
            bassl = "#";
            break;
        case 2:
            bassl = "#";
            break;
        case 3:
            bassl = "#";
            break;
        case 4:
            bassl = "#";
            break;
        case 5:
            bassl = "#";
            break;
        case 6:
            bassl = "#";
            break;
        }
    }
    else if (yn == 'n' || yn == 'N')
    {
        bassl = "#";
    }
    else
    {
        cout << "Wrong input!" << endl;
        diff_bass();
    }
}

void diff_keys()
{
    cout << "Add Keys Difficulty? (y/n) : ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        cout << "Keys Difficulty : ";
        cin >> keys;
        switch (keys)
        {
        case 1:
            keysl = "https://drive.google.com/uc?export=view&id=1UphjgjharXnYc4hn7KDWOM_JFojR4ETe";
            break;
        case 2:
            keysl = "https://drive.google.com/uc?export=view&id=1yFfsJVyrJLcx2CsfeCizvJ7oFbXcXOFb";
            break;
        case 3:
            keysl = "https://drive.google.com/uc?export=view&id=1uSHUMzTDvu4nWWL68AnQa1Q_LHuMGZx8";
            break;
        case 4:
            keysl = "https://drive.google.com/uc?export=view&id=1Bllu6Jsl2XLsOAgZK8ymrrPHo84Cczzp";
            break;
        case 5:
            keysl = "https://drive.google.com/uc?export=view&id=1GqHgSImvZB8SVdlmhaQNefhSVqMG_mPA";
            break;
        case 6:
            keysl = "https://drive.google.com/uc?export=view&id=1yD6PMpPzhIs5krOfKCdOw3JxeHn5Rnnu";
            break;
        }
    }
    else if (yn == 'n' || yn == 'N')
    {
        keysl = "#";
    }
    else
    {
        cout << "Wrong input!" << endl;
        diff_keys();
    }
}

void diff_drums()
{
    cout << "Add Drums Difficulty? (y/n) : ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        cout << "drums Difficulty : ";
        cin >> drums;
        switch (drums)
        {
        case 1:
            drumsl = "https://drive.google.com/uc?export=view&id=1s8PZwULMKaM6iCCIj9fljTGMAglQZa97";
            break;
        case 2:
            drumsl = "https://drive.google.com/uc?export=view&id=1kF0qgu5Gg8vtYIPTcm9ZMtvxz1ripk6X";
            break;
        case 3:
            drumsl = "https://drive.google.com/uc?export=view&id=1U2o1bJZlDgNGIzQWH4W9GiJ6hkDbYU59";
            break;
        case 4:
            drumsl = "https://drive.google.com/uc?export=view&id=1F-HDeHF24RsDVYOh2RUH8hRd0-wprR6c";
            break;
        case 5:
            drumsl = "https://drive.google.com/uc?export=view&id=1hVOBfc3kvBd1QC3jrvX7W_8tyx2Y49R0";
            break;
        case 6:
            drumsl = "https://drive.google.com/uc?export=view&id=1dc7_0BLYRSCCPhwWYBVvMBmZ5jGM4Dn1";
            break;
        }
    }
    else if (yn == 'n' || yn == 'N')
    {
        drumsl = "#";
    }
    else
    {
        cout << "Wrong input!" << endl;
        diff_drums();
    }
}

void preview_input()
{
    cout << "Add Preview Button? (y/n) : ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        cout << "Preview Link : ";
        cin.ignore();
        cin >> preview_link;
    }
    else if (yn == 'n' || yn == 'N')
    {
        preview_link = "#";
    }
    else
    {
        cout << "Wrong input!" << endl;
        preview_input();
    }
    line_duabelas = "<a href=\"" + preview_link + "\" target=\"_blank\"><button class=\"db buttong\">Preview</button></a>";
}

void download_input()
{
    cout << "Add Download Button? (y/n) : ";
    cin >> yn;
    if (yn == 'y' || yn == 'Y')
    {
        cout << "Download Link : ";
        cin.ignore();
        cin >> download_link;
    }
    else if (yn == 'n' || yn == 'N')
    {
        download_link = "#";
    }
    else
    {
        cout << "Wrong input!" << endl;
        download_input();
    }
    line_empatbelas = "<a href = \"" + download_link + "\" target = \"_blank\"><button class = \"db buttong\"> Download</button></a><br>";
}

void sunsun()
{

    string temp_guitar, temp_rhythm, temp_bass, temp_keys, temp_drums;
    if (guitarl != "#")
    {
        temp_guitar = "<img src=\"" + guitarl + "\" style=\"width:10%\">";
    }
    else if (guitarl == "#")
    {
        temp_guitar = "";
    }
    if (rhythml != "#")
    {
        temp_rhythm = "<img src=\"" + rhythml + "\" style=\"width:10%\">";
    }
    else if (rhythml == "#")
    {
        temp_rhythm = "";
    }
    if (bassl != "#")
    {
        temp_bass = "<img src=\"" + bassl + "\"style=\"width:10%\">";
    }
    else if (bassl == "#")
    {
        temp_bass = "";
    }
    if (keysl != "#")
    {
        temp_keys = "<img src=\"" + keysl + "\"style=\"width:10%\">";
    }
    else if (keysl == "#")
    {
        temp_keys = "";
    }
    if (drumsl != "#")
    {
        temp_drums = "<img src=\"" + drumsl + "\"style=\"width:10%\">";
    }
    else if (drumsl == "#")
    {
        temp_drums = "";
    }
    string temp_diff = temp_guitar + temp_rhythm + temp_bass + temp_keys + temp_drums;

    string temp_preview, temp_download;
    if (preview_link != "#")
    {
        temp_preview = "<a href=\"" + preview_link + "\" target=\"_blank\"><button class=\"db buttong\">Preview</button></a>";
    }
    else if (preview_link == "#")
    {
        temp_preview = "";
    }
    if (download_link != "#")
    {
        temp_download = "<a href = \"" + download_link + "\" target = \"_blank\"><button class = \"db buttong\"> Download</button></a><br>";
    }
    else if (download_link == "#")
    {
        temp_download = "";
    }
    // convert input_song to string
    string song = artist + " - " + title;

    line_tujuh = "<h5>" + song + "</h5>";

    string line1 = line_satu;
    string line2 = "<div class=\"card\">";
    string line3 = "\t<!-- album -->";
    string line4 = "\t<div class=\"almeg\">";
    string line5 = "\t\t" + line_empat;
    string line6 = "\t</div>";
    string line7 = "\t<!-- metadata -->";
    string line8 = "\t" + line_tujuh;
    string line9 = "\t" + line_delapan;
    string line10 = "\t<!-- diff icon -->";
    string line11 = "\t<div class=\"diffmg\">";
    string line12 = "\t\t" + temp_diff;
    string line13 = "\t</div>";
    string line14 = "\t<!-- preview & download -->";
    string line15 = "\t" + line_duabelas;
    string line16 = "\t" + line_empatbelas;
    string line17 = "</div>";

    line_all = line1 + "\n" + line2 + "\n" + line3 + "\n" + line4 + "\n" + line5 + "\n" + line6 + "\n" + line7 + "\n" + line8 + "\n" + line9 + "\n" + line10 + "\n" + line11 + "\n" + line12 + "\n" + line13 + "\n" + line14 + "\n" + line15 + "\n" + line16 + "\n" + line17;
}