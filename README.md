

# Othello AI Project

## Project Overview

This project is a simulation of the classic board game Othello (or Reversi) developed in Cin a group in my 3rd year in INSA ROUEN NORMANDIE (ITI3). 
The goal is to create an interactive Othello game where players can compete against a computer opponent with varying levels of difficulty. The AI opponent uses a Minimax algorithm with adjustable depth, allowing for different levels of challenge.

The project includes both a standard game mode and a "tournament" mode, enabling an AI-versus-AI competition through a predefined protocol.

## Features

- **Game Modes**:
  - **Standard Mode**: Play against the AI, with options to select the player’s color and the difficulty level (AI depth).
  - **Tournament Mode**: AI competes against another AI through a communication protocol.

- **Artificial Intelligence**:
  - Implements the Minimax algorithm with adjustable depth for the AI's difficulty.
  - Supports score evaluation for each potential move, including calculating potential outcomes and prioritizing higher-scoring moves.

- **Game Mechanics**:
  - Follows traditional Othello rules on an 8x8 board.
  - Players take turns placing pieces to maximize control of the board.
  - The game ends when no valid moves are available for either player.

## Code Structure

### Key Components

- **Game Functions**:
  - `JEU_faireUnePartie`: Initializes and runs a game session.
  - `JEU_obtenirCoupH`: Processes player moves.
  - `JEU_testerFin`: Checks if the game has reached an end condition.
  - `JEU_trouverVainqueur`: Determines the game winner.

- **Artificial Intelligence Functions**:
  - `IA_minMax`: Core function implementing the Minimax algorithm.
  - `IA_obtenirCoupIA`: Calculates the best move for the AI.
  - `IA_scoreDUnCoup`: Evaluates the score of a potential move for the AI.

- **Data Structures**:
  - `Plateau`: Represents the game board.
  - `Pion`: Represents individual pieces.
  - `Couleur`: Enum defining piece colors.
  - `Coups`: List of possible moves.

### Game Flow

1. **Initialization**: Set up board with starting positions.
2. **Turn-Based Actions**:
   - Player or AI selects a move.
   - Game state updates to reflect board changes.
3. **Endgame Check**: Continuously checks for endgame conditions until no valid moves are available.

## Installation and Setup

1. Clone the repository.
2. Compile the code:
   ```sh
   gcc -o othello main.c
   ```
3. Run the game:
   ```sh
   ./othello
   ```

## Usage

1. Choose the game mode and AI difficulty level.
2. Follow prompts to make moves or view the AI's moves.
3. The game will display the board after each move and announce the winner at the end.

## Authors

- Yasmine Benchekroun
- Lucas Charles
- Jihane Essakhi
- Laurent Foyer

## License

This project is open-source under the MIT License.

