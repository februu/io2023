#include <iostream>
#include <vector>
#include <string>
#include <stdexcept>

#pragma once

// Player object imitation
struct Player
{
    std::string id;
    std::string nickname;
    std::string password;
    int rating;
};

// Room object imitation
struct Room
{
    int id;
    std::string name;
    std::string players[2];
    int timePerPlayer = 60;;
    bool isPrivate = false;
    bool hasStarted = false;
};

// Imitation of database.
class DB
{
private:
    std::vector<Room> rooms;
    std::vector<Player> players = {{"6ee40bcdg5463gh8sjs54sbvn7j", "test", "test", 1320}};

public:
    void connect()
    {
        std::cout << "Connected to database.\n =================================\n";
        printRooms();
    }
    void disconnect()
    {
        std::cout << "Disconnected from database.\n =================================\n";
        printRooms();
    }

    std::vector<Room> getRooms()
    {
        return rooms;
    }

    std::string login(std::string login, std::string password)
    {
        for (auto &player : players)
            if (player.nickname == login)
                if (player.password == password)
                    return player.id;
        return "";
    }

    Room &getRoom(int id)
    {
        for (auto &room : rooms)
            if (room.id == id)
                return room;
        throw std::out_of_range("No room with this id exists.");
    }

    Player &getPlayer(std::string id)
    {
        for (auto &player : players)
            if (player.id == id)
                return player;
        throw std::out_of_range("No player with this id exists.");
    }

    // Creates new room. Returns its id.
    int createRoom(std::string name, int timePerPlayer, bool isPrivate)
    {
        Room room;
        room.id = rand() % 100000 + 899999;
        room.isPrivate = isPrivate;
        room.timePerPlayer = timePerPlayer;
        room.hasStarted = false;
        room.name = name;
        rooms.push_back(room);
        return room.id;
    }

    void printRooms()
    {
        std::cout << "ID"
                  << "\t\t"
                  << "NAME"
                  << "\t\t"
                  << "PRIVATE"
                  << "\t\t"
                  << "TIME"
                  << "\t\t"
                  << "STARTED"
                  << "\t\t"
                  << "PLAYER1"
                  << "\t\t"
                  << "PLAYER2"
                  << "\n";
        for (auto &room : rooms)
            std::cout << room.id << "\t\t" << room.name << "\t\t" << room.isPrivate << "\t\t" << room.timePerPlayer << "\t\t" << room.hasStarted << "\t\t" << room.players[0] << "\t\t" << room.players[1] << "\n";
        std::cout << "\n";
    }
};