#Interpolation Search
#Better than binary search as it returns a closer value of pos on each iteration.
#pos=low +[x-arr[low]*(high-low)/arr[high]-arr[low]]

#iterative implememtation of interpolation search

def interpolationSearch(L,e):

	low=0
	high=len(L)-1

	while low<=high and e >=L[low] and e <=L[high]:
		pos=low + int((high-low)/(L[high]-L[low])*(e-L[low]))

		print(pos)

		if L[pos]==e:
			return pos

		if L[pos]<e:
			low=pos+1

		if L[pos]>e:
			high=pos-1


	return -1


L = [123,
134,
149,
169,
210,
219,
229,
234,
239,
245,
257,
275,
277,
281,
286,
295,
304,
315,
331,
334,
338,
349,
352,
366,
385,
391,
392,
401,
413,
436,
442,
453,
480,
499,
501,
505,
509,
511,
516,
521,
527,
536,
560,
562,
568,
589,
601,
636,
648,
649,
659,
660,
666,
678,
689,
700,
733,
739,
754,
755,
776,
798,
808,
809,
818,
828,
834,
842,
846,
856,
857,
858,
859,
869,
889,
891,
893,
895,
900,
918,
930,
934,
949,
953,
963,
979,
980,
989,
991,
]
  
e = 8931# Element to be searched 
index = interpolationSearch(L,e) 
  
if index != -1: 
    print("Element found at index",index) 
else: 
    print("Element not found")
