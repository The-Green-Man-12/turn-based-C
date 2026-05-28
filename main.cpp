#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
void battle(string& encounter, int& maxHealth, int& health, int& attack, int& defense);
void printStats(int& maxHealth, int& health, int& attack, int& defense);
void wait_ms(int milliseconds);


int main() {
    srand(time(0));
    vector<string> possibleEncounters = {"Dragon", "Giant spider", "Band of goblins", "Knife"};
    int maxHealth = 100;
    int health = 100;
    int attack = 20;
    int defense = 0;
    int randomNum = rand() % possibleEncounters.size();
    string encounter = possibleEncounters[randomNum];
    cout << "You encountered a " << encounter << "!" << endl;
    wait_ms(1000);
    battle(encounter, maxHealth, health, attack, defense);
    return 0;
}

void battle(string& encounter, int& maxHealth, int& health, int& attack, int& defense) {
    cout << "Battle starts..." << endl;
    wait_ms(1000);
    if (encounter == "Dragon") {
        cout << "B" << endl;
        printStats(maxHealth, health, attack, defense);
    } else if (encounter == "Giant spider") {
        cout << "You use your bow to shoot the giant spider!" << endl;
        printStats(maxHealth, health, attack, defense);
    } else if (encounter == "Band of goblins") {
        cout << "You cast a fireball spell to defeat the band of goblins!" << endl;
        printStats(maxHealth, health, attack, defense);
    } else if (encounter == "Knife") {
        cout << "You dodge the knife and counterattack!" << endl;
        printStats(maxHealth, health, attack, defense);
    } else {
        cout << "Error: Encounter not recognized." << endl;
    }
}

void printStats(int& maxHealth, int& health, int& attack, int& defense) {
    cout << "Player stats: " << endl;
    wait_ms(500);
    cout << "Health: " << health << "/" << maxHealth << endl;
    wait_ms(500);
    cout << "Attack: " << attack << endl;
    wait_ms(500);
    cout << "Defense: " << defense << endl;
    wait_ms(1000);
}

void wait_ms(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}