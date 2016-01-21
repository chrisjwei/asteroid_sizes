from secret import *



reader = csv.reader(open('/bin/data/meteorite.csv'), delimiter=',')

for row in reader:
  lat = row[6]
  lng = row[7]

print (lat, lng)


q = 'https://maps.googleapis.com/maps/api/staticmap?maptype=satellite&center='\
  + '37.530101,38.600062' + '&zoom=14&size=10x10&key='+KEY