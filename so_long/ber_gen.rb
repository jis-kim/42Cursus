#! /usr/bin/ruby

# SECTION Arguments setting
x_len = rand(3..25)
y_len = rand(3..25)

if x_len == 3 && y_len < 5
  y_len = rand(5..25)
elsif y_len == 3 && x_len < 5
  x_len = rand(5..25)
end

# SECTION Map generation function
def mapgen(x, y)
  map = []
  mid = Array.new(x, '0')
  mid[0] = '1'
  mid[-1] = '1'
  2.times { map.append(Array.new(x, '1')) }
  (1..(y - 2)).to_a.each { |i| map.insert(i, mid.clone) }
  empty = (x - 2) * (y - 2)

  # NOTE Filling appropriate amount of 'C's and '1's
  rand(1..(empty / 4)).times { map[rand(1..(y - 2))][rand(1..(x - 2))] = 'C' }
  rand(1..(empty / 4)).times {
    x_idx = rand(1..(x - 2))
    y_idx = rand(1..(y - 2))
    map[y_idx][x_idx] = '1' if map[y_idx][x_idx] != 'C'
  }

  # NOTE Fill 'E' and 'P'
  pe = ['P', 'E']
  pe.each { |c|
    empty.times {
      x_idx = rand(1..(x - 2))
      y_idx = rand(1..(y - 2))
      if map[y_idx][x_idx] == '0' || map[y_idx][x_idx] == '1'
        map[y_idx][x_idx] = c
        break
      end
    }
  }

  # NOTE Write .ber file
  map.each_index { |i|
    if i == 0
      File.write('map.ber', "#{map[i].join}", mode: 'w')
    else
      File.write('map.ber', "#{map[i].join}", mode: 'a')
    end
    File.write('map.ber', "\n", mode: 'a') unless i == y
  }
end

mapgen(x_len, y_len)
