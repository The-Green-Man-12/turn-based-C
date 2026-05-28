#include <iostream>
#include <vector>
#include <string>
#include <thread>
#include <chrono>
#include <cstdlib>
#include <ctime>
using namespace std;
bool battle(string& encounter, int& maxHealth, int& health, int& attack, int& defense);
void printStats(int& maxHealth, int& health, int& attack, int& defense, vector<string>& effects, vector<int>& enemyStats);
void enemyAttacks(string& encounter, int& health, int& attack, int& defense, vector<int>& enemyStats);
int findIndex(vector<string>& v, string val);
vector<int> introductions(string& encounter);
int printOptions(vector<string>& options);
void wait(int milliseconds);


int main() {
    srand(time(0));
    vector<string> possibleEncounters = {"Table", "Spider man", "The Green Man", "Knife"};
    int maxHealth = 100;
    int health = 100;
    int attack = 20;
    int defense = 0;
    //int randomNum = rand() % possibleEncounters.size();
    int randomNum = 0;
    string encounter = possibleEncounters[randomNum];
    cout << "You encountered a " << encounter << "!" << endl;
    wait(1000);
    bool enemyDead = battle(encounter, maxHealth, health, attack, defense);
    if(enemyDead) {
        cout << "Good job :) you beat table..." << endl;
        wait(500);
        cout << "Im so proud of you, the table gets what he deserves" << endl;
        wait(1000);
    } else {
        cout << "Why table win >:(" << endl;
    }
    cout << "I would say fight your next enemy but there is no next enemy :(" << endl;
    wait(2000);
    cout << "There was only table." << endl;
    wait(2000);
    cout << "Thank you for playing tho!" << endl;
    wait(500);
    return 0;
}

