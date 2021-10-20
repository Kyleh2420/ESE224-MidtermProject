# Current To Do List
Solve File Saving problem, see main.cpp, lines 55-57



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
#### Floor 1
Floor 1 consists of 2 weak enemies with one random events.
#### Floor 2
Floor 2 consists of 3 weak enemies with two random events.
#### Floor 3
Floor 3 consists of 2 strong enemies with two random events.
#### Floor 4
Floor 4 consists of 4 strong enemies with three random events.

## File Operations
In the file operations class, we create 2 different files. The player file will store all information about the current game, as well as offer a way to load a game from a save file.