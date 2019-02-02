import fileinput

dct = {}
for line in fileinput.input():
	command = line.split()

	if command[0] == 'def':
		dct[command[1]] = int(command[2]) 		
	if command[0] == 'calc':
		command = command[1:]
		var = command[::2]
		op = command[1::2]
		
		answer = True
		for v in var:
			if v not in dct:
				answer = False
		
		if answer:	
			num = dct[var[0]]
			for i in range(len(op)-1):
				if op[i] == '+':
					num += dct[var[i+1]]
				if op[i] == '-':
					num -= dct[var[i+1]]
				
			for key, value in dct.iteritems():
				if value == num:
					print ' '.join(command), key
					answer = True
					break
				else:
					answer = False

		if not answer:
			print ' '.join(command), 'unknown'
		
	if command[0] == 'clear':
		dct = {}	
