# Current To Do List
* Finish up implementing possible random scenerios and enemies, add more weapons etc. 
   * Tell the story! Include dev notes, char development, char senses (Visual, smell, etc). See the reference game below.
* Possible memory leak when reading in empty file
* BUGS
   * When choosing a number outside of the ones listed in the shop the program breaks
   * Starting at floor 2, game kinda ends cuz the player only has 10 max hp but the enemies do so much damage
   * Random events are not changing the player's hp 
* Finish documentation
* BALANCE THE FUCKING GAME YOU FUCK WHY AM I DYING BECUASE OF A BRICK TO THE FACE
# Reference Game: https://web.simple-mmo.com/

# JOURNAL
#### 10/21
* William 
  * changed how scoreboard works. Linked it to the player's save file.
  * Also changed how file creation works - user no longer needs to add .txt when creating a new file.
* Kyle
  * Finished level creation (floor.h and floor.cpp), integrated random enemy encounters/events. 
    * gameFloor::gameFloor(level) constructor. The probability stats are taken from the private variabe floorSettings in floor.h. Probability is used to generate a vector, and then the vector is randomized.
  * Next steps: Implement the takeStep function and track where the user is in the floor. Advance floor when reaching gameFloor.getTotalPos() (See floor.h) steps.
* Kyle (Again)
  * Implemented takeStep function to track where the user is in the floor. 
  * Edited main.cpp to include the main game loop. The game loop will now automatically increment floors when the user has finished the previous floor (By way of taking steps), and recognizes when the top floor is completed.
  * May have accidently just broke everything William just did...
#### 10/22
* Kyle
  * Added additional takeStep user interface. Now, every step that the usre takes, the code will branch to the random even that should happen. See main.cpp, main game loop (Approx. Line 140).
  * Need file operation class to start implementing the random events. The goal is to read a random line out of a file and create the event based around that. Ex: "Fl1Enemies.txt" will contain the information about the various enemies that are available. "Fl1Weapons.txt" will contain the weapons available on fl1. "QuirkyComments.txt" will hold all lines of text relative to the "Do nothing" cycle. Ideally, there should be one of these per floor so that we can control the "story" arc that we see.
* William
  * Started randomEvents class (randomEvents.h and randomEvent.cpp)
    * each floor will have its own text file
    * NEEDS: interface it with floor.cpp to get the random events line
    * If we are gonna evetns where the player gets health/take damage, how we gonna do that in the txt file?
  * Edited floor.h to get floor level
  * Probably broke everything. 
#### 10/23
* Kyle
  * Gave Example of what F0RandomEvent.txt might contain. Is in format [hp gain/loss], followed by [Message to show user]
  * Attempted to create getEvent() in randomEvents.cpp. Failed
  * Removed the ability to get floor level from floor.h. This was available to get from the scoreboard.
  * Adjusted randomEvents.h/cpp by moving openFile to the constructor so that a new file could be called every game cycle
  * In reference to William's comment above: You don't actually need to interface randomEvents class to get randomEvents line.
    * The floor has already been loaded into the variables via the constructor
    * Just implement selecting a random line out of the file
#### 10/24
* William 
  * added money system in player.h
  * modded randomEvents to accommodate for hp and balance changes from the random events.
  * changed how we read from randomEvents text file. We read two int values for hp and balance changes and then a string phrase for the text line to display.
  * migrated lines storage to a vector instead of an array.
  * fixed(hopefully) getRandomEvents().
#### 10/26
* Kyle
  * Added random enemy selector to the default constructor. Now takes the floor level as input, and will generate a random enemy out of the selected text files.
  * Next steps: Upgrade weapon class to create a little shop for the user to spend their money to buy weapons.
  * Next steps: Integrate an actual combat sequence. Each hp drained from the enemy is another coin in the player's pocket.
#### 10/27
* Kyle
  * Made more of a mess in main.cpp
  * Added a little shop for the user to spend money on. Will read from the file weaponsList.txt.
  * Will read all the files into a vector using the weapon class. Will ask to see if the user would like to purchase the weapon. Changes the user profile.
  * You can test the shop by adding coins to the player. Launch into the shop, then pause the program. In autos variables (Debug > Windows > Autos), change p1.balance to whatever you need. Then, press continue.
  * Changed player.setName back to string. Main.cpp now takes int he whole line using getline(), as opposed to just cin >>. Allows the user to use a space in their name.
  * Implemented framework of combat system
#### 10/28
 * Kyle
   * Spilled alphabet soup all over main.cpp
   * Added combat system - enemy now attacks player and player now attacks enemy
   * Enemy combat is exited when the enemy dies
   * Next steps: Detect when the player dies, then quit the game
   * Next steps: Add loading file functionality
   * Clean up user interface/comment all code, then start the project report
  * Kyle (Again)
    * Detected when player dies, will quit game in player.cpp
    * Next steps: Add file loading functionality, clean up code
    * Somehow use the difficulty selector as a part of the code
    * Debug
  * Kyle (Again Again)
    * Partially added file loading functionality
    * Works, kind of, but fails to read the whole line of the player's save file for the strings, making strings that should have spaces miss the rest of the phrase. 
      * It also makes the rest of the ints that come after go missing (Since we read in the next group until the delimiter space, and it's not an int)
    * See lines 44 and 50 of fileOperations.cpp. 
    * Attempted to solve with getline(), didn't work.
    * Already 35 minutes late to class... Will solve after I guess.
  * Kyle (Again Again Again!)
    * Solved it! 
    * I don't know what it was, but I moved all the strings to be saved in the same place (Name, Weapon, MaxHP, HP, attack, Balance), and it worked fine.
  * Vincent and Kyle 
    * Debugged the menu options and the combat options because when a random input was entered that wasn't one of the options, the game broke and just inifinitely looped
    * Fixed it by changing selection to char instead of int  
#### 10/29
  * Kyle
     * Tidied up the game, cleaned up user interfaces and removed debugging nonsense
     * Added more to the possible weapons, enemies, and comments
     * Added organ collection system (Utilizing the scoreboard to keep track of the number of enemies killed.) Require 10+ killed enemies before winning the game.
     * Added a random comment class to describe the scenery around the player
     * Theoretically speaking, the user can no longer die from random events. It still happens though.
#### 10/30
   * Vincent 
     * Trying to test and debug the game before submission
     * Made a new section in To Do list called bugs 
   * Derrick
     * Fixed bug for choosing a number not in the selection for buying a weaepon from the shop


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

## Floor Psuedocode
The floor system is going to work like this:
1. When a new floor is loaded (switch case statement checking scoreboard's floor)
2.    Create a vector with a list of 25 numbers from 0-3, loaded by specific values set by the current floor level. 
        * Use std::random_shuffle to shuffle the vector. This becomes the random occurances that happen when the user steps forward.
2.    Randomly generate a list of 25 numbers from 0-3. This will be the random encounters that happen when a user steps forward. 
        * 0 - Nothing happens
        * 1 - Enemy Encounter. Enter Battle scene
        * 2 - Random encounter. Could be good or bad, will be generated randomly

## File Operations
In the file operations class, we create 2 different files. The player file will store all information about the current game, as well as offer a way to load a game from a save file.


