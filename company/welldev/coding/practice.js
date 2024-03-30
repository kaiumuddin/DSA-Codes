function merge(fsh, ssh){
}

function mergeSort(nums, l, r) {
  if (l >= r) {
    return [nums[l]];
  }

  const mid = (l + r) / 2;

  const firstSortedHalf = mergeSort(nums, l, mid);
  const secondSortedHalf = mergeSort(nums, mid + 1, r);

  const merged = merge(firstSortedHalf, secondSortedHalf);

  return merged;
}

const nums = [2, 5, 3, 10, 1, 4, 7];

const sorted = mergeSort(nums, 0, nums.length);

console.log(sorted);
