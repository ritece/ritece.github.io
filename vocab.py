import urllib2
from bs4 import BeautifulSoup
import os

url = 'http://www.vocabulary.com/lists/194479#view=notes'
f = urllib2.urlopen(url)
html = f.read()
soup = BeautifulSoup(html)

filePath = os.path.expanduser('~/Desktop/words2.txt')
myFile = open(filePath,'w')

words = soup.find_all('li', class_='entry learnable')

for word in words:
    myFile.write(word.a.get_text()+' -> '+word.div.get_text()+'\n')

myFile.close()


