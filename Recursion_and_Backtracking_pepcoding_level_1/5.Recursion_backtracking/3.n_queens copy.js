const placeQueens = (val) => {
    const chess = new Array(val).fill(0).map((e) => Array(val).fill(0));

    const col_taken = new Set();
    const pri_dg_taken = new Set();
    const sec_dg_taken = new Set();

    const answer = [];

    const backtrack = (row = 0) => {
        if (row === chess.length) {
            answer.push(chess.map(row => [...row]));
            return;
        }

        for (let col = 0;col < chess.length;col++) {
            // choose options, choose column
            if (
                !col_taken.has(col) &&
                !pri_dg_taken.has(row - col) &&
                !sec_dg_taken.has(row + col)
            ) {
                // call smart
                chess[row][col] = 1;
                col_taken.add(col);
                pri_dg_taken.add(row - col);
                sec_dg_taken.add(row + col);
                backtrack(row + 1); // goto new level, next row
                sec_dg_taken.delete(row + col);
                pri_dg_taken.delete(row - col);
                col_taken.delete(col);
                chess[row][col] = 0;
            }
        }
    };

    backtrack(0);
    // console.log(answer);
    // for (t of answer) {
    //     console.table(t);
    // }
};

placeQueens(4);