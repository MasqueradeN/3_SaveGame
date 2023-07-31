#include <iostream>
#include <fstream>

#define MAXNAMESIZE 16

enum EWeapon 
{
    none, sword, lance, hammer, bow
};

struct sGameData
{
    char name[MAXNAMESIZE];
    EWeapon currentWeapon;
    unsigned int enemiesKilled;
};

void Log(const char* msg)
{
    std::cout << msg << "\n";
}

int main()
{          
    std::fstream saveFile("data.sav", std::ios::in | std::ios::out);
    if (saveFile.is_open())
    {
        Log("Abriendo Save File");
        sGameData data;
        saveFile.read(data.name, MAXNAMESIZE);
        saveFile.read((char*) &data.currentWeapon, 4);
        saveFile.read((char*) &data.enemiesKilled, 4);
        std::cout << "Hola " << data.name << "\n";
        std::cout << "Tienes " << data.currentWeapon << " y has a matado a " << data.enemiesKilled << "\n";
    }
    else
    {
        Log("Error en save file, crea un nuevo archivo");
        sGameData data;
        Log("Escribe tu nombre: ");
        std::cin >> data.name;
        data.currentWeapon = EWeapon::none;
        data.enemiesKilled = 0;

        saveFile.open("data.sav", std::ios::out);

        if (saveFile.is_open())
        {
            saveFile.seekp(0, std::ios::beg);
            saveFile.write((const char*) & data, sizeof(sGameData));
        }
        else
        {
            Log("no se puede crear el archivo loser");
        }
    }

    saveFile.close();

    return 0;
}