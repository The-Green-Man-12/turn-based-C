#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
void battle(string& encounter, int& maxHealth, int& health, int& attack, int& defense);
void printStats(int& maxHealth, int& health, int& attack, int& defense, vector<string>& effects);
void introductions(string& encounter);
int printOptions();
void wait(int milliseconds);


int main() {
    srand(time(0));
    vector<string> possibleEncounters = {"Table", "Spider man", "The Green Man", "Knife"};
    int maxHealth = 100;
    int health = 100;
    int attack = 20;
    int defense = 0;
    int randomNum = rand() % possibleEncounters.size();
    string encounter = possibleEncounters[randomNum];
    cout << "You encountered a " << encounter << "!" << endl;
    wait(1000);
    battle(encounter, maxHealth, health, attack, defense);
    return 0;
}

void battle(string& encounter, int& maxHealth, int& health, int& attack, int& defense) {
    vector<string> currentEffects;
    int choice;
    cout << "Battle starts..." << endl;
    wait(1000);
    if (encounter == "Table") {
        introductions(encounter);
        printStats(maxHealth, health, attack, defense, currentEffects);
        choice = printOptions();

    } else if (encounter == "Spider man") {
        introductions(encounter);
        printStats(maxHealth, health, attack, defense, currentEffects);
        choice = printOptions();
    } else if (encounter == "The Green Man") {
        introductions(encounter);
        printStats(maxHealth, health, attack, defense, currentEffects);
        choice = printOptions();
    } else if (encounter == "Knife") {
        introductions(encounter);
        printStats(maxHealth, health, attack, defense, currentEffects);
        choice = printOptions();
    } else {
        cout << "Error: Encounter not recognized." << endl;
    }
}

int printOptions() {
    string input;
    cout << "Choose your action: " << endl;
    cout << "1. Attack" << endl;
    cout << "2. Act" << endl;
    cout << "3. Item" << endl;
    try {
        if (!getline(cin, input) || input.empty() || input == "\n") {
            throw invalid_argument("Invalid input");
        }
        int choice = stoi(input);
        if (choice < 1 || choice > 3) {
            throw out_of_range("Value out of range");
        }
        return choice;
    } catch (const invalid_argument& e) {
        cout << "Error: " << e.what() << endl;
        wait(2000);
        return 0;
    } catch (const out_of_range& e) {
        cout << "Error: " << e.what() << endl;
        wait(2000);
        return 0;
    }
}

void introductions(string& encounter) {
    if(encounter == "Table") {
        cout << "the ordinary table wasn't ordinary because table was not table" << endl;
        wait(1000);
        cout << "table" << endl;
        wait(1000);
    } else if (encounter == "Spider man") {
        cout << "Spider-Man hates you." << endl;
        wait(500);
        cout << "Why?" << endl;
        wait(1250);
        cout << "Idk" << endl;
        wait(1000);
    } else if (encounter == "The Green Man") {
        cout << "The Green Man doesn't like you." << endl;
        wait(1000);
        cout << "You are a purple person." << endl;
        wait(1000);
        cout << "Kratos verde" << endl;
        wait(1000);
    } else if (encounter == "Knife") {
        cout << "The tetanus knife is back again" << endl;
        wait(1000);
        cout << "yes its the one that makes you explode" << endl;
        wait(1000);
        cout << "or just tetanus" << endl;
        wait(1000);
        cout << "either way its bad" << endl;
        wait(2000);
    } else {
        cout << "Error: Encounter not recognized." << endl;
    }
}

void printStats(int& maxHealth, int& health, int& attack, int& defense, vector<string>& effects) {
    cout << "Player stats: " << endl;
    wait(250);
    cout << "Health: " << health << "/" << maxHealth << endl;
    wait(250);
    cout << "Attack: " << attack << endl;
    wait(250);
    cout << "Defense: " << defense << endl;
    wait(250);
    if (!effects.empty()) {
        cout << "Current effects: " << endl;
        for (string& effect : effects) {
            cout << "- " << effect << endl;
            wait(250);
        }
    }
    wait(1500);
}

void wait(int milliseconds) {
    //this_thread::sleep_for(chrono::milliseconds(milliseconds));
}