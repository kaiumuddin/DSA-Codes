const permutation = (nboxes, ritems) => {
    const boxes = Array(nboxes).fill(0);

    const _permutation = (curr_i) => {
        if (curr_i > ritems) {
            console.log(boxes);
            return;
        }

        for (let i = 0;i < boxes.length;i++) {
            if (boxes[i] === 0) {
                boxes[i] = curr_i;
                _permutation(curr_i + 1);
                boxes[i] = 0;
            }
        }
    };

    _permutation(1);
};

permutation(5, 3);