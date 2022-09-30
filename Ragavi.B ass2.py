import random
temp=random.randint(40,120)
hum=random.randint(40,120)
if (temp>62 and hum>48):
  print("Area is free")
elif (temp>62 or hum>48):
  if (temp<62 or hum>48):
    print("Humidity is slightly high")
  elif(temp>62 or hum<48):
    print("Temperature is varying")
elif(temp<62 or hum<48):
  print("Everything is good")
