const knight_tour = (n, r, c) => {
    const chess = new Array(n).fill(0).map(x => new Array(n).fill(0));

    const backtrack = (r, c, move) => {
        if (r < 0 || c < 0 || r >= chess.length || c >= chess.length || chess[r][c] != 0) {
            return;
        }
        else if (move === chess.length * chess.length) {
            chess[r][c] = move;
            console.table(chess);
            chess[r][c] = 0;
            return;
        }

        chess[r][c] = move;
        backtrack(r - 2, c + 1, move + 1);
        backtrack(r - 1, c + 2, move + 1);
        backtrack(r + 1, c + 2, move + 1);
        backtrack(r + 2, c + 1, move + 1);

        backtrack(r + 2, c - 1, move + 1);
        backtrack(r + 1, c - 2, move + 1);
        backtrack(r - 1, c - 2, move + 1);
        backtrack(r - 2, c - 1, move + 1);
        chess[r][c] = 0;
    };

    backtrack(r, c, 1);

};


knight_tour(5, 3, 3);