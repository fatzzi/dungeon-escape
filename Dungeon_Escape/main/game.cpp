#include "../header/Dungeon.h"
#include "../header/Player.h"
#include "../header/Room.h"
#include "../header/Challenge.h"
#include "../header/Enemy.h"
#include "../header/Treasure.h"
#include "../header/Dungeon.h"
#include <iostream>
using namespace std;

void showInstructions() {
    cout << "\n📜 HOW TO PLAY 📜\n";
    cout << "1️⃣ Your goal is to escape the dungeon.\n";
    cout << "2️⃣ You start with a limited number of moves.\n";
    cout << "3️⃣ Each room may contain:\n";
    cout << "   - Enemies to fight ⚔️\n";
    cout << "   - Challenges to solve 🧠\n";
    cout << "   - Treasures to collect 💎\n";
    cout << "4️⃣ Moving forward or backward decreases moves.\n";
    cout << "5️⃣ If your health reaches 0 or you run out of moves, you lose.\n";
    cout << "6️⃣ Answer challenges correctly to avoid penalties.\n";
    cout << "7️⃣ Defeat all enemies in a room before proceeding.\n";
    cout << "8️⃣ Reach the final room to escape and win the game! 🎉\n\n";
}

int main() {
    Dungeon dungeon;
    cout<<"whats your name? Only one word, you are not worthy yet."<<endl;
    string name;
    cin>>name;
    Player player(name);
    cout<<"welcome "<< name<<endl;

    int choice;
    cout << "🏰 WELCOME TO DUNGEON ESCAPE 🏰\n";

    showInstructions();
    cout<<"All caught up?\n lets start!!"<<endl;
    cout<<"✨ ✨ ✨ ✨ ✨"<<endl;

    // 🔹 Creating Rooms
    Room* room1 = new Room("white party", Challenge("what liquid is highest in demand here?", "baby oil"), Treasure("rocket launcher"));
    Room* room2 = new Room("beef", Challenge("tryna strike a chord and its probably?", "a minor"), Treasure("pen"));
    Room* room3 = new Room("bikini bottom", Challenge("who lives in a pineapple under the sea?", "spongebob squarepants"), Treasure("crabby patties"));
    Room* room4 = new Room("avengers tower", Challenge("What is the full form of S.H.I.E.L.D?", "Strategic Homeland Intervention, Enforcement and Logistics Division"), Treasure("power stone"));
    Room* room5 = new Room("pakistan-final destination", Challenge("what is the easiest way to steal a man's wallet?", "tell him you are going to steal his watch"), Treasure(""));

    //Adding Enemies
    room1->addEnemy(Enemy("diddy", 30 , 10));
    room1->addEnemy(Enemy("beyonce", 30 , 10));
    room2->addEnemy(Enemy("kanye west", 15, 16));
    room3->addEnemy(Enemy("squidward", 25, 10));
    room3->addEnemy(Enemy("mr crabs", 25, 20));
    room4->addEnemy(Enemy("loki", 25, 15));
    room5->addEnemy(Enemy("baba bandook", 25, 40)); // Added a final boss

    // Linking Rooms
    dungeon.addRoom(room1);
    dungeon.addRoom(room2);
    dungeon.addRoom(room3);
    dungeon.addRoom(room4);
    dungeon.addRoom(room5);

    

    //Manually trigger first room events and push it onto the stack
    dungeon.getRoomStack().push(room1);  
    room1->triggerRoomEvents(player);

    bool running = true;
    while (running && player.isAlive() && player.getMoves() > 0 && !dungeon.isEscaped()) {
        dungeon.displayCurrentRoom();
        cout << "\n💡 Choose an action:\n";
        cout << "1. Move Forward\n2. Move Backward\n3. Check Inventory\n4. Quit Game\n> ";
        
        int choice;       
        cin >> choice;

        switch (choice) {
            case 1:
                dungeon.move(player, true);
                break;
            case 2:
                dungeon.move(player, false);
                break;
            case 3:
                player.showInventory();
                break;
            case 4:
                cout<<"ಠ_ಠ —–— ಠ_ಠ —–— ಠ_ಠ "<<endl;
                cout << "You have chosen to leave the dungeon. Game Over.\n";
                cout << "🚪 You chose to QUIT the game... Just like that. Wow.\n";
                cout << "💀☠️──────────────────────────────☠️💀" << endl;
                cout << "      🏳️ 𝒯𝒽𝑒 𝐶𝑜𝓌𝒶𝓇𝒹𝓁𝓎 𝐸𝓍𝒾𝓉 𝑜𝒻 " << name << " 🏳️" << endl;
                cout << "💀☠️──────────────────────────────☠️💀" << endl;
                cout << "\n";
                cout << "(ノಠ益ಠ)ノ彡┻━┻" << endl;
                cout << "\n";
                cout << "You didn’t even TRY." << endl;
                cout << "\n";
                cout << "📜 Historians will write about your journey, " << name << "." << endl;
                cout << "   Not as a hero, not as a warrior… but as a **quitter.**" << endl;
                cout << "\n";
                cout << "🎶 The bards refuse to write a song about you. Too embarrassing. 🎶" << endl;
                cout << "\n";
                cout << "🔥👑 𝒴𝑜𝓊 𝒸𝑜𝓊𝓁𝒹 𝒽𝒶𝓋𝑒 𝒷𝑒𝑒𝓃 𝒶 𝓁𝑒𝑔𝑒𝓃𝒹, " << name << "... " << endl;
                cout << "   𝐵𝓊𝓉 𝓃𝑜𝓌 𝓎𝑜𝓊'𝓁𝓁 𝒷𝑒 𝓀𝓃𝑜𝓌𝓃 𝒶𝓈 ‘𝒯𝒽𝑒 𝒪𝓃𝑒 𝒲𝒽𝑜 𝐿𝑒𝒻𝓉.’ 👑🔥" << endl;
                cout << "\n";
                cout << " Enjoy your peaceful, monster-free life, coward. " << endl;
                cout << "\n";

                running = false;
                break;
            default:
                cout<<"(⊙_☉) ??? (☉_⊙)"<<endl;
                cout << "Invalid choice. Try again.\n";
        }

        //Check if player escaped
        if (dungeon.isEscaped()&&player.getMoves() > 0&&player.getHealth()>0) {
            cout << "🌟✨──────────────────────────────✨🌟" << endl;
            cout << "      🎉 𝒞𝑜𝓃𝑔𝓇𝒶𝓉𝓈, " << name << "! 🎉" << endl;
            cout << "🌟✨──────────────────────────────✨🌟" << endl;
            cout << "\n";
            cout << "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ *:･ﾟ✧ *:･ﾟ✧" << endl;
            cout << "\n";
            cout << "🏰 You braved the Dungeon with courage!" << endl;
            cout << "🐉 Defeated mighty foes with wisdom!" << endl;
            cout << "🗝️  Solved puzzles with brilliance!" << endl;
            cout << "💎 Gathered treasures like a true hero!" << endl;
            cout << "\n";
            cout << "💖 Your name shall echo through legend! 💖" << endl;
            cout << "\n";
            cout << "(ﾉ◕ヮ◕)ﾉ*:･ﾟ✧ *:･ﾟ✧ *:･ﾟ✧" << endl;
            cout << "\n";
            cout << "🎀💫 **Enjoy your victory!** 💫🎀" << endl;
            cout << "\n";
            
        }
    }

    if (player.getMoves() <= 0) {
        cout << "❌ You ran out of moves! Game Over.\n";
        cout << "💀☠️──────────────────────────────☠️💀" << endl;
        cout << "      😭 𝒯𝒽𝑒 𝐸𝓅𝒾𝒸 𝐹𝒶𝒾𝓁 𝑜𝒻 " << name << " 😭" << endl;
        cout << "💀☠️──────────────────────────────☠️💀" << endl;
        cout << "\n";
        cout << "(╯°□°）╯︵ ┻━┻" << endl;
        cout << "\n";
        cout << "🏚️  You entered the **Dungeon** and IMMEDIATELY regretted it." << endl;
        cout << "👹  The monsters didn't even attack. They just pointed and laughed." << endl;
        cout << "\n";
        cout << "**Your name shall echo through history... as a JOKE!** " << endl;
        cout << "\n";
        cout << "🔥🎖️ 𝒴𝑜𝓊 𝒶𝓇𝑒 𝓃𝑜𝓉 𝒶 𝓁𝑒𝑔𝑒𝓃𝒹, " << name << "... 𝓎𝑜𝓊 𝒶𝓇𝑒 𝒶 **𝓌𝒶𝓇𝓃𝒾𝓃𝑔 𝓉𝒶𝓁𝑒!** 🎖️🔥" << endl;
        cout << "\n";
        cout << "(ノಠ益ಠ)ノ彡┻━┻" << endl;
        cout << "\n";
        cout << "Maybe try a children's game next time?" << endl;
        cout << "\n";
    }
    
    if (player.getHealth() <= 0) {
        cout << "❌ You died bruh! Game Over.\n";
        cout << "💀☠️──────────────────────────────☠️💀" << endl;
        cout << "      😭 𝒯𝒽𝑒 𝐸𝓅𝒾𝒸 𝐹𝒶𝒾𝓁 𝑜𝒻 " << name << " 😭" << endl;
        cout << "💀☠️──────────────────────────────☠️💀" << endl;
        cout << "\n";
        cout << "(╯°□°）╯︵ ┻━┻" << endl;
        cout << "\n";
        cout << "🏚️  You entered the **Dungeon** and IMMEDIATELY regretted it." << endl;
        cout << "👹  The monsters didn't even attack. They just pointed and laughed." << endl;
        cout << "\n";
        cout << "**Your name shall echo through history... as a JOKE!** " << endl;
        cout << "\n";
        cout << "🔥🎖️ 𝒴𝑜𝓊 𝒶𝓇𝑒 𝓃𝑜𝓉 𝒶 𝓁𝑒𝑔𝑒𝓃𝒹, " << name << "... 𝓎𝑜𝓊 𝒶𝓇𝑒 𝒶 **𝓌𝒶𝓇𝓃𝒾𝓃𝑔 𝓉𝒶𝓁𝑒!** 🎖️🔥" << endl;
        cout << "\n";
        cout << "(ノಠ益ಠ)ノ彡┻━┻" << endl;
        cout << "\n";
        cout << "Maybe try a children's game next time?" << endl;
        cout << "\n";
    }

    return 0;
}
