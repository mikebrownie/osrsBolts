# osrsBolts
Automated input for OSRS bolt enchanting. Intended for Windows users. Uses I/O queue to send input. Built in C++ using Windows API. Use responsibly.
### Why?
Enchanting Bolts is a fast (300k+ XP/hour) and sometimes profitable way to train magic to max in OSRS. After a certain point, high alchemy just doesn't cut it anymore. No AHK used to reduce detection rates, indistinguishable from keyboard input. 

## What this program does
- Enchants 10 bolts every 6ms tick until stopped by user


## Quick Guide:
1) Clone this repository
2) Setup inventory so spell is under bolt stack
3) Run `osrsBoltz.exe` 
4)  Hover mouse over spell
5) Press once space to toggle on, and later again to turn off
6) Note you must kill the process to unbind space from toggling the program state

## In Depth:
1) Clone this repository

2) Open a terminal (WindowsKey+r, then type cmd and press enter)

3) Navigate to directory where you cloned this repository in the terminal. [How to use Windows Terminal?](https://www.computerhope.com/issues/chusedos.htm)

4) Compile the  "main.cpp" file to an output file osrsBoltz by typing `g++ main.cpp -o osrsBoltz` in the terminal
5) Run the executable with command` ./osrsBoltz`
6) Toggle state clicking on or off with space bar
