# def myfunc(x):

#     if x == 'true':
#         return 'Hello'

#     elif x == 'false':
#         return 'Goodbye'


# x = input("enter a number:")
# print(myfunc(x))

# def has(nums):
#     for i in range(0,len(nums)-1):
#         #if nums[i]==3 and nums[i+1]==3 :
#         if nums[i:i+2]==[3,3]:
#             return True
#     return False
# x=has([1,3,3,4])
# print(x)

# min = int(input("Enter the min : "))
# max = int(input("Enter the max : "))

# for n in range(min, max + 1):
#    if n > 1:
#        for i in range(2, n):
#            if (n % i) == 0:
#                break
#        else:
#            print(n)

def count_prime(nums):
    if nums < 2:
        return 0
    else:
        primes = [2]
        x = 3
        while x <= nums:
            for y in range(3, x, 2):
                if x % y == 0:
                    x += 2
                    break
            else:
                primes.append(x)
                x += 2
        print(primes)
        return len(primes)


y = count_prime(7)
print(y)
