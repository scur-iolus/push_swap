import random
import os

l = random.sample(range(-2147483648, 2147483647), 100)
random.shuffle(l)
mon_fichier = open("test100python", "w")
mon_fichier.write(' '.join(map(str, l)))
mon_fichier.close()
