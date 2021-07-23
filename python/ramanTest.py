import pandas as pd

import numpy as np
data1 = {"id" : [10,20,30,40],
        "Name" :["Amit","Amita","raghav", "Amisha"],
    "Subject":['maths','science', 'history', 'English'], 
    "Marks":[60,70,50,89], 
    "Sex":["M","F","M", "F"]
    }

df1 = pd.DataFrame(data1) 
df2 = df1.loc[0:2,['Name','Subject']]
print(df2)
df1.to_csv('data.csv')


import pandas as pd
import numpy as np
data = np.array(['a', 'b', 'c', 'd', 'e'])
s = pd.Series(data)
print(s)
