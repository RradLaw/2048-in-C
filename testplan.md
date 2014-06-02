# 2048 Test Plan
## 1. Introduction
This document provides the testing needed for the 2048 game. The main function of this program is to have a board of tiles, with numbers in them. When the board is tilted, these tiles move in the direction of the tile, merging into a larger number if two identical numbers collide.
This test plan is split into a number of sections. Section 2 refers to all relevant testing conducted in this test plan. Section 3 specifies what needs to be tested, and the outcome of the test. Section 4 outlines what is not needed to be tested. Section 5 shows the documentation produced by the program and testing. Finally, section 6 shows what risks are involved in this testing, and what the testing is dependent on.

## 2. Test types to consider
* Unit testing
* White box testing
* Regression testing
* Blackbox testing
* Integration testing

## 3. What to test:
* Initialisation
	* Initial empty 4x4 board
	* Two 2’s are placed
	* User is prompted for first move
* Input
	* Program accepts u,d,l,r, blank input
	* Program rejects all other input, with an error
* Tilting
	* Board tilts in the direction specified by the input
	* If two values next to each other are the same, they will merge into a single tile double the value 
	* Unique tiles will not merge
	* A 2 or 4 will be randomly placed if the board is not full
* Full board
	* If the board cannot be tilted, game notify the user the game is over then quit
	* Else game will continue as normal
* Display
	* The game will output exactly what is calculated and stored
* End game
	* If there is a 2048 piece, game produces win message, prompting the user if they want to finish
* Scoring
	* Score is incremented by the number of a merged piece
## 4. What not to test:
* Input
	* Large number of input sent in a small space of time should function
* Compatibility
	* Program works perfectly with every single platform

## 5. Documentation produced:
* Software documentation
* Commits
* Test log

## 6. Risks and dependencies:
* Risks
	* Misunderstanding of the 2048 rules
	* Tests not sufficient
	* Tests written incorrectly 
* Dependencies
	* Understanding of the 2048 game, and its rules
	* Knowledge of C, the language of the program
	* System with the ability to conduct test
	* 2048 program to test on
