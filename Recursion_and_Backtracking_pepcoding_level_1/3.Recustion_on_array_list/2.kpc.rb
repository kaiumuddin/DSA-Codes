

def kpc(str, codes)
  return [""] if str.empty?

  single_num = str[0].to_i
  rest = kpc(str[1..-1], codes)

  ans = []
  codes[single_num].chars.each do |code|
    rest.each do |child|
      ans << code + child
    end
  end

  ans
end

codes = [
  ".;",
  "abc",
  "def",
  "ghi",
  "jkl",
  "mno",
  "pqrs",
  "tu",
  "vwx",
  "yz"
]

puts kpc("26", codes).inspect
