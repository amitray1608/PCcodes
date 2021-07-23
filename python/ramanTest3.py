import matplotlib as pit

import pandas as pd

data1={'City':['Delhi','Kolkata','Mumbai','Banglore', 'Shillong'],
"No of Covid Cases":[100000,78000, 120000,87000, 30000]}

df1 = pd.DataFrame(data1)
df1.plot(x= 'City', y = 'No of Covid Cases',kind= 'line')
