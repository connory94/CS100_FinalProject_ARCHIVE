#include "../combatHeader/cplayer.h"
#include <iostream>
using namespace std;

cPlayer::cPlayer(string name,int hp, int maxhp, int atk, int def, int spd, int magicAtk, vector<int> unlockedIndices)
    : Character(name, maxhp, atk, def, spd, magicAtk), allSkills(),
      unlockedIndices(unlockedIndices) {

        changeHp(hp - maxhp);

    // references these indices when deciding what the player has unlocked
    allSkills = {                                                                   //indices
        { "Strike",     1.0f,0.2f, "You swing your weapon at the enemy.",              1 }, // 0
        { "Heal",       0.0f, 0.0f, "You bandage your wounds, recovering some HP.",    1 }, // 1   could be changed later if items are for healing
        { "Power Tackle", 1.5f, 0.0f, "You forgo defense and slam the enemy!",         1 }, // 2
        { "Warm up",    0.0f, 0.0f, "Relax and increase your attack and speed.",       1 }, // 3
        { "War Cry",    0.0f, 0.0f, "You let out a fierce cry, improving attack!", 1 }, // 4
        // append new skills here, please dont reorder! remember to update useSkillEffect with the new skill's effects and index
        { "Flame Spark",      0.0f, 1.4f, "You spark a flame at the enemy's position.",      1 }, // 5
        { "Ice Shard",   0.0f, 1.7f, "You fire ice at the enemy, decreasing their speed.", 1 }, // 6
        { "Recall Wisdom", 0.0f, 0.0f, "You ponder, improving your magic but reducing your speed.", 1 }, // 7
        { "Reinforce", 0.0f, 0.0f, "You reinforce your armor, massively increasing your defense but lowering your speed.", 1 }, // 8
        { "All-out Blitz", 2.7f, 0.0f, "You use all your energy and strike, with a higher crit chance but lowering your defense!", 1 }, // 9
        { "Knight's Precision", 1.7f, 0.0f, "You use your knightly skills to strike and expose weaknesses in the enemy.", 1 }, // 10
        { "Armored Tackle", 2.6f, 0.0f, "You rush at the enemy, dealing heavy damage but taking rebound damage.", 1 }, // 11
        { "Pinnacle of Magic", 0.0f, 3.5f, "The ultimate spell. Leaves you vulnerable.", 1 }, // 12
        { "The Peak of Swordsmanship", 3.5f, 0.0f, "The culmination of sword training. Leaves you vulnerable.", 1 }, // 13
        { "The Greatest Offense...", 1.5f, 0.0f, "...is a good defense. Use your defense to strike, but leaves you vulnerable.", 1 }, // 14
        { "Desperate Measures", 3.0f, 0.0f, "The more HP you are missing, the stronger this attack becomes. Has a higher crit chance below 50% HP. Leaves you vulnerable.", 1 }, // 15
        { "Sabotage", 0.0f, 0.0f, "You sabotage the enemy, lowering their speed, attack and defense.", 1 }, // 16
        { "Brute Force", 2.2f, 0.0f, "You use your strength to bypass defenses and deal extra fixed damage.", 1 }, // 17
        { "Knight's Dance", 1.5f, 0.0f, "You dance with your blade and strike at the enemy, increasing your attack and defense.", 1 }, // 18
        { "Arcane Drain", 0.0f, 2.0f, "You drain the enemy's magic, dealing damage and lowering their magic while increasing your health.", 1 }, // 19
        { "Knight's Strength", 2.4f, 0.0f, "You bash your opponent, dealing heavy damage and dazing your opponent, reducing their damage dealt and speed.", 1 }, // 20
        { "Retreating Rush", 1.6f, 0.0f, "You quickly lash out, then recover some health based on your speed and improve your defense.", 1 }, // 21
        { "Arcane Surge", 0.0f, 2.5f, "You unleash a surge of arcane energy, dealing damage and greatly increasing your magic attack.", 1 }, // 22
    };
}

vector<Skill> cPlayer::getUnlockedSkills() const {
    vector<Skill> result;
    for (int i : unlockedIndices)
        result.push_back(allSkills.at(i));
    return result;
}

