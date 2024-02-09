// total substring  = n*(n+1)/2
// total subsequence = 2^n

// base smart, call stupid

const print_maze_paths = (sr, sc, dr, dc, ans = "") => {

    if (sr === dr && sc === dc) {
        console.log(ans);
        return;
    };

    if (sr > dr || sc > dc) return;

    for (let i = 1;i <= dc;i++) {
        print_maze_paths(sr, sc + i, dr, dc, ans + 'h' + i);
    }

    for (let i = 1;i <= dr;i++) {
        print_maze_paths(sr + i, sc, dr, dc, ans + 'v' + i);
    }

    for (let i = 1;i <= dr && i <= dc;i++) {
        print_maze_paths(sr + i, sc + i, dr, dc, ans + 'd' + i);
    }
};

print_maze_paths(1, 1, 3, 3);

////////////////////////////////////////////