bool battle(string& encounter, int& maxHealth, int& health, int& attack, int& defense) {
    bool dead = false;
    vector<string> currentEffects;
    vector<string> options = {"Attack", "Act", "Item"};
    int choice;
    int damage;
    cout << "Battle starts..." << endl;
    wait(1000);
    if (encounter == "Table") {
        vector<int> enemyStats = introductions(encounter);
        vector<string> attackOptions = {"Hit the table with your fist", "Kick the table"};
        vector<string> actOptions = {"Burn the table with a lighter", "Give the table a wedgie"};
        vector<string> itemOptions = {"Screwdriver", "The Green Orb of satisfaction and happiness and everything the best", "The Red Orb of sadness and depression and everything bad", "Knife (Equip)"};
        do {
            if(health <= 0) {
                cout << "You died :(" << endl;
                wait(500);
                cout << "The table wins :(" << endl;
                wait(2000);
                cout << "Why did you let him win?" << endl;
                wait(500);
                cout << "Tables don't win" << endl;
                wait(1000);
                cout << "THEY LOSE, DONT LOSE THEY LOSE" << endl;
                wait(2000);
                return false;
                break;
            }
            if(enemyStats[0] <= 0) {
                cout << "The table is destroyed :)" << endl;
                wait(500);
                cout << "HURRAY" << endl;
                wait(1000);
                return true;
                break;
            }
            if(enemyStats[3] > 0) { //Fire damage haha
                enemyStats[0] -= (2 * enemyStats[3]);
            }
            printStats(maxHealth, health, attack, defense, currentEffects, enemyStats);
            choice = printOptions(options);
            if(choice == 1) {
                cout << "How do you want to attack the table?" << endl;
                int attack = printOptions(attackOptions);
                if(attack == 1) {
                    damage = 10;
                    enemyStats[0] -= (damage + attack);
                    cout << "You hit the table with your fist!" << endl;
                    wait(1000);
                    cout << "You deal " << (damage + attack) << " damage to the table." << endl;
                    wait(1000);
                } else if(attack == 2) {
                    health -= 3;
                    damage = 5;
                    enemyStats[0] -= (damage + attack);
                    cout << "You kick the table!" << endl;
                    wait(1000);
                    cout << "You deal " << (damage + attack) << " damage to the table." << endl;
                    wait(1000);
                    cout << "But you also stub your toe :(" << endl;
                    wait(1000);
                } else {
                    cout << "Invalid attack choice." << endl;
                    wait(1000);
                }
                enemyAttacks(encounter, health, attack, defense, enemyStats);
            } else if (choice == 2) {
                cout << "What do you want to act?" << endl;
                int act = printOptions(actOptions);
                if(act == 1) {
                    cout << "burn burn table you burn burn" << endl;
                    wait(1000);
                    damage = 5;
                    enemyStats[3] += 1;
                    cout << "You deal " << (damage + attack) << " damage to the table." << endl;
                    wait(500);
                    cout << "And now table be fire, fire fire haha fire yes fire" << endl;
                    wait(1000);
                } else if(act == 2) {
                    cout << "He gets big ahhh wedgie. Not effective cus table is table :(" << endl;
                    cout << "You deal NOTHING to the table because you are stupid for trying that >:(" << endl;
                    wait(1000);
                } else {
                    cout << "Invalid act choice." << endl;
                    wait(1000);
                }
                enemyAttacks(encounter, health, attack, defense, enemyStats);
            } else if(choice == 3) {
                cout << "What item do you want to use?" << endl;
                int item = printOptions(itemOptions);
                if(item == 1) {
                    cout << "You use the screwdriver to unscrew the table!" << endl;
                    wait(1000);
                    damage = 15;
                    enemyStats[0] -= (damage + attack);
                    cout << "You deal " << (damage + attack) << " damage to the table." << endl;
                    wait(1000);
                } else if(item == 4) {
                    int tmp = findIndex(itemOptions, "Knife (Equip)");
                    if(tmp != -1) {
                        cout << "You equip the knife" << endl;
                        attack += 10;
                        itemOptions.erase(itemOptions.begin() + tmp);
                    } else {
                        cout << "Oh but wait, NO YOU DON'T, YOU HAVE NO KNIFE." << endl; //Shoudln't be printed
                    }
                    wait(1000);
                } else if(item == 2) {
                    cout << "You use the Green Orb of satisfaction and happiness and everything the best on the table!" << endl;
                    wait(1000);
                    damage = 5;
                    enemyStats[3] += 5;
                    cout << "You deal " << damage << " damage to the table." << endl;
                    wait(500);
                    cout << "You give the fire the BURNNNNN AHHHH" << endl;
                    wait(1000);
                } else if(item == 3) {
                    cout << "You use the Red Orb of sadness and depression and everything bad on the table!" << endl;
                    wait(1000);
                    health -= 20;
                    cout << "The orb hates you since its the sadness orb >:(" << endl;
                    wait(500);
                    cout << "And just cus he's red and hates you, you take 20 damage :(" << endl;
                    wait(2000);
                } else {
                    cout << "Invalid item choice." << endl;
                    wait(1000);
                }
                enemyAttacks(encounter, health, attack, defense, enemyStats);
            }
        } while(dead == false);
        return false;
    } else if (encounter == "Spider man") {
        vector<int> enemyStats = introductions(encounter);
        introductions(encounter);
        printStats(maxHealth, health, attack, defense, currentEffects, enemyStats);
        choice = printOptions(options);
    } else if (encounter == "The Green Man") {
        vector<int> enemyStats = introductions(encounter);
        introductions(encounter);
        printStats(maxHealth, health, attack, defense, currentEffects, enemyStats);
        choice = printOptions(options);
    } else if (encounter == "Knife") {
        vector<int> enemyStats = introductions(encounter);
        introductions(encounter);
        printStats(maxHealth, health, attack, defense, currentEffects, enemyStats);
        choice = printOptions(options);
    } else {
        cout << "Error: Encounter not recognized." << endl;
    }
}

