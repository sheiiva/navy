Navy
===

Time:       3 weeks

Team:       1

Language:   C


The project
----

You all know the very famous **Battleship game**. You must code a terminal version of this game. The two players are ONLY allowed to comunicate using the signals **SIGUSER1** and **SIGUSER2**. **The map size is 8x8**. On each turn, you must display your positions, and then your enemy’s positions. At the end of the game (when all the ships of a player have
been hit), you must display whether “I won” *(and return 0)* or “Enemy won” *(and return 1)*.

##### FILE FORMAT:
The file passed as parameter must contain lines formatted the following way:
> LENGTH : FIRST_SQUARE : LAST_SQUARE
where LENGTH is the length of the ship, FIRST_SQUARE and LAST_SQUARE its first and last positions.
In this file, you must have 4 ships (of lengths 2,3,4 and 5).
If the navy file is invalid, you have to quit the program and consider it as an error.

```
>> cat map
2:C1:C2
3:D4:F4
4:B5:B8
5:D7:H7
```

## USAGE:

```
>> ./navy -h
USAGE
     ./navy [first_player_pid] navy_positions
DESCRIPTION\
    first_player_pid:  only for the 2nd player. pid of the first player.
    navy_positions: file representing the positions of the ships.
```


#### AUTHORIZED FUNCTIONS:
* open
* close
* read
* write
* lseek
* malloc
* free
* getpid
* kill
* signal
* sigaction
* sigemptyset
* setcontext
* getcontext
* usleep
* nanosleep
* pause

Author [**Corentin COUTRET-ROZET**](https://github.com/sheiiva)