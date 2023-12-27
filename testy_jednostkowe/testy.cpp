#include "pch.h"

#include "../funkcje.cpp"
#include "../database.hpp"

DB db;

TEST(TworzeniePokoju, uztykownikNiezalogowany) {
	const std::string currentPlayer = "";
	const std::string roomName = "";
	const bool isPrivate = false;
	const int timePerPlayerInSeconds = 180;
	const int response = createNewRoom(db, currentPlayer, roomName, isPrivate, timePerPlayerInSeconds);
	EXPECT_EQ(-1, response);
}

TEST(TworzeniePokoju, uzytkownikZalogowany) {
	const std::string currentPlayer = "6ee40bcdg5463gh8sjs54sbvn7j";
	const std::string roomName = "ABCDE";
	const bool isPrivate = true;
	const int timePerPlayerInSeconds = 180;
	const int response = createNewRoom(db, currentPlayer, roomName, isPrivate, timePerPlayerInSeconds);
	EXPECT_LT(0, response);
	EXPECT_FALSE(db.getRoom(response).players[0].empty());
}

TEST(TworzeniePokoju, ZaKrotkaNazwaPokoju) {
	const std::string currentPlayer = "6ee40bcdg5463gh8sjs54sbvn7j";
	const std::string roomName = "A";
	const bool isPrivate = true;
	const int timePerPlayerInSeconds = 180;
	const int response = createNewRoom(db, currentPlayer, roomName, isPrivate, timePerPlayerInSeconds);
	EXPECT_EQ(-1, response);
}

TEST(TworzeniePokoju, ZaDlugaNazwaPokoju) {
	const std::string currentPlayer = "6ee40bcdg5463gh8sjs54sbvn7j";
	const std::string roomName = "gergjieogjergfwenw";
	const bool isPrivate = true;
	const int timePerPlayerInSeconds = 180;
	const int response = createNewRoom(db, currentPlayer, roomName, isPrivate, timePerPlayerInSeconds);
	EXPECT_EQ(-1, response);
}

TEST(TworzeniePokoju, ZaKrotkiCzasRozgrywki) {
	const std::string currentPlayer = "6ee40bcdg5463gh8sjs54sbvn7j";
	const std::string roomName = "ABCDE";
	const bool isPrivate = true;
	const int timePerPlayerInSeconds = 30;
	const int response = createNewRoom(db, currentPlayer, roomName, isPrivate, timePerPlayerInSeconds);
	EXPECT_EQ(-1, response);
}

TEST(TworzeniePokoju, ZaDlugiCzasRozgrywki) {
	const std::string currentPlayer = "6ee40bcdg5463gh8sjs54sbvn7j";
	const std::string roomName = "ABCDE";
	const bool isPrivate = true;
	const int timePerPlayerInSeconds = 60*90*100;
	const int response = createNewRoom(db, currentPlayer, roomName, isPrivate, timePerPlayerInSeconds);
	EXPECT_EQ(-1, response);
}
