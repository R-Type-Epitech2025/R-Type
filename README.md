
# R-TYPE

Epitech 2025 end year project



## Summary

- The project

- Server

- Client

- Prerequisites

- Installing 

- Usage

# The project

The project is a rtype game with the possibility to connect multiple players and let them interact with each other in one same game.


# Server

Using [Qt5 with QObject](https://doc.qt.io/qt-5/qobject.html) the server receive the client inputs and treat the data in his different systems and re-send the actualized sprite.


```for exemple a Qt message will be sent if you click on down_key on the keyboard. this same msg will be received by the server```



## Client

The client part is where the gameloop mostly run, it's goal is too init and load all the graphic before the server take and update them.
## Prerequisites

Requirements for the software and other tools to build, test and push

- Visual Studio (Windows)
- GCC (Linux)
- Git

## Installing

On Linux:
- simply run install.sh with this :```sudo ./install.sh```

On Windows:

- run this the Install_windows.bat : ```$>Install_windows.bat```

## Usage

On Linux:
- run : ```./build.sh```

On Windows :
- run : ``` $> Build_Windows.bat```

after building you will have to run two terminal

in the first one:
- run : ```./server/bin/R-type_server.exe``` without ```./``` on cmd.

in the second one:
- run : ``` ./client/bin/R-type_client.exe [ip] [port]``` without ```./``` on cmd.

## Tech Stack

**Client:** C++, Sfml, Qt5

**Server:** C++, Sfml, Qt5


## Authors

- [Leo Maman](https://github.com/mangasteak)
- [Ilan Chekroun](https://github.com/Ilaan16)
- [Saad Berrada](https://github.com/Codrux2200)
- [Arthur Duhot](https://github.com/Carasssiusaurat)
- [Antoine Cadeau](https://github.com/ancadeau)
- [Ali Mhrez](https://github.com/E-Ary)
- [Loic Rouzaud](https://github.com/loic-rouzaud)