// database of all unlockable skills and their effects
void cPlayer::useSkillEffect(int index, Character& user, Character& opponent) {
    int skillIndex = unlockedIndices.at(index);
    const Skill& skill = allSkills.at(skillIndex);
    cout << skill.description << endl;

    switch (skillIndex) {
        case 0: // Strike
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 1: // Heal
        {
            int healAmount = user.getMaxHealth() / 4;
            user.changeHp(healAmount);
            cout << user.getName() << " recovered " << healAmount << " HP!" << endl;
            break;
        }
        case 2: // Power Tackle
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            if (user.getDefense() > 2) {
                user.changeDef(-1);
                cout << user.getName() << "'s defense fell by 1!" << endl;
            }
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 3: // Warmup
        {
            user.changeAtk(2);
            user.changeSpd(1);
            cout << user.getName() << "'s attack rose by 2!" << endl;
            cout << user.getName() << "'s speed rose by 1!" << endl;
            
            break;
        }
        case 4: // War Cry
        {
            user.changeAtk(3);
            cout << user.getName() << "'s attack rose by 3!" << endl;
            break;
        }
        case 5: // Flame Spark
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 6: // Ice Shard
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            opponent.changeSpd(-1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << opponent.getName() << "'s speed fell by 1!" << endl;
            break;
        }
        case 7: // Recall Wisdom
        {
            user.changeMagicAtk(3);
            user.changeSpd(-1);
            cout << user.getName() << "'s magic rose by 3!" << endl;
            cout << user.getName() << "'s speed fell by 1!" << endl;
            break;
        }
        case 8: // Reinforce
        {
            user.changeDef(6);
            user.changeSpd(-2);
            cout << user.getName() << "'s defense rose by 6!" << endl;
            cout << user.getName() << "'s speed fell by 2!" << endl;
            break;
        }
        case 9: // All-out Blitz
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            damage = Character::rollCritical(damage);
            damage = Character::rollCritical(damage); // higher crit chance by rolling crit multiple times
            opponent.changeHp(-damage);
            user.changeDef(-2);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s defense fell by 2!" << endl;
            break;
        }
        case 10: // Knight's Precision
        {
            opponent.changeDef(-1);
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            cout << opponent.getName() << "'s defense fell by 1!" << endl;
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 11: // Armored Tackle
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            int rebound = damage / 4;
            user.changeHp(-rebound);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << " took " << rebound << " rebound damage!" << endl;
            break;
        }
        case 12: // Pinnacle of Magic
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeSpd(-2);
            user.changeDef(-2);
            user.changeMagicAtk(-1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s speed fell by 2!" << endl;
            cout << user.getName() << "'s defense fell by 2!" << endl;
            cout << user.getName() << "'s magic attack fell by 1!" << endl;
            break;
        }
        case 13: // Pinnacle of Swordsmanship
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeSpd(-2);
            user.changeDef(-2);
            user.changeAtk(-1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s speed fell by 2!" << endl;
            cout << user.getName() << "'s defense fell by 2!" << endl;
            cout << user.getName() << "'s attack fell by 1!" << endl;
            break;
        }
        case 14: // The Greatest Offense...
        {
            int selfDef = user.getDefense();
            int damage = Character::calculateDamage(user, skill, opponent);
            damage += selfDef * 2;
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeSpd(-2);
            user.changeDef(-2);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s speed fell by 2!" << endl;
            cout << user.getName() << "'s defense fell by 2!" << endl;
            break;
        }
        case 15: // Desperate Measures
        {
            int missingHp = user.getMaxHealth() - user.getHealth();
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = (int)(damage * (1.0f + (float)missingHp / user.getMaxHealth())); // more missing HP increases damage
            damage = Character::rollCritical(damage);
            if (user.getHealth() < user.getMaxHealth() / 2) {
                damage = Character::rollCritical(damage);
                damage = Character::rollCritical(damage); // higher crit chance if below 50% HP
            }
            opponent.changeHp(-damage);
            user.changeDef(-3);
            user.changeAtk(-1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s defense fell by 3!" << endl;
            cout << user.getName() << "'s attack fell by 1!" << endl;
            break;
        }
        case 16: // Sabotage
        {
            opponent.changeSpd(-2);
            opponent.changeDef(-2);
            opponent.changeAtk(-1);
            cout << opponent.getName() << "'s speed fell by 2!" << endl;
            cout << opponent.getName() << "'s defense fell by 2!" << endl;
            cout << opponent.getName() << "'s attack fell by 1!" << endl;
            break;
        }
        case 17: // Brute Force
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            damage = damage + 5; // fixed extra damage
            opponent.changeHp(-damage);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            break;
        }
        case 18: // Knight's Dance
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeAtk(2);
            user.changeDef(1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s attack rose by 2!" << endl;
            cout << user.getName() << "'s defense rose by 1!" << endl;
            break;
        }
        case 19: // Arcane Drain
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            opponent.changeMagicAtk(-2);
            user.changeHp(damage / 2); // heal for half the damage dealt
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << opponent.getName() << "'s magic attack fell by 2!" << endl;
            cout << user.getName() << " recovered " << damage / 2 << " HP!" << endl;
            break;
        }
        case 20: // Knight's Strength
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            opponent.changeAtk(-1);
            opponent.changeSpd(-1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << opponent.getName() << "'s attack fell by 1!" << endl;
            cout << opponent.getName() << "'s speed fell by 1!" << endl;
            break;
        }
        case 21: // Retreating Rush
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            int healAmount = user.getSpeed() / 2;
            user.changeHp(healAmount);
            user.changeDef(1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << " recovered " << healAmount << " HP!" << endl;
            cout << user.getName() << "'s defense rose by 1!" << endl;
            break;
        }
        case 22: // Arcane Surge
        {
            int damage = Character::calculateDamage(user, skill, opponent);
            damage = Character::rollCritical(damage);
            opponent.changeHp(-damage);
            user.changeMagicAtk(1);
            cout << opponent.getName() << " took " << damage << " damage!" << endl;
            cout << user.getName() << "'s magic attack rose by 1!" << endl;
            break;
        }
        default:
            cout << user.getName() << " used " << skill.name
                 << ", but nothing happened!" << endl;
            break;
    }
}