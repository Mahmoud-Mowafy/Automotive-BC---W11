X-O Game

![dd188cde6560c1ab5d30994da3c139c2--pictures-of-plays](https://user-images.githubusercontent.com/60091384/228658391-89001683-b82d-4611-8574-8507fc0aee34.jpg)


 draw the board

          1. A board will be initialized with numbers from 1 to 9, which state each position number
          2. Implement draw board function
          - Use this prototype void drawBoard(uint8_t *board);
          - This function will take a board as an input and prints it on the console
          2. Implement update board function
          - Use this prototype void updateBoard (uint8_t *board, uint8_t position, uint8_t value);
          - This function will take the board, position to update and value to set in this position

            
 Players Configurations

          1. Only two players (Player 1 abd Player 2)
          2. Implement get player symbol function
          - Use this prototype, uint8_t getPlayerSymbol(uint8_t playerNumber, uint8_t * symbol);
          - This function will take player number and asks the player to choose between X and O (case insensiteve)
          - This function will return 0 when the input symbol is not wrong and/or was not choosen before
          - This function will return 1 when the input symbol is wrong and/or was choosen before
          3. Implement set player config function
          - Use this prototype, void setPlayerConfig(uint8_t *configArray);
          - This function will prompt and asks each user about their preferred symbols and saves it in the configArray
player move

          1. Implement load and update function
          - Use this prototype, void loadAndUpdate(uint8_t playerNumber);
          - This function will take player's number then load his config, asks him for the position then updates the board

winning condition check

          1. Implement a function to check if there is a winning, draw, or continue playing.
          - Use this prototype, void getGameState(uint8_t *gameState, );
          - This function will check after each move if there is a win, draw or continue playing.
          - Returns 0 for winning
          - Returns 1 for draw
          - Returns 2 for continue
 main flow

          1. Implement the main flow acccording to your understanding of the game

Test your main flow

          1. Test the main flow against wrong symbol choice
          2. Test the main flow against repeated sumbole choice
          3. Test the main flow against X player winning:
          - All Rows winning (3)
          - All Columns winning (3)
          - All Diagonals winning (2)
          4. Test the main flow against O player winning: 
          - All Rows winning (3) 
          - All Columns winning (3) 
          - All Diagonals winning (2)
          5. Test the main flow against X player draw case at leaset three draw cases

            
