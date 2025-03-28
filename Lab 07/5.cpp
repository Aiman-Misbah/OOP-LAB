#include <iostream>
#include <string>
using namespace std;

class Character
{
protected:
    int characterID;
    string name;
    int level;
    int healthPoints;
    string weaponType;

public:
    Character(int id, string n, int lvl, int hp, string weapon = "")
        : characterID(id), name(n), level(lvl), healthPoints(hp), weaponType(weapon) {}

    virtual void attack()
    {
        cout << name << " attacks!" << endl;
    }

    virtual void defend()
    {
        cout << name << " defends!" << endl;
    }

    virtual void displayStats() const
    {
        cout << "Character ID: " << characterID << endl;
        cout << "Name: " << name << endl;
        cout << "Level: " << level << endl;
        cout << "Health Points: " << healthPoints << endl;
        if (!weaponType.empty())
        {
            cout << "Weapon: " << weaponType << endl;
        }
    }

    virtual ~Character() {}
};

class Warrior : public Character
{
private:
    int armorStrength;
    int meleeDamage;

public:
    Warrior(int id, string n, int lvl, int hp, string weapon, int armor, int damage)
        : Character(id, n, lvl, hp, weapon), armorStrength(armor), meleeDamage(damage) {}

    void attack() override
    {
        cout << name << " swings a powerful melee attack dealing " << meleeDamage << " damage!" << endl;
    }
};

class Mage : public Character
{
private:
    int manaPoints;
    int spellPower;

public:
    Mage(int id, string n, int lvl, int hp, int mana, int spell)
        : Character(id, n, lvl, hp), manaPoints(mana), spellPower(spell) {}

    void defend() override
    {
        cout << name << " conjures a magical barrier, reducing damage!" << endl;
    }
};

class Archer : public Character
{
private:
    int arrowCount;
    int rangedAccuracy;

public:
    Archer(int id, string n, int lvl, int hp, string weapon, int arrows, int accuracy)
        : Character(id, n, lvl, hp, weapon), arrowCount(arrows), rangedAccuracy(accuracy) {}

    void attack() override
    {
        cout << name << " fires an arrow with " << rangedAccuracy << "% accuracy!" << endl;
    }
};

class Rogue : public Character
{
private:
    int stealthLevel;
    int agility;

public:
    Rogue(int id, string n, int lvl, int hp, string weapon, int stealth, int agilityValue)
        : Character(id, n, lvl, hp, weapon), stealthLevel(stealth), agility(agilityValue) {}

    void displayStats() const override
    {
        Character::displayStats();
        cout << "Stealth Level: " << stealthLevel << endl;
        cout << "Agility: " << agility << endl;
    }
};

int main()
{
    Warrior warrior1(1, "Thor", 10, 150, "Hammer", 50, 40);
    Mage mage1(2, "Gandalf", 12, 120, 200, 90);
    Archer archer1(3, "Legolas", 11, 130, "Bow", 30, 85);
    Rogue rogue1(4, "Ezio", 9, 110, "Dagger", 80, 95);

    warrior1.attack();
    cout << endl;
    mage1.defend();
    cout << endl;
    archer1.attack();
    cout << endl;
    rogue1.displayStats();

    return 0;
}

