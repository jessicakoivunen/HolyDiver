/******************************************************/
// Holy diver - an epic adventure at object-oriented world way beneath the surface!
/******************************************************/
#include <list>
#include <fstream>
#include <iostream>
#include <istream>
#include <stdlib.h>

using namespace std;

#include "gameobject.h"
#include "light.h"
#include "player.h"
#include "map.h"
#include "movingenemy.h"
#include "objects.h"
#include "level.h"

class Level1 : public Level {
private:
    MovingEnemy enemy1 = MovingEnemy(11, 12);

public:

    Level1() {
        player = Player(7, 14);
        map = Map("level_1.txt");
        light = Light(map);
        max_treasure = 3;
        enemies.push_back(enemy1);
        level = 1;
        map.AddCoord(enemy1.getPosX(), enemy1.getPosY(), enemy1.getName());
        map.AddCoord(player.getPosX(), player.getPosY(), player.getName());
        light.AddCoord(player.getPosX(), player.getPosY(), map);
    }

    void Reset() {
        player = Player(7, 14);
        map = Map("level_1.txt");
        light = Light(map);
        enemy1 = MovingEnemy(11, 12);
        o.ResetTreasure();
        map.AddCoord(player.getPosX(), player.getPosY(), player.getName());
        light.AddCoord(player.getPosX(), player.getPosY(), map);
        map.AddCoord(enemy1.getPosX(), enemy1.getPosY(), enemy1.getName());
    }

    ~Level1() {
        map.FreeMemory();
        light.FreeMemory();
        map.~Map();
        light.~Light();
        enemy1.~MovingEnemy();
    }
};

class Level2 : public Level {
private:
    MovingEnemy enemy1 = MovingEnemy(15, 15);
    MovingEnemy enemy2 = MovingEnemy(9, 6);

public:

    Level2() {
        player = Player(9, 9);
        map = Map("level_2.txt");
        light = Light(map);
        max_treasure = 4;
        enemies.push_back(enemy1);
        enemies.push_back(enemy2);
        level = 2;
        for (MovingEnemy e : enemies)
        {
            map.AddCoord(e.getPosX(), e.getPosY(), e.getName());
        }
        map.AddCoord(player.getPosX(), player.getPosY(), player.getName());
        light.AddCoord(player.getPosX(), player.getPosY(), map);
    }

    void Reset(){
        player = Player(9, 9);
        map = Map("level_2.txt");
        light = Light(map);
        enemy1 = MovingEnemy(15, 15);
        enemy2 = MovingEnemy(9, 6);
        o.ResetTreasure();
        map.AddCoord(player.getPosX(), player.getPosY(), player.getName());
        light.AddCoord(player.getPosX(), player.getPosY(), map);
        for (MovingEnemy e : enemies)
        {
            map.AddCoord(e.getPosX(), e.getPosY(), e.getName());
        }
    }

    ~Level2() {
        map.FreeMemory();
        light.FreeMemory();
        player.~Player();
        map.~Map();
        light.~Light();
        o.~Objects();
        enemy1.~MovingEnemy();
        enemy2.~MovingEnemy();
    }
};

class Level3 : public Level {
private:
    MovingEnemy enemy1 = MovingEnemy(13, 6);
    MovingEnemy enemy2 = MovingEnemy(18, 11);
    MovingEnemy enemy3 = MovingEnemy(2, 15);

public:

    Level3() {
        player = Player(9, 9);
        map = Map("level_3.txt");
        light = Light(map);
        max_treasure = 6;
        enemies.push_back(enemy1);
        enemies.push_back(enemy2);
        enemies.push_back(enemy3);
        level = 3;
        for (MovingEnemy e : enemies)
        {
            map.AddCoord(e.getPosX(), e.getPosY(), e.getName());
        }
        map.AddCoord(player.getPosX(), player.getPosY(), player.getName());
        light.AddCoord(player.getPosX(), player.getPosY(), map);
    }

    void Reset(){
        player = Player(9, 9);
        map = Map("level_3.txt");
        light = Light(map);
        enemy1 = MovingEnemy(13, 6);
        enemy2 = MovingEnemy(18, 11);
        enemy3 = MovingEnemy(2, 15);
        o.ResetTreasure();
        map.AddCoord(player.getPosX(), player.getPosY(), player.getName());
        light.AddCoord(player.getPosX(), player.getPosY(), map);
        for (MovingEnemy e : enemies)
        {
            map.AddCoord(e.getPosX(), e.getPosY(), e.getName());
        }
    }

    ~Level3() {
        map.FreeMemory();
        light.FreeMemory();
        player.~Player();
        map.~Map();
        light.~Light();
        o.~Objects();
        enemy1.~MovingEnemy();
        enemy2.~MovingEnemy();
        enemy3.~MovingEnemy();
    }
};

class HallOfFame {
private:
    string filepath = "scorefile.txt";
    ofstream scoreFile;
public:

