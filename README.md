# Chess Game — C++ and Qt

A desktop chess project developed in C++ with a graphical user interface built using Qt.

## Features

- Interactive 8×8 chessboard with clickable squares
- Turn tracking for White and Black
- Piece movement and move validation handled by the game model
- Multiple starting-position options, including a standard setup and rook- or knight-focused configurations
- Separate game logic and user-interface components

## Technologies

- C++
- Qt Widgets
- Object-oriented programming
- Visual Studio project files

## Project Structure

- `projetcpp/` — application source code and Qt interface
- `testFile/` — additional project and test-related source files
- `projetcpp.sln` — Visual Studio solution

## Architecture

The application separates its interface from its game model:

- `MainWindow` manages the graphical interface and user interactions.
- `Partie` manages game state, turns, and starting configurations.
- `Echiquier` represents the board and handles piece placement and movement.
- Piece classes such as `Roi`, `Tour`, and `Cavalier` implement piece-specific behavior.

## Running the Project

The repository contains a Visual Studio solution (`projetcpp.sln`) and Qt interface files. To build the graphical application, open the solution in a compatible Visual Studio environment with Qt configured, then select and build the application project. Build requirements may vary by system.

## Credits

Academic team project developed by **Anta Rayana Mbaye** and **Mohamed Lamine Gueye**.

This repository is an independent portfolio copy of the collaborative project.
