// total substring  = n*(n+1)/2
// total subsequence = 2^n


const print_maze_paths = (sr, sc, dr, dc, ans = "") => {

    if (sr === dr && sc === dc) {
        console.log(ans);
        return;
    };

    if (sr > dr || sc > dc) return;

    print_maze_paths(sr, sc + 1, dr, dc, ans + 'h');
    print_maze_paths(sr + 1, sc, dr, dc, ans + 'v');

};

print_maze_paths(1, 1, 3, 3);

////////////////////////////////////////////


