#include <iostream>
#include <vector>
#include <ctime>

using std::cout;
using std::cin;

class User {
    
};


class Room {
    private:
    int id;
    std::string name;
    User players[2];
    bool isPublic;
    bool isFull = false;
    
    public:
    void createNewRoom();
};

void Room::createNewRoom() {
    id = rand()%89999999 + 10000000;
    cout >> "Type room name: ";
    getline(cin, name);
    cout >> "Should the room be public or private? Type 'public' or 'private': ";
    std::string x;
    getline(cin, x);
    if (x == "public") {
        isPublic = true;
    }
    else if (x == "private") {
        isPublic = false;
    } else {
        cout << "Error!";
        return;
    }
    cout << "Created successfully. Room ID: " << id << "\n";
}


void displayAllRooms(const std::vector<Room> &rooms) {
    cout<<rooms.size()<<"\n";
}

int main() {
    
    srand(time(NULL));
    std::vector<Room> rooms;
    displayAllRooms(rooms);
    char x;
    cout << "\nType 'c' to create new room: \n";
    
    if (x = 'c') {
        Room room;
        room.createNewRoom();
        rooms.push_back(room);
    }
    displayAllRooms(rooms);

    return 0;
}
