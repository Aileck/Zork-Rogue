# Zork-Rogue
<hr>
Github link: https://github.com/Aileck/Zork-Rogue
<hr>
<h3>Zork-Rogue</h3>
Base task:
<ul>
<li>Make Zork with c++.</li>
<li>5+ Room.</li>
<li>Item can be picked up.</li>
<li>Item can drop.</li>
<li>Items can be placed inside other items (key inside the door)</li>
</ul>

<br>
My extension:
<ul>
<li>1. Incorporate RPG system.</li>
<li>2. Battle system.</li>
<li>3. Maxim guidance to make game easier (map, tips...)</li>
</ul>

<p>
Firstly, I added an RPG system where players can engage in turn-based combat through commands. I also included some resource management and exploration system to successfully pass the game (although it is possible to skip exploration, doing so will make the final battle very difficult).
</p>

<p>
Secondly, I added more limitations to the game, unlike Zork which is very open. However, this makes the player's behavior more controllable. Even when I first tried playing Zork, it was very chaotic and I had no idea how to proceed. Therefore, I limited the freedom to help players complete the game more easily.
</p>

<p>
Finally, I did not design a Game Over system for when the player dies, because I don't want players to repeat playing this small demo after dying (regardless, I must admit that because this was completed within a week, the balance definitely lacks polish. I shouldn't punish players by making them replay an unbalanced game.)
</p>

<h3>Game play</h3>

| Command   | Usage                                                                                        |
|-----------|----------------------------------------------------------------------------------------------|
| Check     | Check all the text in square brackets to get detailed information. <br>Special usage 1: check + [me] to check yourself.<br> Special usage 2: check + [here] to check current scene. |
| Goto      | Goto + [north/south/east/west] to move in that direction. Fails if there is no path or if it's locked. <br> Special usage 1: goto back to go back to the previous place. |
| Attack    | Attack + [target name] to choose the name of an enemy to attack.                                                       |
| Inventory | Inventory to see all items in your inventory. <br> Inventory + [item name] to use/equip an item. <br>Inventory + key + [north/south/east/west] to unlock a door in that direction. |
| Use       | Use + [item name] to use an item in the current scene.                                        |
| Pick      | Pick + [item name] to pick up an item in the current scene by using its name.                                       |
| Drop      | Drop + [item name] to drop an item from your inventory into the current scene.                                      |
| Help      | Show this table |
<h3>Walkthrough - Summary - Recommended route</h3>
<p>

Start Game

```
inventory toy sword
```

Defeat enemies

```
use toy shield
goto w //Go room 3
```
Defeat enemies

```
use sky trailers
goto w //Go room 4
```
Defeat enemies

```
pick map 
```
Back to room 1

```
go hidden 
use dragon slayer
go back
go s // Go room 5
```
Defeat enemies

```
pick key
go back
inventory key e
go e //Go room 6
inventory key s
go s //Go room 9
```

Defeat enemies

```
use yggdrasil shield
```
Go to room 7

Defeat Dragon

End Game

</p>

<h3>Walkthrough - Long</h3>
Map (can be checked inside game):

```
     [2] [H8]
     | |/
[L6]=[1]=[3]=[4]
| |  | |
[L9] [5]
     | |
     [E7]
```

<p>
The player starts in room 1 and can directly go to the exit in room 7, but the equipment at that point will definitely not be enough to defeat the enemies, so exploration is necessary.
</p>

<p>
I recommend starting by using the Inventory command to equip the sword in the backpack and defeating the two small monsters in front of the player to obtain the shield.
</p>

<p>
At this point, the player can go to rooms 2, 5, and 3 (room 6 is locked), with difficulty ranking as 2<3<5. Room 2 only contains a potion, so it can be skipped. In room 3, defeat the small monster to obtain the shoes. There won't be any prompt when equipping them, but they will hide and increase the player's critical hit rate. Then go to room 4 to get the map, which will reveal that room 1 has a hidden path leading to room 8. After obtaining a better sword, go to room 5 to obtain the key and unlock rooms 6 and 9. Finally, get the better shield in room 9.
</p>

<p>
With these items, the player can easily defeat the dragon in room 7 and complete the game.
</p>
