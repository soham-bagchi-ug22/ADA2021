
stringP = []
popCount = []
pushCount = []
stringCount = []
opCount = []

def permute(str):
	opCount.append(1)
	if(len(stringP) == 5):
		print(stringP)
		stringCount.append(''.join(stringP))
	else:
		for i in range(len(str)):
			stringP.append(str[i])
			pushCount.append(1)
			permute(str[0:i] + str[i+1:len(str)])
			stringP.pop()
			popCount.append(1)

permute("MONEYSA")
print("Push: " + str(len(pushCount)))
print("Pop: " + str(len(popCount)))
print("Total Strings: " + str(len(stringCount)))
print("Total Nodes: " + str(len(opCount)))