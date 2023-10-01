#=======================================================#
#   AUTHOR :- RAVI SHANKAR KUMAR	                #
#   FROM :- SITAMARHI(BIHAR) , 843317			#
#   NIT JALANDHAR, CSE PRE-FINAL YEAR                   #
#=======================================================#
def mrg (arr,r,left,mid,right):
    last=mid-1
    temp=left 
    ln=right-left+1
    while left<=last and mid<=right :
        if arr[left]<=arr[mid] :
            r[temp]=arr[left]
            temp=temp+1
            left=left+1
        else :
            r[temp]=arr[mid]
            temp=temp+1
            mid=mid+1
    while left<=last:
        r[temp]=arr[left]
        temp=temp+1
        left=left+1
    while mid<=right:
        r[temp]=arr[mid]
        mid=mid+1
        temp=temp+1
    i=0
    while i<ln: 
        arr[right]=r[right]
        right=right-1
        i+=1
    return
def merge_srt(arr,r,left,right):
    if right>left:
        mid=int((right+left)//2)
        merge_srt(arr,r,left,mid)
        merge_srt(arr,r,mid+1,right)
        mrg(arr,r,left,mid+1,right)
    return
arr=[12,11,10,9,8,7,6,5,4,3,2,1]
r=[0 for i in range(0,len(arr))]
merge_srt(arr,r,0,len(arr)-1)
print (arr)