int printOptions(vector<string>& options) {
    string input;
    cout << "Choose your action: " << endl;
    for (int i = 0; i < options.size(); i++) {
        cout << i + 1 << ". " << options[i] << endl;
    }
    try {
        if (!getline(cin, input) || input.empty() || input == "\n") {
            throw invalid_argument("Invalid input");
        }
        int choice = stoi(input);
        if (choice < 1 || choice > options.size()) {
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

void enemyAttacks(string& encounter, int& health, int& attack, int& defense, vector<int>& enemyStats) {

    if (encounter == "Table") {
        vector<string> possibleAttacks = {"The table hits you with its leg!", "The table hits you with its surface!", "The table hits you with its edge!"};
        int randomNum = rand() % possibleAttacks.size();
        if(randomNum == 0) {
            cout << possibleAttacks[randomNum] << endl;
            wait(1000);
            int damage = 5;
            health -= (damage + enemyStats[2]) - defense;
            cout << "You take " << (damage + enemyStats[2]) - defense << " damage." << endl;
            wait(1000);
        } else if(randomNum == 1) {
            cout << possibleAttacks[randomNum] << endl;
            wait(1000);
            int damage = 3;
            health -= (damage + enemyStats[2]) - defense;
            cout << "You take " << (damage + enemyStats[2]) - defense << " damage." << endl;
            wait(1000);
        } else if(randomNum == 2) {
            cout << possibleAttacks[randomNum] << endl;
            wait(1000);
            int damage = 10;
            health -= (damage + enemyStats[2]) - defense;
            cout << "You take " << (damage + enemyStats[2]) - defense << " damage." << endl;
            wait(1000);
        }



    } else if (encounter == "Spider man") {
        cout << "The Spider-Man hits you with its web!" << endl;
        wait(1000);
        int damage = 15;
        health -= damage;
        cout << "You take " << damage << " damage." << endl;
        wait(1000);
    } else if (encounter == "The Green Man") {
        cout << "The Green Man hits you with its club!" << endl;
        wait(1000);
        int damage = 20;
        health -= damage;
        cout << "You take " << damage << " damage." << endl;
        wait(1000);
    } else if (encounter == "Knife") {
        cout << "The Knife hits you with its blade!" << endl;
        wait(1000);
        int damage = 25;
        health -= damage;
        cout << "You take " << damage << " damage." << endl;
        wait(1000);
    }
}

vector<int> introductions(string& encounter) {
    vector<int> stats;
    if(encounter == "Table") {
        stats = {100, 5, 0, 0, 0};
        cout << "the ordinary table wasn't ordinary because table was not table" << endl;
        wait(2000);
        cout << "table" << endl;
        wait(1500);
    } else if (encounter == "Spider man") {
        stats = {100, 5, 20 , 0, 0};
        cout << "Spider-Man hates you." << endl;
        wait(500);
        cout << "Why?" << endl;
        wait(1250);
        cout << "Idk" << endl;
        wait(1000);
    } else if (encounter == "The Green Man") {
        stats = {100, 5, 20, 0, 0};
        cout << "The Green Man doesn't like you." << endl;
        wait(1000);
        cout << "You are a purple person." << endl;
        wait(1000);
        cout << "Kratos verde" << endl;
        wait(1000);
    } else if (encounter == "Knife") {
        stats = {100, 5, 20, 0, 0};
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
    return stats;
}

void printStats(int& maxHealth, int& health, int& attack, int& defense, vector<string>& effects, vector<int>& enemyStats) {
    cout << "Enemy stats: " << endl;
    wait(250);
    cout << "Health: " << enemyStats[0] << endl;
    wait(250);
    cout << "Defense: " << enemyStats[2] << endl;
    wait(500);
    cout << "Fire level: " << enemyStats[3] << endl;
    wait(250);
    cout << "\n-----------------------------\n" << endl;
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
    wait(1250);
}

int findIndex(vector<string>& v, string val) {
    int count = 0;
    for(auto itr = v.begin(); itr != v.end(); ++itr) {
      
        if (*itr == val) { //If the restaurant is found, the index is returned
            return count;
        }
        count += 1;
    }
  	
  	return -1; //If the restaurant is not found, -1 is returned
}

void wait(int milliseconds) {
    this_thread::sleep_for(chrono::milliseconds(milliseconds));
}