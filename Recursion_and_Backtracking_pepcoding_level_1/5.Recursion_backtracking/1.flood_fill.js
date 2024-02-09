const floodfill = (maze, i, j, psf = "") => {

    if (i < 0 || j < 0 || i >= maze.length || j >= maze[0].length || maze[i][j] === 1) return;

    if (i === maze.length - 1 && j === maze[0].length - 1) {
        console.log(psf);
        return;
    }

    maze[i][j] = 1;
    floodfill(maze, i - 1, j, psf + "t");
    floodfill(maze, i, j - 1, psf + "l");
    floodfill(maze, i + 1, j, psf + "d");
    floodfill(maze, i, j + 1, psf + "r");
    maze[i][j] = 0;

};

const maze = [
    [0, 1, 1],
    [0, 0, 1],
    [1, 0, 0],
    [0, 1, 0],
];

floodfill(maze, 0, 0);