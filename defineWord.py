import os
import urllib2
from bs4 import BeautifulSoup

wordListFile = open('words.txt','r')

for word in wordListFile:
    url = 'http://www.vocabulary.com/dictionary/'+word
    f = urllib2.urlopen(url)
    html = f.read()
    soup = BeautifulSoup(html)
    newFileName = word+'.txt'
    newFile = open(newFileName, 'w')
    newFile.write(word+'\n\n')
    newFile.write(soup.find_all('p',class_='short')[0].get_text().encode("utf-8")+'\n\n')
    newFile.write(soup.find_all('p',class_='long')[0].get_text().encode("utf-8")+'\n')
    newFile.close()
