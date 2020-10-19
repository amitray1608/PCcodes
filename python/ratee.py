#Amit(18BCS2059)
print('Employee details:')
noofweek = 4
hours  = 40
names = ['amit', 'anshul', 'rinkiya']
rate = [300, 400, 230]

for i in range(3):
	print('Name : ', names[i])
	print('Payrate : ', rate[i])
	payrate = rate[i]
	salary = hours * payrate * noofweek
	print(salary, ' per month')
	yearly = salary*12
	print(yearly, ' per year')
	if(yearly <= 100000):
		tax = (yearly*10)//100
		print('10 % tax =', tax)
	elif(yearly <= 200000):
		tax = (yearly*20)//100
		print('20 % tax =', tax)
	else:
		tax = (yearly*30)//100
		print('30 % tax =', tax)
		print('\n')
