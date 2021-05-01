#!/usr/bin/env python3

 #def pow(a, n):
 #    ret = 1
 #    while n > 0:
 #        if n % 2 != 0:
 #            ret *= a
 #        a *= a
 #        n //= 2        
 #    return ret
# print(pow(5, 5))
# print(pow(5, 21))
#def powe(x, y):
#    if y == 0:
#        return 1
#    semi_result = powe(x, y // 2)
#    if y % 2 == 0:
#        return semi_result * semi_result
#    else:
#        return x * semi_result * semi_result
#base, power, mod = map(int, input().split(' '))
## ans = base**power
#ans = powe(base, power);
#ans = ans % mod;
#print(ans)

a, b, c = map(int, input().split())
print(pow(a, b, c))
print(pow(a, b) % c)
