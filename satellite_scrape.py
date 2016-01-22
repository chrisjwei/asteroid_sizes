from secret import *
import csv

from lxml import html
import requests

import urllib, cStringIO
from PIL import Image

f1 = open('bin/data/meteorite.csv')
f2 = open('bin/data/meteorite_edit.csv', 'wb')
reader = csv.reader(f1, delimiter=',')
writer = csv.writer(f2, delimiter=',')
results = 0
for row in reader:
  lat = row[1]
  lng = row[2]

  q = 'https://maps.googleapis.com/maps/api/staticmap?maptype=satellite&center='\
    + lat + ',' + lng + '&zoom=14&size=3x3&key='+KEY

  file = cStringIO.StringIO(urllib.urlopen(q).read())
  img = Image.open(file)
  c = img.convert('RGB').getcolors()
  
  r = 0
  g = 0
  b = 0
  count = 0.0
  for i in xrange(len(c)):
    (x, color) = c[i]
    count += x
    r += x * color[0]
    g += x * color[1]
    b += x * color[2]
  r = int(r/count)
  g = int(g/count)
  b = int(b/count)
  rgb = str(hex(r << 16 | g << 8 | b))[2:]
  if len(rgb) == 5:
    rgb = '0' + rgb
  rgb = '#' + rgb

  row.append(rgb)
  writer.writerow(row);
  results += 1
  print results

f2.close()
f1.close()