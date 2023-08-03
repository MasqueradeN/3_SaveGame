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
    unsigned int seleccion;
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
        saveFile.read((char*)&data.seleccion, 4);
        std::cout << "Hola " << data.name << "\n";
        std::cout << "Tienes " << data.currentWeapon << " y has a matado a " << data.enemiesKilled << "\n";
        int seleccion = 0;
        Log("Presiona 1 para iniciar un nuevo juego. Presiona 2 para continuar\n");
        std::cin >> seleccion;
        if (seleccion == 1)
        {
            Log("Iniciando Juego\n");
            int seleccion = 0;
            Log("Estas llegando a tu nuevo hogar, la maravillosa ciudad de Novprism");
            Log("1. Que lugar tan majestuoso");
            Log("2. Asi que aqui es? Esta bien");
            Log("3. Al menos ya llegue");
            Log("4. Me hubiera quedado en mi casa anterior...");
            std::cin >> seleccion;
            if (seleccion == 1)
            {
                Log("Sorela: Verdad? Me alegra estar aqui porfin. Una nueva aventura esta a punto de comenzar\n");
                Log("Sorela: Por cierto, el guardia de las murallas me dio estas armas. Deberias elegir una, yo guardare las demas para despues: ");
                Log("1. Espada");
                Log("2. Lanza");
                Log("3. Martillo");
                Log("4. Arco");
                std::cin >> seleccion;
                if (seleccion == 1)
                {
                    Log("Tomare la espada");
                    data.currentWeapon = sword;
                    std::cout << "Tienes " << data.currentWeapon << "\n";
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 2)
                {
                    Log("Tomare la lanza");
                    data.currentWeapon = lance;
                    std::cout << "Tienes " << data.currentWeapon << "\n";
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 3)
                {
                    Log("Tomare el martillo");
                    data.currentWeapon = hammer;
                    std::cout << "Tienes " << data.currentWeapon << "\n";
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 4)
                {
                    Log("Tomare el arco");
                    data.currentWeapon = bow;
                    std::cout << "Tienes " << data.currentWeapon << "\n";
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
            }
            else if (seleccion == 2)
            {
                
            }

            if (saveFile.is_open())
            {
                saveFile.seekp(0, std::ios::beg);
                saveFile.write((const char*)&data, sizeof(sGameData));
                Log("Guardando master");
            }
            else
            {
                Log("no se puede crear el archivo loser");
            }
            saveFile.close();
        }
        else if (seleccion == 2)
        {

        }
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