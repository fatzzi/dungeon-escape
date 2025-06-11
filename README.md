# 🏰 Dungeon Escape Game 🏰

"Dungeon Escape" is a thrilling text-based adventure game written in C++. Players navigate a mysterious dungeon filled with challenges, formidable enemies, and valuable treasures. Your goal is to strategically manage your health and moves, overcome obstacles, and ultimately find your way out of the dungeon!

## ✨ Features

* **Linear Dungeon Progression:** Explore a series of interconnected rooms, each with unique events.

* **Player Attributes:** Track your health, remaining moves, and an expanding inventory of collected treasures.

* **Dynamic Room Events:**

    * **Challenges 🧠:** Solve intriguing questions to avoid penalties.

    * **Enemy Encounters ⚔️:** Engage in turn-based combat with diverse enemies, featuring options to attack with items, block incoming damage, or even negotiate your way out.

    * **Treasure Discovery 💎:** Find and collect useful items that can aid you in combat or other situations.

* **Strategic Choices:** Decide whether to move forward, backtrack, or check your inventory, with each decision impacting your limited moves.

* **Immersive Text-Based Experience:** Enjoy a narrative-rich adventure conveyed through engaging console output, complete with emojis and ASCII art.

* **Memory Management:** The game uses a custom linked list for dungeon rooms and queues for managing enemies, designed with careful memory handling in mind.

## 🕹️ How to Play

### Game Objective:

Your ultimate goal is to escape the dungeon by reaching the final room. You must maintain your health and moves throughout your journey.

### Controls & Actions:

The game is played by entering numerical choices in the console.

* **Navigation:**

    * `1. Move Forward`: Advance to the next room. Costs 1 move.

    * `2. Move Backward`: Return to the previous room (if available). Costs 1 move.

* **Utility:**

    * `3. Check Inventory`: View the treasures you've collected.

    * `4. Quit Game`: End your adventure (and face a humorous, albeit critical, farewell).

* **Combat:** When facing an enemy, you will be presented with specific combat actions:

    * `1. Block`: Reduce damage from the enemy's attack. Can be used a limited number of times.

    * `2. Attack`: Use a collected item (weapon) to defeat the enemy. The weapon will be consumed.

    * `3. Make a Deal`: Offer a collected item to convince the enemy to leave. The item will be consumed.

### Game End Conditions:

* **Win 🎉:** Successfully reach the final room with health and moves remaining.

* **Loss 💀:** Run out of health, run out of moves, or choose to quit the game.

* The game might roast you a bit, nothing personal.

