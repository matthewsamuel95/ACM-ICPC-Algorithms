def is_prime(number)
    if (number <= 1)
        return false
    end
    (2..Math.sqrt(number).to_i).each do |i|
        if ((number % i) == 0)
            return false
        end
    end
    return true
end

puts "Enter a number : "
number = gets.chomp.to_i

if is_prime(number)
    print "%d is a prime number\n" % number
else
    print "%d is not a prime number\n" % number
end
