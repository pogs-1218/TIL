from math import *
#import math
from enum import Enum

phrase = "Giraffe Academy"
print(phrase.upper().isupper())
print(phrase.index("a"))
print(phrase.index("f"))
print(len(phrase))
print(phrase.replace("Giraffe", "Elephant"))

# number control
my_num = 5
print(str(my_num) + " is my favorite number")
print(pow(my_num, 3))
print(abs(my_num))
my_float = 4.3
print(round(my_float))
print(floor(my_float))
print(ceil(my_float))
print(sqrt(my_float))

# user input
# name = input("Enter your name: ")  # until new line('\n')
# age = input("Enter your age: ")
# print("Hello " + name + "! Your are " + age)

# data structures
fruites = ["apple", "banana"]
name = ["gwani", "namin"]
# extend vs append
#fruites.extend(name)
fruites.append(name)
print(fruites)

# what's difference ?
fr2 = fruites
# fr2 = fruites.copy()
print(fr2)

# list comprehension
squares = []
for x in range(10):
  squares.append(x ** 2)
print(squares)

squares2 = [x ** 2 for x in range(10)]
print(squares2)

# tuple vs list
coordinates = (4, 5)
# coordinates[0] = 5
print(coordinates)

tel = {"jack":1234, "sape":4321}
#tel = {"jack":1234, "jack":4321}  # not allow duplicate
print(tel)
tel["jack"] = 2222
print(tel)


# python 3.10+
# def http_error(status):
#   match status:
#     case 400:
#       return "Bad Request"
#     case 404:
#       return "Not found"
#     case 418:
#       return "I'm a teapot"
#     case _:  # default case in switch statement
#       return "Something's wrong with the internet"

# enumerate function returns the tuple consisting of an index and an element.
for entry in enumerate(['a', 'b', 'c']):  # entry is the tuple
  print(entry)

for i, letter in enumerate(['A', 'B', 'C', 'D'], start=1):
  print(i, letter)

def say_hello(name, age):
  print("Hello " + name + ", you are " + str(age))

say_hello("pi", 36)

class Color(Enum):
    RED = 1
    GREEN = 2
    BLUE = 3
print(Color.BLUE)
print(Color.RED.name)

# The parameter L is remaining even if the functions is out of bound.
def f(a, L=[]):
  L.append(a)
  return L
print(f(1))
print(f(2))
print(f(3))

def ff(a, L=None):
  if L is None:
    L = []
  L.append(a)
  return L
print(ff(1))
print(ff(2))
print(ff(3))
