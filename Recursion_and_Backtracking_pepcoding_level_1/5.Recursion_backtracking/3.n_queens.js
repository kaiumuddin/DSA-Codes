const print_queens = (n) => {
    const chess = new Array(n).fill(0).map(e => Array(n).fill(0));

    const col_taken = new Set();
    const pri_dg_taken = new Set();
    const sec_dg_taken = new Set();

    const backtrack = (row = 0, ans = "") => {
        if (row === chess.length) {
            console.log(ans);
            console.table(chess);
            return;
        }

        for (let col = 0;col < chess.length;col++) { // choose options, choose column
            if (!col_taken.has(col) && !pri_dg_taken.has(row - col) && !sec_dg_taken.has(row + col)) { // call smart
                chess[row][col] = 1;
                col_taken.add(col);
                pri_dg_taken.add(row - col);
                sec_dg_taken.add(row + col);
                backtrack(row + 1, ans + row + "-" + col + ', '); // goto new level, next row
                sec_dg_taken.delete(row + col);
                pri_dg_taken.delete(row - col);
                col_taken.delete(col);
                chess[row][col] = 0;
            }
        }
    };

    backtrack(0, "");
};


print_queens(4);