    int WriteScore(string name, int score, int max) {
        scoreFile.open(filepath, ios_base::app);

        if (!scoreFile.is_open()) {
            cout << "Score file error";
            return -1;
        }
        string save = name + "          " + to_string(score) + " / " + to_string(max) + "\n";
        scoreFile << save;
        scoreFile.close();
        return 0;
    }

    int ReadScores() {
        ifstream scoreFile(filepath);
        string scores;
        //check if opened
        if (!scoreFile.is_open()) {
            //if open failure, return value indicating error			
            cout << "Error opening score file.\n\n";
            return -1;
        }
        while (getline(scoreFile, scores)) {
            // Output text from file
            cout << scores << endl;
        }
        // Close file
        scoreFile.close();
        return 0;
    }
};

class PrintStuff {
public:
    void Title() {
        cout << "********************************************\n"
             << "*                HOLY DIVER                *\n"
             << "*                   2.1                    *\n"
             << "********************************************\n\n";
    }
    void Stats(Level& l0) {
        cout << "*****************************************************************\n";
        cout << "*  HEALTH: " << l0.player.getHealth() << "   OXYGEN: " << l0.player.getOxygen() << "   BATTERY: "
            << l0.light.getBattery() << "   TREASURE: " << l0.o.getTreasure() << " / " << l0.max_treasure << "    * \n";
        cout << "*****************************************************************\n\n";
    }
    void MenuOptions() {
        cout << "[1] START GAME\n"
            << "[2] HALL OF FAME\n"
            << "[3] HOW TO PLAY\n"
            << "[4] STORY\n"
            << "[5] QUIT\n\n";
    }
    void Story() {
        cout << "*** STORY ***\n\n";
        cout << "You are an intrepid diver searching for treasure in the dangerous waters of "
            << "the Bermuda triangle. Deep within the void of the ocean lies unknown threats"
            << " The battery of your diving bell's light is always dying. Though, the "
            << "lack of oxygen or the deep-sea creatures might kill you before that"
            << " even happens.\nFortunately, a support vessel is waiting at the surface "
            << "to aid in a safe return at the end of the day - or in an emergency, at a cost.\n\n";
    }
    void Help() {
        cout << "*** HOW TO PLAY ***\n\n"
            << "The map first consists of '*' characters and a 'P' -the player. "
            << "Move through the map or use the light to reveal more of it. "
            << "You can't move into coordinates with 'x', 'o' is free space, 'T' is treasure, "
            << "'M' is an enemy, 'B' is a battery and 'O' is oxygen.";
        cout << "Try to find all of the level's treasures to move to the next level. When you have "
            << "at least 50% of the treasures you can resurface and continue to the next level. You can"
            << " also restart any level at any point even after death but will lose all progress in "
            << "that level.\n\n";
        cout << "*** CONTROLS ***\n\n"
            << "WASD - move\n"
            << "IJKL - light\n"
            << "R - restart level\n"
            << "U - resurface\n"
            << "H - help\n"
            << "Q - quit\n\n";
    }
    void LevelHeader(Level& l0) {
        cout << "********************************************\n"
            << "*                  LEVEL " << l0.level << "                 * \n"
            << "********************************************\n\n";
    }
    void Win(int t, int max) {
        cout << "********************************************\n"
            << "                  YOU WON!                  \n\n"
            << "            Treasure found: " << t << " / " << max << "\n"
            << "********************************************\n\n"
            << "Enter name for the hall of fame: ";
    }
    void WinOptions() {
        cout << "[M]  MAIN MENU\n"
            << "[H]  HALL OF FAME\n"
            << "[Q]  QUIT\n\n";
    }
    void HallFame(HallOfFame& h) {
        cout << "********************\n"
            << "*** HALL OF FAME ***\n\n"
            << "NAME         SCORE\n";
        h.ReadScores();
        cout << "\n\n";
    }
};

class Game {
private:
    PrintStuff print;
    HallOfFame fame;
    Level1 l1;
    Level2 l2;
    Level3 l3;

    int maxs_treasure = 13;
    int s_treasure = 0;
    int curr_level = 0;
    int last_level = 3;
    char input = ' ';
    string name = " ";

    void CheckInteractions(Level& l0) {
        // is there something in next coord. ?
        // if yes --> do something

        if (l0.map.getMap()[l0.player.nextY(input)][l0.player.nextX(input)] == 'M') {
            //take damage
            l0.player.TakeDamage(l0.o.GiveDamage());
            cout << "Enemy! You take " << l0.o.GiveDamage() << " damage.\n\n";
        }
        else if (l0.map.getMap()[l0.player.nextY(input)][l0.player.nextX(input)] == 'T') {
            //get treasure
            l0.o.AddTreasure();
            cout << "You found treasure!\n\n";
        }
        else if (l0.map.getMap()[l0.player.nextY(input)][l0.player.nextX(input)] == 'B') {
            //get battery
            l0.light.ChangeBattery(l0.o.RestoreBattery());
            cout << "You found battery! " << l0.o.RestoreBattery() << " battery restored!\n\n";
        }
        else if (l0.map.getMap()[l0.player.nextY(input)][l0.player.nextX(input)] == 'O') {
            //get oxygen
            l0.player.ChangeOxygenLevel(l0.o.RestoreOxygen());
            cout << "You found oxygen! " << l0.o.RestoreOxygen() << " oxygen restored!\n\n";
        }
    }

