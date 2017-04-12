primes_list=[]

for number in range(3,100,2):
	is_prime=1
	for prime in primes_list:
		if(number%prime==0):
			is_prime=0
			break

	if(is_prime==1):
		primes_list.append(number)

print(primes_list,len(primes_list))

sum2primes=[]
for i in range(len(primes_list)):
	sum2primes.append(primes_list[0]+primes_list[i])

sum2primes.sort()

print(sum2primes)
'''
for number in sum2primes:
	if(number%2==1):
		sum2primes.remove(number)

#print(sum2primes)

index=0
for even_number in range(4,max(sum2primes),2):
	while(sum2primes[index]<even_number):
		index=index+1

	else:
		if(sum2primes[index]==even_number):
			index=index+1
		elif sum2primes[index]>even_number:
			print(even_number)


'''