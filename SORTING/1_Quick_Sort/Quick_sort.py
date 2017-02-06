#=======================================================#
#   AUTHOR :- RAVI SHANKAR KUMAR	                #
#   FROM :- SITAMARHI(BIHAR) , 843317	                #
#   NIT JALANDHAR, CSE PRE-FINAL YEAR                   #
#=======================================================#
def part (arr,start,last):
	pivot=arr[start]
	i=start+1
	j=last
	temp=0
	while i<=j:
		while arr[j]>pivot :
			j-=1
		while arr[i]<pivot and i<last :
			i+=1
		if i<j:
			temp=arr[j];arr[j]=arr[i];arr[i]=temp
			i+=1;j-=1
		else:
			i+=1
	arr[start]=arr[j];arr[j]=pivot
	return (j)
def sorts (arr,start,last):
	if start>=last:
		return
	pivot=part(arr,start,last)
	sorts(arr,start,pivot-1)
	sorts(arr,pivot+1,last)
	return
#WRITE ANOTHER FUNCTIONS FROM HERE
arr=[5,1,4,10,12]
sorts(arr,0,len(arr)-1)
print (arr)