    void HandleGameInputs(Level& l0) {

        if (input == 'w' || input == 'a' || input == 's' || input == 'd' ||
            input == 'W' || input == 'A' || input == 'S' || input == 'D') {
            if (l0.player.CanMove(input, l0.map)) {
                //can move --> interact --> move
                CheckInteractions(l0);
                l0.player.Move(input, l0.map, l0.light);
            }
            //can't move --> light coordinate
            else l0.light.AddCoord(l0.player.nextX(input), l0.player.nextY(input), l0.map);
        }
        else if (input == 'i' || input == 'j' || input == 'k' || input == 'l' ||
                 input == 'I' || input == 'J' || input == 'K' || input == 'L') {
            l0.light.LightArea(input, l0.player, l0.map);
        }
        else if (input == 'r' || input == 'R') {
            //restart level
            l0.Reset();
        }
        else if (input == 'u' || input == 'U') {
            //surface if 50% < treasure
            Surface(l0);
        }
        else if (input == 'h' || input == 'H') {
            print.Help();
        }
        else if (input == 'q' || input == 'Q') {
            //quit
            Quit();
        }
        else {
            cout << "Invalid input.\n";
        }
    }

    void HandleDeadInputs(Level& l0) {
        while (input != 'q' && input != 'Q' && input != 'r' && input != 'R') {
            cout << "You died. What next?\n"
                << "R - Restart\n"
                << "Q - Quit\n";
            cin.get(input);
            if (input == 'r' || input == 'R') {
                //restart level
                l0.Reset();
            }
            else if (input == 'q' || input == 'Q') {
                //quit
                Quit();
            }
            else cout << "Invalid input.\n";
        }
    }

    void HandleMenuInputs() {
        print.Title();
        while (input != '1') {
            print.MenuOptions();
            cin >> input;
            if (input == '2') print.HallFame(fame);
            else if (input == '3') print.Help();
            else if (input == '4') print.Story();
            else if (input == '5') Quit();
            else cout << "Invalid input.\n\n";
            cin.clear();
        }
    }

    void HandleWinInputs() {
        while (input != 'M' && input != 'm') {
            print.WinOptions();
            cin >> input;
            if (input == 'H' || input == 'h') print.HallFame(fame);
            else if (input == 'Q' || input == 'q') Quit();
            else cout << "Invalid input.\n\n";
            cin.clear();
        }
    }

    void Hall() {
        cin.clear();
        print.Win(s_treasure, maxs_treasure);
        cin >> name;
        fame.WriteScore(name, s_treasure, maxs_treasure);
        cin.clear();
    }

    void MoveEnemies(Level& l0) {
        for (MovingEnemy& e : l0.enemies)
        {
            e.Move(l0.map);
        }
    }

    void Surface(Level& l0) {
        if (l0.o.getTreasure() >= l0.max_treasure * 0.5) {
            s_treasure += l0.o.getTreasure();
            curr_level++;
            if (curr_level == last_level) {
                //hall of fame
                Hall();
            }
        }
    }

    void Quit() {
        //destroy objects + free memory
        l1.~Level1();
        l2.~Level2();
        l3.~Level3();
        print.~PrintStuff();
        //exit program
        exit(0);
    }

    void CheckStatus(Level& l0) {
        //oxygen low -> reduce health
        if (l0.player.getOxygen() < 50) {
            l0.player.TakeDamage(1);
        }
        //dead?
        if (l0.player.IsDead()) {
            HandleDeadInputs(l0);
        }
        //all treasure??
        if (l0.o.getTreasure() == l0.max_treasure) {
            s_treasure += l0.o.getTreasure();
            curr_level++;
            //last level???
            if (curr_level == last_level) {
                //hall of fame
                Hall();
            }
        }
    }

    void CoreLoop(Level& l0) {

        print.LevelHeader(l0);

        while (l0.level > curr_level) {
            // Print map + stats
            l0.light.PrintMap();
            print.Stats(l0);
            // Move enemies
            MoveEnemies(l0);
            // Get player input
            cout << "Your turn: ";            
            cin >> input;
            HandleGameInputs(l0);
            // Check status
            CheckStatus(l0);
            // Clear input
            cin.clear();
        }
    }

    void ResetAll() {
        l1.Reset();
        l2.Reset();
        l3.Reset();
        curr_level = 0;
        s_treasure = 0;
    }

public:

    int GameLoop() {

        while (input != 'q' && input != 'Q') {
            //menu
            HandleMenuInputs();
            //level 1
            CoreLoop(l1);
            //level 2
            CoreLoop(l2);
            //level 3
            CoreLoop(l3);
            //win
            HandleWinInputs();
            //reset levels
            ResetAll();
        }
        Quit();
        return 0;
    }
};



int main()
{
    Game game;
    game.GameLoop();
    game.~Game();

    return 0;
}