import random 
punct = (".", ";", "!", "?", ",") 
count = 0
new_word = "" 
inputfile = input("Enter input file name:") 
with open(inputfile, 'r') as fin: 
    for line in fin.readlines(): 
  
        for word in line.split(): 
  
            if len(word) > 3:  

                if word.endswith(punct): 
                    word1 = word[1:-2] 
                    word1 = random.sample(word1, len(word1)) 
                    word1.insert(0, word[0]) 
                    word1.append(word[-2]) 
                    word1.append(word[-1]) 
                else: 
                    word1 = word[1:-1] 
                    word1 = random.sample(word1, len(word1)) 
                    word1.insert(0, word[0]) 
                    word1.append(word[-1]) 
                    new_word = new_word + ''.join(word1) + " "
        else: 
            new_word = new_word + word + " "
  
with open((inputfile[:-4] + "Scrambled.txt"), 'a+') as fout: 
    fout.write(new_word + "\n") 
  
new_word = "" 
