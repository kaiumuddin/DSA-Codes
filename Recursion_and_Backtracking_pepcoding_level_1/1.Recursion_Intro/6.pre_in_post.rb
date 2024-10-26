def pre_in_post n
  return if n == 0

  puts 'pre  :' + n.to_s
  pre_in_post n - 1
  puts 'in   :' + n.to_s
  pre_in_post n - 1
  puts 'post :' + n.to_s
end


pre_in_post 3
