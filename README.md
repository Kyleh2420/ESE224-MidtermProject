# Current To Do List
Need to understand how the scoreboard is going to work to keep track of things.
New File ahs already been done (Need to set up scoreboard for new file)
Need to work on loading a file (Around line 41 of main.cpp)
Work on the various floors
* See floor psuedo code below. Then, implement the random events of take a step
* This will also read lines from a file: Dev notes, interesting experiences, etc. See the game that Dangy showed.
* Reference Game: https://web.simple-mmo.com/
## Floor Psuedocode
The floor system is going to work like this:
1. When a new floor is loaded (switch case statement checking scoreboard's floor)
2.    Create a vector with a list of 25 numbers from 0-3, loaded by specific values set by the current floor level. 
        * Use std::random_shuffle to shuffle the vector. This becomes the random occurances that happen when the user steps forward.
2.    Randomly generate a list of 25 numbers from 0-3. This will be the random encounters that happen when a user steps forward. 
        * 0 - Nothing happens
        * 1 - Enemy Encounter. Enter Battle scene
        ~~* 2 - Good random encounter. Ex: Player finds a treat or something and gains an extra HP.~~
        ~~* 3 - Bad random encounter. Ex: Player trips over a rock and loses 1 hp.~~ 
        * 2 - Random encounter. Could be good or bad, will be generated randomly



# ESE224-MidtermProject

Stony Brook University's ESE 224 Midterm Project

## Project Goal
This project's goal is to create a playable text-based RPG consisting of 4 levels to satisfy the requirements of the ESE 224 (Advanced Programming and Data Structures) Midterm Project . 
## Game Description
You are a skeleton who has been condemned to the depths of hell. However, hell just isn't to your satisfaction, so you're escaping back to earth. Explore the path, defeat enemies, collect organs, and set yourself up to become a real person again. Succeed, and live a life of comfort back on earth. Fail, and become an unsuccessful ghost, forever stuck in the land of inbetween, neither satisfied on hell or reborn on earth. Succeed, and you're reborn on earth as a brand new being. 

## Game Design

At startup, the user will choose from 3 difficulty multipliers, easy medium or hard. The user will also be given the option to either load from a save file or to start a new game. Either way, the user will be prompted for a savefile name.

There are 4 floors that the user has to traverse though. Each floor has different enemies and weapon selections, with each having higher values as the floor changes. 

To progress though each floor, you take a step. 25 steps = 1 floor. Each step has the possibility of resulting in either a random enemy encounter or a random event. There will be 3-4 enemy encounters per floor, randomly dispersed throughout the level, and 1-2 random events strewn throughout the level.

Each enemy you defeat will add to the scoreboard's points and enemycount. You must defeat at least 7 enemies (Collecting a new organ everytime).
### Level Design
There are 4 floors to this game.
#### Floor 0
Floor 1 consists of 2 weak enemies with one random events.
#### Floor 1
Floor 2 consists of 3 weak enemies with two random events.
#### Floor 2
Floor 3 consists of 2 strong enemies with two random events.
#### Floor 3
Floor 4 consists of 4 strong enemies with three random events.

## File Operations
In the file operations class, we create 2 different files. The player file will store all information about the current game, as well as offer a way to load a game from a save file.

# JOURNAL
10/21
* William 
  * changed how scoreboard works. Linked it to the player's save file.
  * Also changed how file creation works - user no longer needs to add .txt when creating a new file.
