def subsequence(str)
  puts str.inspect
  if str.empty?
    puts '------'
    return [""]
  end

  child_subsequence = subsequence(str[1..-1])
  puts child_subsequence.inspect

  full_subsequence = []
  child_subsequence.each do |child|
    full_subsequence << "-" + child
    full_subsequence << str[0] + child
  end

  full_subsequence
end

puts subsequence("123").inspect









# @param nums [Array<Integer>] the input array
# @return [Array<Array<Integer>>] an array of all subsets
def subsets nums
  puts nums.inspect
  if nums.empty?
    puts '------'
    return [[]]
  end

  child_subsets = subsets(nums[1..-1]) # Array<Array<Integer>>
  puts child_subsets.inspect

  full_subsets = [] #Array<Array<Integer>>
  child_subsets.each do |child| # child: Array<Integer>
    full_subsets << [0] + child
    full_subsets << [nums[0]] + child
  end

  full_subsets # Array<Array<Integer>>
end

# puts subsets([1,2,3]).inspect
