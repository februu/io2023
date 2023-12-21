#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include "database.hpp"

std::string login(DB &db)
{
    std::string nickname;
    std::string password;
    std::string id;

    do
    {
        std::cout << "Podaj login: (użyj test) \n> ";
        std::cin >> nickname;
        std::cout << "Podaj haslo: (użyj test)\n> ";
        std::cin >> password;
        id = db.login(nickname, password);
    } while (id == "");
    return id;
}

// Creates new room.
int createNewRoom(DB db, std::string currentPlayer, std::string roomName, bool isPrivate, int timePerPlayerInSeconds)
{

    // Check if player is logged in.
    if (currentPlayer == "")
        login(db);

    if (roomName == "" || roomName.length() < 3 || roomName.length() > 8)
        return -1;

    if (timePerPlayerInSeconds < 60 || timePerPlayerInSeconds > 60 * 90)
        return -1;

    int roomId = db.createRoom(roomName, timePerPlayerInSeconds, isPrivate);
    db.getRoom(roomId).players[0] = currentPlayer;
    return roomId;
}

int main()
{

    srand(time(NULL));

    // Initialize DB.
    DB db;
    db.connect();

    std::string currentPlayer = login(db);

    // Creates new room.
    //createNewRoom(db, currentPlayer);

    // Disconnect from DB.
    db.disconnect();

    return 0;
}