# Filler
The task was to create a player program to compete against other students on Filler board. The principle is simple: two players take on each other on a board, and take turns placing the piece that the master of the game (supplied in the form of a Ruby executable) gives them, earning points. The game stops as soon as a piece can no longer be placed.

# Compiling and running:

Run make. An executable will compile.

Run ./resources/filler_vm -f ./resources/maps/MAP_NAME -p1 resources/players/PLAYER1_NAME -p2 ./wmarya.filler
Sample maps and players are provided in the resources directory.

# Turning on visualizer

In order to run the program in a visual mode run the following:

./resources/filler_vm -f ./resources/maps/MAP_NAME -p1 resources/players/PLAYER1_NAME -p2 ./wmarya.filler | ./visual/visual 
