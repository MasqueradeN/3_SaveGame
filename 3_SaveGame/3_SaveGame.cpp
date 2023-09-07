#include <iostream>
#include <fstream>

#define stringify( name ) #name

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
    unsigned int selecciones;
};

const char* convert_enum[] =
{
    stringify(manos),
    stringify(la espada),
    stringify(la lanza),
    stringify(el martillo),
    stringify(el arco)
};

void displayWeapon(EWeapon weapon)
{
    std::cout << convert_enum[weapon];
}

void Log(const char* msg)
{
    std::cout << msg << "\n";
}

void Escena1(sGameData saveData)
{
    std::fstream saveFile("data.sav", std::ios::in | std::ios::out);
    saveFile.open("data.sav", std::ios::out);
    if (saveFile.is_open())
    {
        sGameData data;
        saveFile.read(data.name, MAXNAMESIZE);
        data.currentWeapon = saveData.currentWeapon;
        data.enemiesKilled = saveData.enemiesKilled;
        data.selecciones = saveData.selecciones;
        int selección = 0;
        Log("De pronto, vez como sombras empiezan a emerger de todos lados");
        Log("Sorela: Esta ocurriendo?");
        Log("1. Atras, yo me encargo!");
        Log("2. Juntos podemos hacerlo");
        Log("3. Pero que rayos!?");
        Log("4. Nope, yo me voy de aqui");

        std::cin >> selección;
        if (selección == 1)
        {
            Log("Espera! Que haces?");
            Log("Vas a la carga con ");
            displayWeapon(data.currentWeapon);
            Log("\nLogras vencer a multiples sombras pero te ves rodeado por mas de ellas");
            Log("Pero Sorela llega enfureciada al combate y te ayuda");
            Log("Sorela: Porque hiciste eso? Quieres morir?");
            Log("Has sido salvado, pero siguen surgiendo mas enemigos, por lo que deciden retirarse de ahi");
            saveFile.close();
            saveFile.open("data.sav", std::ios::out);
            data.enemiesKilled += 25;
            if (saveFile.is_open())
            {
                saveFile.seekp(0, std::ios::beg);
                saveFile.write((const char*)&data, sizeof(sGameData));
                Log("Guardando master");
            }
        }
    }
}

void Escena2() 
{

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
        saveFile.read((char*)&data.selecciones, 4);
        std::cout << "Hola " << data.name << "\n";
        std::cout << "Tienes ";
        displayWeapon(data.currentWeapon);
        std::cout << " y has a matado a " << data.enemiesKilled << "\n";
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
            Log("3. Al menos ya llegamos");
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
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare la espada");
                    data.currentWeapon = sword;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);

                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                        saveFile.close();
                    }
                    Escena1(data);
                }
                if (seleccion == 2)
                {
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare la lanza");
                    data.currentWeapon = lance;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 3)
                {
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare el martillo");
                    data.currentWeapon = hammer;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 4)
                {
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare el arco");
                    data.currentWeapon = bow;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);
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
                Log("Sorela: Esperaba una mejor reacción, en verdad el lugar es hermoso\n");
                Log("Sorela: Y además mira, el guardia de las murallas me dio estas armas para poder salir a aventuras, ¿Qué amable no?");
                Log("Pues... Si supongo, a ver... Creo que...");
                Log("1. Espada");
                Log("2. Lanza");
                Log("3. Martillo");
                Log("4. Arco");
                
                std::cin >> seleccion;
                if (seleccion == 1)
                {
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare la espada");
                    data.currentWeapon = sword;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);

                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 2)
                {
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare la lanza");
                    data.currentWeapon = lance;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 3)
                {
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare el martillo");
                    data.currentWeapon = hammer;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
                if (seleccion == 4)
                {
                    saveFile.close();
                    saveFile.open("data.sav", std::ios::out);
                    Log("Tomare el arco");
                    data.currentWeapon = bow;
                    std::cout << "Tienes ";
                    displayWeapon(data.currentWeapon);
                    if (saveFile.is_open())
                    {
                        saveFile.seekp(0, std::ios::beg);
                        saveFile.write((const char*)&data, sizeof(sGameData));
                        Log("Guardando master");
                    }
                }
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
        data.selecciones = 0;

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